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
include motion_logger/CMakeFiles/motion-logger.dir/depend.make

# Include the progress variables for this target.
include motion_logger/CMakeFiles/motion-logger.dir/progress.make

# Include the compile flags for this target's objects.
include motion_logger/CMakeFiles/motion-logger.dir/flags.make

motion_logger/CMakeFiles/motion-logger.dir/__/motion_src/motion-logger.c.o: motion_logger/CMakeFiles/motion-logger.dir/flags.make
motion_logger/CMakeFiles/motion-logger.dir/__/motion_src/motion-logger.c.o: ../motion_src/motion-logger.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/user/linuxcnc/cmake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object motion_logger/CMakeFiles/motion-logger.dir/__/motion_src/motion-logger.c.o"
	cd /home/user/linuxcnc/cmake/build/motion_logger && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/motion-logger.dir/__/motion_src/motion-logger.c.o -c /home/user/linuxcnc/cmake/motion_src/motion-logger.c

motion_logger/CMakeFiles/motion-logger.dir/__/motion_src/motion-logger.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/motion-logger.dir/__/motion_src/motion-logger.c.i"
	cd /home/user/linuxcnc/cmake/build/motion_logger && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/user/linuxcnc/cmake/motion_src/motion-logger.c > CMakeFiles/motion-logger.dir/__/motion_src/motion-logger.c.i

motion_logger/CMakeFiles/motion-logger.dir/__/motion_src/motion-logger.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/motion-logger.dir/__/motion_src/motion-logger.c.s"
	cd /home/user/linuxcnc/cmake/build/motion_logger && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/user/linuxcnc/cmake/motion_src/motion-logger.c -o CMakeFiles/motion-logger.dir/__/motion_src/motion-logger.c.s

motion_logger/CMakeFiles/motion-logger.dir/__/emc_src/axis.c.o: motion_logger/CMakeFiles/motion-logger.dir/flags.make
motion_logger/CMakeFiles/motion-logger.dir/__/emc_src/axis.c.o: ../emc_src/axis.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/user/linuxcnc/cmake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object motion_logger/CMakeFiles/motion-logger.dir/__/emc_src/axis.c.o"
	cd /home/user/linuxcnc/cmake/build/motion_logger && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/motion-logger.dir/__/emc_src/axis.c.o -c /home/user/linuxcnc/cmake/emc_src/axis.c

motion_logger/CMakeFiles/motion-logger.dir/__/emc_src/axis.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/motion-logger.dir/__/emc_src/axis.c.i"
	cd /home/user/linuxcnc/cmake/build/motion_logger && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/user/linuxcnc/cmake/emc_src/axis.c > CMakeFiles/motion-logger.dir/__/emc_src/axis.c.i

motion_logger/CMakeFiles/motion-logger.dir/__/emc_src/axis.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/motion-logger.dir/__/emc_src/axis.c.s"
	cd /home/user/linuxcnc/cmake/build/motion_logger && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/user/linuxcnc/cmake/emc_src/axis.c -o CMakeFiles/motion-logger.dir/__/emc_src/axis.c.s

motion_logger/CMakeFiles/motion-logger.dir/__/emc_src/simple_tp.c.o: motion_logger/CMakeFiles/motion-logger.dir/flags.make
motion_logger/CMakeFiles/motion-logger.dir/__/emc_src/simple_tp.c.o: ../emc_src/simple_tp.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/user/linuxcnc/cmake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object motion_logger/CMakeFiles/motion-logger.dir/__/emc_src/simple_tp.c.o"
	cd /home/user/linuxcnc/cmake/build/motion_logger && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/motion-logger.dir/__/emc_src/simple_tp.c.o -c /home/user/linuxcnc/cmake/emc_src/simple_tp.c

motion_logger/CMakeFiles/motion-logger.dir/__/emc_src/simple_tp.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/motion-logger.dir/__/emc_src/simple_tp.c.i"
	cd /home/user/linuxcnc/cmake/build/motion_logger && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/user/linuxcnc/cmake/emc_src/simple_tp.c > CMakeFiles/motion-logger.dir/__/emc_src/simple_tp.c.i

motion_logger/CMakeFiles/motion-logger.dir/__/emc_src/simple_tp.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/motion-logger.dir/__/emc_src/simple_tp.c.s"
	cd /home/user/linuxcnc/cmake/build/motion_logger && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/user/linuxcnc/cmake/emc_src/simple_tp.c -o CMakeFiles/motion-logger.dir/__/emc_src/simple_tp.c.s

# Object files for target motion-logger
motion__logger_OBJECTS = \
"CMakeFiles/motion-logger.dir/__/motion_src/motion-logger.c.o" \
"CMakeFiles/motion-logger.dir/__/emc_src/axis.c.o" \
"CMakeFiles/motion-logger.dir/__/emc_src/simple_tp.c.o"

# External object files for target motion-logger
motion__logger_EXTERNAL_OBJECTS =

motion_logger/motion-logger: motion_logger/CMakeFiles/motion-logger.dir/__/motion_src/motion-logger.c.o
motion_logger/motion-logger: motion_logger/CMakeFiles/motion-logger.dir/__/emc_src/axis.c.o
motion_logger/motion-logger: motion_logger/CMakeFiles/motion-logger.dir/__/emc_src/simple_tp.c.o
motion_logger/motion-logger: motion_logger/CMakeFiles/motion-logger.dir/build.make
motion_logger/motion-logger: ../motion_logger/../build/libnml/libnml.so
motion_logger/motion-logger: ../motion_logger/../build/liblinuxcnchal/liblinuxcnchal.so
motion_logger/motion-logger: motion_logger/CMakeFiles/motion-logger.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/user/linuxcnc/cmake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable motion-logger"
	cd /home/user/linuxcnc/cmake/build/motion_logger && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/motion-logger.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
motion_logger/CMakeFiles/motion-logger.dir/build: motion_logger/motion-logger

.PHONY : motion_logger/CMakeFiles/motion-logger.dir/build

motion_logger/CMakeFiles/motion-logger.dir/clean:
	cd /home/user/linuxcnc/cmake/build/motion_logger && $(CMAKE_COMMAND) -P CMakeFiles/motion-logger.dir/cmake_clean.cmake
.PHONY : motion_logger/CMakeFiles/motion-logger.dir/clean

motion_logger/CMakeFiles/motion-logger.dir/depend:
	cd /home/user/linuxcnc/cmake/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/user/linuxcnc/cmake /home/user/linuxcnc/cmake/motion_logger /home/user/linuxcnc/cmake/build /home/user/linuxcnc/cmake/build/motion_logger /home/user/linuxcnc/cmake/build/motion_logger/CMakeFiles/motion-logger.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : motion_logger/CMakeFiles/motion-logger.dir/depend

