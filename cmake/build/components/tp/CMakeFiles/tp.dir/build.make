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
include components/tp/CMakeFiles/tp.dir/depend.make

# Include the progress variables for this target.
include components/tp/CMakeFiles/tp.dir/progress.make

# Include the compile flags for this target's objects.
include components/tp/CMakeFiles/tp.dir/flags.make

components/tp/CMakeFiles/tp.dir/__/tp_src/tp.c.o: components/tp/CMakeFiles/tp.dir/flags.make
components/tp/CMakeFiles/tp.dir/__/tp_src/tp.c.o: ../components/tp_src/tp.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/user/linuxcnc/cmake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object components/tp/CMakeFiles/tp.dir/__/tp_src/tp.c.o"
	cd /home/user/linuxcnc/cmake/build/components/tp && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/tp.dir/__/tp_src/tp.c.o -c /home/user/linuxcnc/cmake/components/tp_src/tp.c

components/tp/CMakeFiles/tp.dir/__/tp_src/tp.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/tp.dir/__/tp_src/tp.c.i"
	cd /home/user/linuxcnc/cmake/build/components/tp && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/user/linuxcnc/cmake/components/tp_src/tp.c > CMakeFiles/tp.dir/__/tp_src/tp.c.i

components/tp/CMakeFiles/tp.dir/__/tp_src/tp.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/tp.dir/__/tp_src/tp.c.s"
	cd /home/user/linuxcnc/cmake/build/components/tp && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/user/linuxcnc/cmake/components/tp_src/tp.c -o CMakeFiles/tp.dir/__/tp_src/tp.c.s

# Object files for target tp
tp_OBJECTS = \
"CMakeFiles/tp.dir/__/tp_src/tp.c.o"

# External object files for target tp
tp_EXTERNAL_OBJECTS =

components/tp/tp.so: components/tp/CMakeFiles/tp.dir/__/tp_src/tp.c.o
components/tp/tp.so: components/tp/CMakeFiles/tp.dir/build.make
components/tp/tp.so: ../components/tp/../../build/liblinuxcnchal/liblinuxcnchal.so
components/tp/tp.so: components/tp/CMakeFiles/tp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/user/linuxcnc/cmake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C shared library tp.so"
	cd /home/user/linuxcnc/cmake/build/components/tp && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tp.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
components/tp/CMakeFiles/tp.dir/build: components/tp/tp.so

.PHONY : components/tp/CMakeFiles/tp.dir/build

components/tp/CMakeFiles/tp.dir/clean:
	cd /home/user/linuxcnc/cmake/build/components/tp && $(CMAKE_COMMAND) -P CMakeFiles/tp.dir/cmake_clean.cmake
.PHONY : components/tp/CMakeFiles/tp.dir/clean

components/tp/CMakeFiles/tp.dir/depend:
	cd /home/user/linuxcnc/cmake/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/user/linuxcnc/cmake /home/user/linuxcnc/cmake/components/tp /home/user/linuxcnc/cmake/build /home/user/linuxcnc/cmake/build/components/tp /home/user/linuxcnc/cmake/build/components/tp/CMakeFiles/tp.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : components/tp/CMakeFiles/tp.dir/depend

