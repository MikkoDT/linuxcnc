cmake_minimum_required(VERSION 3.0)
# Project name. ~/linuxcnc/src/hal/utils/
set(PROJECT "hal" ) # The name of the file excluding .c or .h
project(${PROJECT} LANGUAGES CXX C ) # Asm is optional.

# Set variables.
set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
set(BUILD_DIR "${CMAKE_CURRENT_BINARY_DIR}")
set(EMC_DIR "${SRC_DIR}/../../../emc")
set(BIN_DIR "${SRC_DIR}/../../../bin")
set(HAL_DIR "${SRC_DIR}/../../")
set(NML_DIR "${SRC_DIR}/../../libnml")
set(RTAPI_DIR "${SRC_DIR}/../../../rtapi")
set(CONFIG_DIR "${SRC_DIR}/../../")
set(LIB_DIR "${SRC_DIR}/../../../../lib")
set(RT_DIR "${SRC_DIR}/../../../../rtlib")
set(PYTHON_DIR "/usr/include/python3.9")
set(TCL_DIR "${SRC_DIR}/../../../../tcl")

# Set includepaths.
include_directories(${SRC_DIR})
include_directories(${RTAPI_DIR})
include_directories(${PYTHON_DIR})
include_directories(${CONFIG_DIR})
include_directories(${SRC_DIR}/../../../)
include_directories(${SRC_DIR}/../../../libnml/inifile)
include_directories(/usr/lib/x86_64-linux-gnu)
include_directories(/usr/include/tcl8.6)

set(CMAKE_SHARED_LIBRARY_PREFIX "")

# Defenitions
add_definitions(-DULAPI)

ADD_LIBRARY(${PROJECT} SHARED
    ${SRC_DIR}/../halcmd.c
    ${SRC_DIR}/../halcmd_commands.cc
    ${SRC_DIR}/../halsh.c
)

# liblinuxcnchal.so
target_include_directories(${PROJECT_NAME} PRIVATE ${BUILD_DIR}/src/hal/linuxcnchal)
# liblinuxcncini.so
target_include_directories(${PROJECT_NAME} PRIVATE ${BUILD_DIR}/src/libnml/inifile)

# Link.
target_link_libraries(${PROJECT_NAME} PRIVATE linuxcncini linuxcnchal -ltclstub8.6 -lX11 -lXss
 -lXext -lXft -lfontconfig -lfreetype -lfontconfig  -lpthread -ldl -lz  -lpthread -lm -ltk8.6
)

# make install
install(TARGETS ${PROJECT} DESTINATION ${TCL_DIR})

# Notes :
# Linking hal.so
# g++ -std=gnu++17 -L/home/user/linuxcnc/lib -Wl,-rpath,/home/user/linuxcnc/lib
# -shared objects/hal/utils/halcmd.o objects/hal/utils/halcmd_commands.o objects/hal/utils/halsh.o
# ../lib/liblinuxcncini.so.0 ../lib/liblinuxcnchal.so.0
# -L/usr/lib/x86_64-linux-gnu -ltclstub8.6 -lX11 -lXss -lXext -lXft -lfontconfig
# -lfreetype -lfontconfig  -lpthread -ldl -lz  -lpthread -lm -L/usr/lib/x86_64-linux-gnu -ltk8.6
# -lXinerama  -o ../tcl/hal.so



