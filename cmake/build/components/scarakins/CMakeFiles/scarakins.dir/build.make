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
include components/scarakins/CMakeFiles/scarakins.dir/depend.make

# Include the progress variables for this target.
include components/scarakins/CMakeFiles/scarakins.dir/progress.make

# Include the compile flags for this target's objects.
include components/scarakins/CMakeFiles/scarakins.dir/flags.make

components/scarakins/CMakeFiles/scarakins.dir/__/scarakins_src/scarakins.c.o: components/scarakins/CMakeFiles/scarakins.dir/flags.make
components/scarakins/CMakeFiles/scarakins.dir/__/scarakins_src/scarakins.c.o: ../components/scarakins_src/scarakins.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/user/linuxcnc/cmake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object components/scarakins/CMakeFiles/scarakins.dir/__/scarakins_src/scarakins.c.o"
	cd /home/user/linuxcnc/cmake/build/components/scarakins && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/scarakins.dir/__/scarakins_src/scarakins.c.o -c /home/user/linuxcnc/cmake/components/scarakins_src/scarakins.c

components/scarakins/CMakeFiles/scarakins.dir/__/scarakins_src/scarakins.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/scarakins.dir/__/scarakins_src/scarakins.c.i"
	cd /home/user/linuxcnc/cmake/build/components/scarakins && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/user/linuxcnc/cmake/components/scarakins_src/scarakins.c > CMakeFiles/scarakins.dir/__/scarakins_src/scarakins.c.i

components/scarakins/CMakeFiles/scarakins.dir/__/scarakins_src/scarakins.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/scarakins.dir/__/scarakins_src/scarakins.c.s"
	cd /home/user/linuxcnc/cmake/build/components/scarakins && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/user/linuxcnc/cmake/components/scarakins_src/scarakins.c -o CMakeFiles/scarakins.dir/__/scarakins_src/scarakins.c.s

# Object files for target scarakins
scarakins_OBJECTS = \
"CMakeFiles/scarakins.dir/__/scarakins_src/scarakins.c.o"

# External object files for target scarakins
scarakins_EXTERNAL_OBJECTS =

components/scarakins/scarakins.so: components/scarakins/CMakeFiles/scarakins.dir/__/scarakins_src/scarakins.c.o
components/scarakins/scarakins.so: components/scarakins/CMakeFiles/scarakins.dir/build.make
components/scarakins/scarakins.so: ../components/scarakins/../../build/liblinuxcnchal/liblinuxcnchal.so
components/scarakins/scarakins.so: components/scarakins/CMakeFiles/scarakins.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/user/linuxcnc/cmake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C shared library scarakins.so"
	cd /home/user/linuxcnc/cmake/build/components/scarakins && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/scarakins.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
components/scarakins/CMakeFiles/scarakins.dir/build: components/scarakins/scarakins.so

.PHONY : components/scarakins/CMakeFiles/scarakins.dir/build

components/scarakins/CMakeFiles/scarakins.dir/clean:
	cd /home/user/linuxcnc/cmake/build/components/scarakins && $(CMAKE_COMMAND) -P CMakeFiles/scarakins.dir/cmake_clean.cmake
.PHONY : components/scarakins/CMakeFiles/scarakins.dir/clean

components/scarakins/CMakeFiles/scarakins.dir/depend:
	cd /home/user/linuxcnc/cmake/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/user/linuxcnc/cmake /home/user/linuxcnc/cmake/components/scarakins /home/user/linuxcnc/cmake/build /home/user/linuxcnc/cmake/build/components/scarakins /home/user/linuxcnc/cmake/build/components/scarakins/CMakeFiles/scarakins.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : components/scarakins/CMakeFiles/scarakins.dir/depend
