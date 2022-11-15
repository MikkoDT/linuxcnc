cmake_minimum_required(VERSION 3.0)
# Name          : _hal.so
# Submakefile   : ~/linuxcnc/src/hal
# Install       : ../lib/python/_hal.so
set(PROJECT "_hal" ) # The name of the file excluding .c or .h
project(${PROJECT} LANGUAGES CXX C ) # Asm is optional.

# Set variables.
set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
set(BUILD_DIR "${CMAKE_CURRENT_BINARY_DIR}")
set(EMC_DIR "${SRC_DIR}/../../../emc")
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

set(CMAKE_SHARED_LIBRARY_PREFIX "")
 add_definitions(-DULAPI)

ADD_LIBRARY(${PROJECT} SHARED
    ${SRC_DIR}/../../halmodule.cc
)

# liblinuxcnchal.so
target_include_directories(${PROJECT_NAME} PRIVATE ${BUILD_DIR}/src/hal/linuxcnchal)

target_link_libraries(${PROJECT_NAME} -pthread -lrt -fPIC linuxcnchal)

# make install
install(TARGETS ${PROJECT} DESTINATION ${LIB_DIR}/python)

# Notes: no ULAPI was defined in original make process.
# Linking python module _hal.so
# g++ -std=gnu++17 -L/home/user/linuxcnc/lib -Wl,-rpath,/home/user/linuxcnc/lib
# -shared -o ../lib/python/_hal.so objects/hal/halmodule.o ../lib/liblinuxcnchal.so





