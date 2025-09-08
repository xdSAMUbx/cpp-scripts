
add_executable(DSAmatrix1 matrix1.cpp)
add_executable(DSAarmadillo1 armadillo1.cpp)

target_link_libraries(DSAarmadillo1 PRIVATE armadillo)
