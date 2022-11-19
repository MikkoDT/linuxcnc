cmake_minimum_required(VERSION 3.0)
set(PROJECT "_togl") # ~/linuxcnc/src/emc/usr_intf/axis/
project(${PROJECT} VERSION 0 LANGUAGES CXX)

# Set variables.
set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
set(BUILD_DIR "${CMAKE_CURRENT_BINARY_DIR}")

# Set includepaths.
include_directories(${SRC_DIR})
include_directories(${SRC_DIR}/../common_src)
include_directories(${SRC_DIR}/../togl_py_src)
include_directories(/usr/include/python3.9)
include_directories(/usr/include/tcl8.6)

# Set prefix.
set(CMAKE_SHARED_LIBRARY_PREFIX "")

ADD_LIBRARY(${PROJECT} SHARED 
    ${SRC_DIR}/../togl_py_src/_toglmodule.c
    )

add_definitions(-DULAPI)


# Link to libraries.
target_link_libraries(${PROJECT_NAME} PRIVATE
    -ltcl8.6 -ltk8.6
    )

# Set custom output name :
# set_property(TARGET  ${PROJECT} PROPERTY OUTPUT_NAME thename)

# Add verion nr. .so.0.0.0
set_target_properties(${PROJECT_NAME} PROPERTIES VERSION ${PROJECT_VERSION})

# Make install
install(TARGETS ${PROJECT} DESTINATION ${SRC_DIR})

# Notes.














