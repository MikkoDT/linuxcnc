cmake_minimum_required(VERSION 3.0)
# Project name.
set(PROJECT "linuxcnc" ) # The name of the file excluding .c or .h
project(${PROJECT} LANGUAGES CXX C ) # Asm is optional.

# Set variables.
set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
set(BUILD_DIR "${CMAKE_CURRENT_BINARY_DIR}")
set(EMC_DIR "${SRC_DIR}/../")
set(BIN_DIR "${SRC_DIR}/../../../bin")
set(HAL_DIR "${SRC_DIR}/../../hal")
set(NML_DIR "${SRC_DIR}/../../nml")
set(RTAPI_DIR "${SRC_DIR}/../../rtapi")
set(CONFIG_DIR "${SRC_DIR}/../../")
set(LIB_DIR "${SRC_DIR}/../../../lib")
set(RT_DIR "${SRC_DIR}/../../../rtlib")
set(PYTHON_DIR "/usr/include/python3.9")

# Set includepaths.
include_directories(${SRC_DIR})
include_directories(${RTAPI_DIR})
include_directories(${PYTHON_DIR})
include_directories(${CONFIG_DIR})
include_directories(${EMC_DIR})
include_directories(${SRC_DIR}/../nml_intf)
include_directories(${SRC_DIR}/../../libnml/posemath)
include_directories(${SRC_DIR}/../../libnml/nml)
include_directories(${SRC_DIR}/../motion)
include_directories(${SRC_DIR}/../tooldata)
include_directories(${SRC_DIR}/../../libnml/rcs)
include_directories(${SRC_DIR}/../../libnml/cms)
include_directories(${SRC_DIR}/../../libnml/inifile)
include_directories(${SRC_DIR}/../pythonplugin)
include_directories(${SRC_DIR}/../../hal)
include_directories(${SRC_DIR}/../rs274ngc)
include_directories(${SRC_DIR}/../../libnml/linklist)

set(CMAKE_SHARED_LIBRARY_PREFIX "lib")
# add_definitions()

ADD_LIBRARY(${PROJECT} SHARED
    ${SRC_DIR}/emcglb.c
    ${SRC_DIR}/../rs274ngc/modal_state.cc 
    ${SRC_DIR}/emc.cc
    ${SRC_DIR}/emcpose.c
    ${SRC_DIR}/emcargs.cc
    ${SRC_DIR}/emcops.cc
    ${SRC_DIR}/canon_position.cc
    ${SRC_DIR}/../ini/emcIniFile.cc 
    ${SRC_DIR}/../ini/iniaxis.cc 
    ${SRC_DIR}/../ini/inijoint.cc 
    ${SRC_DIR}/../ini/inispindle.cc 
    ${SRC_DIR}/../ini/initraj.cc 
    ${SRC_DIR}/../ini/inihal.cc 
    ${SRC_DIR}/interpl.cc
)

add_definitions(-DULAPI)

# Link to :
target_link_libraries(${PROJECT_NAME} PRIVATE -fPIC)

# make install
install(TARGETS ${PROJECT} DESTINATION ${LIB_DIR})

# Notes 





















