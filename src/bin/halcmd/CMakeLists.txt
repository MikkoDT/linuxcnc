# **************************************************************************
cmake_minimum_required(VERSION 3.0)
# Component name. ~/linuxcnc/src/emc/task/
set(PROJECT "halcmd") # The name of the file excluding .c or .h
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
    ${SRC_DIR}/../../hal/utils/halcmd.c
    ${SRC_DIR}/../../hal/utils/halcmd_commands.cc
    ${SRC_DIR}/../../hal/utils/halcmd_main.c
    ${SRC_DIR}/../../hal/utils/halcmd_completion.c
)

add_executable(${PROJECT_NAME} ${SOURCES})

# liblinuxcnchal.so
target_include_directories(${PROJECT_NAME} PRIVATE ${BUILD_DIR}/src/hal/linuxcnchal)
# liblinuxcncini.so
target_include_directories(${PROJECT_NAME} PRIVATE ${BUILD_DIR}/src/libnml/inifile)

# Link.

target_link_libraries(${PROJECT_NAME} PRIVATE linuxcnchal linuxcncini -lreadline)

# make install
install(TARGETS ${PROJECT} DESTINATION ${SRC_DIR}/../../../bin)

# Notes: It looks like halcmd_completion differs in make output.
# If not -lreadline, remove halcmd_completion.c, see submakefile ~/linuxcnc/src/hal/utils
#
# Linking halcmd
# g++ -std=gnu++17 -L/home/user/linuxcnc/lib -Wl,-rpath,/home/user/linuxcnc/lib
# -o ../bin/halcmd objects/hal/utils/halcmd.o objects/hal/utils/halcmd_commands.o
# objects/hal/utils/halcmd_main.o objects/hal/utils/halcmd_completion.o ../lib/liblinuxcncini.so.0
# ../lib/liblinuxcnchal.so.0 -lreadline
# Compiling hal/utils/halrmt.c
# gcc -c -I. -Ilibnml/linklist -Iemc -Ilibnml/cms -Ilibnml/rcs -Ilibnml/inifile -Ilibnml/os_intf
#-Ilibnml/nml -Ilibnml/buffer -Ilibnml/posemath -Irtapi -Ihal -Iemc -Iemc/nml_intf -Iemc/kinematics -Iemc/tp
# -Iemc/motion -Iemc/ini -Iemc -Iemc/rs274ngc -Iemc/sai -Iemc/pythonplugin -Iemc/tooldata -Iemc
# -I/home/user/linuxcnc/src/include -I/usr/include/python3.9 -Os -fwrapv  -g -Wall -Wno-stringop-truncation
# -D_FORTIFY_SOURCE=2  -DULAPI -std=gnu11 -Werror=implicit-function-declaration -g -O2   \












