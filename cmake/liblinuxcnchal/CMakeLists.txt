cmake_minimum_required(VERSION 3.0)
set(PROJECT "liblinuxcnchal") 
project(${PROJECT} VERSION 0 LANGUAGES C)

# Set variables.
set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
set(BUILD_DIR "${CMAKE_CURRENT_BINARY_DIR}")

# Set includepaths.
include_directories(${SRC_DIR})
include_directories(${SRC_DIR}/../src)

# Set prefix.
set(CMAKE_SHARED_LIBRARY_PREFIX "")

ADD_LIBRARY(${PROJECT} SHARED 
    ${SRC_DIR}/../src/uspace_ulapi.c
    ${SRC_DIR}/../src/hal_lib.c
)

add_definitions(-DULAPI)

# Add verion nr. .so.0.0.0
set_target_properties(${PROJECT_NAME} PROPERTIES VERSION ${PROJECT_VERSION})

# Set include paths for libraries to link.
target_include_directories(${PROJECT_NAME} PRIVATE ${BUILD_DIR})

# Link to libraries.
target_link_libraries(${PROJECT_NAME} PRIVATE -pthread -lrt -fPIC)

# Set custom output name :
# set_property(TARGET ${PROJECT} PROPERTY OUTPUT_NAME thename)

# Make install
install(TARGETS ${PROJECT} DESTINATION ${SRC_DIR})

# Notes.
# Compiling hal/hal_lib.c
# gcc -c -I. -Ilibnml/linklist -Iemc -Ilibnml/cms -Ilibnml/rcs -Ilibnml/inifile -Ilibnml/os_intf -Ilibnml/nml
# -Ilibnml/buffer -Ilibnml/posemath -Irtapi -Ihal -Iemc -Iemc/nml_intf -Iemc/kinematics -Iemc/tp -Iemc/motion
# -Iemc/ini -Iemc -Iemc/rs274ngc -Iemc/sai -Iemc/pythonplugin -Iemc/tooldata -Iemc -I/home/user/linuxcnc/src/include
# -I/usr/include/python3.9 -Os -fwrapv  -g -Wall -Wno-stringop-truncation -D_FORTIFY_SOURCE=2  -DULAPI -std=gnu11
# -Werror=implicit-function-declaration -g -O2  -fPIC  \
#        -MP -MD -MF "objects/hal/hal_lib.d" -MT "objects/hal/hal_lib.o" \
#        hal/hal_lib.c -o objects/hal/hal_lib.o
# Creating shared library liblinuxcnchal.so.0
# gcc -L/home/user/linuxcnc/lib -Wl,-rpath,/home/user/linuxcnc/lib   -Wl,-soname,liblinuxcnchal.so.0 -shared -o
# ../lib/liblinuxcnchal.so.0 objects/hal/hal_lib.o objects/rtapi/uspace_ulapi.o -pthread -lrt
# ln -sf liblinuxcnchal.so.0 ../lib/liblinuxcnchal.so
