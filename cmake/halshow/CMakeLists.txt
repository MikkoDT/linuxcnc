cmake_minimum_required(VERSION 3.0)
set(PROJECT "hal") # halshow ~/linuxcnc/src/hal/utils/
project(${PROJECT} VERSION 0 LANGUAGES CXX)

# Set variables.
set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
set(BUILD_DIR "${CMAKE_CURRENT_BINARY_DIR}")

# Set includepaths.
include_directories(${SRC_DIR})
include_directories(${SRC_DIR}/../common_src)
include_directories(${SRC_DIR}/../rtapi_src)
include_directories(${SRC_DIR}/../halshow_src)
include_directories(${SRC_DIR}/../halcmd_src)

# tcl tk cflags, includes and libs
#[[
    TCL_DBGX=
    TK_DBGX=
    TCL_CFLAGS=-I/usr/include/tcl8.6 -DUSE_TCL_STUBS -I/usr/include/tcl8.6
    TCL_LIBS=-L/usr/lib/x86_64-linux-gnu -ltclstub8.6 -lX11 -lXss -lXext -lXft
    -lfontconfig -lfreetype -lfontconfig  -lpthread -ldl -lz  -lpthread -lm -ltk8.6  -lXinerama
    -L/usr/lib/x86_64-linux-gnu
]]
include_directories(/usr/include/tcl8.6)
include_directories(/usr/lib/x86_64-linux-gnu)

# Set prefix.
set(CMAKE_SHARED_LIBRARY_PREFIX "")

ADD_LIBRARY(${PROJECT} SHARED 
    ${SRC_DIR}/../halshow_src/halsh.c
)

add_definitions(-DULAPI -DUSE_TCL_STUBS )

# Set include paths for libraries to link.
target_include_directories(${PROJECT_NAME} PRIVATE ${BUILD_DIR})

# Add verion nr. .so.0.0.0
set_target_properties(${PROJECT_NAME} PROPERTIES VERSION ${PROJECT_VERSION})

# Link to libraries.
add_library(linuxcncini SHARED IMPORTED) # or STATIC instead of SHARED
set_target_properties(linuxcncini PROPERTIES
  IMPORTED_LOCATION "${SRC_DIR}/../build/liblinuxcncini/liblinuxcncini.so"
  INTERFACE_INCLUDE_DIRECTORIES "${SRC_DIR}/../liblinuxcncini_src"
)

add_library(linuxcnchal SHARED IMPORTED) # or STATIC instead of SHARED
set_target_properties(linuxcnchal PROPERTIES
  IMPORTED_LOCATION "${SRC_DIR}/../build/liblinuxcnchal/liblinuxcnchal.so"
  INTERFACE_INCLUDE_DIRECTORIES "${SRC_DIR}/../liblinuxcnchal_src"
)

target_link_libraries(${PROJECT_NAME} linuxcnchal linuxcncini
    -lX11 -lXss -lXext -lXft
    -lfontconfig -lfreetype -lfontconfig
    -lpthread -ldl -lz  -lpthread -lm -ltk8.6 -lXinerama
)

# Set custom output name :
# set_property(TARGET  ${PROJECT} PROPERTY OUTPUT_NAME thename)

# Make install
install(TARGETS ${PROJECT} DESTINATION ${SRC_DIR})

# Notes.






















