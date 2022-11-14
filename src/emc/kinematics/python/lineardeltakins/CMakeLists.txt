cmake_minimum_required(VERSION 3.0)
# Project name.
set(PROJECT "lineardeltakins" ) # The name of the file excluding .c or .h
project(${PROJECT} LANGUAGES CXX C ) # Asm is optional.

# Set variables.
set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
set(BUILD_DIR "${CMAKE_CURRENT_BINARY_DIR}")
set(EMC_DIR "${SRC_DIR}/../../../")
set(BIN_DIR "${SRC_DIR}/../../../../../bin")
set(HAL_DIR "${SRC_DIR}/../../../../hal")
set(NML_DIR "${SRC_DIR}/../../../../nml")
set(RTAPI_DIR "${SRC_DIR}/../../../../rtapi")
set(CONFIG_DIR "${SRC_DIR}/../../../../")
set(LIB_DIR "${SRC_DIR}/../../../../../lib")
set(RT_DIR "${SRC_DIR}/../../../../../rtlib")
set(PYTHON_DIR "/usr/include/python3.9")

# Set includepaths.
include_directories(${SRC_DIR})
include_directories(${RTAPI_DIR})
include_directories(${PYTHON_DIR})
include_directories(${CONFIG_DIR})
include_directories(${EMC_DIR})
include_directories(${SRC_DIR}/../../../nml_intf)
include_directories(${SRC_DIR}/../../../../libnml/posemath)
include_directories(${SRC_DIR}/../../../../libnml/nml)
include_directories(${SRC_DIR}/../../../motion)
include_directories(${SRC_DIR}/../../../tooldata)
include_directories(${SRC_DIR}/../../../../libnml/rcs)
include_directories(${SRC_DIR}/../../../../libnml/cms)
include_directories(${SRC_DIR}/../../../../libnml/inifile)
include_directories(${SRC_DIR}/../../../pythonplugin)
include_directories(${SRC_DIR}/../../../../hal)

set(CMAKE_SHARED_LIBRARY_PREFIX "")
add_definitions(-D_FORTIFY_SOURCE=2 -DBOOST_ALLOW_DEPRECATED_HEADERS=1 -DBOOST_BIND_GLOBAL_PLACEHOLDERS=1)

ADD_LIBRARY(${PROJECT} SHARED
    ${SRC_DIR}/../../../kinematics/lineardeltakins.cc
)

add_definitions(-DULAPI -D_FORTIFY_SOURCE=2 -DBOOST_ALLOW_DEPRECATED_HEADERS=1 -DBOOST_BIND_GLOBAL_PLACEHOLDERS=1)

# Link to :
target_link_libraries(${PROJECT_NAME} PRIVATE -fPIC -lboost_python39 -fPIC )

# make install
install(TARGETS ${PROJECT} DESTINATION ${LIB_DIR}/python)

# Notes 
# Compiling emc/kinematics/lineardeltakins.cc
# g++ -std=gnu++17 -c -I. -Ilibnml/linklist -Iemc -Ilibnml/cms -Ilibnml/rcs -Ilibnml/inifile -Ilibnml/os_intf
# -Ilibnml/nml -Ilibnml/buffer -Ilibnml/posemath -Irtapi -Ihal -Iemc -Iemc/nml_intf -Iemc/kinematics -Iemc/tp
# -Iemc/motion -Iemc/ini -Iemc -Iemc/rs274ngc -Iemc/sai -Iemc/pythonplugin -Iemc/tooldata -Iemc
# -I/home/user/linuxcnc/src/include -I/usr/include/python3.9  -DULAPI  -g -Wall -Wno-stringop-truncation
# -D_FORTIFY_SOURCE=2 -Os -fwrapv -Werror=overloaded-virtual -g -O2  -std=gnu++17 -DBOOST_ALLOW_DEPRECATED_HEADERS=1
# -DBOOST_BIND_GLOBAL_PLACEHOLDERS=1 -fPIC -fno-strict-aliasing 
# -MP -MD -MF "objects/emc/kinematics/lineardeltakins.d" -MT "objects/emc/kinematics/lineardeltakins.o" 
# emc/kinematics/lineardeltakins.cc -o objects/emc/kinematics/lineardeltakins.o
# Linking python module lineardeltakins.so
# g++ -std=gnu++17 -L/home/user/linuxcnc/lib -Wl,-rpath,/home/user/linuxcnc/lib
# -shared -o ../lib/python/lineardeltakins.so objects/emc/kinematics/lineardeltakins.o -lboost_python39























