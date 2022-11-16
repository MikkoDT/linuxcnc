cmake_minimum_required(VERSION 3.0)
set(PROJECT "hal_lib") 
project(${PROJECT} VERSION 0 LANGUAGES C)

# Set variables.
set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
set(BUILD_DIR "${CMAKE_CURRENT_BINARY_DIR}")

# Set includepaths.
include_directories(${SRC_DIR})
include_directories(${SRC_DIR}/../src)

# Set prefix.
set(CMAKE_SHARED_LIBRARY_PREFIX "")

ADD_LIBRARY(${PROJECT} SHARED 
    ${SRC_DIR}/../src/hal_lib.c
)

add_definitions(
    -DRTAPI -DUSPACE -DRTAPI -D_GNU_SOURCE -Drealtime -D__MODULE__ -DSEQUENTIAL_SUPPORT -DHAL_SUPPORT
    -DDYNAMIC_PLCSIZE -DRT_SUPPORT -DOLD_TIMERS_MONOS_SUPPORT -DMODBUS_IO_MASTER
)

# Add verion nr. .so.0.0.0
set_target_properties(${PROJECT_NAME} PROPERTIES VERSION ${PROJECT_VERSION})

# Set include paths for libraries to link.
target_include_directories(${PROJECT_NAME} PRIVATE ${BUILD_DIR})

# Link to libraries.
target_link_libraries(${PROJECT_NAME} PRIVATE -fno-fast-math -mieee-fp -fno-unsafe-math-optimizations
    -Werror=frame-larger-than=2560 -Wno-declaration-after-statement -fwrapv -fno-builtin-sin -fno-builtin-cos
    -fno-builtin-sincos -fPIC -Os)

# Set custom output name :
# set_property(TARGET ${PROJECT} PROPERTY OUTPUT_NAME thename)

# Make install
install(TARGETS ${PROJECT} DESTINATION ${SRC_DIR})

# Notes.

