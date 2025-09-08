cmake_minimum_required(VERSION 3.5)
project(myProjec LANGUAGES C CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/bin")

set(CMAKE_BUILD_TYPE Debug)

find_package(LAPACK REQUIRED) 
find_package(BLAS REQUIRED)
find_package(GDAL REQUIRED)
find_package(Armadillo REQUIRED)

add_library(dependencias INTERFACE)

target_link_libraries(dependencias INTERFACE
  BLAS::BLAS
  LAPACK::LAPACK
  GDAL::GDAL
  armadillo
)

add_subdirectory(src)
