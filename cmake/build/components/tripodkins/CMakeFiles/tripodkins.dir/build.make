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
include components/tripodkins/CMakeFiles/tripodkins.dir/depend.make

# Include the progress variables for this target.
include components/tripodkins/CMakeFiles/tripodkins.dir/progress.make

# Include the compile flags for this target's objects.
include components/tripodkins/CMakeFiles/tripodkins.dir/flags.make

components/tripodkins/CMakeFiles/tripodkins.dir/__/tripodkins_src/tripodkins.c.o: components/tripodkins/CMakeFiles/tripodkins.dir/flags.make
components/tripodkins/CMakeFiles/tripodkins.dir/__/tripodkins_src/tripodkins.c.o: ../components/tripodkins_src/tripodkins.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/user/linuxcnc/cmake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object components/tripodkins/CMakeFiles/tripodkins.dir/__/tripodkins_src/tripodkins.c.o"
	cd /home/user/linuxcnc/cmake/build/components/tripodkins && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/tripodkins.dir/__/tripodkins_src/tripodkins.c.o -c /home/user/linuxcnc/cmake/components/tripodkins_src/tripodkins.c

components/tripodkins/CMakeFiles/tripodkins.dir/__/tripodkins_src/tripodkins.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/tripodkins.dir/__/tripodkins_src/tripodkins.c.i"
	cd /home/user/linuxcnc/cmake/build/components/tripodkins && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/user/linuxcnc/cmake/components/tripodkins_src/tripodkins.c > CMakeFiles/tripodkins.dir/__/tripodkins_src/tripodkins.c.i

components/tripodkins/CMakeFiles/tripodkins.dir/__/tripodkins_src/tripodkins.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/tripodkins.dir/__/tripodkins_src/tripodkins.c.s"
	cd /home/user/linuxcnc/cmake/build/components/tripodkins && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/user/linuxcnc/cmake/components/tripodkins_src/tripodkins.c -o CMakeFiles/tripodkins.dir/__/tripodkins_src/tripodkins.c.s

# Object files for target tripodkins
tripodkins_OBJECTS = \
"CMakeFiles/tripodkins.dir/__/tripodkins_src/tripodkins.c.o"

# External object files for target tripodkins
tripodkins_EXTERNAL_OBJECTS =

components/tripodkins/tripodkins.so: components/tripodkins/CMakeFiles/tripodkins.dir/__/tripodkins_src/tripodkins.c.o
components/tripodkins/tripodkins.so: components/tripodkins/CMakeFiles/tripodkins.dir/build.make
components/tripodkins/tripodkins.so: ../components/tripodkins/../../build/liblinuxcnchal/liblinuxcnchal.so
components/tripodkins/tripodkins.so: components/tripodkins/CMakeFiles/tripodkins.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/user/linuxcnc/cmake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C shared library tripodkins.so"
	cd /home/user/linuxcnc/cmake/build/components/tripodkins && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tripodkins.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
components/tripodkins/CMakeFiles/tripodkins.dir/build: components/tripodkins/tripodkins.so

.PHONY : components/tripodkins/CMakeFiles/tripodkins.dir/build

components/tripodkins/CMakeFiles/tripodkins.dir/clean:
	cd /home/user/linuxcnc/cmake/build/components/tripodkins && $(CMAKE_COMMAND) -P CMakeFiles/tripodkins.dir/cmake_clean.cmake
.PHONY : components/tripodkins/CMakeFiles/tripodkins.dir/clean

components/tripodkins/CMakeFiles/tripodkins.dir/depend:
	cd /home/user/linuxcnc/cmake/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/user/linuxcnc/cmake /home/user/linuxcnc/cmake/components/tripodkins /home/user/linuxcnc/cmake/build /home/user/linuxcnc/cmake/build/components/tripodkins /home/user/linuxcnc/cmake/build/components/tripodkins/CMakeFiles/tripodkins.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : components/tripodkins/CMakeFiles/tripodkins.dir/depend

