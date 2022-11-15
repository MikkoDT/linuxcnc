# Tip: usefull debug when compiling source in it's original way : make BUILD_VERBOSE=1
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

cmake_minimum_required(VERSION 3.0)
# Project name.
set(PROJECT "- LINUX_CNC -") # The name of the file excluding .c or .h
project(${PROJECT} CXX C) # Asm is optional.

# Set variables.
set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
set(BUILD_DIR "${CMAKE_CURRENT_BINARY_DIR}")

# Name          : rtapi_app
# Submakefile   : ~/linuxcnc/src/rtapi
# Install       : ~/linuxcnc/bin
# Cmake         : ~/src/rtapi
# add_subdirectory(${SRC_DIR}/src/rtapi)

# Name          : module_helper
# Submakefile   : ~/linuxcnc/module_helper
# Install       : ~/linuxcnc/bin
# Cmake         : ~/src/module_helper
# add_subdirectory(${SRC_DIR}/src/module_helper)

# Name          : hal_lib.so
# Submakefile   : ~/linuxcnc/src, is build as kernel module for rtlib. For make command find "hal_lib.so" in output of "$ make BUILD_VERBOSE=1"
# Install       : ~/linuxcnc/rtlib
# Cmake         : ~/src/hal/hal_lib
add_subdirectory(${SRC_DIR}/src/hal/hal_lib)

# Name          : liblinuxcnchal.so
# Submakefile   : ~/linuxcnc/src/hal
# Install       : ~/linuxcnc/lib
# Cmake         : ~/src/hal/linuxcnchal
add_subdirectory(${SRC_DIR}/src/hal/linuxcnchal)

# Name          : libnml.so
# Submakefile   : ~/linuxcnc/src/libnml
# Install       : ~/linuxcnc/lib
# Cmake         : ~/src/libnml
add_subdirectory(${SRC_DIR}/src/libnml)

# Name          : liblinuxcncini.so
# Submakefile   : ~/linuxcnc/src/libnml/inifile
# Install       : ~/linuxcnc/lib
# Cmake         : ~/src/libnml/inifile
add_subdirectory(${SRC_DIR}/src/libnml/inifile)

# Name          : libtooldata.so
# Submakefile   : ~/linuxcnc/src/emc/tooldata
# Install       : ~/linuxcnc/lib
# Cmake         : ~/src/emc/tooldata
add_subdirectory(${SRC_DIR}/src/emc/tooldata)

# Name          : libposemath.so
# Submakefile   : ~/linuxcnc/src/libnml/posemath
# Install       : ~/linuxcnc/lib
# Cmake         : ~/src/libnml/posemath
add_subdirectory(${SRC_DIR}/src/libnml/posemath)

# Name          : lineardeltakins.so
# Submakefile   : ~/linuxcnc/src/emc/kinematics
# Install       : ~/linuxcnc/lib/python
# Cmake         : ~/src/emc/kinematics/python/lineardeltakins
add_subdirectory(${SRC_DIR}/src/emc/kinematics/python/lineardeltakins)

# Name          : rotarydeltakins.so
# Submakefile   : ~/linuxcnc/src/emc/kinematics
# Install       : ~/linuxcnc/lib/python
# Cmake         : ~/src/emc/kinematics/python/rotarydeltakins
add_subdirectory(${SRC_DIR}/src/emc/kinematics/python/rotarydeltakins)

# Name          : _hal.so
# Submakefile   : ~/linuxcnc/src/hal
# Install       : ../lib/python/_hal.so
# Cmake         : ~/src/hal/linuxcnchal/python
add_subdirectory(${SRC_DIR}/src/hal/linuxcnchal/python)

# Note : 3x Duplicate project names, to be fixed in future lcnc versions :
# Note : liblinuxcnc.a gives reallocation error.

# Name          : liblinuxcnc.a ,changed to liblinuxcnc.so
# Submakefile   : ~/linuxcnc/src/emc/nml_intf
# Install       : ~/linuxcnc/lib
# Cmake         : ~/src/emc/nml_intf/linuxcnc
add_subdirectory(${SRC_DIR}/src/emc/nml_intf)

# Name          : linuxcnc.so
# Submakefile   : ~/linuxcnc/src/emc/usr_intf
# Install       : ~/linuxcnc/tcl
# Cmake         : ~/src/emc/usr_intf
add_subdirectory(${SRC_DIR}/src/emc/usr_intf)

