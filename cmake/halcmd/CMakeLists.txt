cmake_minimum_required(VERSION 3.0)
set(PROJECT "halcmd")
project(${PROJECT} LANGUAGES CXX C)

# Set variables.
set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
set(BUILD_DIR "${CMAKE_CURRENT_BINARY_DIR}")

# Set includepaths.
include_directories(${SRC_DIR})
include_directories(${SRC_DIR}/../common_src)
include_directories(${SRC_DIR}/../rtapi_src)
include_directories(${SRC_DIR}/../liblinuxcnchal_src)
include_directories(${SRC_DIR}/../libnml_src)

# Set prefix.
# set(CMAKE_SHARED_LIBRARY_PREFIX "")

set(SOURCES
    ${SRC_DIR}/../halcmd_src/halcmd.c
    ${SRC_DIR}/../halcmd_src/halcmd_commands.cc
    ${SRC_DIR}/../halcmd_src/halcmd_main.c
    ${SRC_DIR}/../halcmd_src/halcmd_completion.c
    ${SRC_DIR}/../liblinuxcnchal_src/hal_lib.c
    ${SRC_DIR}/../rtapi_src/uspace_ulapi.c
    )
add_executable(${PROJECT_NAME} ${SOURCES})

add_definitions(-DULAPI)

# Set include paths for libraries to link.
# target_include_directories(${PROJECT_NAME} PRIVATE ${BUILD_DIR})

# Link to libraries.
target_link_libraries(${PROJECT_NAME} PRIVATE readline libnml liblinuxcncini)

# Set custom output name :
# set_property(TARGET  ${PROJECT} PROPERTY OUTPUT_NAME thename)

# Make install
install(TARGETS ${PROJECT} DESTINATION ${SRC_DIR})

# Notes.
