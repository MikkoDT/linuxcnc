# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/user/linuxcnc/cmake

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/user/linuxcnc/cmake/build

# Include any dependencies generated for this target.
include linuxcncsrv/CMakeFiles/linuxcncsrv.dir/depend.make

# Include the progress variables for this target.
include linuxcncsrv/CMakeFiles/linuxcncsrv.dir/progress.make

# Include the compile flags for this target's objects.
include linuxcncsrv/CMakeFiles/linuxcncsrv.dir/flags.make

linuxcncsrv/CMakeFiles/linuxcncsrv.dir/__/emc_src/emcsvr.cc.o: linuxcncsrv/CMakeFiles/linuxcncsrv.dir/flags.make
linuxcncsrv/CMakeFiles/linuxcncsrv.dir/__/emc_src/emcsvr.cc.o: ../emc_src/emcsvr.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/user/linuxcnc/cmake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object linuxcncsrv/CMakeFiles/linuxcncsrv.dir/__/emc_src/emcsvr.cc.o"
	cd /home/user/linuxcnc/cmake/build/linuxcncsrv && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/linuxcncsrv.dir/__/emc_src/emcsvr.cc.o -c /home/user/linuxcnc/cmake/emc_src/emcsvr.cc

linuxcncsrv/CMakeFiles/linuxcncsrv.dir/__/emc_src/emcsvr.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/linuxcncsrv.dir/__/emc_src/emcsvr.cc.i"
	cd /home/user/linuxcnc/cmake/build/linuxcncsrv && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/user/linuxcnc/cmake/emc_src/emcsvr.cc > CMakeFiles/linuxcncsrv.dir/__/emc_src/emcsvr.cc.i

linuxcncsrv/CMakeFiles/linuxcncsrv.dir/__/emc_src/emcsvr.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/linuxcncsrv.dir/__/emc_src/emcsvr.cc.s"
	cd /home/user/linuxcnc/cmake/build/linuxcncsrv && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/user/linuxcnc/cmake/emc_src/emcsvr.cc -o CMakeFiles/linuxcncsrv.dir/__/emc_src/emcsvr.cc.s

# Object files for target linuxcncsrv
linuxcncsrv_OBJECTS = \
"CMakeFiles/linuxcncsrv.dir/__/emc_src/emcsvr.cc.o"

# External object files for target linuxcncsrv
linuxcncsrv_EXTERNAL_OBJECTS =

linuxcncsrv/linuxcncsrv: linuxcncsrv/CMakeFiles/linuxcncsrv.dir/__/emc_src/emcsvr.cc.o
linuxcncsrv/linuxcncsrv: linuxcncsrv/CMakeFiles/linuxcncsrv.dir/build.make
linuxcncsrv/linuxcncsrv: ../linuxcncsrv/../build/libnml/libnml.so
linuxcncsrv/linuxcncsrv: ../linuxcncsrv/../build/liblinuxcnchal/liblinuxcnchal.so
linuxcncsrv/linuxcncsrv: ../linuxcncsrv/../build/liblinuxcncini/liblinuxcncini.so
linuxcncsrv/linuxcncsrv: ../linuxcncsrv/../build/liblinuxcnc/liblinuxcnc.a
linuxcncsrv/linuxcncsrv: linuxcncsrv/CMakeFiles/linuxcncsrv.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/user/linuxcnc/cmake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable linuxcncsrv"
	cd /home/user/linuxcnc/cmake/build/linuxcncsrv && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/linuxcncsrv.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
linuxcncsrv/CMakeFiles/linuxcncsrv.dir/build: linuxcncsrv/linuxcncsrv

.PHONY : linuxcncsrv/CMakeFiles/linuxcncsrv.dir/build

linuxcncsrv/CMakeFiles/linuxcncsrv.dir/clean:
	cd /home/user/linuxcnc/cmake/build/linuxcncsrv && $(CMAKE_COMMAND) -P CMakeFiles/linuxcncsrv.dir/cmake_clean.cmake
.PHONY : linuxcncsrv/CMakeFiles/linuxcncsrv.dir/clean

linuxcncsrv/CMakeFiles/linuxcncsrv.dir/depend:
	cd /home/user/linuxcnc/cmake/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/user/linuxcnc/cmake /home/user/linuxcnc/cmake/linuxcncsrv /home/user/linuxcnc/cmake/build /home/user/linuxcnc/cmake/build/linuxcncsrv /home/user/linuxcnc/cmake/build/linuxcncsrv/CMakeFiles/linuxcncsrv.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : linuxcncsrv/CMakeFiles/linuxcncsrv.dir/depend

