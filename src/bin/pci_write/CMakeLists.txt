# **************************************************************************
cmake_minimum_required(VERSION 3.0)
# Component name. 
set(PROJECT "pci_write") # The name of the file excluding .c or .h
project(${PROJECT} LANGUAGES C CXX)

# Set variables.
set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
set(BUILD_DIR "${CMAKE_CURRENT_BINARY_DIR}")
set(EMC_DIR "${SRC_DIR}/../../emc")
set(BIN_DIR "${SRC_DIR}/../../bin")
set(HAL_DIR "${SRC_DIR}/../../hal")
set(RTAPI_DIR "${SRC_DIR}/../../rtapi")
set(LIB_NML_DIR "${SRC_DIR}/../../libnml")
set(CONFIG_DIR "${SRC_DIR}/../../")
set(PYTHON_DIR "/usr/include/python3.9")

include_directories(${SRC_DIR})
include_directories(${EMC_DIR})
include_directories(${BIN_DIR})
include_directories(${HAL_DIR})
include_directories(${RTAPI_DIR})
include_directories(${LIB_NML_DIR})
include_directories(${CONFIG_DIR})
include_directories(${PYTHON_DIR})
include_directories(${EMC_DIR}/rs274ngc)
include_directories(${EMC_DIR}/nml_intf)
include_directories(${EMC_DIR}/motion)
include_directories(${EMC_DIR}/tooldata)
include_directories(${EMC_DIR}/task)
include_directories(${EMC_DIR}/pythonplugin)
include_directories(${EMC_DIR}/kinematics)
include_directories(${EMC_DIR}/tp)
include_directories(${EMC_DIR}/ini)
include_directories(${LIB_NML_DIR}/posemath)
include_directories(${LIB_NML_DIR}/nml)
include_directories(${LIB_NML_DIR}/rcs)
include_directories(${LIB_NML_DIR}/cms)
include_directories(${LIB_NML_DIR}/inifile)
include_directories(${LIB_NML_DIR}/os_intf)
include_directories(${LIB_NML_DIR}/../../enc/rs274ngc)

add_definitions(-DULAPI)

set(SOURCES
    ${SRC_DIR}/../../hal/utils/pci_write.c
    ${SRC_DIR}/../../hal/utils/upci.c
)

add_executable(${PROJECT_NAME} ${SOURCES})

# Link.

target_link_libraries(${PROJECT_NAME} PRIVATE )

# make install
install(TARGETS ${PROJECT} DESTINATION ${SRC_DIR}/../../../bin)

# Notes: 