# Name          : libpyplugin.so
# Submakefile   : ~/linuxcnc/src/emc/pythonplugin
# Install       : ~/linuxcnc/lib
# Cmake         : ~/src/emc/pythonplugin
add_subdirectory(${SRC_DIR}/src/emc/pythonplugin)

# Name          : librs274ngc.so
# Submakefile   : ~/linuxcnc/src/emc/rs274ngc
# Install       : ~/linuxcnc/lib
# Cmake         : ~/src/emc/rs274ngc
add_subdirectory(${SRC_DIR}/src/emc/rs274ngc)

# Name          : milltask
# Submakefile   : ~/linuxcnc/src/emc/task
# Install       : ~/linuxcnc/bin/
# Cmake         : ~/src/bin
# add_subdirectory(${SRC_DIR}/src/bin/milltask)

# Name          : libcanterp.so
# Submakefile   : ~/linuxcnc/src/emc/canterp
# Install       : ~/linuxcnc/lib
# Cmake         : ~/src/canterp
# add_subdirectory(${SRC_DIR}/src/emc/canterp)

# Name          : linuxcnc.so
# Submakefile   : ~/linuxcnc/src/emc/usr_intf/axis
# Install       : ~/linuxcnc/lib/python
# Cmake         : ~/src/emc/usr_intf/axis/extensions/python/linuxcnc
# add_subdirectory(${SRC_DIR}/src/emc/usr_intf/axis/extensions/python/linuxcnc)

# Name          : gcode.so
# Submakefile   : ~/linuxcnc/src/emc/rs274ngc
# Install       : ~/linuxcnc/lib/python
# Cmake         : ~/src/emc/rs274ngc/python/
# add_subdirectory(${SRC_DIR}/src/emc/rs274ngc/python)

# For every item use a different directory, to be fixed in future lcnc versions :
# _togl.so axis extension.
# Name          : _togl.so
# Submakefile   : ~/linuxcnc/src/emc/usr_intf/axis
# Install       : ~/linuxcnc/lib/python
# Cmake         : ~/src/emc/usr_intf/axis/extensions/python/togl
# add_subdirectory(${SRC_DIR}/src/emc/usr_intf/axis/extensions/python/togl)

# Name          : hal.so
# Submakefile   : ~/linuxcnc/src/hal/utils
# Install       : ~/linuxcnc/tcl
# Cmake         : ~/src/hal
# add_subdirectory(${SRC_DIR}/src/hal/utils/hal)

# Name          : halcmd
# Submakefile   : ~/linuxcnc/src/hal/utils
# Install       : ~/linuxcnc/bin
# Cmake         : ~/src/bin
# add_subdirectory(${SRC_DIR}/src/bin/halcmd)

# Name          : halrmt
# Submakefile   : ~/linuxcnc/src/hal/utils
# Install       : ~/linuxcnc/bin/
# Cmake         : ~/src/bin
# add_subdirectory(${SRC_DIR}/src/bin/halrmt)

# Name          : halmeter
# Submakefile   : ~/linuxcnc/src/hal/utils
# Install       : ~/linuxcnc/bin/
# Cmake         : ~/src/bin
# add_subdirectory(${SRC_DIR}/src/bin/halmeter)

# Name          : halscope
# Submakefile   : ~/linuxcnc/src/hal/utils
# Install       : ~/linuxcnc/bin/
# Cmake         : ~/src/bin
# add_subdirectory(${SRC_DIR}/src/bin/halscope)

# Name          : pci_writee
# Submakefile   : ~/linuxcnc/src/hal/utils
# Install       : ~/linuxcnc/bin/
# Cmake         : ~/src/bin
# add_subdirectory(${SRC_DIR}/src/bin/pci_write)

# Name          : pci_read
# Submakefile   : ~/linuxcnc/src/hal/utils
# Install       : ~/linuxcnc/bin/
# Cmake         : ~/src/bin
# add_subdirectory(${SRC_DIR}/src/bin/pci_read)



# classicladder src: ~/linuxcnc/src/hal/classicladder install: ~/linuxcnc/bin/
# Error..
# add_subdirectory(${SRC_DIR}/src/bin/classicladder)

















