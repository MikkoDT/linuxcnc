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
include components/sc_tp/CMakeFiles/sc_tp.dir/depend.make

# Include the progress variables for this target.
include components/sc_tp/CMakeFiles/sc_tp.dir/progress.make

# Include the compile flags for this target's objects.
include components/sc_tp/CMakeFiles/sc_tp.dir/flags.make

components/sc_tp/CMakeFiles/sc_tp.dir/__/sc_tp_src/sc_tp.c.o: components/sc_tp/CMakeFiles/sc_tp.dir/flags.make
components/sc_tp/CMakeFiles/sc_tp.dir/__/sc_tp_src/sc_tp.c.o: ../components/sc_tp_src/sc_tp.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/user/linuxcnc/cmake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object components/sc_tp/CMakeFiles/sc_tp.dir/__/sc_tp_src/sc_tp.c.o"
	cd /home/user/linuxcnc/cmake/build/components/sc_tp && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/sc_tp.dir/__/sc_tp_src/sc_tp.c.o -c /home/user/linuxcnc/cmake/components/sc_tp_src/sc_tp.c

components/sc_tp/CMakeFiles/sc_tp.dir/__/sc_tp_src/sc_tp.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/sc_tp.dir/__/sc_tp_src/sc_tp.c.i"
	cd /home/user/linuxcnc/cmake/build/components/sc_tp && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/user/linuxcnc/cmake/components/sc_tp_src/sc_tp.c > CMakeFiles/sc_tp.dir/__/sc_tp_src/sc_tp.c.i

components/sc_tp/CMakeFiles/sc_tp.dir/__/sc_tp_src/sc_tp.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/sc_tp.dir/__/sc_tp_src/sc_tp.c.s"
	cd /home/user/linuxcnc/cmake/build/components/sc_tp && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/user/linuxcnc/cmake/components/sc_tp_src/sc_tp.c -o CMakeFiles/sc_tp.dir/__/sc_tp_src/sc_tp.c.s

components/sc_tp/CMakeFiles/sc_tp.dir/__/sc_tp_src/sc_struct.cpp.o: components/sc_tp/CMakeFiles/sc_tp.dir/flags.make
components/sc_tp/CMakeFiles/sc_tp.dir/__/sc_tp_src/sc_struct.cpp.o: ../components/sc_tp_src/sc_struct.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/user/linuxcnc/cmake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object components/sc_tp/CMakeFiles/sc_tp.dir/__/sc_tp_src/sc_struct.cpp.o"
	cd /home/user/linuxcnc/cmake/build/components/sc_tp && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sc_tp.dir/__/sc_tp_src/sc_struct.cpp.o -c /home/user/linuxcnc/cmake/components/sc_tp_src/sc_struct.cpp

components/sc_tp/CMakeFiles/sc_tp.dir/__/sc_tp_src/sc_struct.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sc_tp.dir/__/sc_tp_src/sc_struct.cpp.i"
	cd /home/user/linuxcnc/cmake/build/components/sc_tp && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/user/linuxcnc/cmake/components/sc_tp_src/sc_struct.cpp > CMakeFiles/sc_tp.dir/__/sc_tp_src/sc_struct.cpp.i

components/sc_tp/CMakeFiles/sc_tp.dir/__/sc_tp_src/sc_struct.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sc_tp.dir/__/sc_tp_src/sc_struct.cpp.s"
	cd /home/user/linuxcnc/cmake/build/components/sc_tp && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/user/linuxcnc/cmake/components/sc_tp_src/sc_struct.cpp -o CMakeFiles/sc_tp.dir/__/sc_tp_src/sc_struct.cpp.s

components/sc_tp/CMakeFiles/sc_tp.dir/__/sc_tp_src/sc_arcs.cpp.o: components/sc_tp/CMakeFiles/sc_tp.dir/flags.make
components/sc_tp/CMakeFiles/sc_tp.dir/__/sc_tp_src/sc_arcs.cpp.o: ../components/sc_tp_src/sc_arcs.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/user/linuxcnc/cmake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object components/sc_tp/CMakeFiles/sc_tp.dir/__/sc_tp_src/sc_arcs.cpp.o"
	cd /home/user/linuxcnc/cmake/build/components/sc_tp && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sc_tp.dir/__/sc_tp_src/sc_arcs.cpp.o -c /home/user/linuxcnc/cmake/components/sc_tp_src/sc_arcs.cpp

