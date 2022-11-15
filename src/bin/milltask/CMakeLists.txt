# **************************************************************************
cmake_minimum_required(VERSION 3.0)
# Component name. ~/linuxcnc/src/emc/task/
set(PROJECT "milltask") # The name of the file excluding .c or .h
project(${PROJECT} LANGUAGES CXX)

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
    ${EMC_DIR}/motion/emcmotglb.c
    ${EMC_DIR}/task/emctask.cc
    ${EMC_DIR}/task/emccanon.cc
    ${EMC_DIR}/task/emctaskmain.cc
    ${EMC_DIR}/motion/usrmotintf.cc
    ${EMC_DIR}/motion/emcmotutil.c
    ${EMC_DIR}/task/taskintf.cc
    ${EMC_DIR}/motion/dbuf.c
    ${EMC_DIR}/motion/stashf.c
    ${EMC_DIR}/task/taskmodule.cc
    ${EMC_DIR}/task/taskclass.cc
    ${EMC_DIR}/task/backtrace.cc
)
add_executable(${PROJECT_NAME} ${SOURCES})

# liblinuxcnchal.so
target_include_directories(${PROJECT_NAME} PRIVATE ${BUILD_DIR}/src/hal/linuxcnchal)
# liblinuxcncini.so
target_include_directories(${PROJECT_NAME} PRIVATE ${BUILD_DIR}/src/libnml/inifile)
# libnml.so
target_include_directories(${PROJECT_NAME} PRIVATE ${BUILD_DIR}/src/libnml)
# libposemath.so
target_include_directories(${PROJECT_NAME} PRIVATE ${BUILD_DIR}/src/libnml/posemath)
# libtooldata.so
target_include_directories(${PROJECT_NAME} PRIVATE ${BUILD_DIR}/src/emc/tooldata)
# libpyglugin.so
target_include_directories(${PROJECT_NAME} PRIVATE ${BUILD_DIR}/src/emc/pyplugin)
# librs274.so
target_include_directories(${PROJECT_NAME} PRIVATE ${BUILD_DIR}/src/emc/rs274ngc)
# liblinuxcnc.so - .a
target_include_directories(${PROJECT_NAME} PRIVATE ${BUILD_DIR}/src/emc/nml_intf)

# To link in future : liblinuxcnc.a

target_link_libraries(${PROJECT_NAME} PRIVATE  rs274 nml linuxcncini posemath linuxcnchal  pyplugin tooldata linuxcnc
    -Bsymbolic-functions -Xlinker -export-dynamic -lstdc++ -lboost_python39 -lpython3.9
    -lcrypt -lpthread -ldl -lutil -lm -std=gnu++17
)

# make install
install(TARGETS ${PROJECT} DESTINATION ${SRC_DIR}/../../../bin)

# Notes: No ULAPIE is defined in original make process.
#
# g++ -std=gnu++17 -g -L/home/user/linuxcnc/lib -Wl,-rpath,/home/user/linuxcnc/lib   -Xlinker -export-dynamic
# -Wl,-O1 -Wl,-Bsymbolic-functions -Wl,-soname,librs274.so.0 -shared -o
# ../lib/librs274.so.0 objects/emc/rs274ngc/interp_arc.o objects/emc/rs274ngc/interp_array.o
# objects/emc/rs274ngc/interp_base.o objects/emc/rs274ngc/interp_check.o objects/emc/rs274ngc/interp_convert.o
# objects/emc/rs274ngc/interp_queue.o objects/emc/rs274ngc/interp_cycles.o objects/emc/rs274ngc/interp_execute.o
# objects/emc/rs274ngc/interp_find.o objects/emc/rs274ngc/interp_internal.o objects/emc/rs274ngc/interp_inverse.o
# objects/emc/rs274ngc/interp_read.o objects/emc/rs274ngc/interp_write.o objects/emc/rs274ngc/interp_o_word.o
# objects/emc/rs274ngc/interp_g7x.o objects/emc/rs274ngc/modal_state.o objects/emc/rs274ngc/nurbs_additional_functions.o
# objects/emc/rs274ngc/interp_namedparams.o objects/emc/rs274ngc/interp_python.o objects/emc/rs274ngc/interp_remap.o
# objects/emc/rs274ngc/interp_setup.o objects/emc/rs274ngc/canonmodule.o objects/emc/rs274ngc/pyparamclass.o
# objects/emc/rs274ngc/pyemctypes.o objects/emc/rs274ngc/pyinterp1.o objects/emc/rs274ngc/pyblock.o objects/emc/rs274ngc/pyarrays.o 
# objects/emc/rs274ngc/interpmodule.o objects/emc/rs274ngc/rs274ngc_pre.o objects/emc/rs274ngc/interp_inspection.o
# ../lib/liblinuxcncini.so ../lib/libpyplugin.so ../lib/liblinuxcnchal.so.0 ../lib/libtooldata.so.0
# -lstdc++ -lboost_python39 -L/usr/lib -lpython3.9 -lcrypt -lpthread -ldl  -lutil -lm -lm
# Linking milltask










