include(${CMAKE_SOURCE_DIR}/config/cflags.cmake)

add_executable(matrix1 matrix1.cpp matrixUtilities.cpp "../Arrays/vecUtilities.cpp")
add_executable(matrix2 matrix2.cpp matrixUtilities.cpp "../Arrays/vecUtilities.cpp")
add_executable(matrix3 matrix3.cpp matrixUtilities.cpp "../Arrays/vecUtilities.cpp")


target_include_directories(matrix1 PUBLIC "${CMAKE_SOURCE_DIR}/include")
target_include_directories(matrix2 PUBLIC "${CMAKE_SOURCE_DIR}/include")
target_include_directories(matrix3 PUBLIC "${CMAKE_SOURCE_DIR}/include")

