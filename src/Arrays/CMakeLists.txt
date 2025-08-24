include(${CMAKE_SOURCE_DIR}/config/cflags.cmake)

add_executable(arrays1 arrays1.cpp)
add_executable(arrays2 arrays2.cpp vecUtilities.cpp)

target_include_directories(arrays2 PUBLIC "${CMAKE_SOURCE_DIR}/include")