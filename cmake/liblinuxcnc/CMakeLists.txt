cmake_minimum_required(VERSION 3.0)
set(PROJECT "liblinuxcnc") # ~/linuxcnc/src/emc/nml_inft
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
    ${SRC_DIR}/../src/emcglb.c
    ${SRC_DIR}/../src/modal_state.cc
    ${SRC_DIR}/../src/emc.cc
    ${SRC_DIR}/../src/emcpose.c
    ${SRC_DIR}/../src/emcargs.cc
    ${SRC_DIR}/../src/emcops.cc
    ${SRC_DIR}/../src/canon_position.cc
    ${SRC_DIR}/../src/emcIniFile.cc
    ${SRC_DIR}/../src/iniaxis.cc
    ${SRC_DIR}/../src/inijoint.cc
    ${SRC_DIR}/../src/inispindle.cc
    ${SRC_DIR}/../src/initraj.cc
    ${SRC_DIR}/../src/inihal.cc
    ${SRC_DIR}/../src/interpl.cc
    )

add_definitions(-DULAPI)

# Set include paths for libraries to link.
target_include_directories(${PROJECT_NAME} PRIVATE ${BUILD_DIR})

# Add verion nr. .so.0.0.0
set_target_properties(${PROJECT_NAME} PROPERTIES VERSION ${PROJECT_VERSION})

# Link to libraries.
target_link_libraries(${PROJECT_NAME} PRIVATE )

# Set custom output name :
# set_property(TARGET  ${PROJECT} PROPERTY OUTPUT_NAME thename)

# Make install
install(TARGETS ${PROJECT} DESTINATION ${SRC_DIR})

# Notes.
#[[ Compiling emc/nml_intf/emcglb.c
gcc -c -I. -Ilibnml/linklist -Iemc -Ilibnml/cms -Ilibnml/rcs -Ilibnml/inifile -Ilibnml/os_intf -Ilibnml/nml -Ilibnml/buffer -Ilibnml/posemath -Irtapi -Ihal -Iemc -Iemc/nml_intf -Iemc/kinematics -Iemc/tp -Iemc/motion -Iemc/ini -Iemc -Iemc/rs274ngc -Iemc/sai -Iemc/pythonplugin -Iemc/tooldata -Iemc -I/home/user/linuxcnc/src/include -I/usr/include/python3.9 -Os -fwrapv  -g -Wall -Wno-stringop-truncation -D_FORTIFY_SOURCE=2  -DULAPI -std=gnu11 -Werror=implicit-function-declaration -g -O2  -fPIC \
        -MP -MD -MF "objects/emc/nml_intf/emcglb.d" -MT "objects/emc/nml_intf/emcglb.o" \
        emc/nml_intf/emcglb.c -o objects/emc/nml_intf/emcglb.o
Compiling emc/nml_intf/emc.cc
g++ -std=gnu++17 -c -I. -Ilibnml/linklist -Iemc -Ilibnml/cms -Ilibnml/rcs -Ilibnml/inifile -Ilibnml/os_intf -Ilibnml/nml -Ilibnml/buffer -Ilibnml/posemath -Irtapi -Ihal -Iemc -Iemc/nml_intf -Iemc/kinematics -Iemc/tp -Iemc/motion -Iemc/ini -Iemc -Iemc/rs274ngc -Iemc/sai -Iemc/pythonplugin -Iemc/tooldata -Iemc -I/home/user/linuxcnc/src/include -I/usr/include/python3.9  -DULAPI  -g -Wall -Wno-stringop-truncation -D_FORTIFY_SOURCE=2 -Os -fwrapv -Werror=overloaded-virtual -g -O2  -std=gnu++17 -fPIC \
        -MP -MD -MF "objects/emc/nml_intf/emc.d" -MT "objects/emc/nml_intf/emc.o" \
        emc/nml_intf/emc.cc -o objects/emc/nml_intf/emc.o
