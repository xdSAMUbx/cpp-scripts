include(${CMAKE_SOURCE_DIR}/config/cflags.cmake)

add_executable(searchTests searchTests.cpp searchAlgorithms.cpp)
add_executable(sortTests sortTests.cpp sortAlgorithms.cpp vecUtilities.cpp)

target_include_directories(searchTests PUBLIC "${CMAKE_SOURCE_DIR}/include")
target_include_directories(sortTests PUBLIC "${CMAKE_SOURCE_DIR}/include")