cmake_minimum_required(VERSION 3.0)
set(PROJECT "linuxcnc_tlc")
project(${PROJECT} LANGUAGES CXX)

# Set variables.
set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
set(BUILD_DIR "${CMAKE_CURRENT_BINARY_DIR}")

# Set includepaths.
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
include_directories(/usr/include/tcl8.6)
include_directories(/usr/lib/x86_64-linux-gnu)

# Set prefix.
set(CMAKE_SHARED_LIBRARY_PREFIX "")

ADD_LIBRARY(${PROJECT} SHARED
    ${SRC_DIR}/../emc_src/emcsh.cc
    ${SRC_DIR}/../emc_src/shcom.cc
    )

add_definitions(-DULAPI)

# Set include paths for libraries to link.
add_library(linuxcnc_ STATIC IMPORTED) # or STATIC instead of SHARED
set_target_properties(linuxcnc_ PROPERTIES
    IMPORTED_LOCATION "${SRC_DIR}/../build/liblinuxcnc/liblinuxcnc.a"
    INTERFACE_INCLUDE_DIRECTORIES "${SRC_DIR}/../liblinuxcnc_src"
    )

add_library(nml SHARED IMPORTED) # or STATIC instead of SHARED
set_target_properties(nml PROPERTIES
    IMPORTED_LOCATION "${SRC_DIR}/../build/libnml/libnml.so"
    INTERFACE_INCLUDE_DIRECTORIES "${SRC_DIR}/../libnml_src"
    )


add_library(linuxcncini_ SHARED IMPORTED) # or STATIC instead of SHARED
set_target_properties(linuxcncini_ PROPERTIES
    IMPORTED_LOCATION "${SRC_DIR}/../build/liblinuxcncini/liblinuxcncini.so"
    INTERFACE_INCLUDE_DIRECTORIES "${SRC_DIR}/../liblinuxcncini_src"
    )

# Link to libraries.
target_link_libraries(${PROJECT_NAME} PRIVATE
    linuxcncini_
    linuxcnc_
    nml
    -ltclstub8.6  -lX11 -lXss -lXext -lXft -lfontconfig -lfreetype -lfontconfig  -lpthread -ldl -lz  -lpthread -lm  -lXinerama
    -ltcl8.6 -ltk8.6
    )

# Set custom output name :
set_property(TARGET  ${PROJECT} PROPERTY OUTPUT_NAME linuxcnc)

# Make install
install(TARGETS ${PROJECT} DESTINATION ${SRC_DIR})
