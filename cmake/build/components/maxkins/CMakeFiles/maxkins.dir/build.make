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
include components/maxkins/CMakeFiles/maxkins.dir/depend.make

# Include the progress variables for this target.
include components/maxkins/CMakeFiles/maxkins.dir/progress.make

# Include the compile flags for this target's objects.
include components/maxkins/CMakeFiles/maxkins.dir/flags.make

components/maxkins/CMakeFiles/maxkins.dir/__/maxkins_src/maxkins.c.o: components/maxkins/CMakeFiles/maxkins.dir/flags.make
components/maxkins/CMakeFiles/maxkins.dir/__/maxkins_src/maxkins.c.o: ../components/maxkins_src/maxkins.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/user/linuxcnc/cmake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object components/maxkins/CMakeFiles/maxkins.dir/__/maxkins_src/maxkins.c.o"
	cd /home/user/linuxcnc/cmake/build/components/maxkins && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/maxkins.dir/__/maxkins_src/maxkins.c.o -c /home/user/linuxcnc/cmake/components/maxkins_src/maxkins.c

components/maxkins/CMakeFiles/maxkins.dir/__/maxkins_src/maxkins.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/maxkins.dir/__/maxkins_src/maxkins.c.i"
	cd /home/user/linuxcnc/cmake/build/components/maxkins && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/user/linuxcnc/cmake/components/maxkins_src/maxkins.c > CMakeFiles/maxkins.dir/__/maxkins_src/maxkins.c.i

components/maxkins/CMakeFiles/maxkins.dir/__/maxkins_src/maxkins.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/maxkins.dir/__/maxkins_src/maxkins.c.s"
	cd /home/user/linuxcnc/cmake/build/components/maxkins && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/user/linuxcnc/cmake/components/maxkins_src/maxkins.c -o CMakeFiles/maxkins.dir/__/maxkins_src/maxkins.c.s

# Object files for target maxkins
maxkins_OBJECTS = \
"CMakeFiles/maxkins.dir/__/maxkins_src/maxkins.c.o"

# External object files for target maxkins
maxkins_EXTERNAL_OBJECTS =

components/maxkins/maxkins.so: components/maxkins/CMakeFiles/maxkins.dir/__/maxkins_src/maxkins.c.o
components/maxkins/maxkins.so: components/maxkins/CMakeFiles/maxkins.dir/build.make
components/maxkins/maxkins.so: ../components/maxkins/../../build/liblinuxcnchal/liblinuxcnchal.so
components/maxkins/maxkins.so: components/maxkins/CMakeFiles/maxkins.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/user/linuxcnc/cmake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C shared library maxkins.so"
	cd /home/user/linuxcnc/cmake/build/components/maxkins && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/maxkins.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
components/maxkins/CMakeFiles/maxkins.dir/build: components/maxkins/maxkins.so

.PHONY : components/maxkins/CMakeFiles/maxkins.dir/build

components/maxkins/CMakeFiles/maxkins.dir/clean:
	cd /home/user/linuxcnc/cmake/build/components/maxkins && $(CMAKE_COMMAND) -P CMakeFiles/maxkins.dir/cmake_clean.cmake
.PHONY : components/maxkins/CMakeFiles/maxkins.dir/clean

components/maxkins/CMakeFiles/maxkins.dir/depend:
	cd /home/user/linuxcnc/cmake/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/user/linuxcnc/cmake /home/user/linuxcnc/cmake/components/maxkins /home/user/linuxcnc/cmake/build /home/user/linuxcnc/cmake/build/components/maxkins /home/user/linuxcnc/cmake/build/components/maxkins/CMakeFiles/maxkins.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : components/maxkins/CMakeFiles/maxkins.dir/depend
