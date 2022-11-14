cmake_minimum_required(VERSION 3.0)
# Project name.
set(PROJECT "linuxcnchal" ) # The name of the file excluding .c or .h
project(${PROJECT} LANGUAGES CXX C ) # Asm is optional.

# Set variables.
set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
set(BUILD_DIR "${CMAKE_CURRENT_BINARY_DIR}")
set(EMC_DIR "${SRC_DIR}/../../emc")
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

set(CMAKE_SHARED_LIBRARY_PREFIX "lib")
add_definitions(-D_FORTIFY_SOURCE=2 -DULAPI)

ADD_LIBRARY(${PROJECT} SHARED
    ${RTAPI_DIR}/uspace_ulapi.c
    ${HAL_DIR}/hal_lib.c
)

target_link_libraries(${PROJECT_NAME} -pthread -lrt -fPIC)

# make install
install(TARGETS ${PROJECT} DESTINATION ${LIB_DIR})






