cmake_minimum_required(VERSION 3.0)
# Project name.
set(PROJECT "gcode" ) # The name of the file excluding .c or .h
project(${PROJECT} LANGUAGES CXX) # Asm is optional.

# Set variables.
set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
set(BUILD_DIR "${CMAKE_CURRENT_BINARY_DIR}")
set(EMC_DIR "${SRC_DIR}/../")
set(BIN_DIR "${SRC_DIR}/../../../../bin")
set(HAL_DIR "${SRC_DIR}/../../../hal")
set(NML_DIR "${SRC_DIR}/../../../nml")
set(RTAPI_DIR "${SRC_DIR}/../../../rtapi")
set(CONFIG_DIR "${SRC_DIR}/../../../")
set(LIB_DIR "${SRC_DIR}/../../../../lib")
set(RT_DIR "${SRC_DIR}/../../../../rtlib")
set(PYTHON_DIR "/usr/include/python3.9")

# Set includepaths.
include_directories(${SRC_DIR})
include_directories(${RTAPI_DIR})
include_directories(${PYTHON_DIR})
include_directories(${CONFIG_DIR})
include_directories(${EMC_DIR})
include_directories(${SRC_DIR}/../../)
include_directories(${SRC_DIR}/../../nml_intf)
include_directories(${SRC_DIR}/../../../libnml/posemath)
include_directories(${SRC_DIR}/../../../libnml/nml)
include_directories(${SRC_DIR}/../../motion)
include_directories(${SRC_DIR}/../../tooldata)
include_directories(${SRC_DIR}/../../../libnml/rcs)
include_directories(${SRC_DIR}/../../../libnml/cms)
include_directories(${SRC_DIR}/../../../libnml/inifile)
include_directories(${SRC_DIR}/../../../hal)
include_directories(${SRC_DIR}/../../rs274ngc)

set(CMAKE_SHARED_LIBRARY_PREFIX "")
# add_definitions()

ADD_LIBRARY(${PROJECT} SHARED
    ${SRC_DIR}/../gcodemodule.cc
)

add_definitions(-DULAPI)

target_include_directories(${PROJECT_NAME} PRIVATE ${BUILD_DIR}/src/emc/rs274ngc)

# Link to :
target_link_libraries(${PROJECT_NAME} PRIVATE -fPIC rs274  -lstdc++
)

# make install
install(TARGETS ${PROJECT} DESTINATION ${LIB_DIR}/python)

# Notes 

















