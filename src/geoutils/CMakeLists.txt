add_executable(gdal1 try1.cpp)
add_executable(gdal2 lecturaShp.cpp)

# Flags de compilación razonables
target_compile_options(gdal1 PRIVATE -Wall -Wextra -O2)
target_compile_options(gdal2 PRIVATE -Wall -Wextra -O2)

# Enlaces (cada ejecutable usa las mismas deps; ajusta si alguno no las necesita)
target_link_libraries(gdal1
    PRIVATE
        GDAL::GDAL
        GEOS::geos_c
        BLAS::BLAS
        LAPACK::LAPACK
        armadillo
)

target_link_libraries(gdal2
    PRIVATE
        GDAL::GDAL
        GEOS::geos_c
        BLAS::BLAS
        LAPACK::LAPACK
        armadillo
)
