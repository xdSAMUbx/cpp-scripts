set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/config")
include(cflags)

add_executable(DSAmatrix1 matrix1.cpp)
add_executable(DSAarmadillo1 armadillo1.cpp)
add_executable(matrix3 matrix3.cpp)

target_link_libraries(DSAarmadillo1 PRIVATE dependencias)