components/sc_tp/CMakeFiles/sc_tp.dir/__/sc_tp_src/sc_arcs.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sc_tp.dir/__/sc_tp_src/sc_arcs.cpp.i"
	cd /home/user/linuxcnc/cmake/build/components/sc_tp && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/user/linuxcnc/cmake/components/sc_tp_src/sc_arcs.cpp > CMakeFiles/sc_tp.dir/__/sc_tp_src/sc_arcs.cpp.i

components/sc_tp/CMakeFiles/sc_tp.dir/__/sc_tp_src/sc_arcs.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sc_tp.dir/__/sc_tp_src/sc_arcs.cpp.s"
	cd /home/user/linuxcnc/cmake/build/components/sc_tp && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/user/linuxcnc/cmake/components/sc_tp_src/sc_arcs.cpp -o CMakeFiles/sc_tp.dir/__/sc_tp_src/sc_arcs.cpp.s

components/sc_tp/CMakeFiles/sc_tp.dir/__/sc_tp_src/sc_lines.cpp.o: components/sc_tp/CMakeFiles/sc_tp.dir/flags.make
components/sc_tp/CMakeFiles/sc_tp.dir/__/sc_tp_src/sc_lines.cpp.o: ../components/sc_tp_src/sc_lines.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/user/linuxcnc/cmake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object components/sc_tp/CMakeFiles/sc_tp.dir/__/sc_tp_src/sc_lines.cpp.o"
	cd /home/user/linuxcnc/cmake/build/components/sc_tp && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sc_tp.dir/__/sc_tp_src/sc_lines.cpp.o -c /home/user/linuxcnc/cmake/components/sc_tp_src/sc_lines.cpp

components/sc_tp/CMakeFiles/sc_tp.dir/__/sc_tp_src/sc_lines.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sc_tp.dir/__/sc_tp_src/sc_lines.cpp.i"
	cd /home/user/linuxcnc/cmake/build/components/sc_tp && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/user/linuxcnc/cmake/components/sc_tp_src/sc_lines.cpp > CMakeFiles/sc_tp.dir/__/sc_tp_src/sc_lines.cpp.i

components/sc_tp/CMakeFiles/sc_tp.dir/__/sc_tp_src/sc_lines.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sc_tp.dir/__/sc_tp_src/sc_lines.cpp.s"
	cd /home/user/linuxcnc/cmake/build/components/sc_tp && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/user/linuxcnc/cmake/components/sc_tp_src/sc_lines.cpp -o CMakeFiles/sc_tp.dir/__/sc_tp_src/sc_lines.cpp.s

components/sc_tp/CMakeFiles/sc_tp.dir/__/sc_tp_src/sc_block.c.o: components/sc_tp/CMakeFiles/sc_tp.dir/flags.make
components/sc_tp/CMakeFiles/sc_tp.dir/__/sc_tp_src/sc_block.c.o: ../components/sc_tp_src/sc_block.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/user/linuxcnc/cmake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object components/sc_tp/CMakeFiles/sc_tp.dir/__/sc_tp_src/sc_block.c.o"
	cd /home/user/linuxcnc/cmake/build/components/sc_tp && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/sc_tp.dir/__/sc_tp_src/sc_block.c.o -c /home/user/linuxcnc/cmake/components/sc_tp_src/sc_block.c

components/sc_tp/CMakeFiles/sc_tp.dir/__/sc_tp_src/sc_block.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/sc_tp.dir/__/sc_tp_src/sc_block.c.i"
	cd /home/user/linuxcnc/cmake/build/components/sc_tp && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/user/linuxcnc/cmake/components/sc_tp_src/sc_block.c > CMakeFiles/sc_tp.dir/__/sc_tp_src/sc_block.c.i

components/sc_tp/CMakeFiles/sc_tp.dir/__/sc_tp_src/sc_block.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/sc_tp.dir/__/sc_tp_src/sc_block.c.s"
	cd /home/user/linuxcnc/cmake/build/components/sc_tp && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/user/linuxcnc/cmake/components/sc_tp_src/sc_block.c -o CMakeFiles/sc_tp.dir/__/sc_tp_src/sc_block.c.s

