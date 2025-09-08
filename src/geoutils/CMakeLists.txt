set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/config")
include(cflags)

add_executable(gdal1 try1.cpp)

target_include_directories(gdal1 PRIVATE ${GDAL_CFLAGS})
target_link_libraries(gdal1 PRIVATE dependencias ${GDAL_LIBS})
