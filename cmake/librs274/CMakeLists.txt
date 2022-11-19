cmake_minimum_required(VERSION 3.0)
set(PROJECT "librs274")
project(${PROJECT} VERSION 0 LANGUAGES CXX C)

# Set variables.
set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
set(BUILD_DIR "${CMAKE_CURRENT_BINARY_DIR}")

# Set includepaths.
include_directories(${SRC_DIR})
include_directories(${SRC_DIR}/../common_src)
include_directories(${SRC_DIR}/../rtapi_src)
include_directories(${SRC_DIR}/../liblinuxcnchal_src)
include_directories(${SRC_DIR}/../liblinuxcncini_src)
include_directories(${SRC_DIR}/../libtooldata_src)
include_directories(${SRC_DIR}/../libpylugin_src)
include_directories(${SRC_DIR}/../emc_src)
include_directories(${SRC_DIR}/../libnml_src)
include_directories(${SRC_DIR}/../librs274_src)
include_directories(/usr/include/python3.9)

# Set prefix.
set(CMAKE_SHARED_LIBRARY_PREFIX "")

ADD_LIBRARY(${PROJECT} SHARED
    ${SRC_DIR}/../librs274_src/interp_arc.cc
    ${SRC_DIR}/../librs274_src/interp_array.cc
    ${SRC_DIR}/../librs274_src/interp_base.cc
    ${SRC_DIR}/../librs274_src/interp_check.cc
    ${SRC_DIR}/../librs274_src/interp_convert.cc
    ${SRC_DIR}/../librs274_src/interp_queue.cc
    ${SRC_DIR}/../librs274_src/interp_cycles.cc
    ${SRC_DIR}/../librs274_src/interp_execute.cc
    ${SRC_DIR}/../librs274_src/interp_find.cc
    ${SRC_DIR}/../librs274_src/interp_internal.cc
    ${SRC_DIR}/../librs274_src/interp_inverse.cc
    ${SRC_DIR}/../librs274_src/interp_read.cc
    ${SRC_DIR}/../librs274_src/interp_write.cc
    ${SRC_DIR}/../librs274_src/interp_o_word.cc
    ${SRC_DIR}/../librs274_src/interp_g7x.cc
    ${SRC_DIR}/../librs274_src/modal_state.cc
    ${SRC_DIR}/../librs274_src/nurbs_additional_functions.cc
    ${SRC_DIR}/../librs274_src/interp_namedparams.cc
    ${SRC_DIR}/../librs274_src/interp_python.cc
    ${SRC_DIR}/../librs274_src/interp_remap.cc
    ${SRC_DIR}/../librs274_src/interp_setup.cc
    ${SRC_DIR}/../librs274_src/canonmodule.cc
    ${SRC_DIR}/../librs274_src/pyparamclass.cc
    ${SRC_DIR}/../librs274_src/pyemctypes.cc
    ${SRC_DIR}/../librs274_src/pyinterp1.cc
    ${SRC_DIR}/../librs274_src/pyblock.cc
    ${SRC_DIR}/../librs274_src/pyarrays.cc
    ${SRC_DIR}/../librs274_src/interpmodule.cc
    ${SRC_DIR}/../librs274_src/rs274ngc_pre.cc
    ${SRC_DIR}/../librs274_src/interp_inspection.cc
    )

add_definitions(-DULAPI)

# Set include paths for libraries to link.
add_library(linuxcnchal SHARED IMPORTED) # or STATIC instead of SHARED
set_target_properties(linuxcnchal PROPERTIES
    IMPORTED_LOCATION "${SRC_DIR}/../build/liblinuxcnchal/liblinuxcnchal.so"
    INTERFACE_INCLUDE_DIRECTORIES "${SRC_DIR}/../liblinuxcnchal_src"
    )

add_library(linuxcncini SHARED IMPORTED) # or STATIC instead of SHARED
set_target_properties(linuxcncini PROPERTIES
    IMPORTED_LOCATION "${SRC_DIR}/../build/liblinuxcncini/liblinuxcncini.so"
    INTERFACE_INCLUDE_DIRECTORIES "${SRC_DIR}/../liblinuxcncini_src"
    )

add_library(tooldata SHARED IMPORTED) # or STATIC instead of SHARED
set_target_properties(tooldata PROPERTIES
    IMPORTED_LOCATION "${SRC_DIR}/../build/libtooldata/libtooldata.so"
    INTERFACE_INCLUDE_DIRECTORIES "${SRC_DIR}/../libtooldata_src"
    )

add_library(pyplugin SHARED IMPORTED) # or STATIC instead of SHARED
set_target_properties(pyplugin PROPERTIES
    IMPORTED_LOCATION "${SRC_DIR}/../build/libpyplugin/libpyplugin.so"
    INTERFACE_INCLUDE_DIRECTORIES "${SRC_DIR}/../../include" # Todo: figur out the excact includes for this one.
    )

# Link to libraries.
target_link_libraries(${PROJECT_NAME} PRIVATE  linuxcncini pyplugin linuxcnchal tooldata
    -lpython3.9
    )

# Add verion nr. .so.0.0.0
set_target_properties(${PROJECT_NAME} PROPERTIES VERSION ${PROJECT_VERSION})

# Set custom output name :
# set_property(TARGET  ${PROJECT} PROPERTY OUTPUT_NAME thename)

# Make install
install(TARGETS ${PROJECT} DESTINATION ${BUILD_DIR}/../../../lib)

# Notes.









