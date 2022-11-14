# Install script for directory: /home/user/linuxcnc

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Build")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/user/linuxcnc/build/src/rtapi/cmake_install.cmake")
  include("/home/user/linuxcnc/build/src/module_helper/cmake_install.cmake")
  include("/home/user/linuxcnc/build/src/hal/hal_lib/cmake_install.cmake")
  include("/home/user/linuxcnc/build/src/hal/linuxcnchal/cmake_install.cmake")
  include("/home/user/linuxcnc/build/src/libnml/cmake_install.cmake")
  include("/home/user/linuxcnc/build/src/libnml/inifile/cmake_install.cmake")
  include("/home/user/linuxcnc/build/src/emc/tooldata/cmake_install.cmake")
  include("/home/user/linuxcnc/build/src/emc/pythonplugin/cmake_install.cmake")
  include("/home/user/linuxcnc/build/src/emc/rs274ngc/cmake_install.cmake")
  include("/home/user/linuxcnc/build/src/libnml/posemath/cmake_install.cmake")
  include("/home/user/linuxcnc/build/src/emc/kinematics/python/lineardeltakins/cmake_install.cmake")
  include("/home/user/linuxcnc/build/src/emc/kinematics/python/rotarydeltakins/cmake_install.cmake")
  include("/home/user/linuxcnc/build/src/emc/canterp/cmake_install.cmake")
  include("/home/user/linuxcnc/build/src/emc/rs274ngc/python/cmake_install.cmake")
  include("/home/user/linuxcnc/build/src/hal/linuxcnchal/python/cmake_install.cmake")
  include("/home/user/linuxcnc/build/src/emc/nml_intf/cmake_install.cmake")
  include("/home/user/linuxcnc/build/src/emc/usr_intf/cmake_install.cmake")
  include("/home/user/linuxcnc/build/src/emc/usr_intf/axis/extensions/python/linuxcnc/cmake_install.cmake")
  include("/home/user/linuxcnc/build/src/emc/usr_intf/axis/extensions/python/togl/cmake_install.cmake")
  include("/home/user/linuxcnc/build/src/bin/milltask/cmake_install.cmake")
  include("/home/user/linuxcnc/build/src/hal/utils/hal/cmake_install.cmake")
  include("/home/user/linuxcnc/build/src/bin/halcmd/cmake_install.cmake")
  include("/home/user/linuxcnc/build/src/bin/halrmt/cmake_install.cmake")
  include("/home/user/linuxcnc/build/src/bin/halmeter/cmake_install.cmake")
  include("/home/user/linuxcnc/build/src/bin/halscope/cmake_install.cmake")
  include("/home/user/linuxcnc/build/src/bin/pci_write/cmake_install.cmake")
  include("/home/user/linuxcnc/build/src/bin/pci_read/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/home/user/linuxcnc/build/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
