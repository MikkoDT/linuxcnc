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
include liblinuxcncini/CMakeFiles/liblinuxcncini.dir/depend.make

# Include the progress variables for this target.
include liblinuxcncini/CMakeFiles/liblinuxcncini.dir/progress.make

# Include the compile flags for this target's objects.
include liblinuxcncini/CMakeFiles/liblinuxcncini.dir/flags.make

liblinuxcncini/CMakeFiles/liblinuxcncini.dir/__/liblinuxcncini_src/inifile.cc.o: liblinuxcncini/CMakeFiles/liblinuxcncini.dir/flags.make
liblinuxcncini/CMakeFiles/liblinuxcncini.dir/__/liblinuxcncini_src/inifile.cc.o: ../liblinuxcncini_src/inifile.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/user/linuxcnc/cmake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object liblinuxcncini/CMakeFiles/liblinuxcncini.dir/__/liblinuxcncini_src/inifile.cc.o"
	cd /home/user/linuxcnc/cmake/build/liblinuxcncini && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/liblinuxcncini.dir/__/liblinuxcncini_src/inifile.cc.o -c /home/user/linuxcnc/cmake/liblinuxcncini_src/inifile.cc

liblinuxcncini/CMakeFiles/liblinuxcncini.dir/__/liblinuxcncini_src/inifile.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/liblinuxcncini.dir/__/liblinuxcncini_src/inifile.cc.i"
	cd /home/user/linuxcnc/cmake/build/liblinuxcncini && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/user/linuxcnc/cmake/liblinuxcncini_src/inifile.cc > CMakeFiles/liblinuxcncini.dir/__/liblinuxcncini_src/inifile.cc.i

liblinuxcncini/CMakeFiles/liblinuxcncini.dir/__/liblinuxcncini_src/inifile.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/liblinuxcncini.dir/__/liblinuxcncini_src/inifile.cc.s"
	cd /home/user/linuxcnc/cmake/build/liblinuxcncini && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/user/linuxcnc/cmake/liblinuxcncini_src/inifile.cc -o CMakeFiles/liblinuxcncini.dir/__/liblinuxcncini_src/inifile.cc.s

# Object files for target liblinuxcncini
liblinuxcncini_OBJECTS = \
"CMakeFiles/liblinuxcncini.dir/__/liblinuxcncini_src/inifile.cc.o"

# External object files for target liblinuxcncini
liblinuxcncini_EXTERNAL_OBJECTS =

liblinuxcncini/liblinuxcncini.so.0: liblinuxcncini/CMakeFiles/liblinuxcncini.dir/__/liblinuxcncini_src/inifile.cc.o
liblinuxcncini/liblinuxcncini.so.0: liblinuxcncini/CMakeFiles/liblinuxcncini.dir/build.make
liblinuxcncini/liblinuxcncini.so.0: liblinuxcncini/CMakeFiles/liblinuxcncini.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/user/linuxcnc/cmake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library liblinuxcncini.so"
	cd /home/user/linuxcnc/cmake/build/liblinuxcncini && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/liblinuxcncini.dir/link.txt --verbose=$(VERBOSE)
	cd /home/user/linuxcnc/cmake/build/liblinuxcncini && $(CMAKE_COMMAND) -E cmake_symlink_library liblinuxcncini.so.0 liblinuxcncini.so.0 liblinuxcncini.so

liblinuxcncini/liblinuxcncini.so: liblinuxcncini/liblinuxcncini.so.0
	@$(CMAKE_COMMAND) -E touch_nocreate liblinuxcncini/liblinuxcncini.so

# Rule to build all files generated by this target.
liblinuxcncini/CMakeFiles/liblinuxcncini.dir/build: liblinuxcncini/liblinuxcncini.so

.PHONY : liblinuxcncini/CMakeFiles/liblinuxcncini.dir/build

liblinuxcncini/CMakeFiles/liblinuxcncini.dir/clean:
	cd /home/user/linuxcnc/cmake/build/liblinuxcncini && $(CMAKE_COMMAND) -P CMakeFiles/liblinuxcncini.dir/cmake_clean.cmake
.PHONY : liblinuxcncini/CMakeFiles/liblinuxcncini.dir/clean

liblinuxcncini/CMakeFiles/liblinuxcncini.dir/depend:
	cd /home/user/linuxcnc/cmake/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/user/linuxcnc/cmake /home/user/linuxcnc/cmake/liblinuxcncini /home/user/linuxcnc/cmake/build /home/user/linuxcnc/cmake/build/liblinuxcncini /home/user/linuxcnc/cmake/build/liblinuxcncini/CMakeFiles/liblinuxcncini.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : liblinuxcncini/CMakeFiles/liblinuxcncini.dir/depend
