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
include linuxcnc_py/CMakeFiles/linuxcnc_py.dir/depend.make

# Include the progress variables for this target.
include linuxcnc_py/CMakeFiles/linuxcnc_py.dir/progress.make

# Include the compile flags for this target's objects.
include linuxcnc_py/CMakeFiles/linuxcnc_py.dir/flags.make

linuxcnc_py/CMakeFiles/linuxcnc_py.dir/__/linuxcnc_py_src/emcmodule.cc.o: linuxcnc_py/CMakeFiles/linuxcnc_py.dir/flags.make
linuxcnc_py/CMakeFiles/linuxcnc_py.dir/__/linuxcnc_py_src/emcmodule.cc.o: ../linuxcnc_py_src/emcmodule.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/user/linuxcnc/cmake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object linuxcnc_py/CMakeFiles/linuxcnc_py.dir/__/linuxcnc_py_src/emcmodule.cc.o"
	cd /home/user/linuxcnc/cmake/build/linuxcnc_py && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/linuxcnc_py.dir/__/linuxcnc_py_src/emcmodule.cc.o -c /home/user/linuxcnc/cmake/linuxcnc_py_src/emcmodule.cc

linuxcnc_py/CMakeFiles/linuxcnc_py.dir/__/linuxcnc_py_src/emcmodule.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/linuxcnc_py.dir/__/linuxcnc_py_src/emcmodule.cc.i"
	cd /home/user/linuxcnc/cmake/build/linuxcnc_py && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/user/linuxcnc/cmake/linuxcnc_py_src/emcmodule.cc > CMakeFiles/linuxcnc_py.dir/__/linuxcnc_py_src/emcmodule.cc.i

linuxcnc_py/CMakeFiles/linuxcnc_py.dir/__/linuxcnc_py_src/emcmodule.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/linuxcnc_py.dir/__/linuxcnc_py_src/emcmodule.cc.s"
	cd /home/user/linuxcnc/cmake/build/linuxcnc_py && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/user/linuxcnc/cmake/linuxcnc_py_src/emcmodule.cc -o CMakeFiles/linuxcnc_py.dir/__/linuxcnc_py_src/emcmodule.cc.s

# Object files for target linuxcnc_py
linuxcnc_py_OBJECTS = \
"CMakeFiles/linuxcnc_py.dir/__/linuxcnc_py_src/emcmodule.cc.o"

# External object files for target linuxcnc_py
linuxcnc_py_EXTERNAL_OBJECTS =

linuxcnc_py/linuxcnc_py.so.0: linuxcnc_py/CMakeFiles/linuxcnc_py.dir/__/linuxcnc_py_src/emcmodule.cc.o
linuxcnc_py/linuxcnc_py.so.0: linuxcnc_py/CMakeFiles/linuxcnc_py.dir/build.make
linuxcnc_py/linuxcnc_py.so.0: ../linuxcnc_py/../build/liblinuxcncini/liblinuxcncini.so
linuxcnc_py/linuxcnc_py.so.0: ../linuxcnc_py/../build/libnml/libnml.so
linuxcnc_py/linuxcnc_py.so.0: ../linuxcnc_py/../build/liblinuxcnc/liblinuxcnc.a
linuxcnc_py/linuxcnc_py.so.0: ../linuxcnc_py/../build/libtooldata/libtooldata.so
linuxcnc_py/linuxcnc_py.so.0: linuxcnc_py/CMakeFiles/linuxcnc_py.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/user/linuxcnc/cmake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library linuxcnc_py.so"
	cd /home/user/linuxcnc/cmake/build/linuxcnc_py && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/linuxcnc_py.dir/link.txt --verbose=$(VERBOSE)
	cd /home/user/linuxcnc/cmake/build/linuxcnc_py && $(CMAKE_COMMAND) -E cmake_symlink_library linuxcnc_py.so.0 linuxcnc_py.so.0 linuxcnc_py.so

linuxcnc_py/linuxcnc_py.so: linuxcnc_py/linuxcnc_py.so.0
	@$(CMAKE_COMMAND) -E touch_nocreate linuxcnc_py/linuxcnc_py.so

# Rule to build all files generated by this target.
linuxcnc_py/CMakeFiles/linuxcnc_py.dir/build: linuxcnc_py/linuxcnc_py.so

.PHONY : linuxcnc_py/CMakeFiles/linuxcnc_py.dir/build

linuxcnc_py/CMakeFiles/linuxcnc_py.dir/clean:
	cd /home/user/linuxcnc/cmake/build/linuxcnc_py && $(CMAKE_COMMAND) -P CMakeFiles/linuxcnc_py.dir/cmake_clean.cmake
.PHONY : linuxcnc_py/CMakeFiles/linuxcnc_py.dir/clean

linuxcnc_py/CMakeFiles/linuxcnc_py.dir/depend:
	cd /home/user/linuxcnc/cmake/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/user/linuxcnc/cmake /home/user/linuxcnc/cmake/linuxcnc_py /home/user/linuxcnc/cmake/build /home/user/linuxcnc/cmake/build/linuxcnc_py /home/user/linuxcnc/cmake/build/linuxcnc_py/CMakeFiles/linuxcnc_py.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : linuxcnc_py/CMakeFiles/linuxcnc_py.dir/depend