components/sc_tp/CMakeFiles/sc_tp.dir/__/sc_tp_src/sc_optimizer.cpp.o: components/sc_tp/CMakeFiles/sc_tp.dir/flags.make
components/sc_tp/CMakeFiles/sc_tp.dir/__/sc_tp_src/sc_optimizer.cpp.o: ../components/sc_tp_src/sc_optimizer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/user/linuxcnc/cmake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object components/sc_tp/CMakeFiles/sc_tp.dir/__/sc_tp_src/sc_optimizer.cpp.o"
	cd /home/user/linuxcnc/cmake/build/components/sc_tp && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sc_tp.dir/__/sc_tp_src/sc_optimizer.cpp.o -c /home/user/linuxcnc/cmake/components/sc_tp_src/sc_optimizer.cpp

components/sc_tp/CMakeFiles/sc_tp.dir/__/sc_tp_src/sc_optimizer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sc_tp.dir/__/sc_tp_src/sc_optimizer.cpp.i"
	cd /home/user/linuxcnc/cmake/build/components/sc_tp && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/user/linuxcnc/cmake/components/sc_tp_src/sc_optimizer.cpp > CMakeFiles/sc_tp.dir/__/sc_tp_src/sc_optimizer.cpp.i

components/sc_tp/CMakeFiles/sc_tp.dir/__/sc_tp_src/sc_optimizer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sc_tp.dir/__/sc_tp_src/sc_optimizer.cpp.s"
	cd /home/user/linuxcnc/cmake/build/components/sc_tp && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/user/linuxcnc/cmake/components/sc_tp_src/sc_optimizer.cpp -o CMakeFiles/sc_tp.dir/__/sc_tp_src/sc_optimizer.cpp.s

components/sc_tp/CMakeFiles/sc_tp.dir/__/sc_tp_src/sc_interpolate.c.o: components/sc_tp/CMakeFiles/sc_tp.dir/flags.make
components/sc_tp/CMakeFiles/sc_tp.dir/__/sc_tp_src/sc_interpolate.c.o: ../components/sc_tp_src/sc_interpolate.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/user/linuxcnc/cmake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object components/sc_tp/CMakeFiles/sc_tp.dir/__/sc_tp_src/sc_interpolate.c.o"
	cd /home/user/linuxcnc/cmake/build/components/sc_tp && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/sc_tp.dir/__/sc_tp_src/sc_interpolate.c.o -c /home/user/linuxcnc/cmake/components/sc_tp_src/sc_interpolate.c

components/sc_tp/CMakeFiles/sc_tp.dir/__/sc_tp_src/sc_interpolate.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/sc_tp.dir/__/sc_tp_src/sc_interpolate.c.i"
	cd /home/user/linuxcnc/cmake/build/components/sc_tp && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/user/linuxcnc/cmake/components/sc_tp_src/sc_interpolate.c > CMakeFiles/sc_tp.dir/__/sc_tp_src/sc_interpolate.c.i

components/sc_tp/CMakeFiles/sc_tp.dir/__/sc_tp_src/sc_interpolate.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/sc_tp.dir/__/sc_tp_src/sc_interpolate.c.s"
	cd /home/user/linuxcnc/cmake/build/components/sc_tp && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/user/linuxcnc/cmake/components/sc_tp_src/sc_interpolate.c -o CMakeFiles/sc_tp.dir/__/sc_tp_src/sc_interpolate.c.s

components/sc_tp/CMakeFiles/sc_tp.dir/__/sc_tp_src/sc_conversion.c.o: components/sc_tp/CMakeFiles/sc_tp.dir/flags.make
components/sc_tp/CMakeFiles/sc_tp.dir/__/sc_tp_src/sc_conversion.c.o: ../components/sc_tp_src/sc_conversion.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/user/linuxcnc/cmake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object components/sc_tp/CMakeFiles/sc_tp.dir/__/sc_tp_src/sc_conversion.c.o"
	cd /home/user/linuxcnc/cmake/build/components/sc_tp && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/sc_tp.dir/__/sc_tp_src/sc_conversion.c.o -c /home/user/linuxcnc/cmake/components/sc_tp_src/sc_conversion.c