Compiling emc/nml_intf/emcpose.c
gcc -c -I. -Ilibnml/linklist -Iemc -Ilibnml/cms -Ilibnml/rcs -Ilibnml/inifile -Ilibnml/os_intf -Ilibnml/nml -Ilibnml/buffer -Ilibnml/posemath -Irtapi -Ihal -Iemc -Iemc/nml_intf -Iemc/kinematics -Iemc/tp -Iemc/motion -Iemc/ini -Iemc -Iemc/rs274ngc -Iemc/sai -Iemc/pythonplugin -Iemc/tooldata -Iemc -I/home/user/linuxcnc/src/include -I/usr/include/python3.9 -Os -fwrapv  -g -Wall -Wno-stringop-truncation -D_FORTIFY_SOURCE=2  -DULAPI -std=gnu11 -Werror=implicit-function-declaration -g -O2  -fPIC \
        -MP -MD -MF "objects/emc/nml_intf/emcpose.d" -MT "objects/emc/nml_intf/emcpose.o" \
        emc/nml_intf/emcpose.c -o objects/emc/nml_intf/emcpose.o
Compiling emc/nml_intf/emcargs.cc
g++ -std=gnu++17 -c -I. -Ilibnml/linklist -Iemc -Ilibnml/cms -Ilibnml/rcs -Ilibnml/inifile -Ilibnml/os_intf -Ilibnml/nml -Ilibnml/buffer -Ilibnml/posemath -Irtapi -Ihal -Iemc -Iemc/nml_intf -Iemc/kinematics -Iemc/tp -Iemc/motion -Iemc/ini -Iemc -Iemc/rs274ngc -Iemc/sai -Iemc/pythonplugin -Iemc/tooldata -Iemc -I/home/user/linuxcnc/src/include -I/usr/include/python3.9  -DULAPI  -g -Wall -Wno-stringop-truncation -D_FORTIFY_SOURCE=2 -Os -fwrapv -Werror=overloaded-virtual -g -O2  -std=gnu++17 -fPIC \
        -MP -MD -MF "objects/emc/nml_intf/emcargs.d" -MT "objects/emc/nml_intf/emcargs.o" \
        emc/nml_intf/emcargs.cc -o objects/emc/nml_intf/emcargs.o
Compiling emc/nml_intf/emcops.cc
g++ -std=gnu++17 -c -I. -Ilibnml/linklist -Iemc -Ilibnml/cms -Ilibnml/rcs -Ilibnml/inifile -Ilibnml/os_intf -Ilibnml/nml -Ilibnml/buffer -Ilibnml/posemath -Irtapi -Ihal -Iemc -Iemc/nml_intf -Iemc/kinematics -Iemc/tp -Iemc/motion -Iemc/ini -Iemc -Iemc/rs274ngc -Iemc/sai -Iemc/pythonplugin -Iemc/tooldata -Iemc -I/home/user/linuxcnc/src/include -I/usr/include/python3.9  -DULAPI  -g -Wall -Wno-stringop-truncation -D_FORTIFY_SOURCE=2 -Os -fwrapv -Werror=overloaded-virtual -g -O2  -std=gnu++17 -fPIC \
        -MP -MD -MF "objects/emc/nml_intf/emcops.d" -MT "objects/emc/nml_intf/emcops.o" \
        emc/nml_intf/emcops.cc -o objects/emc/nml_intf/emcops.o
Compiling emc/nml_intf/canon_position.cc
g++ -std=gnu++17 -c -I. -Ilibnml/linklist -Iemc -Ilibnml/cms -Ilibnml/rcs -Ilibnml/inifile -Ilibnml/os_intf -Ilibnml/nml -Ilibnml/buffer -Ilibnml/posemath -Irtapi -Ihal -Iemc -Iemc/nml_intf -Iemc/kinematics -Iemc/tp -Iemc/motion -Iemc/ini -Iemc -Iemc/rs274ngc -Iemc/sai -Iemc/pythonplugin -Iemc/tooldata -Iemc -I/home/user/linuxcnc/src/include -I/usr/include/python3.9  -DULAPI  -g -Wall -Wno-stringop-truncation -D_FORTIFY_SOURCE=2 -Os -fwrapv -Werror=overloaded-virtual -g -O2  -std=gnu++17 -fPIC \
        -MP -MD -MF "objects/emc/nml_intf/canon_position.d" -MT "objects/emc/nml_intf/canon_position.o" \
        emc/nml_intf/canon_position.cc -o objects/emc/nml_intf/canon_position.o
