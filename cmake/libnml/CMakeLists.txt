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
  IMPORTED_LOCATION "${SRC_DIR}/../build/liblinuxcnchal/liblinuxcnchal.so"
  INTERFACE_INCLUDE_DIRECTORIES "${SRC_DIR}/../liblinuxcnchal/"
)

# Link to libraries.
target_link_libraries(${PROJECT_NAME} PRIVATE linuxcnchal -fPIC)

# Set custom output name :
# set_property(TARGET  ${PROJECT} PROPERTY OUTPUT_NAME thename)

# Add verion nr. .so.0.0.0
set_target_properties(${PROJECT_NAME} PROPERTIES VERSION ${PROJECT_VERSION})

# Make install
install(TARGETS ${PROJECT} DESTINATION ${BUILD_DIR}/../../../lib)














