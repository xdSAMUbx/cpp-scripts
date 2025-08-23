include(${CMAKE_SOURCE_DIR}/config/cflags.cmake)

add_executable(searchTests searchTests.cpp searchAlgorithms.cpp)

target_include_directories(searchTests PRIVATE ${CMAKE_SOURCE_DIR}/include)