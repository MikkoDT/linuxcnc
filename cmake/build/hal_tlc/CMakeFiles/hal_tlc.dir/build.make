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
include hal_tlc/CMakeFiles/hal_tlc.dir/depend.make

# Include the progress variables for this target.
include hal_tlc/CMakeFiles/hal_tlc.dir/progress.make

# Include the compile flags for this target's objects.
include hal_tlc/CMakeFiles/hal_tlc.dir/flags.make

hal_tlc/CMakeFiles/hal_tlc.dir/__/hal_tlc_src/halsh.c.o: hal_tlc/CMakeFiles/hal_tlc.dir/flags.make
hal_tlc/CMakeFiles/hal_tlc.dir/__/hal_tlc_src/halsh.c.o: ../hal_tlc_src/halsh.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/user/linuxcnc/cmake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object hal_tlc/CMakeFiles/hal_tlc.dir/__/hal_tlc_src/halsh.c.o"
	cd /home/user/linuxcnc/cmake/build/hal_tlc && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/hal_tlc.dir/__/hal_tlc_src/halsh.c.o -c /home/user/linuxcnc/cmake/hal_tlc_src/halsh.c

hal_tlc/CMakeFiles/hal_tlc.dir/__/hal_tlc_src/halsh.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/hal_tlc.dir/__/hal_tlc_src/halsh.c.i"
	cd /home/user/linuxcnc/cmake/build/hal_tlc && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/user/linuxcnc/cmake/hal_tlc_src/halsh.c > CMakeFiles/hal_tlc.dir/__/hal_tlc_src/halsh.c.i

hal_tlc/CMakeFiles/hal_tlc.dir/__/hal_tlc_src/halsh.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/hal_tlc.dir/__/hal_tlc_src/halsh.c.s"
	cd /home/user/linuxcnc/cmake/build/hal_tlc && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/user/linuxcnc/cmake/hal_tlc_src/halsh.c -o CMakeFiles/hal_tlc.dir/__/hal_tlc_src/halsh.c.s

# Object files for target hal_tlc
hal_tlc_OBJECTS = \
"CMakeFiles/hal_tlc.dir/__/hal_tlc_src/halsh.c.o"

# External object files for target hal_tlc
hal_tlc_EXTERNAL_OBJECTS =

hal_tlc/linuxcnc.so: hal_tlc/CMakeFiles/hal_tlc.dir/__/hal_tlc_src/halsh.c.o
hal_tlc/linuxcnc.so: hal_tlc/CMakeFiles/hal_tlc.dir/build.make
hal_tlc/linuxcnc.so: ../hal_tlc/../build/liblinuxcncini/liblinuxcncini.so
hal_tlc/linuxcnc.so: ../hal_tlc/../build/liblinuxcnchal/liblinuxcnchal.so
hal_tlc/linuxcnc.so: hal_tlc/CMakeFiles/hal_tlc.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/user/linuxcnc/cmake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C shared library linuxcnc.so"
	cd /home/user/linuxcnc/cmake/build/hal_tlc && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/hal_tlc.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
hal_tlc/CMakeFiles/hal_tlc.dir/build: hal_tlc/linuxcnc.so

.PHONY : hal_tlc/CMakeFiles/hal_tlc.dir/build

hal_tlc/CMakeFiles/hal_tlc.dir/clean:
	cd /home/user/linuxcnc/cmake/build/hal_tlc && $(CMAKE_COMMAND) -P CMakeFiles/hal_tlc.dir/cmake_clean.cmake
.PHONY : hal_tlc/CMakeFiles/hal_tlc.dir/clean

hal_tlc/CMakeFiles/hal_tlc.dir/depend:
	cd /home/user/linuxcnc/cmake/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/user/linuxcnc/cmake /home/user/linuxcnc/cmake/hal_tlc /home/user/linuxcnc/cmake/build /home/user/linuxcnc/cmake/build/hal_tlc /home/user/linuxcnc/cmake/build/hal_tlc/CMakeFiles/hal_tlc.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : hal_tlc/CMakeFiles/hal_tlc.dir/depend
