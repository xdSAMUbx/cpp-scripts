set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/config")
include(cflags)

add_executable(DSAarrays1 arrays1.cpp)
add_executable(DSAarrays2 arrays2.cpp)
add_executable(DSAarrays3 arrays3.cpp)
add_executable(DSAarrays4 arrays4.cpp)

target_compile_options(DSAarrays2 PRIVATE ${CFLAGS_COMMON})
target_compile_options(DSAarrays3 PRIVATE ${CFLAGS_COMMON})
target_compile_options(DSAarrays4 PRIVATE ${CFLAGS_COMMON})
