cmake_minimum_required(VERSION 3.0)
# Project name.
set(PROJECT "nml" ) # The name of the file excluding .c or .h
project(${PROJECT} VERSION 0 LANGUAGES CXX C ) # Asm is optional.

# Set variables.
set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
set(BUILD_DIR "${CMAKE_CURRENT_BINARY_DIR}")
set(EMC_DIR "${SRC_DIR}/../emc")
set(BIN_DIR "${SRC_DIR}/../../bin")
set(HAL_DIR "${SRC_DIR}/../hal")
set(NML_DIR "${SRC_DIR}/../nml")
set(EMC_DIR "${SRC_DIR}/../emc")
set(RTAPI_DIR "${SRC_DIR}/../rtapi")
set(CONFIG_DIR "${SRC_DIR}/../")
set(LIB_DIR "${SRC_DIR}/../../lib")
set(RT_DIR "${SRC_DIR}/../../rtlib")
set(PYTHON_DIR "/usr/include/python3.9")

# Set includepaths.
include_directories(${SRC_DIR})
include_directories(${RTAPI_DIR})
include_directories(${PYTHON_DIR})
include_directories(${CONFIG_DIR})
include_directories(${EMC_DIR})
include_directories(${SRC_DIR}/buffer)
include_directories(${SRC_DIR}/cms)
include_directories(${SRC_DIR}/inifile)
include_directories(${SRC_DIR}/linklist)
include_directories(${SRC_DIR}/nml)
include_directories(${SRC_DIR}/os_intf)
include_directories(${SRC_DIR}/posemath)
include_directories(${SRC_DIR}/rcs)

set(CMAKE_SHARED_LIBRARY_PREFIX "lib")
# add_definitions()

ADD_LIBRARY(${PROJECT} SHARED
    ${SRC_DIR}/rcs/rcs_print.cc
    ${SRC_DIR}/rcs/rcs_exit.cc
    ${SRC_DIR}/os_intf/_sem.c
    ${SRC_DIR}/os_intf/_shm.c
    ${SRC_DIR}/os_intf/_timer.c
    ${SRC_DIR}/os_intf/sem.cc
    ${SRC_DIR}/os_intf/shm.cc
    ${SRC_DIR}/os_intf/timer.cc
    ${SRC_DIR}/buffer/locmem.cc
    ${SRC_DIR}/buffer/memsem.cc
    ${SRC_DIR}/buffer/phantom.cc
    ${SRC_DIR}/buffer/physmem.cc
    ${SRC_DIR}/buffer/recvn.c
    ${SRC_DIR}/buffer/sendn.c
    ${SRC_DIR}/buffer/shmem.cc
    ${SRC_DIR}/buffer/tcpmem.cc
    ${SRC_DIR}/cms/cms.cc
    ${SRC_DIR}/cms/cms_aup.cc
    ${SRC_DIR}/cms/cms_cfg.cc
    ${SRC_DIR}/cms/cms_in.cc
    ${SRC_DIR}/cms/cms_dup.cc
    ${SRC_DIR}/cms/cms_pm.cc
    ${SRC_DIR}/cms/cms_srv.cc
    ${SRC_DIR}/cms/cms_up.cc
    ${SRC_DIR}/cms/cms_xup.cc
    ${SRC_DIR}/cms/cmsdiag.cc
    ${SRC_DIR}/cms/tcp_opts.cc
    ${SRC_DIR}/cms/tcp_srv.cc
    ${SRC_DIR}/nml/cmd_msg.cc
    ${SRC_DIR}/nml/nml_mod.cc
    ${SRC_DIR}/nml/nml_oi.cc
    ${SRC_DIR}/nml/nml_srv.cc
    ${SRC_DIR}/nml/nml.cc
    ${SRC_DIR}/nml/nmldiag.cc
    ${SRC_DIR}/nml/nmlmsg.cc
    ${SRC_DIR}/nml/stat_msg.cc
    ${SRC_DIR}/linklist/linklist.cc
)

# Defenitions
add_definitions(-DULAPI)

# Include path
target_include_directories(${PROJECT_NAME} PRIVATE ${BUILD_DIR}/src/hal/linuxcnchal)

# Add verion nr. .so.0.0.0
set_target_properties(${PROJECT_NAME} PROPERTIES VERSION ${PROJECT_VERSION}
)

target_link_libraries(${PROJECT_NAME} PRIVATE -fPIC linuxcnchal)

# make install
install(TARGETS ${PROJECT} DESTINATION ${LIB_DIR})

# Creating shared library libnml.so.0
# g++ -std=gnu++17 -Wl,-soname,libnml.so.0 -shared -o ../lib/libnml.so.0 objects/libnml/rcs/rcs_print.o
# objects/libnml/rcs/rcs_exit.o objects/libnml/os_intf/_sem.o objects/libnml/os_intf/_shm.o objects/libnml/os_intf/_timer.o
# objects/libnml/os_intf/sem.o objects/libnml/os_intf/shm.o objects/libnml/os_intf/timer.o objects/libnml/buffer/locmem.o
# objects/libnml/buffer/memsem.o objects/libnml/buffer/phantom.o objects/libnml/buffer/physmem.o objects/libnml/buffer/recvn.o
# objects/libnml/buffer/sendn.o objects/libnml/buffer/shmem.o objects/libnml/buffer/tcpmem.o objects/libnml/cms/cms.o
# objects/libnml/cms/cms_aup.o objects/libnml/cms/cms_cfg.o objects/libnml/cms/cms_in.o objects/libnml/cms/cms_dup.o
# objects/libnml/cms/cms_pm.o objects/libnml/cms/cms_srv.o objects/libnml/cms/cms_up.o objects/libnml/cms/cms_xup.o
# objects/libnml/cms/cmsdiag.o objects/libnml/cms/tcp_opts.o objects/libnml/cms/tcp_srv.o objects/libnml/nml/cmd_msg.o
# objects/libnml/nml/nml_mod.o objects/libnml/nml/nml_oi.o objects/libnml/nml/nml_srv.o objects/libnml/nml/nml.o
# objects/libnml/nml/nmldiag.o objects/libnml/nml/nmlmsg.o objects/libnml/nml/stat_msg.o objects/libnml/linklist/linklist.o
# ../lib/liblinuxcnchal.so -L/home/user/linuxcnc/lib -Wl,-rpath,/home/user/linuxcnc/lib
# ln -sf libnml.so.0 ../lib/libnml.so

# Notes, in original make process, no -DULAPI was defined for libnml.so









