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
CMAKE_SOURCE_DIR = /home/user/linuxcnc/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/user/linuxcnc/src/build

# Include any dependencies generated for this target.
include CMakeFiles/gs2_vfd.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/gs2_vfd.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/gs2_vfd.dir/flags.make

CMakeFiles/gs2_vfd.dir/hal/user_comps/gs2_vfd.c.o: CMakeFiles/gs2_vfd.dir/flags.make
CMakeFiles/gs2_vfd.dir/hal/user_comps/gs2_vfd.c.o: ../hal/user_comps/gs2_vfd.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/user/linuxcnc/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/gs2_vfd.dir/hal/user_comps/gs2_vfd.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/gs2_vfd.dir/hal/user_comps/gs2_vfd.c.o -c /home/user/linuxcnc/src/hal/user_comps/gs2_vfd.c

CMakeFiles/gs2_vfd.dir/hal/user_comps/gs2_vfd.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/gs2_vfd.dir/hal/user_comps/gs2_vfd.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/user/linuxcnc/src/hal/user_comps/gs2_vfd.c > CMakeFiles/gs2_vfd.dir/hal/user_comps/gs2_vfd.c.i

CMakeFiles/gs2_vfd.dir/hal/user_comps/gs2_vfd.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/gs2_vfd.dir/hal/user_comps/gs2_vfd.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/user/linuxcnc/src/hal/user_comps/gs2_vfd.c -o CMakeFiles/gs2_vfd.dir/hal/user_comps/gs2_vfd.c.s

# Object files for target gs2_vfd
gs2_vfd_OBJECTS = \
"CMakeFiles/gs2_vfd.dir/hal/user_comps/gs2_vfd.c.o"

# External object files for target gs2_vfd
gs2_vfd_EXTERNAL_OBJECTS =

gs2_vfd.so: CMakeFiles/gs2_vfd.dir/hal/user_comps/gs2_vfd.c.o
gs2_vfd.so: CMakeFiles/gs2_vfd.dir/build.make
gs2_vfd.so: CMakeFiles/gs2_vfd.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/user/linuxcnc/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C shared library gs2_vfd.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gs2_vfd.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/gs2_vfd.dir/build: gs2_vfd.so

.PHONY : CMakeFiles/gs2_vfd.dir/build

CMakeFiles/gs2_vfd.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/gs2_vfd.dir/cmake_clean.cmake
.PHONY : CMakeFiles/gs2_vfd.dir/clean

CMakeFiles/gs2_vfd.dir/depend:
	cd /home/user/linuxcnc/src/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/user/linuxcnc/src /home/user/linuxcnc/src /home/user/linuxcnc/src/build /home/user/linuxcnc/src/build /home/user/linuxcnc/src/build/CMakeFiles/gs2_vfd.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/gs2_vfd.dir/depend