components/sc_tp/CMakeFiles/sc_tp.dir/__/sc_tp_src/sc_conversion.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/sc_tp.dir/__/sc_tp_src/sc_conversion.c.i"
	cd /home/user/linuxcnc/cmake/build/components/sc_tp && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/user/linuxcnc/cmake/components/sc_tp_src/sc_conversion.c > CMakeFiles/sc_tp.dir/__/sc_tp_src/sc_conversion.c.i

components/sc_tp/CMakeFiles/sc_tp.dir/__/sc_tp_src/sc_conversion.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/sc_tp.dir/__/sc_tp_src/sc_conversion.c.s"
	cd /home/user/linuxcnc/cmake/build/components/sc_tp && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/user/linuxcnc/cmake/components/sc_tp_src/sc_conversion.c -o CMakeFiles/sc_tp.dir/__/sc_tp_src/sc_conversion.c.s

components/sc_tp/CMakeFiles/sc_tp.dir/__/sc_tp_src/ruckig/brake.cpp.o: components/sc_tp/CMakeFiles/sc_tp.dir/flags.make
components/sc_tp/CMakeFiles/sc_tp.dir/__/sc_tp_src/ruckig/brake.cpp.o: ../components/sc_tp_src/ruckig/brake.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/user/linuxcnc/cmake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object components/sc_tp/CMakeFiles/sc_tp.dir/__/sc_tp_src/ruckig/brake.cpp.o"
	cd /home/user/linuxcnc/cmake/build/components/sc_tp && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sc_tp.dir/__/sc_tp_src/ruckig/brake.cpp.o -c /home/user/linuxcnc/cmake/components/sc_tp_src/ruckig/brake.cpp

components/sc_tp/CMakeFiles/sc_tp.dir/__/sc_tp_src/ruckig/brake.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sc_tp.dir/__/sc_tp_src/ruckig/brake.cpp.i"
	cd /home/user/linuxcnc/cmake/build/components/sc_tp && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/user/linuxcnc/cmake/components/sc_tp_src/ruckig/brake.cpp > CMakeFiles/sc_tp.dir/__/sc_tp_src/ruckig/brake.cpp.i

components/sc_tp/CMakeFiles/sc_tp.dir/__/sc_tp_src/ruckig/brake.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sc_tp.dir/__/sc_tp_src/ruckig/brake.cpp.s"
	cd /home/user/linuxcnc/cmake/build/components/sc_tp && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/user/linuxcnc/cmake/components/sc_tp_src/ruckig/brake.cpp -o CMakeFiles/sc_tp.dir/__/sc_tp_src/ruckig/brake.cpp.s

components/sc_tp/CMakeFiles/sc_tp.dir/__/sc_tp_src/ruckig/position-step1.cpp.o: components/sc_tp/CMakeFiles/sc_tp.dir/flags.make
components/sc_tp/CMakeFiles/sc_tp.dir/__/sc_tp_src/ruckig/position-step1.cpp.o: ../components/sc_tp_src/ruckig/position-step1.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/user/linuxcnc/cmake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object components/sc_tp/CMakeFiles/sc_tp.dir/__/sc_tp_src/ruckig/position-step1.cpp.o"
	cd /home/user/linuxcnc/cmake/build/components/sc_tp && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sc_tp.dir/__/sc_tp_src/ruckig/position-step1.cpp.o -c /home/user/linuxcnc/cmake/components/sc_tp_src/ruckig/position-step1.cpp

components/sc_tp/CMakeFiles/sc_tp.dir/__/sc_tp_src/ruckig/position-step1.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sc_tp.dir/__/sc_tp_src/ruckig/position-step1.cpp.i"
	cd /home/user/linuxcnc/cmake/build/components/sc_tp && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/user/linuxcnc/cmake/components/sc_tp_src/ruckig/position-step1.cpp > CMakeFiles/sc_tp.dir/__/sc_tp_src/ruckig/position-step1.cpp.i

components/sc_tp/CMakeFiles/sc_tp.dir/__/sc_tp_src/ruckig/position-step1.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sc_tp.dir/__/sc_tp_src/ruckig/position-step1.cpp.s"
	cd /home/user/linuxcnc/cmake/build/components/sc_tp && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/user/linuxcnc/cmake/components/sc_tp_src/ruckig/position-step1.cpp -o CMakeFiles/sc_tp.dir/__/sc_tp_src/ruckig/position-step1.cpp.s

