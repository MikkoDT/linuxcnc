# Missing component : user_comps/thermistor.c
# Not done yet, executables :
# linuxcncrsh
# schedrmt
# linuxcnclcd
# linuxcncsvr
# io
# iov2
# rs274
# motion-logger

# python_plugin.cc => line 232 => "handle_pyerror" to "handle_pyerror_mod"
# reason : muliple defenitions.

# rtapi , #define ULAPI
# rtapi , boost::atomic #include <boost/atomic...>

# Tip: usefull debug when compiling source in it's original way : make BUILD_VERBOSE=1
# Tip: For reverse engineering, by just deleting one .so lib, then invoke "make BUILD_VERBOSE=1"
# It shows how its build and linked.

cmake_minimum_required(VERSION 3.0)
# Project name.
set(PROJECT "_linuxcnc_axis") # The name of the file excluding .c or .h
project(${PROJECT} CXX C) # Asm is optional.

# Set variables.
set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
set(BUILD_DIR "${CMAKE_CURRENT_BINARY_DIR}")

# rtapi_app
add_subdirectory(${SRC_DIR}/src/rtapi)
# module_helper
add_subdirectory(${SRC_DIR}/src/module_helper)
# hal_lib.so
add_subdirectory(${SRC_DIR}/src/hal/hal_lib)
# liblinuxcnchal.so
add_subdirectory(${SRC_DIR}/src/hal/linuxcnchal)
# libnml.so
add_subdirectory(${SRC_DIR}/src/libnml)
# liblinuxcncini.so
add_subdirectory(${SRC_DIR}/src/libnml/inifile)
# libtooldata.so
add_subdirectory(${SRC_DIR}/src/emc/tooldata)
# libpyplugin.so
add_subdirectory(${SRC_DIR}/src/emc/pythonplugin)
# librs274ngc.so
add_subdirectory(${SRC_DIR}/src/emc/rs274ngc)
# libposemath.so
add_subdirectory(${SRC_DIR}/src/libnml/posemath)
# lineardeltakins.so
add_subdirectory(${SRC_DIR}/src/emc/kinematics/python/lineardeltakins)
# rotarydeltakins.so
add_subdirectory(${SRC_DIR}/src/emc/kinematics/python/rotarydeltakins)
# libcanterp.so
add_subdirectory(${SRC_DIR}/src/emc/canterp)
# gcode.so
add_subdirectory(${SRC_DIR}/src/emc/rs274ngc/python)
# _hal.so
add_subdirectory(${SRC_DIR}/src/hal/linuxcnchal/python)
# liblinuxcnc.a , changed to .so
add_subdirectory(${SRC_DIR}/src/emc/nml_intf)
# linuxcnc.so, error
add_subdirectory(${SRC_DIR}/src/emc/usr_intf)
# linuxcnc.so axis extension.
add_subdirectory(${SRC_DIR}/src/emc/usr_intf/axis/extensions/python/linuxcnc)
# _togl.so axis extension.l
add_subdirectory(${SRC_DIR}/src/emc/usr_intf/axis/extensions/python/togl)
# milltask, ~/linuxcnc/src/emc/task
add_subdirectory(${SRC_DIR}/src/bin/milltask)
# hal.so src: ~/linuxcnc/src/hal/utils install: ~/linuxcnc/tcl/
add_subdirectory(${SRC_DIR}/src/hal/utils/hal)
# halcmd src: ~/linuxcnc/src/hal/utils install: ~/linuxcnc/bin/
add_subdirectory(${SRC_DIR}/src/bin/halcmd)
# halrmt src: ~/linuxcnc/src/hal/utils install: ~/linuxcnc/bin/
add_subdirectory(${SRC_DIR}/src/bin/halrmt)
# halmeter src: ~/linuxcnc/src/hal/utils install: ~/linuxcnc/bin/
add_subdirectory(${SRC_DIR}/src/bin/halmeter)
# halscope src: ~/linuxcnc/src/hal/utils install: ~/linuxcnc/bin/
add_subdirectory(${SRC_DIR}/src/bin/halscope)
# pci_write src: ~/linuxcnc/src/hal/utils install: ~/linuxcnc/bin/
add_subdirectory(${SRC_DIR}/src/bin/pci_write)
# pci_read src: ~/linuxcnc/src/hal/utils install: ~/linuxcnc/bin/
add_subdirectory(${SRC_DIR}/src/bin/pci_read)
# classicladder src: ~/linuxcnc/src/hal/classicladder install: ~/linuxcnc/bin/
# Error..
# add_subdirectory(${SRC_DIR}/src/bin/classicladder)
















