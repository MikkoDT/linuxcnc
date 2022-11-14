cmake_minimum_required(VERSION 3.0)
# Project name, should be linuxcnc.so, but name already excists in the cmake hierarchy.
set(PROJECT "linuxcnc_tcl_lib" ) # The name of the file excluding .c or .h
project(${PROJECT} LANGUAGES CXX C ) # Asm is optional.

# Set variables.
set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
set(BUILD_DIR "${CMAKE_CURRENT_BINARY_DIR}")
set(EMC_DIR "${SRC_DIR}/../")
set(BIN_DIR "${SRC_DIR}/../../../bin")
set(HAL_DIR "${SRC_DIR}/../../hal")
set(NML_DIR "${SRC_DIR}/../../nml")
set(RTAPI_DIR "${SRC_DIR}/../../rtapi")
set(CONFIG_DIR "${SRC_DIR}/../../")
set(LIB_DIR "${SRC_DIR}/../../../lib")
set(RT_DIR "${SRC_DIR}/../../../rtlib")
set(PYTHON_DIR "/usr/include/python3.9")

# Set includepaths.
include_directories(${SRC_DIR})
include_directories(${RTAPI_DIR})
include_directories(${PYTHON_DIR})
include_directories(${CONFIG_DIR})
include_directories(${EMC_DIR})
include_directories(${SRC_DIR}/../nml_intf)
include_directories(${SRC_DIR}/../../libnml/posemath)
include_directories(${SRC_DIR}/../../libnml/nml)
include_directories(${SRC_DIR}/../motion)
include_directories(${SRC_DIR}/../tooldata)
include_directories(${SRC_DIR}/../../libnml/rcs)
include_directories(${SRC_DIR}/../../libnml/cms)
include_directories(${SRC_DIR}/../../libnml/inifile)
include_directories(${SRC_DIR}/../pythonplugin)
include_directories(${SRC_DIR}/../../hal)
include_directories(${SRC_DIR}/../rs274ngc)
include_directories(${SRC_DIR}/../../libnml/linklist)
include_directories(${SRC_DIR}/../../libnml/os_intf)
include_directories(/usr/include/tcl8.6)
include_directories(/usr/lib/x86_64-linux-gnu)

set(CMAKE_SHARED_LIBRARY_PREFIX "")
# add_definitions()

ADD_LIBRARY(${PROJECT} SHARED
    ${SRC_DIR}/emcsh.cc 
    ${SRC_DIR}/shcom.cc
)

add_definitions(-DULAPI)

# liblinuxcncini.so
target_include_directories(${PROJECT_NAME} PRIVATE ${BUILD_DIR}/src/libnml/inifile)
# libnml.so
target_include_directories(${PROJECT_NAME} PRIVATE ${BUILD_DIR}/src/libnml)
# liblinuxcnc.so, linking to liblinuxcnc.a gives error.
target_include_directories(${PROJECT_NAME} PRIVATE ${BUILD_DIR}/src/emc/nml_intf)

# Link to :
target_link_libraries(${PROJECT_NAME} PRIVATE -fPIC linuxcncini nml linuxcnc
     -ltclstub8.6 -lX11 -lXss -lXext -lXft -lfontconfig -lfreetype
     -lfontconfig -lpthread -ldl -lz -lpthread -lm -ltk8.6 -fPIC
)

# make install
install(TARGETS ${PROJECT} DESTINATION ${LIB_DIR}/tcl)

# Notes, linking to liblinuxcnc.a gives reallocation error. Solution compile liblinuxcnc shared .so
# Linking to liblinuxcnc.so gives no error.
# The makefile is a little confusing. linuxcnc.so has only resources from : EMCSHSRCS

# ../tcl/linuxcnc.so: $(call TOOBJS, $(EMCSHSRCS))
# ../lib/liblinuxcnc.a ../lib/liblinuxcncini.so.0 ../lib/libnml.so.0
# $(ECHO) Linking $(notdir $@)
# $(Q)$(CXX) -shared $(LDFLAGS) -o $@ $(ULFLAGS) $(TCL_CFLAGS) $^ $(TCL_LIBS)
# -lXinerama
# TARGETS += ../tcl/linuxcnc.so

# g++ -std=gnu++17 -shared -L/home/user/linuxcnc/lib -Wl,-rpath,/home/user/linuxcnc/lib
# -o ../tcl/linuxcnc.so -Wall -g -I. -I/home/user/linuxcnc/src/include -DULAPI -D_GNU_SOURCE -Os
# -DLOCALE_DIR=\"/usr/share/locale\" -DPACKAGE=\"linuxcnc\" -I/usr/include/tcl8.6 -DUSE_TCL_STUBS
# -I/usr/include/tcl8.6  objects/emc/usr_intf/emcsh.o objects/emc/usr_intf/shcom.o ../lib/liblinuxcnc.a
# ../lib/liblinuxcncini.so.0 ../lib/libnml.so.0 -L/usr/lib/x86_64-linux-gnu
# -ltclstub8.6 -lX11 -lXss -lXext -lXft -lfontconfig -lfreetype -lfontconfig  -lpthread -ldl -lz  -lpthread -lm
# -L/usr/lib/x86_64-linux-gnu -ltk8.6  -lXinerama  -lXinerama
# Compiling emc/usr_intf/emcrsh.cc
# g++ -std=gnu++17 -c -I. -Ilibnml/linklist -Iemc -Ilibnml/cms -Ilibnml/rcs -Ilibnml/inifile -Ilibnml/os_intf -Ilibnml/nml
# -Ilibnml/buffer -Ilibnml/posemath -Irtapi -Ihal -Iemc -Iemc/nml_intf -Iemc/kinematics -Iemc/tp -Iemc/motion
# -Iemc/ini -Iemc -Iemc/rs274ngc -Iemc/sai -Iemc/pythonplugin -Iemc/tooldata -Iemc -I/home/user/linuxcnc/src/include
# -I/usr/include/python3.9  -DULAPI  -g -Wall -Wno-stringop-truncation -D_FORTIFY_SOURCE=2 -Os -fwrapv -Werror=overloaded-virtual
# -g -O2  -std=gnu++17  \


















