cmake_minimum_required(VERSION 3.5)
project(myProjec LANGUAGES C CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/bin")

set(CMAKE_BUILD_TYPE Debug)

add_subdirectory(src)