components/sc_tp/CMakeFiles/sc_tp.dir/__/sc_tp_src/ruckig/position-step2.cpp.o: components/sc_tp/CMakeFiles/sc_tp.dir/flags.make
components/sc_tp/CMakeFiles/sc_tp.dir/__/sc_tp_src/ruckig/position-step2.cpp.o: ../components/sc_tp_src/ruckig/position-step2.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/user/linuxcnc/cmake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object components/sc_tp/CMakeFiles/sc_tp.dir/__/sc_tp_src/ruckig/position-step2.cpp.o"
	cd /home/user/linuxcnc/cmake/build/components/sc_tp && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sc_tp.dir/__/sc_tp_src/ruckig/position-step2.cpp.o -c /home/user/linuxcnc/cmake/components/sc_tp_src/ruckig/position-step2.cpp

components/sc_tp/CMakeFiles/sc_tp.dir/__/sc_tp_src/ruckig/position-step2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sc_tp.dir/__/sc_tp_src/ruckig/position-step2.cpp.i"
	cd /home/user/linuxcnc/cmake/build/components/sc_tp && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/user/linuxcnc/cmake/components/sc_tp_src/ruckig/position-step2.cpp > CMakeFiles/sc_tp.dir/__/sc_tp_src/ruckig/position-step2.cpp.i

components/sc_tp/CMakeFiles/sc_tp.dir/__/sc_tp_src/ruckig/position-step2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sc_tp.dir/__/sc_tp_src/ruckig/position-step2.cpp.s"
	cd /home/user/linuxcnc/cmake/build/components/sc_tp && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/user/linuxcnc/cmake/components/sc_tp_src/ruckig/position-step2.cpp -o CMakeFiles/sc_tp.dir/__/sc_tp_src/ruckig/position-step2.cpp.s

components/sc_tp/CMakeFiles/sc_tp.dir/__/sc_tp_src/ruckig/velocity-step1.cpp.o: components/sc_tp/CMakeFiles/sc_tp.dir/flags.make
components/sc_tp/CMakeFiles/sc_tp.dir/__/sc_tp_src/ruckig/velocity-step1.cpp.o: ../components/sc_tp_src/ruckig/velocity-step1.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/user/linuxcnc/cmake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object components/sc_tp/CMakeFiles/sc_tp.dir/__/sc_tp_src/ruckig/velocity-step1.cpp.o"
	cd /home/user/linuxcnc/cmake/build/components/sc_tp && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sc_tp.dir/__/sc_tp_src/ruckig/velocity-step1.cpp.o -c /home/user/linuxcnc/cmake/components/sc_tp_src/ruckig/velocity-step1.cpp

components/sc_tp/CMakeFiles/sc_tp.dir/__/sc_tp_src/ruckig/velocity-step1.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sc_tp.dir/__/sc_tp_src/ruckig/velocity-step1.cpp.i"
	cd /home/user/linuxcnc/cmake/build/components/sc_tp && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/user/linuxcnc/cmake/components/sc_tp_src/ruckig/velocity-step1.cpp > CMakeFiles/sc_tp.dir/__/sc_tp_src/ruckig/velocity-step1.cpp.i

components/sc_tp/CMakeFiles/sc_tp.dir/__/sc_tp_src/ruckig/velocity-step1.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sc_tp.dir/__/sc_tp_src/ruckig/velocity-step1.cpp.s"
	cd /home/user/linuxcnc/cmake/build/components/sc_tp && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/user/linuxcnc/cmake/components/sc_tp_src/ruckig/velocity-step1.cpp -o CMakeFiles/sc_tp.dir/__/sc_tp_src/ruckig/velocity-step1.cpp.s

components/sc_tp/CMakeFiles/sc_tp.dir/__/sc_tp_src/ruckig/velocity-step2.cpp.o: components/sc_tp/CMakeFiles/sc_tp.dir/flags.make
components/sc_tp/CMakeFiles/sc_tp.dir/__/sc_tp_src/ruckig/velocity-step2.cpp.o: ../components/sc_tp_src/ruckig/velocity-step2.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/user/linuxcnc/cmake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object components/sc_tp/CMakeFiles/sc_tp.dir/__/sc_tp_src/ruckig/velocity-step2.cpp.o"
	cd /home/user/linuxcnc/cmake/build/components/sc_tp && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sc_tp.dir/__/sc_tp_src/ruckig/velocity-step2.cpp.o -c /home/user/linuxcnc/cmake/components/sc_tp_src/ruckig/velocity-step2.cpp

