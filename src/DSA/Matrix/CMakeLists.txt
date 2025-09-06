set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/config")
include(cflags)

add_executable(DSAmatrix1 matrix1.cpp)

target_compile_options(DSAmatrix1 PRIVATE ${CFLAGS_COMMON})
