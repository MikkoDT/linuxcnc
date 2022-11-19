cmake_minimum_required(VERSION 3.0)
set(PROJECT "linuxcnc") # ~/linuxcnc/src/emc/nml_inft
project(${PROJECT} VERSION 0 LANGUAGES CXX)

# Set variables.
set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
set(BUILD_DIR "${CMAKE_CURRENT_BINARY_DIR}")

# Set includepaths.
include_directories(${SRC_DIR})
include_directories(${SRC_DIR}/../common_src)
include_directories(${SRC_DIR}/../rtapi_src)
include_directories(${SRC_DIR}/../liblinuxcnchal_src) # hal.h
include_directories(${SRC_DIR}/../emc_src)
include_directories(${SRC_DIR}/../libnml_src)

# Set prefix.
# set(CMAKE_SHARED_LIBRARY_PREFIX "")

ADD_LIBRARY(${PROJECT} STATIC # Mention static.
    ${SRC_DIR}/../emc_src/emc.hh
    ${SRC_DIR}/../emc_src/emcglb.c
    ${SRC_DIR}/../emc_src/modal_state.cc
    ${SRC_DIR}/../emc_src/emc.cc
    ${SRC_DIR}/../emc_src/emcpose.c
    ${SRC_DIR}/../emc_src/emcargs.cc
    ${SRC_DIR}/../emc_src/emcops.cc
    ${SRC_DIR}/../emc_src/canon_position.cc
    ${SRC_DIR}/../emc_src/emcIniFile.cc
    ${SRC_DIR}/../emc_src/iniaxis.cc
    ${SRC_DIR}/../emc_src/inijoint.cc
    ${SRC_DIR}/../emc_src/inispindle.cc
    ${SRC_DIR}/../emc_src/initraj.cc
    ${SRC_DIR}/../emc_src/inihal.cc
    ${SRC_DIR}/../emc_src/interpl.cc
    )

add_definitions(-DULAPI)

# Set include paths for libraries to link.
target_include_directories(${PROJECT_NAME} PRIVATE ${BUILD_DIR})

# Add verion nr. .so.0.0.0
set_target_properties(${PROJECT_NAME} PROPERTIES VERSION ${PROJECT_VERSION})

# Solves compile error for /tcl/linuxcnc.so lib.
set(CMAKE_CXX_FLAGS "-fPIC ${CMAKE_CXX_FLAGS}")

# Link to libraries.
target_link_libraries(${PROJECT_NAME} PRIVATE)

# Set custom output name :
# set_property(TARGET  ${PROJECT} PROPERTY OUTPUT_NAME thename)

# Make install
install(TARGETS ${PROJECT} DESTINATION ${BUILD_DIR}/../../../lib)

# Notes.



