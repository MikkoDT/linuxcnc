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

# Utility rule file for qt_nml_autogen.

# Include the progress variables for this target.
include projects/qt_nml/CMakeFiles/qt_nml_autogen.dir/progress.make

projects/qt_nml/CMakeFiles/qt_nml_autogen:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/user/linuxcnc/cmake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and UIC for target qt_nml"
	cd /home/user/linuxcnc/cmake/build/projects/qt_nml && /usr/bin/cmake -E cmake_autogen /home/user/linuxcnc/cmake/build/projects/qt_nml/CMakeFiles/qt_nml_autogen.dir/AutogenInfo.json ""

qt_nml_autogen: projects/qt_nml/CMakeFiles/qt_nml_autogen
qt_nml_autogen: projects/qt_nml/CMakeFiles/qt_nml_autogen.dir/build.make

.PHONY : qt_nml_autogen

# Rule to build all files generated by this target.
projects/qt_nml/CMakeFiles/qt_nml_autogen.dir/build: qt_nml_autogen

.PHONY : projects/qt_nml/CMakeFiles/qt_nml_autogen.dir/build

projects/qt_nml/CMakeFiles/qt_nml_autogen.dir/clean:
	cd /home/user/linuxcnc/cmake/build/projects/qt_nml && $(CMAKE_COMMAND) -P CMakeFiles/qt_nml_autogen.dir/cmake_clean.cmake
.PHONY : projects/qt_nml/CMakeFiles/qt_nml_autogen.dir/clean

projects/qt_nml/CMakeFiles/qt_nml_autogen.dir/depend:
	cd /home/user/linuxcnc/cmake/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/user/linuxcnc/cmake /home/user/linuxcnc/cmake/projects/qt_nml /home/user/linuxcnc/cmake/build /home/user/linuxcnc/cmake/build/projects/qt_nml /home/user/linuxcnc/cmake/build/projects/qt_nml/CMakeFiles/qt_nml_autogen.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : projects/qt_nml/CMakeFiles/qt_nml_autogen.dir/depend

