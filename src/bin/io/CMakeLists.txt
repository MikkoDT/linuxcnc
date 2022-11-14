# **************************************************************************
cmake_minimum_required(VERSION 3.0)
# Component name.
set(PROJECT "milltask") # The name of the file excluding .c or .h
project(${PROJECT} CXX C)

# Set variables.
set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
set(BUILD_DIR "${CMAKE_CURRENT_BINARY_DIR}")
set(EMC_DIR "${SRC_DIR}/../../emc")
set(BIN_DIR "${SRC_DIR}/../../bin")
set(HAL_DIR "${SRC_DIR}/../../hal")
set(LIB_NML_DIR "${SRC_DIR}/../../libnml")
set(CONFIG_DIR "${SRC_DIR}/../../")

include_directories(${SRC_DIR})
include_directories(${EMC_DIR})
include_directories(${BIN_DIR})
include_directories(${HAL_DIR})
include_directories(${LIB_NML_DIR})
include_directories(${CONFIG_DIR})

add_definitions(-DSIM -DULAPI -UULAPI -DRTAPI )
set(SOURCES
    ${SRC_DIR}/dummy.cpp
    )
add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} PRIVATE )

# make install
install(TARGETS ${PROJECT} DESTINATION ${BIN_DIR})

# Notes:
# g++ -std=gnu++17 -g -L/home/user/linuxcnc/lib -Wl,-rpath,/home/user/linuxcnc/lib   -Xlinker -export-dynamic -Wl,-O1 -Wl,-Bsymbolic-functions -Wl,-soname,librs274.so.0 -shared -o ../lib/librs274.so.0 objects/emc/rs274ngc/interp_arc.o objects/emc/rs274ngc/interp_array.o objects/emc/rs274ngc/interp_base.o objects/emc/rs274ngc/interp_check.o objects/emc/rs274ngc/interp_convert.o objects/emc/rs274ngc/interp_queue.o objects/emc/rs274ngc/interp_cycles.o objects/emc/rs274ngc/interp_execute.o objects/emc/rs274ngc/interp_find.o objects/emc/rs274ngc/interp_internal.o objects/emc/rs274ngc/interp_inverse.o objects/emc/rs274ngc/interp_read.o objects/emc/rs274ngc/interp_write.o objects/emc/rs274ngc/interp_o_word.o objects/emc/rs274ngc/interp_g7x.o objects/emc/rs274ngc/modal_state.o objects/emc/rs274ngc/nurbs_additional_functions.o objects/emc/rs274ngc/interp_namedparams.o objects/emc/rs274ngc/interp_python.o objects/emc/rs274ngc/interp_remap.o objects/emc/rs274ngc/interp_setup.o objects/emc/rs274ngc/canonmodule.o objects/emc/rs274ngc/pyparamclass.o objects/emc/rs274ngc/pyemctypes.o objects/emc/rs274ngc/pyinterp1.o objects/emc/rs274ngc/pyblock.o objects/emc/rs274ngc/pyarrays.o objects/emc/rs274ngc/interpmodule.o objects/emc/rs274ngc/rs274ngc_pre.o objects/emc/rs274ngc/interp_inspection.o ../lib/liblinuxcncini.so ../lib/libpyplugin.so ../lib/liblinuxcnchal.so.0 ../lib/libtooldata.so.0 -lstdc++ -lboost_python39 -L/usr/lib -lpython3.9 -lcrypt -lpthread -ldl  -lutil -lm -lm
# Linking milltask
