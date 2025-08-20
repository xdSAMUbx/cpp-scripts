cmake_minimum_required(VERSION 3.20)
project(myProject 
        VERSION 0.0.1
        DESCRIPTION "Es una código de aprendizaje"
        LANGUAGES CXX)

set(EXECUTABLE_NAME "main")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_executable(${EXECUTABLE_NAME} armadilloEx.cpp)

target_include_directories(${EXECUTABLE_NAME} PRIVATE "$ENV{HOME}/cpp-libs/armadillo-14.6.3/include")
find_package(BLAS REQUIRED)
find_package(LAPACK REQUIRED)
target_link_libraries(${EXECUTABLE_NAME} PRIVATE ${BLAS_LIBRARIES} ${LAPACK_LIBRARIES})