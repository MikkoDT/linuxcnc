cmake_minimum_required(VERSION 3.0)
# Project name.
set(PROJECT "linuxcncini" ) # The name of the file excluding .c or .h
project(${PROJECT} VERSION 0 LANGUAGES CXX C ) # Asm is optional.

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
    ${SRC_DIR}/inifile.cc
    ${SRC_DIR}/inivar.cc
    )

# Link.
target_link_libraries(${PROJECT_NAME} -fPIC)

# Add verion nr. .so.0.0.0
set_target_properties(${PROJECT_NAME} PROPERTIES VERSION ${PROJECT_VERSION}
)

# make install
install(TARGETS ${PROJECT} DESTINATION ${LIB_DIR})

# Compiling libnml/inifile/inifile.cc
# g++ -std=gnu++17 -c -I. -Ilibnml/linklist -Iemc -Ilibnml/cms -Ilibnml/rcs -Ilibnml/inifile -Ilibnml/os_intf
# -Ilibnml/nml -Ilibnml/buffer -Ilibnml/posemath -Irtapi -Ihal -Iemc -Iemc/nml_intf -Iemc/kinematics -Iemc/tp -Iemc/motion
#- Iemc/ini -Iemc -Iemc/rs274ngc -Iemc/sai -Iemc/pythonplugin -Iemc/tooldata -Iemc -I/home/user/linuxcnc/src/include
# -I/usr/include/python3.9  -DULAPI  -g -Wall -Wno-stringop-truncation -D_FORTIFY_SOURCE=2 -Os -fwrapv -Werror=overloaded-virtual
# -g -O2 -std=gnu++17 -fPIC -MP -MD -MF "objects/libnml/inifile/inifile.d" -MT "objects/libnml/inifile/inifile.o" \
# libnml/inifile/inifile.cc -o objects/libnml/inifile/inifile.o
# Creating shared library liblinuxcncini.so.0





