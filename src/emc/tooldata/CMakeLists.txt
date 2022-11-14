cmake_minimum_required(VERSION 3.0)
# Project name.
set(PROJECT "tooldata" ) # The name of the file excluding .c or .h
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
include_directories(${SRC_DIR})
include_directories(${SRC_DIR}/../nml_intf)
include_directories(${SRC_DIR}/../../libnml/posemath)
include_directories(${SRC_DIR}/../motion)
include_directories(${SRC_DIR}/../rs274ngc)
include_directories(${SRC_DIR}/../../libnml/nml)
include_directories(${SRC_DIR}/../../libnml/rcs)
include_directories(${SRC_DIR}/../../libnml/cms)

set(CMAKE_SHARED_LIBRARY_PREFIX "lib")
# add_definitions()
add_definitions(-DULAPI)

ADD_LIBRARY(${PROJECT} SHARED
            ${SRC_DIR}/tooldata_mmap.cc
            ${SRC_DIR}/tooldata_common.cc
            ${SRC_DIR}/tooldata_db.cc
)

# Link to :
target_link_libraries(${PROJECT_NAME} PRIVATE -fPIC )

# make install
install(TARGETS ${PROJECT} DESTINATION ${LIB_DIR})

# Notes : I think "tooldata_nml.cc" could be removed.



























