cmake_minimum_required(VERSION 3.0)
# Project name.
set(PROJECT "togl" ) # The name of the file excluding .c or .h
project(${PROJECT} LANGUAGES CXX C ) # Asm is optional.

# Set variables.
set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
set(BUILD_DIR "${CMAKE_CURRENT_BINARY_DIR}")
set(EMC_DIR "${SRC_DIR}/../../")
set(BIN_DIR "${SRC_DIR}/../../../../../../bin")
set(HAL_DIR "${SRC_DIR}/../../../../../../hal")
set(NML_DIR "${SRC_DIR}/../../../../../../nml")
set(RTAPI_DIR "${SRC_DIR}/../../../../../../rtapi")
set(CONFIG_DIR "${SRC_DIR}/../../../../../")
set(LIB_DIR "${SRC_DIR}/../../../../../../../lib")
set(RT_DIR "${SRC_DIR}/../../../../../../../rtlib")
set(PYTHON_DIR "/usr/include/python3.9")

# Set includepaths.
include_directories(${SRC_DIR})
include_directories(${RTAPI_DIR})
include_directories(${PYTHON_DIR})
include_directories(${CONFIG_DIR})
include_directories(${EMC_DIR})
include_directories(${SRC_DIR}/../../../../../nml_intf)
include_directories(${SRC_DIR}/../../../../../../libnml/posemath)
include_directories(${SRC_DIR}/../../../../../../libnml/nml)
include_directories(${SRC_DIR}/../../../../../motion)
include_directories(${SRC_DIR}/../../../../../tooldata)
include_directories(${SRC_DIR}/../../../../../../libnml/rcs)
include_directories(${SRC_DIR}/../../../../../../libnml/cms)
include_directories(${SRC_DIR}/../../../../../../libnml/os_intf)
include_directories(${SRC_DIR}/../../../../../../libnml/inifile)
include_directories(${SRC_DIR}/../../../../../../hal)
include_directories(${SRC_DIR}/../../../../../../)
include_directories(${SRC_DIR}/../../../../../rs274ngc)
include_directories(${SRC_DIR}/../../../../../kinematics)
include_directories(/usr/X11R6/lib )
include_directories(/usr/include/tcl8.6)
include_directories(/usr/lib/x86_64-linux-gnu)

set(CMAKE_SHARED_LIBRARY_PREFIX "")
# add_definitions()

ADD_LIBRARY(${PROJECT} SHARED
	${SRC_DIR}/../../_toglmodule.c
)

# add_definitions(-DULAPI)

# Link to :
target_link_libraries(${PROJECT_NAME} PRIVATE -lX11 -lepoxy -lXmu -lX11 -lepoxy -lXmu -ltclstub8.6 -lXss -lXext -lXft
-lfontconfig -lfreetype -lpthread -ldl -lz  -lm -ltk8.6 
)

# make install
install(TARGETS ${PROJECT} DESTINATION ${LIB_DIR}/python)

# Notes.
# $(Q)$(CC) $(LDFLAGS) -shared -o $@ $(TCL_CFLAGS) $^ -L/usr/X11R6/lib -lX11 -lepoxy -lXmu $(TCL_LIBS)
# emc/usr_intf/axis/extensions/_toglmodule.c -o objects/emc/usr_intf/axis/extensions/_toglmodule.o
# Linking python module _togl.so
# gcc -L/home/user/linuxcnc/lib -Wl,-rpath,/home/user/linuxcnc/lib   -shared -o ../lib/python/_togl.so
# -I/usr/include/tcl8.6 -DUSE_TCL_STUBS -I/usr/include/tcl8.6  objects/emc/usr_intf/axis/extensions/_toglmodule.o
# -L/usr/X11R6/lib -lX11 -lepoxy -lXmu -L/usr/lib/x86_64-linux-gnu -ltclstub8.6 -lX11 -lXss -lXext -lXft
# -lfontconfig -lfreetype -lfontconfig  -lpthread -ldl -lz  -lpthread -lm -L/usr/lib/x86_64-linux-gnu -ltk8.6
# -lXinerama 













