include(${CMAKE_SOURCE_DIR}/config/cflags.cmake)

add_executable(forLoop forloop.cpp)
add_executable(holaMundo holaMundo.cpp)
add_executable(sumaGauss sumaGaus.cpp)
add_executable(pointers pointers.cpp)
add_executable(references references.cpp)
add_executable(randomNumber randomNumber.cpp)
add_executable(matrix matrix.cpp "../Matrix/matrixUtilities.cpp")

target_include_directories(matrix PUBLIC "${CMAKE_SOURCE_DIR}/include")