cmake_minimum_required(VERSION 3.0)
set(PROJECT "rtapi_app")
project(${PROJECT} C)

# Set variables.
set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
set(BUILD_DIR "${CMAKE_CURRENT_BINARY_DIR}")

# Set includepaths.
include_directories(${SRC_DIR})
include_directories(${SRC_DIR}/../common_src)
include_directories(${SRC_DIR}/../liblinuxcnchal_src)
include_directories(${SRC_DIR}/../rtapi_src)

# Set prefix.
set(CMAKE_SHARED_LIBRARY_PREFIX "")

set(SOURCES
    ${SRC_DIR}/../rtapi_src/uspace_rtapi_app.cc
    ${SRC_DIR}/../rtapi_src/uspace_rtapi_parport.cc
    ${SRC_DIR}/../rtapi_src/uspace_rtapi_string.c
    ${SRC_DIR}/../rtapi_src/rtapi_pci.cc
    )
add_executable(${PROJECT_NAME} ${SOURCES})

add_definitions(-DSIM -DULAPI -UULAPI -DRTAPI)

# Set include paths for libraries to link.
target_include_directories(${PROJECT_NAME} PRIVATE ${BUILD_DIR})

# Link to libraries.
target_link_libraries(${PROJECT_NAME} PRIVATE pthread -pthread -lrt -ludev -ldl)

# Set custom output name :
# set_property(TARGET  ${PROJECT} PROPERTY OUTPUT_NAME thename)

# Make install
install(TARGETS ${PROJECT} DESTINATION ${BUILD_DIR}/../../../bin)

# Notes.
