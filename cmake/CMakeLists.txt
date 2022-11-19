## Tip: usefull debug when compiling source in it's original way : make BUILD_VERBOSE=1
# Tip: For reverse engineering, by just deleting one .so lib, then invoke "make BUILD_VERBOSE=1"
# It shows how its build and linked.

# Note :
# To test if something is working after "make install" it can be you have to do a "sudo ldconfig ~/linuxcnc lib"
# so system know's where to find libs.

# Note :
# After "make install", you could consider "~/src/./sudo make setuid".

# Problems :
# Duplicate library names, cmake policy. To set output name :
# ~/linuxcnc/tcl/linuxcnc.so is duplicate.
# set_property(TARGET  ${PROJECT} PROPERTY OUTPUT_NAME linuxcnc)

# Tip :
# If you have problems with solving compile errors. What worked for me is when problems occur, include the original lcnc compiled libs first
# in your project, unitl the build finishes ok. Then switch out libs step by step with your own compiled libs. Use full filepath's to be sure.

# Important :
#
# After clean build and install :   ~/src : sudo make setuid
#

cmake_minimum_required(VERSION 3.0)
# Project name.
set(PROJECT "- LINUX_CNC -") # The name of the file excluding .c or .h
project(${PROJECT} CXX C) # Asm is optional.

# Set variables.
set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
set(BUILD_DIR "${CMAKE_CURRENT_BINARY_DIR}")

# ~/bin
add_subdirectory(${SRC_DIR}/rtapi)
add_subdirectory(${SRC_DIR}/module_helper)
# ~/lib

add_subdirectory(${SRC_DIR}/liblinuxcnchal)
add_subdirectory(${SRC_DIR}/liblinuxcncini)
add_subdirectory(${SRC_DIR}/libtooldata)
add_subdirectory(${SRC_DIR}/libnml)
add_subdirectory(${SRC_DIR}/liblinuxcnc)
add_subdirectory(${SRC_DIR}/libposemath)
add_subdirectory(${SRC_DIR}/libpyplugin)
add_subdirectory(${SRC_DIR}/librs274)
add_subdirectory(${SRC_DIR}/libcanterp)


# ~/rtlib
 add_subdirectory(${SRC_DIR}/hal_lib)
add_subdirectory(${SRC_DIR}/components/threads)

# ~/bin
add_subdirectory(${SRC_DIR}/halcmd)
add_subdirectory(${SRC_DIR}/halmeter)
add_subdirectory(${SRC_DIR}/halscope)
add_subdirectory(${SRC_DIR}/classicladder)
add_subdirectory(${SRC_DIR}/halui)
add_subdirectory(${SRC_DIR}/halrmt)
add_subdirectory(${SRC_DIR}/pci_write)
add_subdirectory(${SRC_DIR}/pci_read)
add_subdirectory(${SRC_DIR}/io)
add_subdirectory(${SRC_DIR}/iov2)
add_subdirectory(${SRC_DIR}/motion_logger)
add_subdirectory(${SRC_DIR}/sai)

add_subdirectory(${SRC_DIR}/linuxcncsrv)
add_subdirectory(${SRC_DIR}/milltask)
add_subdirectory(${SRC_DIR}/linuxcncrsh)
add_subdirectory(${SRC_DIR}/schedrmt)
add_subdirectory(${SRC_DIR}/linuxcnclcd)
# ~/tlc
add_subdirectory(${SRC_DIR}/linuxcnc_tlc)
add_subdirectory(${SRC_DIR}/hal_tlc)
# ~/lib/python
add_subdirectory(${SRC_DIR}/lineardeltakins_py)
add_subdirectory(${SRC_DIR}/rotarydeltakins_py)
add_subdirectory(${SRC_DIR}/hal_py)
add_subdirectory(${SRC_DIR}/togl_py)
add_subdirectory(${SRC_DIR}/linuxcnc_py)
add_subdirectory(${SRC_DIR}/gcode_py)


