set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/config")
include(cflags)

add_executable(DSAmatrix1 matrix1.cpp)
add_executable(DSAarmadillo1 armadillo1.cpp)

target_compile_options(DSAmatrix1 PRIVATE ${CFLAGS_COMMON})

target_link_libraries(DSAarmadillo1 PRIVATE dependencias)
target_compile_options(DSAarmadillo1 PRIVATE ${CFLAGS_COMMON})
