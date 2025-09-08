cmake_minimum_required(VERSION 3.16)
project(myProject LANGUAGES C CXX)

# Salidas y estándar
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Dependencias "modernas"
find_package(GDAL REQUIRED)        # Provee target GDAL::GDAL
find_package(Armadillo REQUIRED)   # Provee target armadillo
find_package(BLAS REQUIRED)        # Provee target BLAS::BLAS
find_package(LAPACK REQUIRED)      # Provee target LAPACK::LAPACK

# --- GEOS (C API) ---
# 1) Intento directo: buscar headers/so de geos_c
find_path(GEOS_C_INCLUDE_DIR NAMES geos_c.h)
find_library(GEOS_C_LIBRARY     NAMES geos_c)

if (GEOS_C_INCLUDE_DIR AND GEOS_C_LIBRARY)
    add_library(GEOS::geos_c UNKNOWN IMPORTED)
    set_target_properties(GEOS::geos_c PROPERTIES
        IMPORTED_LOCATION            "${GEOS_C_LIBRARY}"
        INTERFACE_INCLUDE_DIRECTORIES "${GEOS_C_INCLUDE_DIR}"
    )
else()
    # 2) Fallback: geos-config (muy común en Ubuntu/Debian)
    find_program(GEOS_CONFIG geos-config)
    if (GEOS_CONFIG)
        execute_process(COMMAND ${GEOS_CONFIG} --includes
                        OUTPUT_VARIABLE GEOS_C_INCLUDES
                        OUTPUT_STRIP_TRAILING_WHITESPACE)
        execute_process(COMMAND ${GEOS_CONFIG} --clibs
                        OUTPUT_VARIABLE GEOS_C_LIBS
                        OUTPUT_STRIP_TRAILING_WHITESPACE)

        # Creamos un target INTERFACE con las flags devueltas
        add_library(GEOS::geos_c INTERFACE IMPORTED)
        separate_arguments(GEOS_C_INCLUDES)
        separate_arguments(GEOS_C_LIBS)
        target_compile_options(GEOS::geos_c INTERFACE ${GEOS_C_INCLUDES})
        target_link_libraries(GEOS::geos_c INTERFACE ${GEOS_C_LIBS})
    else()
        message(FATAL_ERROR "No se encontró la API C de GEOS (geos_c). 
Instala libgeos-dev o asegúrate de tener geos-config en el PATH.")
    endif()
endif()

add_subdirectory(src)
