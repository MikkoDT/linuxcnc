cmake_minimum_required(VERSION 3.0)
set(PROJECT "sc_tp")
set(CMAKE_CXX_STANDARD 20) # Needed by ruckig.
project(${PROJECT} CXX C) 

# Set variables.
set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
set(BUILD_DIR "${CMAKE_CURRENT_BINARY_DIR}")
set(RTLINK "liblinuxcnchal")

# Set includepaths.
include_directories(${SRC_DIR})
include_directories(${SRC_DIR}/../../rtapi_src)
include_directories(${SRC_DIR}/../../liblinuxcnchal_src)
include_directories(${SRC_DIR}/../../libposemath_src)
include_directories(${SRC_DIR}/../../emc_src)
include_directories(${SRC_DIR}/../components/tp_src)

# Set path to eigen3, for install $ sudo apt-get install libeigen3-dev
include_directories("/usr/include/eigen3/Eigen")

# Set prefix.
set(CMAKE_SHARED_LIBRARY_PREFIX "")

# Set compile flags.
SET(GCC_COVERAGE_COMPILE_FLAGS "-I. -I${RTAPI_DIR} -I${HAL_DIR} \
    -DUSPACE -fno-fast-math -fno-unsafe-math-optimizations -DRTAPI -D_GNU_SOURCE
    -Drealtime -D__MODULE__ -DSIM -fPIC -Os")
add_definitions(-DRTAPI -DUSPACE -D_GNU_SOURCE -D__MODULE__ )

ADD_LIBRARY(${PROJECT} SHARED 
    ${SRC_DIR}/../../emc_src/tp.h
    ${SRC_DIR}/../../emc_src/motion.h
    ${SRC_DIR}/../sc_tp_src/sc_tp.c

    ${SRC_DIR}/../sc_tp_src/sc_struct.h
    ${SRC_DIR}/../sc_tp_src/sc_extern.h
    ${SRC_DIR}/../sc_tp_src/sc_struct.cpp
    ${SRC_DIR}/../sc_tp_src/sc_arcs.h
    ${SRC_DIR}/../sc_tp_src/sc_arcs.cpp
    ${SRC_DIR}/../sc_tp_src/sc_lines.h
    ${SRC_DIR}/../sc_tp_src/sc_lines.cpp
    ${SRC_DIR}/../sc_tp_src/sc_block.h
    ${SRC_DIR}/../sc_tp_src/sc_block.c
    ${SRC_DIR}/../sc_tp_src/sc_optimizer.h
    ${SRC_DIR}/../sc_tp_src/sc_optimizer.cpp
    ${SRC_DIR}/../sc_tp_src/sc_interpolate.h
    ${SRC_DIR}/../sc_tp_src/sc_interpolate.c
    ${SRC_DIR}/../sc_tp_src/sc_conversion.h
    ${SRC_DIR}/../sc_tp_src/sc_conversion.c

    ${SRC_DIR}/../sc_tp_src/ruckig/block.hpp
    ${SRC_DIR}/../sc_tp_src/ruckig/brake.hpp
    ${SRC_DIR}/../sc_tp_src/ruckig/brake.cpp
    ${SRC_DIR}/../sc_tp_src/ruckig/calculator.hpp
    ${SRC_DIR}/../sc_tp_src/ruckig/calculator_online.hpp
    ${SRC_DIR}/../sc_tp_src/ruckig/calculator_target.hpp
    ${SRC_DIR}/../sc_tp_src/ruckig/input_parameter.hpp
    ${SRC_DIR}/../sc_tp_src/ruckig/output_parameter.hpp
    ${SRC_DIR}/../sc_tp_src/ruckig/position.hpp
    ${SRC_DIR}/../sc_tp_src/ruckig/position-step1.cpp
    ${SRC_DIR}/../sc_tp_src/ruckig/position-step2.cpp
    ${SRC_DIR}/../sc_tp_src/ruckig/profile.hpp
    ${SRC_DIR}/../sc_tp_src/ruckig/reflexxes_comparison.hpp
    ${SRC_DIR}/../sc_tp_src/ruckig/roots.hpp
    ${SRC_DIR}/../sc_tp_src/ruckig/ruckig.hpp
    ${SRC_DIR}/../sc_tp_src/ruckig/trajectory.hpp
    ${SRC_DIR}/../sc_tp_src/ruckig/utils.hpp
    ${SRC_DIR}/../sc_tp_src/ruckig/velocity.hpp
    ${SRC_DIR}/../sc_tp_src/ruckig/velocity-step1.cpp
    ${SRC_DIR}/../sc_tp_src/ruckig/velocity-step2.cpp
    ${SRC_DIR}/../sc_tp_src/ruckig/sc_ruckig.h
    ${SRC_DIR}/../sc_tp_src/ruckig/sc_ruckig.cpp
    )

# Set include paths for libraries to link.
add_library(linuxcnchal SHARED IMPORTED) # or STATIC instead of SHARED
set_target_properties(linuxcnchal PROPERTIES
    IMPORTED_LOCATION "${SRC_DIR}/../../build/liblinuxcnchal/liblinuxcnchal.so"
    INTERFACE_INCLUDE_DIRECTORIES "${SRC_DIR}/../../liblinuxcnchal/"
    )

add_library(posemath SHARED IMPORTED) # or STATIC instead of SHARED
set_target_properties(posemath PROPERTIES
    IMPORTED_LOCATION "${SRC_DIR}/../../build/libposemath/libposemath.so"
    INTERFACE_INCLUDE_DIRECTORIES "${SRC_DIR}/../../libposemath/"
    )


# Link to libraries.
target_link_libraries(${PROJECT_NAME} PRIVATE linuxcnchal posemath)

# Set custom output name :
# set_property(TARGET  ${PROJECT} PROPERTY OUTPUT_NAME thename)

# Make install
install(TARGETS ${PROJECT} DESTINATION ${BUILD_DIR}/../../../../rtlib)

# Notes.
