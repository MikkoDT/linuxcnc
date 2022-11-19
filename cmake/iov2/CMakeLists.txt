cmake_minimum_required(VERSION 3.0)
set(PROJECT "iov2")
project(${PROJECT} CXX C) 

# Set variables.
set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
set(BUILD_DIR "${CMAKE_CURRENT_BINARY_DIR}")

# Set includepaths.
include_directories(${SRC_DIR})
include_directories(${SRC_DIR}/../rtapi_src)
include_directories(${SRC_DIR}/../liblinuxcnchal_src)
include_directories(${SRC_DIR}/../liblinuxcncini_src)
include_directories(${SRC_DIR}/../libtooldata_src)
include_directories(${SRC_DIR}/../libnml_src)
include_directories(${SRC_DIR}/../emc_src)
include_directories(${SRC_DIR}/../common_src)

# Set prefix.
# set(CMAKE_SHARED_LIBRARY_PREFIX "")

set(SOURCES
    ${SRC_DIR}/../iov2_src/ioControl_v2.cc
)
add_executable(${PROJECT_NAME} ${SOURCES})

add_definitions(-DULAPI)

# Set include paths for libraries to link.
add_library(nml SHARED IMPORTED) # or STATIC instead of SHARED
set_target_properties(nml PROPERTIES
  IMPORTED_LOCATION "${SRC_DIR}/../build/libnml/libnml.so"
  INTERFACE_INCLUDE_DIRECTORIES "${SRC_DIR}/../libnml_src"
)

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
  # IMPORTED_LOCATION "/home/user/lcncladdertest/lib/libtooldata.so"
  IMPORTED_LOCATION "${SRC_DIR}/../build/libtooldata/libtooldata.so"
  INTERFACE_INCLUDE_DIRECTORIES "${SRC_DIR}/../libtooldata_src"
)

add_library(linuxcnc_a STATIC IMPORTED) # or STATIC instead of SHARED
set_target_properties(linuxcnc_a PROPERTIES
  # IMPORTED_LOCATION "/home/user/lcncladdertest/lib/liblinuxcnc.a"
  IMPORTED_LOCATION "${SRC_DIR}/../build/liblinuxcnc/liblinuxcnc.a"
  INTERFACE_INCLUDE_DIRECTORIES "${SRC_DIR}/../liblinuxcnc_src"
)

# Link to libraries.
target_link_libraries(${PROJECT_NAME} PRIVATE linuxcnc_a nml linuxcnchal linuxcncini tooldata
)

# Set custom output name :
# set_property(TARGET  ${PROJECT} PROPERTY OUTPUT_NAME thename)

# Make install
install(TARGETS ${PROJECT} DESTINATION ${SRC_DIR})

# Notes.
