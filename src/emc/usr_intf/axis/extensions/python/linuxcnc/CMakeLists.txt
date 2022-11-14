cmake_minimum_required(VERSION 3.0)
# Project name, should be linuxcnc.so, but name already used by other lib in this cmake hierarchy.
set(PROJECT "linuxcnc_axis_extension" ) # The name of the file excluding .c or .h
project(${PROJECT} LANGUAGES CXX C ) # Asm is optional.

# Set variables.
set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
set(BUILD_DIR "${CMAKE_CURRENT_BINARY_DIR}")
set(EMC_DIR "${SRC_DIR}/../../")
set(BIN_DIR "${SRC_DIR}/../../../../../../bin")
set(HAL_DIR "${SRC_DIR}/../../../../../../hal")
set(NML_DIR "${SRC_DIR}/../../../../../../nml")
set(RTAPI_DIR "${SRC_DIR}/../../../../../../rtapi")
set(CONFIG_DIR "${SRC_DIR}/../../../../../")
set(LIB_DIR "${SRC_DIR}/../../../../../../../lib")
set(RT_DIR "${SRC_DIR}/../../../../../../../rtlib")
set(PYTHON_DIR "/usr/include/python3.9")

# Set includepaths.
include_directories(${SRC_DIR})
include_directories(${RTAPI_DIR})
include_directories(${PYTHON_DIR})
include_directories(${CONFIG_DIR})
include_directories(${EMC_DIR})
include_directories(${SRC_DIR}/../../../../../nml_intf)
include_directories(${SRC_DIR}/../../../../../../libnml/posemath)
include_directories(${SRC_DIR}/../../../../../../libnml/nml)
include_directories(${SRC_DIR}/../../../../../motion)
include_directories(${SRC_DIR}/../../../../../tooldata)
include_directories(${SRC_DIR}/../../../../../../libnml/rcs)
include_directories(${SRC_DIR}/../../../../../../libnml/cms)
include_directories(${SRC_DIR}/../../../../../../libnml/os_intf)
include_directories(${SRC_DIR}/../../../../../../libnml/inifile)
include_directories(${SRC_DIR}/../../../../../../hal)
include_directories(${SRC_DIR}/../../../../../../)
include_directories(${SRC_DIR}/../../../../../rs274ngc)
include_directories(${SRC_DIR}/../../../../../kinematics)

set(CMAKE_SHARED_LIBRARY_PREFIX "")
# add_definitions()

ADD_LIBRARY(${PROJECT} SHARED
	${SRC_DIR}/../../emcmodule.cc
)

add_definitions(-DULAPI)

# liblinuxcncini.so
target_include_directories(${PROJECT_NAME} PRIVATE ${BUILD_DIR}/src/libnml/inifile)
# libnml.so
target_include_directories(${PROJECT_NAME} PRIVATE ${BUILD_DIR}/src/libnml)
# liblinuxcnc.so
target_include_directories(${PROJECT_NAME} PRIVATE ${BUILD_DIR}/src/emc/nml_intf)
# libtootldata.so
target_include_directories(${PROJECT_NAME} PRIVATE ${BUILD_DIR}/src/emc/tooldata)

# Link to :
target_link_libraries(${PROJECT_NAME} PRIVATE linuxcncini -L/usr/X11R6/lib -lm -lepoxy
)

# make install
install(TARGETS ${PROJECT} DESTINATION ${LIB_DIR}/python)

# Notes 
# emc/pythonplugin/python_plugin.cc -o objects/emc/pythonplugin/python_plugin.o
# Linking libpyplugin.so.0
# g++ -std=gnu++17 -g -L/home/user/linuxcnc/lib -Wl,-rpath,/home/user/linuxcnc/lib
# -Xlinker -export-dynamic -Wl,-O1 -Wl,-Bsymbolic-functions -Wl,-soname,libpyplugin.so.0
# -shared -o ../lib/libpyplugin.so.0 objects/emc/pythonplugin/python_plugin.o ../lib/liblinuxcncini.so
# -lstdc++ -lboost_python39 -L/usr/lib -lpython3.9 -lcrypt -lpthread -ldl  -lutil -lm -lm
# ln -sf libpyplugin.so.0 ../lib/libpyplugin.so



















