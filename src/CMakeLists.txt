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

# usefull debug : make BUILD_VERBOSE=1

cmake_minimum_required(VERSION 3.0)
# Project name.
set(PROJECT "linuxcncini") # The name of the file excluding .c or .h
project(${PROJECT} CXX C) # Asm is optional.

# Set variables.
set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
set(BUILD_DIR "${CMAKE_CURRENT_BINARY_DIR}")

# Set includepaths.
include_directories(${SRC_DIR})

# Compile with cmake.
# set(CMAKE_SHARED_LIBRARY_PREFIX "")

ADD_LIBRARY(${PROJECT} SHARED
    ${SRC_DIR}/libnml/inifile/inifile.cc
    ${SRC_DIR}/libnml/inifile/inivar.cc
    )

# make install
# install(TARGETS ${PROJECT} DESTINATION ${RT_DIR})

# **************************************************************************
cmake_minimum_required(VERSION 3.0)
# Project name.
set(PROJECT "posemath") # The name of the file excluding .c or .h
project(${PROJECT} CXX C) # Asm is optional.

# Set variables.
set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
set(BUILD_DIR "${CMAKE_CURRENT_BINARY_DIR}")

# Set includepaths.
include_directories(${SRC_DIR})

# Compile with cmake.
# set(CMAKE_SHARED_LIBRARY_PREFIX "")

ADD_LIBRARY(${PROJECT} SHARED
    ${SRC_DIR}/libnml/posemath/_posemath.c
    ${SRC_DIR}/libnml/posemath/posemath.cc
    ${SRC_DIR}/libnml/posemath/gomath.c
    ${SRC_DIR}/libnml/posemath/sincos.c
    )

# make install
# install(TARGETS ${PROJECT} DESTINATION ${RT_DIR})

# **************************************************************************

# Hal components.
# Hal user_comps.
# Hal classicladder.
# Hal utils.
# Hal drivers.

# **************************************************************************
cmake_minimum_required(VERSION 3.0)
# Component name.
set(PROJECT "halstreamer") # The name of the file excluding .c or .h
set(RT_CORE "linuxcnchal") # Link to halcore or for Lcnc use linuxcnchal
project(${PROJECT} C CXX ASM) # Asm is optional.

# Set variables.
set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
set(BUILD_DIR "${CMAKE_CURRENT_BINARY_DIR}")
set(RTAPI_DIR "${SRC_DIR}/rtapi")
set(HAL_DIR "${SRC_DIR}/hal")
set(NML_DIR "${SRC_DIR}/libnml")
set(COMPONENT_DIR "${SRC_DIR}/hal/components")

# Set includepaths for header files etc.
include_directories(${SRC_DIR})
include_directories(${RTAPI_DIR})
include_directories(${HAL_DIR})
include_directories(${LIB_DIR})
include_directories(${COMPONENT_DIR})

