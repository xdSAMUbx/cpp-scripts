set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -O2 -std=c++20")
set(CMAKE_CFLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -O2")

# Flags de GDAL
execute_process(COMMAND gdal-config --cflags
                OUTPUT_VARIABLE GDAL_CFLAGS
                OUTPUT_STRIP_TRAILING_WHITESPACE)
execute_process(COMMAND gdal-config --libs
                OUTPUT_VARIABLE GDAL_LIBS
                OUTPUT_STRIP_TRAILING_WHITESPACE)

