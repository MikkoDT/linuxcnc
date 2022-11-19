cmake_minimum_required(VERSION 3.0)
set(PROJECT "hal_tlc") # ~/linuxcnc/src/hal/utils/
project(${PROJECT} LANGUAGES CXX)

# Set variables.
set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
set(BUILD_DIR "${CMAKE_CURRENT_BINARY_DIR}")

# Set includepaths.
include_directories(${SRC_DIR}/../common_src)
include_directories(${SRC_DIR}/../rtapi_src)
include_directories(${SRC_DIR}/../liblinuxcnchal_src)
include_directories(${SRC_DIR}/../liblinuxcncini_src)
include_directories(${SRC_DIR}/../halcmd_src)
include_directories(/usr/include/tcl8.6)

# Set prefix.
set(CMAKE_SHARED_LIBRARY_PREFIX "")

ADD_LIBRARY(${PROJECT} SHARED
    ${SRC_DIR}/../hal_tlc_src/halsh.c
    )

add_definitions(-DULAPI)

# Set include paths for libraries to link.
add_library(linuxcncini_ SHARED IMPORTED) # or STATIC instead of SHARED
set_target_properties(linuxcncini_ PROPERTIES
    IMPORTED_LOCATION "${SRC_DIR}/../build/liblinuxcncini/liblinuxcncini.so"
    INTERFACE_INCLUDE_DIRECTORIES "${SRC_DIR}/../liblinuxcncini_src"
    )

add_library(linuxcnchal_ SHARED IMPORTED) # or STATIC instead of SHARED
set_target_properties(linuxcnchal_ PROPERTIES
    IMPORTED_LOCATION "${SRC_DIR}/../build/liblinuxcnchal/liblinuxcnchal.so"
    INTERFACE_INCLUDE_DIRECTORIES "${SRC_DIR}/../liblinuxcnchal_src"
    )

# Link to libraries.
target_link_libraries(${PROJECT_NAME} PRIVATE
    linuxcncini_
    linuxcnchal_
    -ltcl8.6 -ltk8.6
    )

# Set custom output name :
set_property(TARGET  ${PROJECT} PROPERTY OUTPUT_NAME linuxcnc)

# Make install
install(TARGETS ${PROJECT} DESTINATION ${SRC_DIR})
