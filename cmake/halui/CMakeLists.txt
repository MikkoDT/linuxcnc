cmake_minimum_required(VERSION 3.0)
set(PROJECT "halui")
project(${PROJECT} LANGUAGES CXX)

# Set variables.
set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
set(BUILD_DIR "${CMAKE_CURRENT_BINARY_DIR}")

# Set includepaths.
include_directories(${SRC_DIR})
include_directories(${SRC_DIR}/../src)

# Set prefix.
# set(CMAKE_SHARED_LIBRARY_PREFIX "")

set(SOURCES
    ${SRC_DIR}/../src/halui.cc
)
add_executable(${PROJECT_NAME} ${SOURCES})

add_definitions(-DULAPI)

# Set include paths for libraries to link.
# target_include_directories(${PROJECT_NAME} PRIVATE ${BUILD_DIR}/liblinuxcnc)
# target_include_directories(${PROJECT_NAME} PRIVATE ${BUILD_DIR}/liblinuxcnchal)
# target_include_directories(${PROJECT_NAME} PRIVATE ${BUILD_DIR}/liblinuxcncini)
# target_include_directories(${PROJECT_NAME} PRIVATE ${BUILD_DIR}/libnml)
# target_include_directories(${PROJECT_NAME} PRIVATE ${BUILD_DIR}/libtooldata)

# Link to libraries.
target_link_libraries(${PROJECT_NAME} PRIVATE liblinuxcnc liblinuxcncini libnml liblinuxcnchal libtooldata
)

# Set custom output name :
# set_property(TARGET  ${PROJECT} PROPERTY OUTPUT_NAME thename)

# Make install
install(TARGETS ${PROJECT} DESTINATION ${SRC_DIR})

# Notes.
# Compiling emc/usr_intf/halui.cc
# g++ -std=gnu++17 -c -I. -Ilibnml/linklist -Iemc -Ilibnml/cms -Ilibnml/rcs -Ilibnml/inifile -Ilibnml/os_intf
# -Ilibnml/nml -Ilibnml/buffer -Ilibnml/posemath -Irtapi -Ihal -Iemc -Iemc/nml_intf -Iemc/kinematics
# -Iemc/tp -Iemc/motion -Iemc/ini -Iemc -Iemc/rs274ngc -Iemc/sai -Iemc/pythonplugin -Iemc/tooldata
# -Iemc -I/home/user/linuxcnc/src/include -I/usr/include/python3.9  -DULAPI  -g -Wall -Wno-stringop-truncation
# -D_FORTIFY_SOURCE=2 -Os -fwrapv -Werror=overloaded-virtual -g -O2  -std=gnu++17  \
#         -MP -MD -MF "objects/emc/usr_intf/halui.d" -MT "objects/emc/usr_intf/halui.o" \
#         emc/usr_intf/halui.cc -o objects/emc/usr_intf/halui.o
# Linking halui
# g++ -std=gnu++17 -I. -Ilibnml/linklist -Iemc -Ilibnml/cms -Ilibnml/rcs -Ilibnml/inifile -Ilibnml/os_intf -
# Ilibnml/nml -Ilibnml/buffer -Ilibnml/posemath -Irtapi -Ihal -Iemc -Iemc/nml_intf -Iemc/kinematics -Iemc/tp
# -Iemc/motion -Iemc/ini -Iemc -Iemc/rs274ngc -Iemc/sai -Iemc/pythonplugin -Iemc/tooldata -Iemc
# -I/home/user/linuxcnc/src/include -I/usr/include/python3.9  -DULAPI  -g -Wall -Wno-stringop-truncation
# -D_FORTIFY_SOURCE=2 -Os -fwrapv -Werror=overloaded-virtual -g -O2  -std=gnu++17 -o ../bin/halui -Wall -g -I.
# -I/home/user/linuxcnc/src/include -DULAPI -D_GNU_SOURCE -Os -DLOCALE_DIR=\"/usr/share/locale\" -DPACKAGE=\"linuxcnc\"
# objects/emc/usr_intf/halui.o ../lib/liblinuxcnc.so ../lib/liblinuxcncini.so.0 ../lib/libnml.so.0 ../lib/liblinuxcnchal.so.0
# ../lib/libtooldata.so.0 -L/home/user/linuxcnc/lib -Wl,-rpath,/home/user/linuxcnc/lib
# You now need to run 'sudo make setuid' in order to run in place with access to hardware.






