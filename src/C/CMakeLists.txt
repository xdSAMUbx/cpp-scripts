set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/config")
include(cflags)

add_executable(holaMundoC holamundo.c)
add_executable(tempC progTemp.c)

