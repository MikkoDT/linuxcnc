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
include halrmt/CMakeFiles/halrmt.dir/depend.make

# Include the progress variables for this target.
include halrmt/CMakeFiles/halrmt.dir/progress.make

# Include the compile flags for this target's objects.
include halrmt/CMakeFiles/halrmt.dir/flags.make

halrmt/CMakeFiles/halrmt.dir/__/halrmt_src/halrmt.c.o: halrmt/CMakeFiles/halrmt.dir/flags.make
halrmt/CMakeFiles/halrmt.dir/__/halrmt_src/halrmt.c.o: ../halrmt_src/halrmt.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/user/linuxcnc/cmake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object halrmt/CMakeFiles/halrmt.dir/__/halrmt_src/halrmt.c.o"
	cd /home/user/linuxcnc/cmake/build/halrmt && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/halrmt.dir/__/halrmt_src/halrmt.c.o -c /home/user/linuxcnc/cmake/halrmt_src/halrmt.c

halrmt/CMakeFiles/halrmt.dir/__/halrmt_src/halrmt.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/halrmt.dir/__/halrmt_src/halrmt.c.i"
	cd /home/user/linuxcnc/cmake/build/halrmt && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/user/linuxcnc/cmake/halrmt_src/halrmt.c > CMakeFiles/halrmt.dir/__/halrmt_src/halrmt.c.i

halrmt/CMakeFiles/halrmt.dir/__/halrmt_src/halrmt.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/halrmt.dir/__/halrmt_src/halrmt.c.s"
	cd /home/user/linuxcnc/cmake/build/halrmt && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/user/linuxcnc/cmake/halrmt_src/halrmt.c -o CMakeFiles/halrmt.dir/__/halrmt_src/halrmt.c.s

# Object files for target halrmt
halrmt_OBJECTS = \
"CMakeFiles/halrmt.dir/__/halrmt_src/halrmt.c.o"

# External object files for target halrmt
halrmt_EXTERNAL_OBJECTS =

halrmt/halrmt-0: halrmt/CMakeFiles/halrmt.dir/__/halrmt_src/halrmt.c.o
halrmt/halrmt-0: halrmt/CMakeFiles/halrmt.dir/build.make
halrmt/halrmt-0: ../halrmt/../build/liblinuxcnchal/liblinuxcnchal.so
halrmt/halrmt-0: halrmt/CMakeFiles/halrmt.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/user/linuxcnc/cmake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable halrmt"
	cd /home/user/linuxcnc/cmake/build/halrmt && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/halrmt.dir/link.txt --verbose=$(VERBOSE)
	cd /home/user/linuxcnc/cmake/build/halrmt && $(CMAKE_COMMAND) -E cmake_symlink_executable halrmt-0 halrmt

halrmt/halrmt: halrmt/halrmt-0


# Rule to build all files generated by this target.
halrmt/CMakeFiles/halrmt.dir/build: halrmt/halrmt

.PHONY : halrmt/CMakeFiles/halrmt.dir/build

halrmt/CMakeFiles/halrmt.dir/clean:
	cd /home/user/linuxcnc/cmake/build/halrmt && $(CMAKE_COMMAND) -P CMakeFiles/halrmt.dir/cmake_clean.cmake
.PHONY : halrmt/CMakeFiles/halrmt.dir/clean

halrmt/CMakeFiles/halrmt.dir/depend:
	cd /home/user/linuxcnc/cmake/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/user/linuxcnc/cmake /home/user/linuxcnc/cmake/halrmt /home/user/linuxcnc/cmake/build /home/user/linuxcnc/cmake/build/halrmt /home/user/linuxcnc/cmake/build/halrmt/CMakeFiles/halrmt.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : halrmt/CMakeFiles/halrmt.dir/depend

