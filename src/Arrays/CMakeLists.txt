include(${CMAKE_SOURCE_DIR}/config/cflags.cmake)

add_executable(arrays1 arrays1.cpp)
add_executable(arrays2 arrays2.cpp vecUtilities.cpp)
add_executable(arrays3 arrays3.cpp vecUtilities.cpp "../Matrix/matrixUtilities.cpp")
add_executable(arrays4 arrays4.cpp)
add_executable(arrays5 arrays5.cpp)

target_include_directories(arrays2 PUBLIC "${CMAKE_SOURCE_DIR}/include")
target_include_directories(arrays3 PUBLIC "${CMAKE_SOURCE_DIR}/include")
