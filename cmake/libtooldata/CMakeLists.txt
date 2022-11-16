cmake_minimum_required(VERSION 3.0)
set(PROJECT "libtooldata") 
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
    ${SRC_DIR}/../src/tooldata_mmap.cc
    ${SRC_DIR}/../src/tooldata_common.cc
    ${SRC_DIR}/../src/tooldata_db.cc
)

add_definitions(-DULAPI)

# Add verion nr. .so.0.0.0
set_target_properties(${PROJECT_NAME} PROPERTIES VERSION ${PROJECT_VERSION})

# Set include paths for libraries to link.
target_include_directories(${PROJECT_NAME} PRIVATE ${BUILD_DIR})

# Link to libraries.
target_link_libraries(${PROJECT_NAME} PRIVATE)

# Set custom output name :
# set_property(TARGET  ${PROJECT} PROPERTY OUTPUT_NAME thename)

# Make install
install(TARGETS ${PROJECT} DESTINATION ${SRC_DIR})

# Notes.
# Compiling emc/tooldata/tooldata_mmap.cc
# g++ -std=gnu++17 -c -I. -Ilibnml/linklist -Iemc -Ilibnml/cms -Ilibnml/rcs -Ilibnml/inifile -Ilibnml/os_intf
# -Ilibnml/nml -Ilibnml/buffer -Ilibnml/posemath -Irtapi -Ihal -Iemc -Iemc/nml_intf -Iemc/kinematics -Iemc/tp
# -Iemc/motion -Iemc/ini -Iemc -Iemc/rs274ngc -Iemc/sai -Iemc/pythonplugin -Iemc/tooldata -Iemc
# -I/home/user/linuxcnc/src/include -I/usr/include/python3.9  -DULAPI  -g -Wall -Wno-stringop-truncation
# -D_FORTIFY_SOURCE=2 -Os -fwrapv -Werror=overloaded-virtual -g -O2  -std=gnu++17 -fPIC \
#        -MP -MD -MF "objects/emc/tooldata/tooldata_mmap.d" -MT "objects/emc/tooldata/tooldata_mmap.o" \
#        emc/tooldata/tooldata_mmap.cc -o objects/emc/tooldata/tooldata_mmap.o
# Compiling emc/tooldata/tooldata_common.cc
# g++ -std=gnu++17 -c -I. -Ilibnml/linklist -Iemc -Ilibnml/cms -Ilibnml/rcs -Ilibnml/inifile -Ilibnml/os_intf
# -Ilibnml/nml -Ilibnml/buffer -Ilibnml/posemath -Irtapi -Ihal -Iemc -Iemc/nml_intf -Iemc/kinematics -Iemc/tp
# -Iemc/motion -Iemc/ini -Iemc -Iemc/rs274ngc -Iemc/sai -Iemc/pythonplugin -Iemc/tooldata -Iemc
# -I/home/user/linuxcnc/src/include -I/usr/include/python3.9  -DULAPI  -g -Wall -Wno-stringop-truncation
# -D_FORTIFY_SOURCE=2 -Os -fwrapv -Werror=overloaded-virtual -g -O2  -std=gnu++17 -fPIC \
#         -MP -MD -MF "objects/emc/tooldata/tooldata_common.d" -MT "objects/emc/tooldata/tooldata_common.o" \
#         emc/tooldata/tooldata_common.cc -o objects/emc/tooldata/tooldata_common.o
# Compiling emc/tooldata/tooldata_db.cc
# g++ -std=gnu++17 -c -I. -Ilibnml/linklist -Iemc -Ilibnml/cms -Ilibnml/rcs -Ilibnml/inifile -Ilibnml/os_intf
# -Ilibnml/nml -Ilibnml/buffer -Ilibnml/posemath -Irtapi -Ihal -Iemc -Iemc/nml_intf -Iemc/kinematics -Iemc/tp
# -Iemc/motion -Iemc/ini -Iemc -Iemc/rs274ngc -Iemc/sai -Iemc/pythonplugin -Iemc/tooldata -Iemc
# -I/home/user/linuxcnc/src/include -I/usr/include/python3.9  -DULAPI  -g -Wall -Wno-stringop-truncation
#-D_FORTIFY_SOURCE=2 -Os -fwrapv -Werror=overloaded-virtual -g -O2  -std=gnu++17 -fPIC \
#        -MP -MD -MF "objects/emc/tooldata/tooldata_db.d" -MT "objects/emc/tooldata/tooldata_db.o" \
#        emc/tooldata/tooldata_db.cc -o objects/emc/tooldata/tooldata_db.o
# tooldata: depends: objects/emc/tooldata/tooldata_mmap.o objects/emc/tooldata/tooldata_common.o objects/emc/tooldata/tooldata_db.o
# tooldata: Linking: libtooldata.so.0
