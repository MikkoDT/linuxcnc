cmake_minimum_required(VERSION 3.0)
# Project name.
set(PROJECT "hal_lib" ) # The name of the file excluding .c or .h
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

set(CMAKE_SHARED_LIBRARY_PREFIX "")
add_definitions(
    -DRTAPI -DUSPACE -DRTAPI -D_GNU_SOURCE -Drealtime -D__MODULE__ -DSEQUENTIAL_SUPPORT -DHAL_SUPPORT
    -DDYNAMIC_PLCSIZE -DRT_SUPPORT -DOLD_TIMERS_MONOS_SUPPORT -DMODBUS_IO_MASTER
)

ADD_LIBRARY(${PROJECT} SHARED
    ${SRC_DIR}/../hal_lib.c
    )

target_link_libraries(${PROJECT_NAME} PRIVATE -fno-fast-math -mieee-fp -fno-unsafe-math-optimizations
    -Werror=frame-larger-than=2560 -Wno-declaration-after-statement -fwrapv -fno-builtin-sin -fno-builtin-cos
    -fno-builtin-sincos -fPIC -Os
)

# make install
install(TARGETS ${PROJECT} DESTINATION ${RT_DIR})

# gcc -c -Os -fwrapv  -g -Wall -Wno-stringop-truncation -D_FORTIFY_SOURCE=2  -DRTAPI
# -I. -I/home/user/linuxcnc/src/include -DUSPACE -DRTAPI -D_GNU_SOURCE -Drealtime -D__MODULE__
# -I/home/user/linuxcnc/src/../include -I/home/user/linuxcnc/src -I/home/user/linuxcnc/src/libnml/linklist
# -I/home/user/linuxcnc/src/libnml/cms -I/home/user/linuxcnc/src/libnml/rcs -I/home/user/linuxcnc/src/libnml/inifile
#-I/home/user/linuxcnc/src/libnml/os_intf -I/home/user/linuxcnc/src/libnml/nml -I/home/user/linuxcnc/src/libnml/buffer
# -I/home/user/linuxcnc/src/libnml/posemath -I/home/user/linuxcnc/src/rtapi -I/home/user/linuxcnc/src/hal
# -I/home/user/linuxcnc/src/emc/nml_intf -I/home/user/linuxcnc/src/emc/kinematics -I/home/user/linuxcnc/src/emc/tp
# -I/home/user/linuxcnc/src/emc/motion -DSEQUENTIAL_SUPPORT -DHAL_SUPPORT -DDYNAMIC_PLCSIZE -DRT_SUPPORT
# -DOLD_TIMERS_MONOS_SUPPORT -DMODBUS_IO_MASTER -fno-fast-math -mieee-fp -fno-unsafe-math-optimizations
#-Werror=frame-larger-than=2560 -Wno-declaration-after-statement -fwrapv -fno-builtin-sin -fno-builtin-cos -fno-builtin-sincos -fPIC -Os
#-MP -MD -MF "objects/rthal/hal_lib.d" -MT "objects/rthal/hal_lib.o"
# hal/hal_lib.c -o objects/rthal/hal_lib.o
# Linking ../rtlib/hal_lib.so

