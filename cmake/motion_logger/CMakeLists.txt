cmake_minimum_required(VERSION 3.0)
set(PROJECT "motion-logger")
project(${PROJECT} LANGUAGES CXX)

# Set variables.
set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
set(BUILD_DIR "${CMAKE_CURRENT_BINARY_DIR}")

# Set includepaths.
include_directories(${SRC_DIR})
include_directories(${SRC_DIR}/../common_src)
include_directories(${SRC_DIR}/../rtapi_src)
include_directories(${SRC_DIR}/../liblinuxcnchal_src)
include_directories(${SRC_DIR}/../libnml_src)
include_directories(${SRC_DIR}/../emc_src)
include_directories(${SRC_DIR}/../motion_src)
# Set prefix.
# set(CMAKE_SHARED_LIBRARY_PREFIX "")

set(SOURCES
    ${SRC_DIR}/../motion_src/motion-logger.c
    ${SRC_DIR}/../emc_src/axis.c
    ${SRC_DIR}/../emc_src/simple_tp.c
    )
add_executable(${PROJECT_NAME} ${SOURCES})

add_definitions(-DULAPI)

# Set include paths for libraries to link.
add_library(linuxcnchal SHARED IMPORTED) # or STATIC instead of SHARED
set_target_properties(linuxcnchal PROPERTIES
    IMPORTED_LOCATION "${SRC_DIR}/../build/liblinuxcnchal/liblinuxcnchal.so"
    INTERFACE_INCLUDE_DIRECTORIES "${SRC_DIR}/../liblinuxcnchal_src"
    )

add_library(nml SHARED IMPORTED) # or STATIC instead of SHARED
set_target_properties(nml PROPERTIES
    IMPORTED_LOCATION "${SRC_DIR}/../build/libnml/libnml.so"
    INTERFACE_INCLUDE_DIRECTORIES "${SRC_DIR}/../libnml_src"
    )

# Link to libraries.
target_link_libraries(${PROJECT_NAME} PRIVATE nml linuxcnchal -lm) # -lm, m=math for sqrt.

# Set custom output name :
# set_property(TARGET  ${PROJECT} PROPERTY OUTPUT_NAME thename)

# Make install
install(TARGETS ${PROJECT} DESTINATION ${SRC_DIR})

# Notes.