# Compile flags.
SET(GCC_COVERAGE_COMPILE_FLAGS "
    -DUSPACE -fno-fast-math -fno-unsafe-math-optimizations -DULAPI -D_GNU_SOURCE \
    -Drealtime -D__MODULE__ -DSIM -fPIC -Os pthread rt")
add_definitions(-DULAPI -DUSPACE -D_GNU_SOURCE -D__MODULE__ )

# No "lib" before filename.
set(CMAKE_SHARED_LIBRARY_PREFIX "")

ADD_LIBRARY(${PROJECT} SHARED
    ${COMPONENT_DIR}/streamer_usr.c
    )

# Link to other libraries
target_include_directories(${PROJECT_NAME} PRIVATE "${BUILD_DIR}/${RT_CORE}")
target_link_libraries(${PROJECT_NAME} PRIVATE pthread rt ${RT_CORE})

# make install
# install(TARGETS ${PROJECT} DESTINATION ${RT_DIR})

# **************************************************************************
cmake_minimum_required(VERSION 3.0)
# Component name.
set(PROJECT "halsampler") # The name of the file excluding .c or .h
set(RT_CORE "linuxcnchal") # Link to halcore or for Lcnc use linuxcnchal
project(${PROJECT} C CXX ASM) # Asm is optional.

# Set variables.
set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
set(BUILD_DIR "${CMAKE_CURRENT_BINARY_DIR}")
set(RTAPI_DIR "${SRC_DIR}/rtapi")
set(HAL_DIR "${SRC_DIR}/hal")
set(NML_DIR "${SRC_DIR}/libnml")
set(COMPONENT_DIR "${SRC_DIR}/hal/components")

# Set includepaths for header files etc.
include_directories(${SRC_DIR})
include_directories(${RTAPI_DIR})
include_directories(${HAL_DIR})
include_directories(${LIB_DIR})
include_directories(${COMPONENT_DIR})

# Compile flags.
SET(GCC_COVERAGE_COMPILE_FLAGS "
    -DUSPACE -fno-fast-math -fno-unsafe-math-optimizations -DULAPI -D_GNU_SOURCE \
    -Drealtime -D__MODULE__ -DSIM -fPIC -Os pthread rt")
add_definitions(-DULAPI -DUSPACE -D_GNU_SOURCE -D__MODULE__ )

# No "lib" before filename.
set(CMAKE_SHARED_LIBRARY_PREFIX "")

ADD_LIBRARY(${PROJECT} SHARED
    ${COMPONENT_DIR}/sampler_usr.c
    )

# Link to other libraries
target_include_directories(${PROJECT_NAME} PRIVATE "${BUILD_DIR}/${RT_CORE}")
target_link_libraries(${PROJECT_NAME} PRIVATE pthread rt ${RT_CORE})

# make install
# install(TARGETS ${PROJECT} DESTINATION ${RT_DIR})

# **************************************************************************
cmake_minimum_required(VERSION 3.0)
# Component name.
set(PROJECT "panelui") # The name of the file excluding .c or .h
set(RT_CORE "linuxcnchal") # Link to halcore or for Lcnc use linuxcnchal
project(${PROJECT} C CXX ASM) # Asm is optional.

# Set variables.
set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
set(BUILD_DIR "${CMAKE_CURRENT_BINARY_DIR}")
set(RTAPI_DIR "${SRC_DIR}/rtapi")
set(HAL_DIR "${SRC_DIR}/hal")
set(NML_DIR "${SRC_DIR}/libnml")
set(COMPONENT_DIR "${SRC_DIR}/hal/components")
set(PYTHON_DIR "/usr/include/python3.9")

# Set includepaths for header files etc.
include_directories(${SRC_DIR})
include_directories(${RTAPI_DIR})
include_directories(${HAL_DIR})
include_directories(${LIB_DIR})
include_directories(${COMPONENT_DIR})
include_directories(${PYTHON_DIR})

# Compile flags.
SET(GCC_COVERAGE_COMPILE_FLAGS "
    -DUSPACE -fno-fast-math -fno-unsafe-math-optimizations -DULAPI -D_GNU_SOURCE \
    -Drealtime -D__MODULE__ -DSIM -fPIC -Os pthread rt")
add_definitions(-DULAPI -DUSPACE -D_GNU_SOURCE -D__MODULE__ )

# No "lib" before filename.
set(CMAKE_SHARED_LIBRARY_PREFIX "")

ADD_LIBRARY(${PROJECT} SHARED
    ${COMPONENT_DIR}/panelui.c
    )

# Link to other libraries
target_include_directories(${PROJECT_NAME} PRIVATE "${BUILD_DIR}/${RT_CORE}")
target_link_libraries(${PROJECT_NAME} PRIVATE pthread rt ${RT_CORE})

# make install
# install(TARGETS ${PROJECT} DESTINATION ${RT_DIR})

# **************************************************************************
cmake_minimum_required(VERSION 3.0)
# Component name.
set(PROJECT "mb2hal") # The name of the file excluding .c or .h
set(RT_CORE "linuxcnchal") # Link to halcore or for Lcnc use linuxcnchal
project(${PROJECT} C CXX ASM) # Asm is optional.

# Set variables.
set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
set(BUILD_DIR "${CMAKE_CURRENT_BINARY_DIR}")
set(RTAPI_DIR "${SRC_DIR}/rtapi")
set(HAL_DIR "${SRC_DIR}/hal")
set(NML_DIR "${SRC_DIR}/libnml")
set(COMPONENT_DIR "${SRC_DIR}/hal/components")
set(USER_COMPS_DIR "${SRC_DIR}/hal/user_comps")
set(PYTHON_DIR "/usr/include/python3.9")
set(MODBUS_DIR "/usr/include/modbus")

# Set includepaths for header files etc.
include_directories(${SRC_DIR})
include_directories(${RTAPI_DIR})
include_directories(${HAL_DIR})
include_directories(${LIB_DIR})
include_directories(${COMPONENT_DIR})
include_directories(${USER_COMPS_DIR})
include_directories(${USER_COMPS_DIR}/mb2hal)
include_directories(${PYTHON_DIR})
include_directories(${MODBUS_DIR})

# Compile flags.
SET(GCC_COVERAGE_COMPILE_FLAGS "
    -DUSPACE -fno-fast-math -fno-unsafe-math-optimizations -DULAPI -D_GNU_SOURCE \
    -Drealtime -D__MODULE__ -DSIM -fPIC -Os pthread rt")
add_definitions(-DULAPI -DUSPACE -D_GNU_SOURCE -D__MODULE__ )

# No "lib" before filename.
set(CMAKE_SHARED_LIBRARY_PREFIX "")

ADD_LIBRARY(${PROJECT} SHARED
    ${USER_COMPS_DIR}/mb2hal/mb2hal.c
    ${USER_COMPS_DIR}/mb2hal/mb2hal_init.c
    ${USER_COMPS_DIR}/mb2hal/mb2hal_modbus.c
    ${USER_COMPS_DIR}/mb2hal/mb2hal_hal.c
    )

# Link to other libraries
target_include_directories(${PROJECT_NAME} PRIVATE "${BUILD_DIR}/${RT_CORE}")
target_link_libraries(${PROJECT_NAME} PRIVATE pthread rt ${RT_CORE})

# make install
# install(TARGETS ${PROJECT} DESTINATION ${RT_DIR})

# **************************************************************************
cmake_minimum_required(VERSION 3.0)
# Component name.
set(PROJECT "gs2_vfd") # The name of the file excluding .c or .h
set(RT_CORE "linuxcnchal") # Link to halcore or for Lcnc use linuxcnchal
project(${PROJECT} C CXX ASM) # Asm is optional.

# Set variables.
set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
set(BUILD_DIR "${CMAKE_CURRENT_BINARY_DIR}")
set(RTAPI_DIR "${SRC_DIR}/rtapi")
set(HAL_DIR "${SRC_DIR}/hal")
set(NML_DIR "${SRC_DIR}/libnml")
set(COMPONENT_DIR "${SRC_DIR}/hal/components")
set(USER_COMPS_DIR "${SRC_DIR}/hal/user_comps")
set(PYTHON_DIR "/usr/include/python3.9")
set(MODBUS_DIR "/usr/include/modbus")

# Set includepaths for header files etc.
include_directories(${SRC_DIR})
include_directories(${RTAPI_DIR})
include_directories(${HAL_DIR})
include_directories(${LIB_DIR})
include_directories(${COMPONENT_DIR})
include_directories(${USER_COMPS_DIR})
include_directories(${PYTHON_DIR})
include_directories(${MODBUS_DIR})

# Compile flags.
SET(GCC_COVERAGE_COMPILE_FLAGS "
    -DUSPACE -fno-fast-math -fno-unsafe-math-optimizations -DULAPI -D_GNU_SOURCE \
    -Drealtime -D__MODULE__ -DSIM -fPIC -Os pthread rt")
add_definitions(-DULAPI -DUSPACE -D_GNU_SOURCE -D__MODULE__ )

# No "lib" before filename.
set(CMAKE_SHARED_LIBRARY_PREFIX "")

ADD_LIBRARY(${PROJECT} SHARED
    ${USER_COMPS_DIR}/gs2_vfd.c
    )

# Link to other libraries
target_include_directories(${PROJECT_NAME} PRIVATE "${BUILD_DIR}/${RT_CORE}")
target_link_libraries(${PROJECT_NAME} PRIVATE pthread rt ${RT_CORE})

# make install
# install(TARGETS ${PROJECT} DESTINATION ${RT_DIR})

# **************************************************************************
cmake_minimum_required(VERSION 3.0)
# Component name.
set(PROJECT "hy_gt_vfd") # The name of the file excluding .c or .h
set(RT_CORE "linuxcnchal") # Link to halcore or for Lcnc use linuxcnchal
project(${PROJECT} C CXX ASM) # Asm is optional.

# Set variables.
set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
set(BUILD_DIR "${CMAKE_CURRENT_BINARY_DIR}")
set(RTAPI_DIR "${SRC_DIR}/rtapi")
set(HAL_DIR "${SRC_DIR}/hal")
set(NML_DIR "${SRC_DIR}/libnml")
set(COMPONENT_DIR "${SRC_DIR}/hal/components")
set(USER_COMPS_DIR "${SRC_DIR}/hal/user_comps")
set(PYTHON_DIR "/usr/include/python3.9")
set(MODBUS_DIR "/usr/include/modbus")

# Set includepaths for header files etc.
include_directories(${SRC_DIR})
include_directories(${RTAPI_DIR})
include_directories(${HAL_DIR})
include_directories(${LIB_DIR})
include_directories(${COMPONENT_DIR})
include_directories(${USER_COMPS_DIR})
include_directories(${PYTHON_DIR})
include_directories(${MODBUS_DIR})

# Compile flags.
SET(GCC_COVERAGE_COMPILE_FLAGS "
    -DUSPACE -fno-fast-math -fno-unsafe-math-optimizations -DULAPI -D_GNU_SOURCE \
    -Drealtime -D__MODULE__ -DSIM -fPIC -Os pthread rt")
add_definitions(-DULAPI -DUSPACE -D_GNU_SOURCE -D__MODULE__ )

# No "lib" before filename.
set(CMAKE_SHARED_LIBRARY_PREFIX "")

ADD_LIBRARY(${PROJECT} SHARED
    ${USER_COMPS_DIR}/hy_gt_vfd.c
    )

# Link to other libraries
target_include_directories(${PROJECT_NAME} PRIVATE "${BUILD_DIR}/${RT_CORE}")
target_link_libraries(${PROJECT_NAME} PRIVATE pthread rt ${RT_CORE})

# make install
# install(TARGETS ${PROJECT} DESTINATION ${RT_DIR})

# **************************************************************************
cmake_minimum_required(VERSION 3.0)
# Component name.
set(PROJECT "svd-ps_vfd") # The name of the file excluding .c or .h
set(RT_CORE "linuxcnchal") # Link to halcore or for Lcnc use linuxcnchal
project(${PROJECT} C CXX ASM) # Asm is optional.

# Set variables.
set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
set(BUILD_DIR "${CMAKE_CURRENT_BINARY_DIR}")
set(RTAPI_DIR "${SRC_DIR}/rtapi")
set(HAL_DIR "${SRC_DIR}/hal")
set(NML_DIR "${SRC_DIR}/libnml")
set(COMPONENT_DIR "${SRC_DIR}/hal/components")
set(USER_COMPS_DIR "${SRC_DIR}/hal/user_comps")
set(PYTHON_DIR "/usr/include/python3.9")
set(MODBUS_DIR "/usr/include/modbus")

# Set includepaths for header files etc.
include_directories(${SRC_DIR})
include_directories(${RTAPI_DIR})
include_directories(${HAL_DIR})
include_directories(${LIB_DIR})
include_directories(${COMPONENT_DIR})
include_directories(${USER_COMPS_DIR})
include_directories(${PYTHON_DIR})
include_directories(${MODBUS_DIR})

# Compile flags.
SET(GCC_COVERAGE_COMPILE_FLAGS "
    -DUSPACE -fno-fast-math -fno-unsafe-math-optimizations -DULAPI -D_GNU_SOURCE \
    -Drealtime -D__MODULE__ -DSIM -fPIC -Os pthread rt")
add_definitions(-DULAPI -DUSPACE -D_GNU_SOURCE -D__MODULE__ )

# No "lib" before filename.
set(CMAKE_SHARED_LIBRARY_PREFIX "")

ADD_LIBRARY(${PROJECT} SHARED
    ${USER_COMPS_DIR}/svd-ps_vfd.c
    )

# Link to other libraries
target_include_directories(${PROJECT_NAME} PRIVATE "${BUILD_DIR}/${RT_CORE}")
target_link_libraries(${PROJECT_NAME} PRIVATE pthread rt ${RT_CORE})

# make install
# install(TARGETS ${PROJECT} DESTINATION ${RT_DIR})

# **************************************************************************
cmake_minimum_required(VERSION 3.0)
# Component name.
set(PROJECT "shuttle") # The name of the file excluding .c or .h
set(RT_CORE "linuxcnchal") # Link to halcore or for Lcnc use linuxcnchal
project(${PROJECT} C CXX ASM) # Asm is optional.

# Set variables.
set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
set(BUILD_DIR "${CMAKE_CURRENT_BINARY_DIR}")
set(RTAPI_DIR "${SRC_DIR}/rtapi")
set(HAL_DIR "${SRC_DIR}/hal")
set(NML_DIR "${SRC_DIR}/libnml")
set(COMPONENT_DIR "${SRC_DIR}/hal/components")
set(USER_COMPS_DIR "${SRC_DIR}/hal/user_comps")
set(PYTHON_DIR "/usr/include/python3.9")
set(MODBUS_DIR "/usr/include/modbus")

# Set includepaths for header files etc.
include_directories(${SRC_DIR})
include_directories(${RTAPI_DIR})
include_directories(${HAL_DIR})
include_directories(${LIB_DIR})
include_directories(${COMPONENT_DIR})
include_directories(${USER_COMPS_DIR})
include_directories(${PYTHON_DIR})
include_directories(${MODBUS_DIR})

# Compile flags.
SET(GCC_COVERAGE_COMPILE_FLAGS "
    -DUSPACE -fno-fast-math -fno-unsafe-math-optimizations -DULAPI -D_GNU_SOURCE \
    -Drealtime -D__MODULE__ -DSIM -fPIC -Os pthread rt")
add_definitions(-DULAPI -DUSPACE -D_GNU_SOURCE -D__MODULE__ )

# No "lib" before filename.
set(CMAKE_SHARED_LIBRARY_PREFIX "")

ADD_LIBRARY(${PROJECT} SHARED
    ${USER_COMPS_DIR}/shuttle.c
    )

# Link to other libraries
target_include_directories(${PROJECT_NAME} PRIVATE "${BUILD_DIR}/${RT_CORE}")
target_link_libraries(${PROJECT_NAME} PRIVATE pthread rt ${RT_CORE})

# make install
# install(TARGETS ${PROJECT} DESTINATION ${RT_DIR})

# **************************************************************************
cmake_minimum_required(VERSION 3.0)
# Component name.
set(PROJECT "xhc-hb04") # The name of the file excluding .c or .h
set(RT_CORE "linuxcnchal") # Link to halcore or for Lcnc use linuxcnchal
project(${PROJECT} C CXX ASM) # Asm is optional.

# Set variables.
set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
set(BUILD_DIR "${CMAKE_CURRENT_BINARY_DIR}")
set(RTAPI_DIR "${SRC_DIR}/rtapi")
set(HAL_DIR "${SRC_DIR}/hal")
set(NML_DIR "${SRC_DIR}/libnml")
set(COMPONENT_DIR "${SRC_DIR}/hal/components")
set(USER_COMPS_DIR "${SRC_DIR}/hal/user_comps")
set(PYTHON_DIR "/usr/include/python3.9")
set(MODBUS_DIR "/usr/include/modbus")
set(LIBUSB_DIR "/usr/include/libusb-1.0")

# Set includepaths for header files etc.
include_directories(${SRC_DIR})
include_directories(${RTAPI_DIR})
include_directories(${HAL_DIR})
include_directories(${LIB_DIR})
include_directories(${COMPONENT_DIR})
include_directories(${USER_COMPS_DIR})
include_directories(${PYTHON_DIR})
include_directories(${MODBUS_DIR})
include_directories(${LIBUSB_DIR})

# Compile flags.
SET(GCC_COVERAGE_COMPILE_FLAGS "
    -DUSPACE -fno-fast-math -fno-unsafe-math-optimizations -DULAPI -D_GNU_SOURCE \
    -Drealtime -D__MODULE__ -DSIM -fPIC -Os pthread rt")
add_definitions(-DULAPI -DUSPACE -D_GNU_SOURCE -D__MODULE__ )

# No "lib" before filename.
set(CMAKE_SHARED_LIBRARY_PREFIX "")

ADD_LIBRARY(${PROJECT} SHARED
    ${USER_COMPS_DIR}/xhc-hb04.cc
    )

# Link to other libraries
target_include_directories(${PROJECT_NAME} PRIVATE "${BUILD_DIR}/${RT_CORE}")
target_link_libraries(${PROJECT_NAME} PRIVATE pthread rt ${RT_CORE})

# make install
# install(TARGETS ${PROJECT} DESTINATION ${RT_DIR})

# **************************************************************************
cmake_minimum_required(VERSION 3.0)
# Component name.
set(PROJECT "sendkeys") # The name of the file excluding .c or .h
set(RT_CORE "linuxcnchal") # Link to halcore or for Lcnc use linuxcnchal
project(${PROJECT} C CXX ASM) # Asm is optional.

# Set variables.
set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
set(BUILD_DIR "${CMAKE_CURRENT_BINARY_DIR}")
set(RTAPI_DIR "${SRC_DIR}/rtapi")
set(HAL_DIR "${SRC_DIR}/hal")
set(NML_DIR "${SRC_DIR}/libnml")
set(COMPONENT_DIR "${SRC_DIR}/hal/components")
set(USER_COMPS_DIR "${SRC_DIR}/hal/user_comps")
set(PYTHON_DIR "/usr/include/python3.9")
set(MODBUS_DIR "/usr/include/modbus")
set(LIBUSB_DIR "/usr/include/libusb-1.0")

# Set includepaths for header files etc.
include_directories(${SRC_DIR})
include_directories(${RTAPI_DIR})
include_directories(${HAL_DIR})
include_directories(${LIB_DIR})
include_directories(${COMPONENT_DIR})
include_directories(${USER_COMPS_DIR})
include_directories(${PYTHON_DIR})
include_directories(${MODBUS_DIR})
include_directories(${LIBUSB_DIR})

# Compile flags.
SET(GCC_COVERAGE_COMPILE_FLAGS "
    -DUSPACE -fno-fast-math -fno-unsafe-math-optimizations -DULAPI -D_GNU_SOURCE \
    -Drealtime -D__MODULE__ -DSIM -fPIC -Os pthread rt")
add_definitions(-DULAPI -DUSPACE -D_GNU_SOURCE -D__MODULE__ )

# No "lib" before filename.
set(CMAKE_SHARED_LIBRARY_PREFIX "")

ADD_LIBRARY(${PROJECT} SHARED
    ${USER_COMPS_DIR}/sendkeys.c
    )

# Link to other libraries
target_include_directories(${PROJECT_NAME} PRIVATE "${BUILD_DIR}/${RT_CORE}")
target_link_libraries(${PROJECT_NAME} PRIVATE pthread rt ${RT_CORE})

# make install
# install(TARGETS ${PROJECT} DESTINATION ${RT_DIR})

# **************************************************************************
cmake_minimum_required(VERSION 3.0)
# Component name.
set(PROJECT "vfs11_vfd") # The name of the file excluding .c or .h
set(RT_CORE "linuxcnchal") # Link to halcore or for Lcnc use linuxcnchal
project(${PROJECT} C CXX ASM) # Asm is optional.

# Set variables.
set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
set(BUILD_DIR "${CMAKE_CURRENT_BINARY_DIR}")
set(RTAPI_DIR "${SRC_DIR}/rtapi")
set(HAL_DIR "${SRC_DIR}/hal")
set(NML_DIR "${SRC_DIR}/libnml")
set(COMPONENT_DIR "${SRC_DIR}/hal/components")
set(USER_COMPS_DIR "${SRC_DIR}/hal/user_comps")
set(PYTHON_DIR "/usr/include/python3.9")
set(MODBUS_DIR "/usr/include/modbus")
set(LIBUSB_DIR "/usr/include/libusb-1.0")

# Set includepaths for header files etc.
include_directories(${SRC_DIR})
include_directories(${RTAPI_DIR})
include_directories(${HAL_DIR})
include_directories(${LIB_DIR})
include_directories(${COMPONENT_DIR})
include_directories(${USER_COMPS_DIR})
include_directories(${PYTHON_DIR})
include_directories(${MODBUS_DIR})
include_directories(${LIBUSB_DIR})

# Compile flags.
SET(GCC_COVERAGE_COMPILE_FLAGS "
    -DUSPACE -fno-fast-math -fno-unsafe-math-optimizations -DULAPI -D_GNU_SOURCE \
    -Drealtime -D__MODULE__ -DSIM -fPIC -Os pthread rt")
add_definitions(-DULAPI -DUSPACE -D_GNU_SOURCE -D__MODULE__ )

# No "lib" before filename.
set(CMAKE_SHARED_LIBRARY_PREFIX "")

ADD_LIBRARY(${PROJECT} SHARED
    ${USER_COMPS_DIR}/vfs11_vfd/vfs11_vfd.c
    )

# Link to other libraries
target_include_directories(${PROJECT_NAME} PRIVATE "${BUILD_DIR}/${RT_CORE}")
target_link_libraries(${PROJECT_NAME} PRIVATE pthread rt ${RT_CORE})

# make install
# install(TARGETS ${PROJECT} DESTINATION ${RT_DIR})

# **************************************************************************
cmake_minimum_required(VERSION 3.0)
# Project name.
set(PROJECT "linuxcnc") # The name of the file excluding .c or .h
project(${PROJECT} CXX C) # Asm is optional.

# Set variables.
set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
set(BUILD_DIR "${CMAKE_CURRENT_BINARY_DIR}")
set(RTAPI_DIR "${SRC_DIR}/rtapi")
set(HAL_DIR "${SRC_DIR}/hal")
set(NML_DIR "${SRC_DIR}/libnml")
set(TCL_DIR "/usr/include/tcl")
# Set includepaths.
include_directories(${SRC_DIR})
include_directories(${RTAPI_DIR})
include_directories(${HAL_DIR})
include_directories(${NML_DIR})
include_directories(${NML_DIR}/linklist)
include_directories(${NML_DIR}/os_intf)
include_directories(${NML_DIR}/rcs/)
include_directories(${NML_DIR}/cms/)
include_directories(${NML_DIR}/buffer/)
include_directories(${NML_DIR}/posemath/)
include_directories(${NML_DIR}/nml/)
include_directories(${NML_DIR}/inifile/)
include_directories(${SRC_DIR}/emc/usr_intf)
include_directories(${SRC_DIR}/emc/nml_intf)
include_directories(${SRC_DIR}/emc/motion)
include_directories(${SRC_DIR}/emc/rs274ngc)
include_directories(${SRC_DIR}/emc/tooldata)

include_directories(${TCL_DIR})

# Compile with cmake.
set(CMAKE_SHARED_LIBRARY_PREFIX "")
add_definitions(-DULAPI)

ADD_LIBRARY(${PROJECT} SHARED
    ${SRC_DIR}/emc/usr_intf/emcsh.cc
    ${SRC_DIR}/emc/usr_intf/shcom.cc
    ${SRC_DIR}/emc/nml_intf/emcglb.c
    ${SRC_DIR}/emc/rs274ngc/modal_state.cc
    ${SRC_DIR}/emc/nml_intf/emc.cc
    ${SRC_DIR}/emc/nml_intf/emcpose.c
    ${SRC_DIR}/emc/nml_intf/emcargs.cc
    ${SRC_DIR}/emc/nml_intf/emcops.cc
    ${SRC_DIR}/emc/nml_intf/canon_position.cc
    ${SRC_DIR}/emc/ini/emcIniFile.cc
    ${SRC_DIR}/emc/ini/iniaxis.cc
    ${SRC_DIR}/emc/ini/inijoint.cc
    ${SRC_DIR}/emc/ini/inispindle.cc
    ${SRC_DIR}/emc/ini/initraj.cc
    ${SRC_DIR}/emc/ini/inihal.cc
    ${SRC_DIR}/emc/nml_intf/interpl.cc
    )

# make install
# install(TARGETS ${PROJECT} DESTINATION ${RT_DIR})

# **************************************************************************
cmake_minimum_required(VERSION 3.0)
# Project name.
set(PROJECT "tooldata") # The name of the file excluding .c or .h
project(${PROJECT} CXX C) # Asm is optional.

# Set variables.
set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
set(BUILD_DIR "${CMAKE_CURRENT_BINARY_DIR}")
set(RTAPI_DIR "${SRC_DIR}/rtapi")
set(HAL_DIR "${SRC_DIR}/hal")
set(NML_DIR "${SRC_DIR}/libnml")
set(TCL_DIR "/usr/include/tcl")
# Set includepaths.
include_directories(${SRC_DIR})
include_directories(${RTAPI_DIR})
include_directories(${HAL_DIR})
include_directories(${NML_DIR})
include_directories(${NML_DIR}/linklist)
include_directories(${NML_DIR}/os_intf)
include_directories(${NML_DIR}/rcs/)
include_directories(${NML_DIR}/cms/)
include_directories(${NML_DIR}/buffer/)
include_directories(${NML_DIR}/posemath/)
include_directories(${NML_DIR}/nml/)
include_directories(${NML_DIR}/inifile/)
include_directories(${SRC_DIR}/emc/usr_intf)
include_directories(${SRC_DIR}/emc/nml_intf)
include_directories(${SRC_DIR}/emc/motion)
include_directories(${SRC_DIR}/emc/rs274ngc)
include_directories(${SRC_DIR}/emc/tooldata)

include_directories(${TCL_DIR})

# Compile with cmake.
set(CMAKE_SHARED_LIBRARY_PREFIX "")
add_definitions(-DULAPI)

ADD_LIBRARY(${PROJECT} SHARED
    ${SRC_DIR}/emc/usr_intf/halui.cc
    ${SRC_DIR}/emc/tooldata/tooldata_mmap.cc
    ${SRC_DIR}/emc/tooldata/tooldata_common.cc
    ${SRC_DIR}/emc/tooldata/tooldata_db.cc
    )

# make install
# install(TARGETS ${PROJECT} DESTINATION ${RT_DIR})



# **************************************************************************
cmake_minimum_required(VERSION 3.0)
# Project name.
set(PROJECT "canterp") # The name of the file excluding .c or .h
project(${PROJECT} CXX C) # Asm is optional.

# Set variables.
set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
set(BUILD_DIR "${CMAKE_CURRENT_BINARY_DIR}")
set(RTAPI_DIR "${SRC_DIR}/rtapi")
set(HAL_DIR "${SRC_DIR}/hal")
set(NML_DIR "${SRC_DIR}/libnml")
set(TCL_DIR "/usr/include/tcl")
# Set includepaths.
include_directories(${SRC_DIR})
include_directories(${RTAPI_DIR})
include_directories(${HAL_DIR})
include_directories(${NML_DIR})
include_directories(${NML_DIR}/linklist)
include_directories(${NML_DIR}/os_intf)
include_directories(${NML_DIR}/rcs/)
include_directories(${NML_DIR}/cms/)
include_directories(${NML_DIR}/buffer/)
include_directories(${NML_DIR}/posemath/)
include_directories(${NML_DIR}/nml/)
include_directories(${NML_DIR}/inifile/)
include_directories(${SRC_DIR}/emc/usr_intf)
include_directories(${SRC_DIR}/emc/nml_intf)
include_directories(${SRC_DIR}/emc/motion)
include_directories(${SRC_DIR}/emc/rs274ngc)
include_directories(${SRC_DIR}/emc/tooldata)
include_directories(${SRC_DIR}/emc/pythonplugin)
include_directories(${SRC_DIR}/emc/kinematics)
include_directories(${SRC_DIR}/emc/tp)
include_directories(${SRC_DIR}/emc/ini)
include_directories(${TCL_DIR})

# Compile with cmake.
set(CMAKE_SHARED_LIBRARY_PREFIX "")
add_definitions(-DULAPI)

ADD_LIBRARY(${PROJECT} SHARED
    ${SRC_DIR}/emc/kinematics/ugenserkins.c
    ${SRC_DIR}/emc/kinematics/genserfuncs.c
    ${SRC_DIR}/emc/canterp/canterp.cc
    )

# make install
# install(TARGETS ${PROJECT} DESTINATION ${RT_DIR})


# **************************************************************************
cmake_minimum_required(VERSION 3.0)
# Component name.
set(PROJECT "hal_lib") # The name of the file excluding .c or .h
project(${PROJECT} C ASM) # Asm is optional.

# Set variables.
set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
set(BUILD_DIR "${CMAKE_CURRENT_BINARY_DIR}")
set(RTAPI_DIR "${SRC_DIR}/rtapi")
set(HAL_DIR "${SRC_DIR}/hal")
set(NML_DIR "${SRC_DIR}/libnml")
set(TCL_DIR "/usr/include/tcl")
# Set includepaths.
include_directories(${SRC_DIR})
include_directories(${RTAPI_DIR})
include_directories(${HAL_DIR})
include_directories(${NML_DIR})
include_directories(${NML_DIR}/linklist)
include_directories(${NML_DIR}/os_intf)
include_directories(${NML_DIR}/rcs/)
include_directories(${NML_DIR}/cms/)
include_directories(${NML_DIR}/buffer/)
include_directories(${NML_DIR}/posemath/)
include_directories(${NML_DIR}/nml/)
include_directories(${NML_DIR}/inifile/)
include_directories(${SRC_DIR}/emc/usr_intf)
include_directories(${SRC_DIR}/emc/nml_intf)
include_directories(${SRC_DIR}/emc/motion)
include_directories(${SRC_DIR}/emc/rs274ngc)
include_directories(${SRC_DIR}/emc/tooldata)
include_directories(${SRC_DIR}/emc/pythonplugin)
include_directories(${SRC_DIR}/emc/kinematics)
include_directories(${SRC_DIR}/emc/tp)
include_directories(${SRC_DIR}/emc/ini)
include_directories(${TCL_DIR})

# Compile with cmake.
set(CMAKE_SHARED_LIBRARY_PREFIX "")
add_definitions(-DULAPI)
ADD_LIBRARY(${PROJECT} SHARED
    ${SRC_DIR}/hal/hal_lib.c
    )

# make install
install(TARGETS ${PROJECT} DESTINATION ${RT_DIR})

# **************************************************************************
cmake_minimum_required(VERSION 3.0)
# Component name.
set(PROJECT "halmeter") # The name of the file excluding .c or .h
set(RT_CORE "linuxcnchal") # Link to halcore or for Lcnc use linuxcnchal
project(${PROJECT} C CXX ASM) # Asm is optional.

# Set variables.
set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
set(BUILD_DIR "${CMAKE_CURRENT_BINARY_DIR}")
set(RTAPI_DIR "${SRC_DIR}/rtapi")
set(HAL_DIR "${SRC_DIR}/hal")
set(NML_DIR "${SRC_DIR}/libnml")
set(COMPONENT_DIR "${SRC_DIR}/hal/components")
set(PYTHON_DIR "/usr/include/python3.9")

# Set includepaths for header files etc.
include_directories(${SRC_DIR})
include_directories(${RTAPI_DIR})
include_directories(${HAL_DIR})
include_directories(${LIB_DIR})
include_directories(${COMPONENT_DIR})
include_directories(${PYTHON_DIR})
include_directories("/usr/include/gtk-2.0")
include_directories("/usr/include/cairo")
include_directories("/usr/include/pango-1.0")
include_directories("/usr/include/gio-unix-2.0")
include_directories("/usr/local/include/freetype2")
include_directories("/usr/local/include")
include_directories("/usr/include/gtk-3.0")
include_directories("/usr/include/at-spi2-atk/2.0")
include_directories("/usr/include/at-spi-2.0")
include_directories("/usr/include/dbus-1.0")
include_directories("/usr/lib/x86_64-linux-gnu/dbus-1.0/include")
include_directories("/usr/include/gio-unix-2.0")
include_directories("/usr/include/fribidi")
include_directories("/usr/include/harfbuzz")
include_directories("/usr/include/atk-1.0")
include_directories("/usr/include/pixman-1")
include_directories("/usr/include/uuid")
include_directories("/usr/include/libpng16")
include_directories("/usr/include/gdk-pixbuf-2.0")
include_directories("/usr/include/libmount")
include_directories("/usr/include/blkid")
include_directories("/usr/include/glib-2.0")
include_directories("/usr/lib/x86_64-linux-gnu/glib-2.0/include")
include_directories("/usr/lib/x86_64-linux-gnu/gtk-2.0/include")

# Compile flags.
SET(GCC_COVERAGE_COMPILE_FLAGS "")
#add_definitions(-DULAPI -DUSPACE -D_GNU_SOURCE -D__MODULE__ )

# No "lib" before filename.
set(CMAKE_SHARED_LIBRARY_PREFIX "")

add_executable(${PROJECT}
    ${SRC_DIR}/hal/utils/meter.c
    ${SRC_DIR}/hal/utils/miscgtk.c
    )

# Link to other libraries
target_include_directories(${PROJECT_NAME} PRIVATE "${BUILD_DIR}/${RT_CORE}")
target_link_libraries(${PROJECT_NAME} PRIVATE pthread rt ${RT_CORE} gtk-3 gdk-3 pangocairo-1.0
    pango-1.0 harfbuzz atk-1.0 cairo-gobject cairo gdk_pixbuf-2.0 gio-2.0 gobject-2.0 glib-2.0
    )

# **************************************************************************
cmake_minimum_required(VERSION 3.0)
# Component name.
set(PROJECT "rs274") # The name of the file excluding .c or .h
set(RT_CORE "linuxcnchal") # Link to halcore or for Lcnc use linuxcnchal
project(${PROJECT} C CXX ASM) # Asm is optional.

# Set variables.
set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
set(BUILD_DIR "${CMAKE_CURRENT_BINARY_DIR}")
set(RTAPI_DIR "${SRC_DIR}/rtapi")
set(HAL_DIR "${SRC_DIR}/hal")
set(NML_DIR "${SRC_DIR}/libnml")
set(EMC_DIR "${SRC_DIR}/emc")
set(EMC_RS274_DIR "${SRC_DIR}/emc/rs274ngc")
set(COMPONENT_DIR "${SRC_DIR}/hal/components")

# Set includepaths for header files etc.
include_directories(${SRC_DIR})
include_directories(${RTAPI_DIR})
include_directories(${HAL_DIR})
include_directories(${LIB_DIR})
include_directories(${EMC_DIR})
include_directories(${EMC_RS274_DIR})
include_directories(${COMPONENT_DIR})

# Compile flags.
SET(GCC_COVERAGE_COMPILE_FLAGS "
    -DUSPACE -fno-fast-math -fno-unsafe-math-optimizations -DULAPI -D_GNU_SOURCE \
    -Drealtime -D__MODULE__ -DSIM -fPIC -Os pthread rt")
add_definitions(-DULAPI -DUSPACE -D_GNU_SOURCE -D__MODULE__ )

# No "lib" before filename.
# set(CMAKE_SHARED_LIBRARY_PREFIX "")

ADD_LIBRARY(${PROJECT} SHARED
    ${EMC_RS274_DIR}/interp_arc.cc
    ${EMC_RS274_DIR}/interp_array.cc
    ${EMC_RS274_DIR}/interp_base.cc
    ${EMC_RS274_DIR}/interp_check.cc
    ${EMC_RS274_DIR}/interp_convert.cc
    ${EMC_RS274_DIR}/interp_queue.cc
    ${EMC_RS274_DIR}/interp_cycles.cc
    ${EMC_RS274_DIR}/interp_execute.cc
    ${EMC_RS274_DIR}/interp_find.cc
    ${EMC_RS274_DIR}/interp_internal.cc
    ${EMC_RS274_DIR}/interp_inverse.cc
    ${EMC_RS274_DIR}/interp_read.cc
    ${EMC_RS274_DIR}/interp_write.cc
    ${EMC_RS274_DIR}/interp_o_word.cc
    ${EMC_RS274_DIR}/interp_g7x.cc
    ${EMC_RS274_DIR}/modal_state.cc
    ${EMC_RS274_DIR}/nurbs_additional_functions.cc
    ${EMC_RS274_DIR}/interp_namedparams.cc
    ${EMC_RS274_DIR}/interp_python.cc
    ${EMC_RS274_DIR}/interp_remap.cc
    ${EMC_RS274_DIR}/interp_setup.cc
    ${EMC_RS274_DIR}/canonmodule.cc
    ${EMC_RS274_DIR}/pyparamclass.cc
    ${EMC_RS274_DIR}/pyemctypes.cc
    ${EMC_RS274_DIR}/pyinterp1.cc
    ${EMC_RS274_DIR}/pyblock.cc
    ${EMC_RS274_DIR}/pyarrays.cc
    ${EMC_RS274_DIR}/interpmodule.cc
    ${EMC_RS274_DIR}/rs274ngc_pre.cc
    ${EMC_RS274_DIR}/interp_inspection.cc
    )

# Link to other libraries
target_include_directories(${PROJECT_NAME} PRIVATE "${BUILD_DIR}/${RT_CORE}")
target_link_libraries(${PROJECT_NAME} PRIVATE pthread rt -fPIC ${RT_CORE})

# make install
# install(TARGETS ${PROJECT} DESTINATION ${RT_DIR})

# **************************************************************************
cmake_minimum_required(VERSION 3.0)
# Component name.
set(PROJECT "gcode") # The name of the file excluding .c or .h
set(RT_CORE "linuxcnchal") # Link to halcore or for Lcnc use linuxcnchal
project(${PROJECT} C CXX ASM) # Asm is optional.

# Set variables.
set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
set(BUILD_DIR "${CMAKE_CURRENT_BINARY_DIR}")
set(RTAPI_DIR "${SRC_DIR}/rtapi")
set(HAL_DIR "${SRC_DIR}/hal")
set(NML_DIR "${SRC_DIR}/libnml")
set(EMC_DIR "${SRC_DIR}/emc")
set(EMC_RS274_DIR "${SRC_DIR}/emc/rs274ngc")
set(COMPONENT_DIR "${SRC_DIR}/hal/components")

# Set includepaths for header files etc.
include_directories(${SRC_DIR})
include_directories(${RTAPI_DIR})
include_directories(${HAL_DIR})
include_directories(${LIB_DIR})
include_directories(${EMC_DIR})
include_directories(${EMC_RS274_DIR})
include_directories(${COMPONENT_DIR})

# Compile flags.
SET(GCC_COVERAGE_COMPILE_FLAGS "
    -DUSPACE -fno-fast-math -fno-unsafe-math-optimizations -DULAPI -D_GNU_SOURCE \
    -Drealtime -D__MODULE__ -DSIM -fPIC -Os pthread rt")
add_definitions(-DULAPI -DUSPACE -D_GNU_SOURCE -D__MODULE__ )

# No "lib" before filename.
set(CMAKE_SHARED_LIBRARY_PREFIX "")

ADD_LIBRARY(${PROJECT} SHARED
    ${EMC_RS274_DIR}/gcodemodule.cc

    )

# Link to other libraries
target_include_directories(${PROJECT_NAME} PRIVATE "${BUILD_DIR}/${RT_CORE}")
target_link_libraries(${PROJECT_NAME} PRIVATE pthread rt -fPIC ${RT_CORE} rs274)

# make install
# install(TARGETS ${PROJECT} DESTINATION ${RT_DIR})




