include(${CMAKE_SOURCE_DIR}/config/cflags.cmake)

add_executable(holaMundo holaMundo.cpp)
add_executable(forLoop forloop.cpp)
add_executable(sumaGauss sumaGaus.cpp)
add_executable(linearSearch linearSearch.cpp searchAlgorithms.cpp)
target_include_directories(linearSearch PRIVATE ${CMAKE_SOURCE_DIR}/include)

add_subdirectory(pointers)