Compiling emc/ini/emcIniFile.cc
g++ -std=gnu++17 -c -I. -Ilibnml/linklist -Iemc -Ilibnml/cms -Ilibnml/rcs -Ilibnml/inifile -Ilibnml/os_intf -Ilibnml/nml -Ilibnml/buffer -Ilibnml/posemath -Irtapi -Ihal -Iemc -Iemc/nml_intf -Iemc/kinematics -Iemc/tp -Iemc/motion -Iemc/ini -Iemc -Iemc/rs274ngc -Iemc/sai -Iemc/pythonplugin -Iemc/tooldata -Iemc -I/home/user/linuxcnc/src/include -I/usr/include/python3.9  -DULAPI  -g -Wall -Wno-stringop-truncation -D_FORTIFY_SOURCE=2 -Os -fwrapv -Werror=overloaded-virtual -g -O2  -std=gnu++17 -fPIC \
        -MP -MD -MF "objects/emc/ini/emcIniFile.d" -MT "objects/emc/ini/emcIniFile.o" \
        emc/ini/emcIniFile.cc -o objects/emc/ini/emcIniFile.o
Compiling emc/ini/iniaxis.cc
g++ -std=gnu++17 -c -I. -Ilibnml/linklist -Iemc -Ilibnml/cms -Ilibnml/rcs -Ilibnml/inifile -Ilibnml/os_intf -Ilibnml/nml -Ilibnml/buffer -Ilibnml/posemath -Irtapi -Ihal -Iemc -Iemc/nml_intf -Iemc/kinematics -Iemc/tp -Iemc/motion -Iemc/ini -Iemc -Iemc/rs274ngc -Iemc/sai -Iemc/pythonplugin -Iemc/tooldata -Iemc -I/home/user/linuxcnc/src/include -I/usr/include/python3.9  -DULAPI  -g -Wall -Wno-stringop-truncation -D_FORTIFY_SOURCE=2 -Os -fwrapv -Werror=overloaded-virtual -g -O2  -std=gnu++17 -fPIC \
        -MP -MD -MF "objects/emc/ini/iniaxis.d" -MT "objects/emc/ini/iniaxis.o" \
        emc/ini/iniaxis.cc -o objects/emc/ini/iniaxis.o
Compiling emc/ini/inijoint.cc
g++ -std=gnu++17 -c -I. -Ilibnml/linklist -Iemc -Ilibnml/cms -Ilibnml/rcs -Ilibnml/inifile -Ilibnml/os_intf -Ilibnml/nml -Ilibnml/buffer -Ilibnml/posemath -Irtapi -Ihal -Iemc -Iemc/nml_intf -Iemc/kinematics -Iemc/tp -Iemc/motion -Iemc/ini -Iemc -Iemc/rs274ngc -Iemc/sai -Iemc/pythonplugin -Iemc/tooldata -Iemc -I/home/user/linuxcnc/src/include -I/usr/include/python3.9  -DULAPI  -g -Wall -Wno-stringop-truncation -D_FORTIFY_SOURCE=2 -Os -fwrapv -Werror=overloaded-virtual -g -O2  -std=gnu++17 -fPIC \
        -MP -MD -MF "objects/emc/ini/inijoint.d" -MT "objects/emc/ini/inijoint.o" \
        emc/ini/inijoint.cc -o objects/emc/ini/inijoint.o
