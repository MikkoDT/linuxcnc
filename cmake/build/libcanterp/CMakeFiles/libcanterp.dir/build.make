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
include libcanterp/CMakeFiles/libcanterp.dir/depend.make

# Include the progress variables for this target.
include libcanterp/CMakeFiles/libcanterp.dir/progress.make

# Include the compile flags for this target's objects.
include libcanterp/CMakeFiles/libcanterp.dir/flags.make

libcanterp/CMakeFiles/libcanterp.dir/__/libcanterp_src/canterp.cc.o: libcanterp/CMakeFiles/libcanterp.dir/flags.make
libcanterp/CMakeFiles/libcanterp.dir/__/libcanterp_src/canterp.cc.o: ../libcanterp_src/canterp.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/user/linuxcnc/cmake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object libcanterp/CMakeFiles/libcanterp.dir/__/libcanterp_src/canterp.cc.o"
	cd /home/user/linuxcnc/cmake/build/libcanterp && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/libcanterp.dir/__/libcanterp_src/canterp.cc.o -c /home/user/linuxcnc/cmake/libcanterp_src/canterp.cc

libcanterp/CMakeFiles/libcanterp.dir/__/libcanterp_src/canterp.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libcanterp.dir/__/libcanterp_src/canterp.cc.i"
	cd /home/user/linuxcnc/cmake/build/libcanterp && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/user/linuxcnc/cmake/libcanterp_src/canterp.cc > CMakeFiles/libcanterp.dir/__/libcanterp_src/canterp.cc.i

libcanterp/CMakeFiles/libcanterp.dir/__/libcanterp_src/canterp.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libcanterp.dir/__/libcanterp_src/canterp.cc.s"
	cd /home/user/linuxcnc/cmake/build/libcanterp && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/user/linuxcnc/cmake/libcanterp_src/canterp.cc -o CMakeFiles/libcanterp.dir/__/libcanterp_src/canterp.cc.s

# Object files for target libcanterp
libcanterp_OBJECTS = \
"CMakeFiles/libcanterp.dir/__/libcanterp_src/canterp.cc.o"

# External object files for target libcanterp
libcanterp_EXTERNAL_OBJECTS =

libcanterp/libcanterp.so.0: libcanterp/CMakeFiles/libcanterp.dir/__/libcanterp_src/canterp.cc.o
libcanterp/libcanterp.so.0: libcanterp/CMakeFiles/libcanterp.dir/build.make
libcanterp/libcanterp.so.0: ../libcanterp/../build/liblinuxcncini/liblinuxcncini.so
libcanterp/libcanterp.so.0: ../libcanterp/../build/librs274/librs274.so
libcanterp/libcanterp.so.0: libcanterp/CMakeFiles/libcanterp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/user/linuxcnc/cmake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library libcanterp.so"
	cd /home/user/linuxcnc/cmake/build/libcanterp && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/libcanterp.dir/link.txt --verbose=$(VERBOSE)
	cd /home/user/linuxcnc/cmake/build/libcanterp && $(CMAKE_COMMAND) -E cmake_symlink_library libcanterp.so.0 libcanterp.so.0 libcanterp.so

libcanterp/libcanterp.so: libcanterp/libcanterp.so.0
	@$(CMAKE_COMMAND) -E touch_nocreate libcanterp/libcanterp.so

# Rule to build all files generated by this target.
libcanterp/CMakeFiles/libcanterp.dir/build: libcanterp/libcanterp.so

.PHONY : libcanterp/CMakeFiles/libcanterp.dir/build

libcanterp/CMakeFiles/libcanterp.dir/clean:
	cd /home/user/linuxcnc/cmake/build/libcanterp && $(CMAKE_COMMAND) -P CMakeFiles/libcanterp.dir/cmake_clean.cmake
.PHONY : libcanterp/CMakeFiles/libcanterp.dir/clean

libcanterp/CMakeFiles/libcanterp.dir/depend:
	cd /home/user/linuxcnc/cmake/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/user/linuxcnc/cmake /home/user/linuxcnc/cmake/libcanterp /home/user/linuxcnc/cmake/build /home/user/linuxcnc/cmake/build/libcanterp /home/user/linuxcnc/cmake/build/libcanterp/CMakeFiles/libcanterp.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : libcanterp/CMakeFiles/libcanterp.dir/depend

