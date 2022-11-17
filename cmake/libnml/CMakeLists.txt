cmake_minimum_required(VERSION 3.0)
set(PROJECT "libnml") 
project(${PROJECT} VERSION 0 LANGUAGES CXX)

# Set variables.
set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
set(BUILD_DIR "${CMAKE_CURRENT_BINARY_DIR}")

# Set includepaths.
include_directories(${SRC_DIR})
include_directories(${SRC_DIR}/../common_src)
include_directories(${SRC_DIR}/../rtapi_src)
include_directories(${SRC_DIR}/../libnml_src)

# Set prefix.
set(CMAKE_SHARED_LIBRARY_PREFIX "")

ADD_LIBRARY(${PROJECT} SHARED 
    ${SRC_DIR}/../libnml_src/rcs_print.cc
    ${SRC_DIR}/../libnml_src/rcs_exit.cc
    ${SRC_DIR}/../libnml_src/_sem.c
    ${SRC_DIR}/../libnml_src/_shm.c
    ${SRC_DIR}/../libnml_src/_timer.c
    ${SRC_DIR}/../libnml_src/sem.cc
    ${SRC_DIR}/../libnml_src/shm.cc
    ${SRC_DIR}/../libnml_src/timer.cc
    ${SRC_DIR}/../libnml_src/locmem.cc
    ${SRC_DIR}/../libnml_src/memsem.cc
    ${SRC_DIR}/../libnml_src/phantom.cc
    ${SRC_DIR}/../libnml_src/physmem.cc
    ${SRC_DIR}/../libnml_src/recvn.c
    ${SRC_DIR}/../libnml_src/sendn.c
    ${SRC_DIR}/../libnml_src/shmem.cc
    ${SRC_DIR}/../libnml_src/tcpmem.cc
    ${SRC_DIR}/../libnml_src/cms.cc
    ${SRC_DIR}/../libnml_src/cms_aup.cc
    ${SRC_DIR}/../libnml_src/cms_cfg.cc
    ${SRC_DIR}/../libnml_src/cms_in.cc
    ${SRC_DIR}/../libnml_src/cms_dup.cc
    ${SRC_DIR}/../libnml_src/cms_pm.cc
    ${SRC_DIR}/../libnml_src/cms_srv.cc
    ${SRC_DIR}/../libnml_src/cms_up.cc
    ${SRC_DIR}/../libnml_src/cms_xup.cc
    ${SRC_DIR}/../libnml_src/cmsdiag.cc
    ${SRC_DIR}/../libnml_src/tcp_opts.cc
    ${SRC_DIR}/../libnml_src/tcp_srv.cc
    ${SRC_DIR}/../libnml_src/cmd_msg.cc
    ${SRC_DIR}/../libnml_src/nml_mod.cc
    ${SRC_DIR}/../libnml_src/nml_oi.cc
    ${SRC_DIR}/../libnml_src/nml_srv.cc
    ${SRC_DIR}/../libnml_src/nml.cc
    ${SRC_DIR}/../libnml_src/nmldiag.cc
    ${SRC_DIR}/../libnml_src/nmlmsg.cc
    ${SRC_DIR}/../libnml_src/stat_msg.cc
    ${SRC_DIR}/../libnml_src/linklist.cc
)

add_definitions(-DULAPI)

add_library(linuxcnchal SHARED IMPORTED) # or STATIC instead of SHARED
set_target_properties(linuxcnchal PROPERTIES
  IMPORTED_LOCATION "/home/user/lcncladdertest/lib/liblinuxcnchal.so"
  INTERFACE_INCLUDE_DIRECTORIES "/home/user/lcncladdertest/include"
)

# Link to libraries.
target_link_libraries(${PROJECT_NAME} PRIVATE linuxcnchal)

# Set custom output name :
# set_property(TARGET  ${PROJECT} PROPERTY OUTPUT_NAME thename)

# Add verion nr. .so.0.0.0
set_target_properties(${PROJECT_NAME} PROPERTIES VERSION ${PROJECT_VERSION})

# Make install
install(TARGETS ${PROJECT} DESTINATION ${SRC_DIR})

# Notes.
# Compiling libnml/nml/nml.cc
# g++ -std=gnu++17 -c -I. -Ilibnml/linklist -Iemc -Ilibnml/cms -Ilibnml/rcs -Ilibnml/inifile -Ilibnml/os_intf
# -Ilibnml/nml -Ilibnml/buffer -Ilibnml/posemath -Irtapi -Ihal -Iemc -Iemc/nml_intf -Iemc/kinematics
# -Iemc/tp -Iemc/motion -Iemc/ini -Iemc -Iemc/rs274ngc -Iemc/sai -Iemc/pythonplugin -Iemc/tooldata -Iemc
#-I/home/user/linuxcnc/src/include -I/usr/include/python3.9  -DULAPI  -g -Wall -Wno-stringop-truncation
#-D_FORTIFY_SOURCE=2 -Os -fwrapv -Werror=overloaded-virtual -g -O2  -std=gnu++17 -fPIC \
#        -MP -MD -MF "objects/libnml/nml/nml.d" -MT "objects/libnml/nml/nml.o" \
#        libnml/nml/nml.cc -o objects/libnml/nml/nml.o
# Creating shared library libnml.so.0
# g++ -std=gnu++17 -Wl,-soname,libnml.so.0 -shared -o ../lib/libnml.so.0 objects/libnml/rcs/rcs_print.o
# objects/libnml/rcs/rcs_exit.o objects/libnml/os_intf/_sem.o objects/libnml/os_intf/_shm.o
# objects/libnml/os_intf/_timer.o objects/libnml/os_intf/sem.o objects/libnml/os_intf/shm.o objects/libnml/os_intf/timer.o
# objects/libnml/buffer/locmem.o objects/libnml/buffer/memsem.o objects/libnml/buffer/phantom.o objects/libnml/buffer/physmem.o
# objects/libnml/buffer/recvn.o objects/libnml/buffer/sendn.o objects/libnml/buffer/shmem.o
# objects/libnml/buffer/tcpmem.o objects/libnml/cms/cms.o objects/libnml/cms/cms_aup.o objects/libnml/cms/cms_cfg.o
# objects/libnml/cms/cms_in.o objects/libnml/cms/cms_dup.o objects/libnml/cms/cms_pm.o objects/libnml/cms/cms_srv.o
# objects/libnml/cms/cms_up.o objects/libnml/cms/cms_xup.o objects/libnml/cms/cmsdiag.o objects/libnml/cms/tcp_opts.o
# objects/libnml/cms/tcp_srv.o objects/libnml/nml/cmd_msg.o objects/libnml/nml/nml_mod.o objects/libnml/nml/nml_oi.o
# objects/libnml/nml/nml_srv.o objects/libnml/nml/nml.o objects/libnml/nml/nmldiag.o objects/libnml/nml/nmlmsg.o
# objects/libnml/nml/stat_msg.o objects/libnml/linklist/linklist.o
# ../lib/liblinuxcnchal.so -L/home/user/linuxcnc/lib
# -Wl,-rpath,/home/user/linuxcnc/lib
# ln -sf libnml.so.0 ../lib/libnml.so
















