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
include components/test/CMakeFiles/test.dir/depend.make

# Include the progress variables for this target.
include components/test/CMakeFiles/test.dir/progress.make

# Include the compile flags for this target's objects.
include components/test/CMakeFiles/test.dir/flags.make

components/test/CMakeFiles/test.dir/__/test_src/test.c.o: components/test/CMakeFiles/test.dir/flags.make
components/test/CMakeFiles/test.dir/__/test_src/test.c.o: ../components/test_src/test.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/user/linuxcnc/cmake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object components/test/CMakeFiles/test.dir/__/test_src/test.c.o"
	cd /home/user/linuxcnc/cmake/build/components/test && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/test.dir/__/test_src/test.c.o -c /home/user/linuxcnc/cmake/components/test_src/test.c

components/test/CMakeFiles/test.dir/__/test_src/test.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test.dir/__/test_src/test.c.i"
	cd /home/user/linuxcnc/cmake/build/components/test && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/user/linuxcnc/cmake/components/test_src/test.c > CMakeFiles/test.dir/__/test_src/test.c.i

components/test/CMakeFiles/test.dir/__/test_src/test.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test.dir/__/test_src/test.c.s"
	cd /home/user/linuxcnc/cmake/build/components/test && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/user/linuxcnc/cmake/components/test_src/test.c -o CMakeFiles/test.dir/__/test_src/test.c.s

# Object files for target test
test_OBJECTS = \
"CMakeFiles/test.dir/__/test_src/test.c.o"

# External object files for target test
test_EXTERNAL_OBJECTS =

components/test/test.so: components/test/CMakeFiles/test.dir/__/test_src/test.c.o
components/test/test.so: components/test/CMakeFiles/test.dir/build.make
components/test/test.so: ../components/test/../../build/liblinuxcnchal/liblinuxcnchal.so
components/test/test.so: components/test/CMakeFiles/test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/user/linuxcnc/cmake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C shared library test.so"
	cd /home/user/linuxcnc/cmake/build/components/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
components/test/CMakeFiles/test.dir/build: components/test/test.so

.PHONY : components/test/CMakeFiles/test.dir/build

components/test/CMakeFiles/test.dir/clean:
	cd /home/user/linuxcnc/cmake/build/components/test && $(CMAKE_COMMAND) -P CMakeFiles/test.dir/cmake_clean.cmake
.PHONY : components/test/CMakeFiles/test.dir/clean

components/test/CMakeFiles/test.dir/depend:
	cd /home/user/linuxcnc/cmake/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/user/linuxcnc/cmake /home/user/linuxcnc/cmake/components/test /home/user/linuxcnc/cmake/build /home/user/linuxcnc/cmake/build/components/test /home/user/linuxcnc/cmake/build/components/test/CMakeFiles/test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : components/test/CMakeFiles/test.dir/depend

