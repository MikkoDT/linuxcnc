cmake_minimum_required(VERSION 3.0)
set(PROJECT "module_helper") 
project(${PROJECT} C)

# Set variables.
set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
set(BUILD_DIR "${CMAKE_CURRENT_BINARY_DIR}")

# Set includepaths.
include_directories(${SRC_DIR})
include_directories(${SRC_DIR}/../src)

# Set prefix.
set(CMAKE_SHARED_LIBRARY_PREFIX "")

ADD_LIBRARY(${PROJECT} SHARED 
    ${SRC_DIR}/../src/module_helper.c
)

add_definitions(-DULAPI)

# Set include paths for libraries to link.
target_include_directories(${PROJECT_NAME} PRIVATE ${BUILD_DIR})

# Link to libraries.
target_link_libraries(${PROJECT_NAME} PRIVATE)

# Set custom output name :
# set_property(TARGET  ${PROJECT} PROPERTY OUTPUT_NAME thename)

# Make install
install(TARGETS ${PROJECT} DESTINATION ${SRC_DIR})

# Notes.
# Compiling module_helper/module_helper.c
# gcc -c -I. -Ilibnml/linklist -Iemc -Ilibnml/cms -Ilibnml/rcs -Ilibnml/inifile -Ilibnml/os_intf
# -Ilibnml/nml -Ilibnml/buffer -Ilibnml/posemath -Irtapi -Ihal -Iemc -Iemc/nml_intf -Iemc/kinematics
# -Iemc/tp -Iemc/motion -Iemc/ini -Iemc -Iemc/rs274ngc -Iemc/sai -Iemc/pythonplugin -Iemc/tooldata -Iemc
# -I/home/user/linuxcnc/src/include -I/usr/include/python3.9 -Os -fwrapv  -g -Wall -Wno-stringop-truncation
# -D_FORTIFY_SOURCE=2  -DULAPI -std=gnu11 -Werror=implicit-function-declaration -g -O2  -Wall -Werror \
#         -MP -MD -MF "objects/module_helper/module_helper.d" -MT "objects/module_helper/module_helper.o" \
#         module_helper/module_helper.c -o objects/module_helper/module_helper.o
# Linking linuxcnc_module_helper