Compiling emc/ini/inispindle.cc
g++ -std=gnu++17 -c -I. -Ilibnml/linklist -Iemc -Ilibnml/cms -Ilibnml/rcs -Ilibnml/inifile -Ilibnml/os_intf -Ilibnml/nml -Ilibnml/buffer -Ilibnml/posemath -Irtapi -Ihal -Iemc -Iemc/nml_intf -Iemc/kinematics -Iemc/tp -Iemc/motion -Iemc/ini -Iemc -Iemc/rs274ngc -Iemc/sai -Iemc/pythonplugin -Iemc/tooldata -Iemc -I/home/user/linuxcnc/src/include -I/usr/include/python3.9  -DULAPI  -g -Wall -Wno-stringop-truncation -D_FORTIFY_SOURCE=2 -Os -fwrapv -Werror=overloaded-virtual -g -O2  -std=gnu++17 -fPIC \
        -MP -MD -MF "objects/emc/ini/inispindle.d" -MT "objects/emc/ini/inispindle.o" \
        emc/ini/inispindle.cc -o objects/emc/ini/inispindle.o
Compiling emc/ini/initraj.cc
g++ -std=gnu++17 -c -I. -Ilibnml/linklist -Iemc -Ilibnml/cms -Ilibnml/rcs -Ilibnml/inifile -Ilibnml/os_intf -Ilibnml/nml -Ilibnml/buffer -Ilibnml/posemath -Irtapi -Ihal -Iemc -Iemc/nml_intf -Iemc/kinematics -Iemc/tp -Iemc/motion -Iemc/ini -Iemc -Iemc/rs274ngc -Iemc/sai -Iemc/pythonplugin -Iemc/tooldata -Iemc -I/home/user/linuxcnc/src/include -I/usr/include/python3.9  -DULAPI  -g -Wall -Wno-stringop-truncation -D_FORTIFY_SOURCE=2 -Os -fwrapv -Werror=overloaded-virtual -g -O2  -std=gnu++17 -fPIC \
        -MP -MD -MF "objects/emc/ini/initraj.d" -MT "objects/emc/ini/initraj.o" \
        emc/ini/initraj.cc -o objects/emc/ini/initraj.o
Compiling emc/ini/inihal.cc
g++ -std=gnu++17 -c -I. -Ilibnml/linklist -Iemc -Ilibnml/cms -Ilibnml/rcs -Ilibnml/inifile -Ilibnml/os_intf -Ilibnml/nml -Ilibnml/buffer -Ilibnml/posemath -Irtapi -Ihal -Iemc -Iemc/nml_intf -Iemc/kinematics -Iemc/tp -Iemc/motion -Iemc/ini -Iemc -Iemc/rs274ngc -Iemc/sai -Iemc/pythonplugin -Iemc/tooldata -Iemc -I/home/user/linuxcnc/src/include -I/usr/include/python3.9  -DULAPI  -g -Wall -Wno-stringop-truncation -D_FORTIFY_SOURCE=2 -Os -fwrapv -Werror=overloaded-virtual -g -O2  -std=gnu++17 -fPIC \
        -MP -MD -MF "objects/emc/ini/inihal.d" -MT "objects/emc/ini/inihal.o" \
        emc/ini/inihal.cc -o objects/emc/ini/inihal.o
Compiling emc/nml_intf/interpl.cc
g++ -std=gnu++17 -c -I. -Ilibnml/linklist -Iemc -Ilibnml/cms -Ilibnml/rcs -Ilibnml/inifile -Ilibnml/os_intf -Ilibnml/nml -Ilibnml/buffer -Ilibnml/posemath -Irtapi -Ihal -Iemc -Iemc/nml_intf -Iemc/kinematics -Iemc/tp -Iemc/motion -Iemc/ini -Iemc -Iemc/rs274ngc -Iemc/sai -Iemc/pythonplugin -Iemc/tooldata -Iemc -I/home/user/linuxcnc/src/include -I/usr/include/python3.9  -DULAPI  -g -Wall -Wno-stringop-truncation -D_FORTIFY_SOURCE=2 -Os -fwrapv -Werror=overloaded-virtual -g -O2  -std=gnu++17 -fPIC \
        -MP -MD -MF "objects/emc/nml_intf/interpl.d" -MT "objects/emc/nml_intf/interpl.o" \
        emc/nml_intf/interpl.cc -o objects/emc/nml_intf/interpl.o
Linking liblinuxcnc.so ]]








