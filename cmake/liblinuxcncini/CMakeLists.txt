cmake_minimum_required(VERSION 3.0)
set(PROJECT "liblinuxcncini") 
project(${PROJECT} VERSION 0 LANGUAGES CXX)

# Set variables.
set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
set(BUILD_DIR "${CMAKE_CURRENT_BINARY_DIR}")

# Set includepaths.
include_directories(${SRC_DIR})
include_directories(${SRC_DIR}/../src)

# Set prefix.
set(CMAKE_SHARED_LIBRARY_PREFIX "")

ADD_LIBRARY(${PROJECT} SHARED 
    ${SRC_DIR}/../src/inifile.cc
    # ${SRC_DIR}/../src/inivar.cc # I think this was a wrong input, belong to : Linking mb2hal
)

add_definitions()

# Set include paths for libraries to link.
target_include_directories(${PROJECT_NAME} PRIVATE ${BUILD_DIR})

# Add verion nr. .so.0.0.0
set_target_properties(${PROJECT_NAME} PROPERTIES VERSION ${PROJECT_VERSION})

# Link to libraries.
target_link_libraries(${PROJECT_NAME} PRIVATE -fPIC)

# Set custom output name :
# set_property(TARGET  ${PROJECT} PROPERTY OUTPUT_NAME thename)

# Make install
install(TARGETS ${PROJECT} DESTINATION ${SRC_DIR})

# Notes.
# Compiling libnml/inifile/inifile.cc
# g++ -std=gnu++17 -c -I. -Ilibnml/linklist -Iemc -Ilibnml/cms -Ilibnml/rcs -Ilibnml/inifile -Ilibnml/os_intf
# -Ilibnml/nml -Ilibnml/buffer -Ilibnml/posemath -Irtapi -Ihal -Iemc -Iemc/nml_intf -Iemc/kinematics -Iemc/tp -Iemc/motion
# -Iemc/ini -Iemc -Iemc/rs274ngc -Iemc/sai -Iemc/pythonplugin -Iemc/tooldata -Iemc -I/home/user/linuxcnc/src/include
# -I/usr/include/python3.9  -DULAPI  -g -Wall -Wno-stringop-truncation -D_FORTIFY_SOURCE=2 -Os -fwrapv -Werror=overloaded-virtual
# -g -O2  -std=gnu++17 -fPIC \
# -MP -MD -MF "objects/libnml/inifile/inifile.d" -MT "objects/libnml/inifile/inifile.o" \
# libnml/inifile/inifile.cc -o objects/libnml/inifile/inifile.o
# Creating shared library liblinuxcncini.so.0
# g++ -std=gnu++17 -L/home/user/linuxcnc/lib -Wl,-rpath,/home/user/linuxcnc/lib   -Wl,-soname,liblinuxcncini.so.0 -shared -o
# ../lib/liblinuxcncini.so.0 objects/libnml/inifile/inifile.o
# ln -sf liblinuxcncini.so.0 ../lib/liblinuxcncini.so



























