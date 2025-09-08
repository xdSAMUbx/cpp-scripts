set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/config")
include(cflags)

add_executable(gdal1 try1.cpp)
add_executable(gdal2 lecturaShp.cpp)

target_include_directories(gdal1 PRIVATE ${GDAL_CFLAGS})
target_link_libraries(gdal1 PRIVATE dependencias ${GDAL_LIBS})

target_include_directories(gdal2 PRIVATE ${GDAL_CFLAGS})
target_link_libraries(gdal2 PRIVATE dependencias ${GDAL_LIBS})
