cmake_minimum_required(VERSION 3.0)
set(PROJECT "linuxcnc")
project(${PROJECT} LANGUAGES CXX)

# Set variables.
set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
set(BUILD_DIR "${CMAKE_CURRENT_BINARY_DIR}")

# Set includepaths.
# include_directories(${SRC_DIR})

include_directories(${SRC_DIR}/../../../include)
include_directories(${SRC_DIR}/../../)

include_directories(/usr/include/tcl8.6)
include_directories(/usr/lib/x86_64-linux-gnu)
#[[ tcl tk cflags, includes and libs
TCL_DBGX=
TK_DBGX=
TCL_CFLAGS=-I/usr/include/tcl8.6 -DUSE_TCL_STUBS -I/usr/include/tcl8.6
TCL_LIBS=-L/usr/lib/x86_64-linux-gnu -ltclstub-lX11 -lXss -lXext -lXft -lfontconfig -lfreetype -lfontconfig
-lpthread -ldl -lz  -lpthread -lm -L/usr/lib/x86_64-linux-gnu -ltk8.6  -lXinerama8.6

]]

# Set prefix.
set(CMAKE_SHARED_LIBRARY_PREFIX "")

ADD_LIBRARY(${PROJECT} SHARED
    ${SRC_DIR}/emcsh.cc
    ${SRC_DIR}/shcom.cc
    )

add_definitions(-DULAPI -DUSE_TCL_STUBS -DULAPI -D_GNU_SOURCE -Os -DLOCALE_DIR=\"/usr/share/locale\" -DPACKAGE=\"linuxcnc\")

# Set include paths for libraries to link.

add_library(linuxcnc_ STATIC IMPORTED) # or STATIC instead of SHARED
set_target_properties(linuxcnc_ PROPERTIES
     IMPORTED_LOCATION "/home/user/lcnc/lib/liblinuxcnc.a"
    INTERFACE_INCLUDE_DIRECTORIES "${SRC_DIR}/../../../include"
    )

add_library(nml SHARED IMPORTED) # or STATIC instead of SHARED
set_target_properties(nml PROPERTIES  
    IMPORTED_LOCATION "/home/user/lcnc/lib/libnml.so"
    INTERFACE_INCLUDE_DIRECTORIES "${SRC_DIR}/../../../include"
    )


add_library(linuxcncini_ SHARED IMPORTED) # or STATIC instead of SHARED
set_target_properties(linuxcncini_ PROPERTIES
    IMPORTED_LOCATION "/home/user/lcnc/lib/liblinuxcncini.so"
    INTERFACE_INCLUDE_DIRECTORIES "${SRC_DIR}/../../../include"
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
#set_property(TARGET  ${PROJECT} PROPERTY OUTPUT_NAME linuxcnc)

# Make install
install(TARGETS ${PROJECT} DESTINATION ${SRC_DIR})

# Notes.
#[[
Linking liblinuxcnc.a
Linking linuxcnc.so
g++ -std=gnu++17 -shared -L/home/user/linuxcnc/lib -Wl,-rpath,/home/user/linuxcnc/lib   -o ../tcl/linuxcnc.so -Wall -g -I.
-I/home/user/linuxcnc/src/include -DULAPI -D_GNU_SOURCE -Os
-DLOCALE_DIR=\"/usr/share/locale\" -DPACKAGE=\"linuxcnc\" -I/usr/include/tcl8.6 -DUSE_TCL_STUBS -I/usr/include/tcl8.6
objects/emc/usr_intf/emcsh.o objects/emc/usr_intf/shcom.o ../lib/liblinuxcnc.a ../lib/liblinuxcncini.so.0 ../lib/libnml.so.0
-L/usr/lib/x86_64-linux-gnu -ltclstub8.6 -lX11 -lXss -lXext -lXft -lfontconfig -lfreetype -lfontconfig  -lpthread -ldl -lz
-lpthread -lm -L/usr/lib/x86_64-linux-gnu -ltk8.6  -lXinerama  -lXinerama
Compiling emc/usr_intf/emcrsh.cc
g++ -std=gnu++17 -c -I. -Ilibnml/linklist -Iemc -Ilibnml/cms -Ilibnml/rcs -Ilibnml/inifile -Ilibnml/os_intf -Ilibnml/nml
-Ilibnml/buffer -Ilibnml/posemath -Irtapi -Ihal -Iemc -Iemc/nml_intf -Iemc/kinematics -Iemc/tp -Iemc/motion -Iemc/ini -Iemc
-Iemc/rs274ngc -Iemc/sai -Iemc/pythonplugin -Iemc/tooldata -Iemc -I/home/user/linuxcnc/src/include -I/usr/include/python3.9
-DULAPI  -g -Wall -Wno-stringop-truncation -D_FORTIFY_SOURCE=2 -Os -fwrapv -Werror=overloaded-virtual -g -O2  -std=gnu++17  \
]]
