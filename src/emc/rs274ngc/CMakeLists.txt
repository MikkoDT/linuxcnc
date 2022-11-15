cmake_minimum_required(VERSION 3.0)
# Project name.
set(PROJECT "rs274" ) # The name of the file excluding .c or .h
project(${PROJECT} VERSION 0 LANGUAGES CXX ) # Asm is optional.

# Set variables.
set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
set(BUILD_DIR "${CMAKE_CURRENT_BINARY_DIR}")
set(EMC_DIR "${SRC_DIR}/../")
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
include_directories(${EMC_DIR})
include_directories(${SRC_DIR}/../nml_intf)
include_directories(${SRC_DIR}/../../libnml/posemath)
include_directories(${SRC_DIR}/../../libnml/nml)
include_directories(${SRC_DIR}/../motion)
include_directories(${SRC_DIR}/../tooldata)
include_directories(${SRC_DIR}/../../libnml/rcs)
include_directories(${SRC_DIR}/../../libnml/cms)
include_directories(${SRC_DIR}/../../libnml/inifile)
include_directories(${SRC_DIR}/../pythonplugin)
include_directories(${SRC_DIR}/../../hal)

set(CMAKE_SHARED_LIBRARY_PREFIX "lib")
# add_definitions()

ADD_LIBRARY(${PROJECT} SHARED
    ${SRC_DIR}/interp_arc.cc
    ${SRC_DIR}/interp_array.cc
    ${SRC_DIR}/interp_base.cc
    ${SRC_DIR}/interp_check.cc
    ${SRC_DIR}/interp_convert.cc
    ${SRC_DIR}/interp_queue.cc
    ${SRC_DIR}/interp_cycles.cc
    ${SRC_DIR}/interp_execute.cc
    ${SRC_DIR}/interp_find.cc
    ${SRC_DIR}/interp_internal.cc
    ${SRC_DIR}/interp_inverse.cc
    ${SRC_DIR}/interp_read.cc
    ${SRC_DIR}/interp_write.cc
    ${SRC_DIR}/interp_o_word.cc
    ${SRC_DIR}/interp_g7x.cc
    ${SRC_DIR}/modal_state.cc
    ${SRC_DIR}/nurbs_additional_functions.cc
    ${SRC_DIR}/interp_namedparams.cc
    ${SRC_DIR}/interp_python.cc
    ${SRC_DIR}/interp_remap.cc
    ${SRC_DIR}/interp_setup.cc
    ${SRC_DIR}/canonmodule.cc
    ${SRC_DIR}/pyparamclass.cc
    ${SRC_DIR}/pyemctypes.cc
    ${SRC_DIR}/pyinterp1.cc
    ${SRC_DIR}/pyblock.cc
    ${SRC_DIR}/pyarrays.cc
    ${SRC_DIR}/interpmodule.cc
    ${SRC_DIR}/rs274ngc_pre.cc
    ${SRC_DIR}/interp_inspection.cc

    # ${SRC_DIR}/pyinterp1.cc
    # ${SRC_DIR}/pyparamclass.cc
    # ${SRC_DIR}/pyinterp1.cc
    # ${SRC_DIR}/pyblock.cc
    # ${SRC_DIR}/pyarrays.cc
    # ${SRC_DIR}/interpmodule.cc
    )

add_definitions(-DULAPI)
# liblinuxcnchal.so
target_include_directories(${PROJECT_NAME} PRIVATE ${BUILD_DIR}/src/hal/linuxcnchal)
# liblinuxcncini.so
target_include_directories(${PROJECT_NAME} PRIVATE ${BUILD_DIR}/src/libnml/inifile)
# libpyplugin.so
target_include_directories(${PROJECT_NAME} PRIVATE ${BUILD_DIR}/src/emc/pythonplugin)
# libtooldata.so
target_include_directories(${PROJECT_NAME} PRIVATE ${BUILD_DIR}/src/emc/tooldata)
# including the one did the job !
# hal_lib.so
target_include_directories(${PROJECT_NAME} PRIVATE ${BUILD_DIR}/src/hal/hal_lib)

# Link to :
target_link_libraries(${PROJECT_NAME} PRIVATE linuxcnchal linuxcncini pyplugin tooldata hal_lib
 -lstdc++ -lboost_python39 -L/usr/lib -lpython3.9 -lcrypt -lpthread -ldl  -lutil -lm -lm
    )

# Add verion nr. .so.0.0.0
set_target_properties(${PROJECT_NAME} PROPERTIES VERSION ${PROJECT_VERSION}
    )

# make install
install(TARGETS ${PROJECT} DESTINATION ${SRC_DIR})

# Notes from above also a libpyplugin.so is made.
# Has to be linked to multiple libs, see below.

# Linking librs274.so.0
# g++ -std=gnu++17 -g -L/home/user/linuxcnc/lib -Wl,-rpath,/home/user/linuxcnc/lib
# -Xlinker -export-dynamic -Wl,-O1 -Wl,-Bsymbolic-functions -Wl,-soname,librs274.so.0
# -shared -o ../lib/librs274.so.0 objects/emc/rs274ngc/interp_arc.o objects/emc/rs274ngc/interp_array.o
# objects/emc/rs274ngc/interp_base.o objects/emc/rs274ngc/interp_check.o
# objects/emc/rs274ngc/interp_convert.o objects/emc/rs274ngc/interp_queue.o
# objects/emc/rs274ngc/interp_cycles.o objects/emc/rs274ngc/interp_execute.o
# objects/emc/rs274ngc/interp_find.o objects/emc/rs274ngc/interp_internal.o
# objects/emc/rs274ngc/interp_inverse.o objects/emc/rs274ngc/interp_read.o
# objects/emc/rs274ngc/interp_write.o objects/emc/rs274ngc/interp_o_word.o
# objects/emc/rs274ngc/interp_g7x.o objects/emc/rs274ngc/modal_state.o
# objects/emc/rs274ngc/nurbs_additional_functions.o objects/emc/rs274ngc/interp_namedparams.o
# objects/emc/rs274ngc/interp_python.o objects/emc/rs274ngc/interp_remap.o
# objects/emc/rs274ngc/interp_setup.o objects/emc/rs274ngc/canonmodule.o
# objects/emc/rs274ngc/pyparamclass.o objects/emc/rs274ngc/pyemctypes.o
# objects/emc/rs274ngc/pyinterp1.o objects/emc/rs274ngc/pyblock.o objects/emc/rs274ngc/pyarrays.o
# objects/emc/rs274ngc/interpmodule.o objects/emc/rs274ngc/rs274ngc_pre.o
# objects/emc/rs274ngc/interp_inspection.o
# ../lib/liblinuxcncini.so ../lib/libpyplugin.so
# ../lib/liblinuxcnchal.so.0 ../lib/libtooldata.so.0 -lstdc++ -lboost_python39 -L/usr/lib -lpython3.9
# -lcrypt -lpthread -ldl  -lutil -lm -lm


























