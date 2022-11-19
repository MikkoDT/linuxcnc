cmake_minimum_required(VERSION 3.0)
set(PROJECT "linuxcncsrv")
project(${PROJECT} LANGUAGES CXX)

# Set variables.
set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
set(BUILD_DIR "${CMAKE_CURRENT_BINARY_DIR}")

# Set includepaths.
include_directories(${SRC_DIR})
include_directories(${SRC_DIR}/../common_src)
include_directories(${SRC_DIR}/../rtapi_src)
include_directories(${SRC_DIR}/../liblinuxcnchal_src)
include_directories(${SRC_DIR}/../liblinuxcncini_src)
include_directories(${SRC_DIR}/../libnml_src)
include_directories(${SRC_DIR}/../libtooldata_src)
include_directories(${SRC_DIR}/../libpyplugin_src)
include_directories(${SRC_DIR}/../liblinuxcnc_src)
include_directories(${SRC_DIR}/../librs274_src)
include_directories(${SRC_DIR}/../emc_src)
include_directories(/usr/include/python3.9)

# Set prefix.
set(CMAKE_SHARED_LIBRARY_PREFIX "")

set(SOURCES
    ${SRC_DIR}/../emc_src/emcsvr.cc
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

add_library(linuxcnc_a STATIC IMPORTED) # or STATIC instead of SHARED
set_target_properties(linuxcnc_a PROPERTIES
  # IMPORTED_LOCATION "/home/user/lcncladdertest/lib/liblinuxcnc.a"
  IMPORTED_LOCATION "${SRC_DIR}/../build/liblinuxcnc/liblinuxcnc.a"
  INTERFACE_INCLUDE_DIRECTORIES "${SRC_DIR}/../liblinuxcnc_src"
)

# Link to libraries.
target_link_libraries(${PROJECT_NAME} PRIVATE
    nml linuxcnchal linuxcncini linuxcnc_a
   # -lreadline
)

# Set custom output name :
# set_property(TARGET  ${PROJECT} PROPERTY OUTPUT_NAME thename)

# Make install
install(TARGETS ${PROJECT} DESTINATION ${SRC_DIR})

# Notes.