components/sc_tp/CMakeFiles/sc_tp.dir/__/sc_tp_src/ruckig/velocity-step2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sc_tp.dir/__/sc_tp_src/ruckig/velocity-step2.cpp.i"
	cd /home/user/linuxcnc/cmake/build/components/sc_tp && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/user/linuxcnc/cmake/components/sc_tp_src/ruckig/velocity-step2.cpp > CMakeFiles/sc_tp.dir/__/sc_tp_src/ruckig/velocity-step2.cpp.i

components/sc_tp/CMakeFiles/sc_tp.dir/__/sc_tp_src/ruckig/velocity-step2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sc_tp.dir/__/sc_tp_src/ruckig/velocity-step2.cpp.s"
	cd /home/user/linuxcnc/cmake/build/components/sc_tp && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/user/linuxcnc/cmake/components/sc_tp_src/ruckig/velocity-step2.cpp -o CMakeFiles/sc_tp.dir/__/sc_tp_src/ruckig/velocity-step2.cpp.s

components/sc_tp/CMakeFiles/sc_tp.dir/__/sc_tp_src/ruckig/sc_ruckig.cpp.o: components/sc_tp/CMakeFiles/sc_tp.dir/flags.make
components/sc_tp/CMakeFiles/sc_tp.dir/__/sc_tp_src/ruckig/sc_ruckig.cpp.o: ../components/sc_tp_src/ruckig/sc_ruckig.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/user/linuxcnc/cmake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object components/sc_tp/CMakeFiles/sc_tp.dir/__/sc_tp_src/ruckig/sc_ruckig.cpp.o"
	cd /home/user/linuxcnc/cmake/build/components/sc_tp && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sc_tp.dir/__/sc_tp_src/ruckig/sc_ruckig.cpp.o -c /home/user/linuxcnc/cmake/components/sc_tp_src/ruckig/sc_ruckig.cpp

components/sc_tp/CMakeFiles/sc_tp.dir/__/sc_tp_src/ruckig/sc_ruckig.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sc_tp.dir/__/sc_tp_src/ruckig/sc_ruckig.cpp.i"
	cd /home/user/linuxcnc/cmake/build/components/sc_tp && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/user/linuxcnc/cmake/components/sc_tp_src/ruckig/sc_ruckig.cpp > CMakeFiles/sc_tp.dir/__/sc_tp_src/ruckig/sc_ruckig.cpp.i

components/sc_tp/CMakeFiles/sc_tp.dir/__/sc_tp_src/ruckig/sc_ruckig.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sc_tp.dir/__/sc_tp_src/ruckig/sc_ruckig.cpp.s"
	cd /home/user/linuxcnc/cmake/build/components/sc_tp && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/user/linuxcnc/cmake/components/sc_tp_src/ruckig/sc_ruckig.cpp -o CMakeFiles/sc_tp.dir/__/sc_tp_src/ruckig/sc_ruckig.cpp.s

# Object files for target sc_tp
sc_tp_OBJECTS = \
"CMakeFiles/sc_tp.dir/__/sc_tp_src/sc_tp.c.o" \
"CMakeFiles/sc_tp.dir/__/sc_tp_src/sc_struct.cpp.o" \
"CMakeFiles/sc_tp.dir/__/sc_tp_src/sc_arcs.cpp.o" \
"CMakeFiles/sc_tp.dir/__/sc_tp_src/sc_lines.cpp.o" \
"CMakeFiles/sc_tp.dir/__/sc_tp_src/sc_block.c.o" \
"CMakeFiles/sc_tp.dir/__/sc_tp_src/sc_optimizer.cpp.o" \
"CMakeFiles/sc_tp.dir/__/sc_tp_src/sc_interpolate.c.o" \
"CMakeFiles/sc_tp.dir/__/sc_tp_src/sc_conversion.c.o" \
"CMakeFiles/sc_tp.dir/__/sc_tp_src/ruckig/brake.cpp.o" \
"CMakeFiles/sc_tp.dir/__/sc_tp_src/ruckig/position-step1.cpp.o" \
"CMakeFiles/sc_tp.dir/__/sc_tp_src/ruckig/position-step2.cpp.o" \
"CMakeFiles/sc_tp.dir/__/sc_tp_src/ruckig/velocity-step1.cpp.o" \
"CMakeFiles/sc_tp.dir/__/sc_tp_src/ruckig/velocity-step2.cpp.o" \
"CMakeFiles/sc_tp.dir/__/sc_tp_src/ruckig/sc_ruckig.cpp.o"

