include(${CMAKE_SOURCE_DIR}/config/cflags.cmake)

add_executable(holaMundo holaMundo.cpp)
add_executable(forLoop forloop.cpp)
add_executable(sumaGauss sumaGaus.cpp)
add_executable(searchTests searchTests.cpp searchAlgorithms.cpp)
add_executable(randomNumber randomNumber.cpp)

target_include_directories(searchTests PRIVATE ${CMAKE_SOURCE_DIR}/include)

add_subdirectory(pointers)