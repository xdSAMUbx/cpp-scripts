include(${CMAKE_SOURCE_DIR}/config/cflags.cmake)

add_executable(matrix1 matrix1.cpp matrixUtilities.cpp "../Algorithms/vecUtilities.cpp")

target_include_directories(matrix1 PUBLIC "${CMAKE_SOURCE_DIR}/include")