# External object files for target sc_tp
sc_tp_EXTERNAL_OBJECTS =

components/sc_tp/sc_tp.so: components/sc_tp/CMakeFiles/sc_tp.dir/__/sc_tp_src/sc_tp.c.o
components/sc_tp/sc_tp.so: components/sc_tp/CMakeFiles/sc_tp.dir/__/sc_tp_src/sc_struct.cpp.o
components/sc_tp/sc_tp.so: components/sc_tp/CMakeFiles/sc_tp.dir/__/sc_tp_src/sc_arcs.cpp.o
components/sc_tp/sc_tp.so: components/sc_tp/CMakeFiles/sc_tp.dir/__/sc_tp_src/sc_lines.cpp.o
components/sc_tp/sc_tp.so: components/sc_tp/CMakeFiles/sc_tp.dir/__/sc_tp_src/sc_block.c.o
components/sc_tp/sc_tp.so: components/sc_tp/CMakeFiles/sc_tp.dir/__/sc_tp_src/sc_optimizer.cpp.o
components/sc_tp/sc_tp.so: components/sc_tp/CMakeFiles/sc_tp.dir/__/sc_tp_src/sc_interpolate.c.o
components/sc_tp/sc_tp.so: components/sc_tp/CMakeFiles/sc_tp.dir/__/sc_tp_src/sc_conversion.c.o
components/sc_tp/sc_tp.so: components/sc_tp/CMakeFiles/sc_tp.dir/__/sc_tp_src/ruckig/brake.cpp.o
components/sc_tp/sc_tp.so: components/sc_tp/CMakeFiles/sc_tp.dir/__/sc_tp_src/ruckig/position-step1.cpp.o
components/sc_tp/sc_tp.so: components/sc_tp/CMakeFiles/sc_tp.dir/__/sc_tp_src/ruckig/position-step2.cpp.o
components/sc_tp/sc_tp.so: components/sc_tp/CMakeFiles/sc_tp.dir/__/sc_tp_src/ruckig/velocity-step1.cpp.o
components/sc_tp/sc_tp.so: components/sc_tp/CMakeFiles/sc_tp.dir/__/sc_tp_src/ruckig/velocity-step2.cpp.o
components/sc_tp/sc_tp.so: components/sc_tp/CMakeFiles/sc_tp.dir/__/sc_tp_src/ruckig/sc_ruckig.cpp.o
components/sc_tp/sc_tp.so: components/sc_tp/CMakeFiles/sc_tp.dir/build.make
components/sc_tp/sc_tp.so: ../components/sc_tp/../../build/liblinuxcnchal/liblinuxcnchal.so
components/sc_tp/sc_tp.so: ../components/sc_tp/../../build/libposemath/libposemath.so
components/sc_tp/sc_tp.so: components/sc_tp/CMakeFiles/sc_tp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/user/linuxcnc/cmake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Linking CXX shared library sc_tp.so"
	cd /home/user/linuxcnc/cmake/build/components/sc_tp && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sc_tp.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
components/sc_tp/CMakeFiles/sc_tp.dir/build: components/sc_tp/sc_tp.so

.PHONY : components/sc_tp/CMakeFiles/sc_tp.dir/build

components/sc_tp/CMakeFiles/sc_tp.dir/clean:
	cd /home/user/linuxcnc/cmake/build/components/sc_tp && $(CMAKE_COMMAND) -P CMakeFiles/sc_tp.dir/cmake_clean.cmake
.PHONY : components/sc_tp/CMakeFiles/sc_tp.dir/clean

components/sc_tp/CMakeFiles/sc_tp.dir/depend:
	cd /home/user/linuxcnc/cmake/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/user/linuxcnc/cmake /home/user/linuxcnc/cmake/components/sc_tp /home/user/linuxcnc/cmake/build /home/user/linuxcnc/cmake/build/components/sc_tp /home/user/linuxcnc/cmake/build/components/sc_tp/CMakeFiles/sc_tp.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : components/sc_tp/CMakeFiles/sc_tp.dir/depend

