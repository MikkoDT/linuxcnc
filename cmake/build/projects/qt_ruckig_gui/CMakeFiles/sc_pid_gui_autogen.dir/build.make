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

# Utility rule file for sc_pid_gui_autogen.

# Include the progress variables for this target.
include projects/qt_ruckig_gui/CMakeFiles/sc_pid_gui_autogen.dir/progress.make

projects/qt_ruckig_gui/CMakeFiles/sc_pid_gui_autogen:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/user/linuxcnc/cmake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and UIC for target sc_pid_gui"
	cd /home/user/linuxcnc/cmake/build/projects/qt_ruckig_gui && /usr/bin/cmake -E cmake_autogen /home/user/linuxcnc/cmake/build/projects/qt_ruckig_gui/CMakeFiles/sc_pid_gui_autogen.dir/AutogenInfo.json ""

sc_pid_gui_autogen: projects/qt_ruckig_gui/CMakeFiles/sc_pid_gui_autogen
sc_pid_gui_autogen: projects/qt_ruckig_gui/CMakeFiles/sc_pid_gui_autogen.dir/build.make

.PHONY : sc_pid_gui_autogen

# Rule to build all files generated by this target.
projects/qt_ruckig_gui/CMakeFiles/sc_pid_gui_autogen.dir/build: sc_pid_gui_autogen

.PHONY : projects/qt_ruckig_gui/CMakeFiles/sc_pid_gui_autogen.dir/build

projects/qt_ruckig_gui/CMakeFiles/sc_pid_gui_autogen.dir/clean:
	cd /home/user/linuxcnc/cmake/build/projects/qt_ruckig_gui && $(CMAKE_COMMAND) -P CMakeFiles/sc_pid_gui_autogen.dir/cmake_clean.cmake
.PHONY : projects/qt_ruckig_gui/CMakeFiles/sc_pid_gui_autogen.dir/clean

projects/qt_ruckig_gui/CMakeFiles/sc_pid_gui_autogen.dir/depend:
	cd /home/user/linuxcnc/cmake/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/user/linuxcnc/cmake /home/user/linuxcnc/cmake/projects/qt_ruckig_gui /home/user/linuxcnc/cmake/build /home/user/linuxcnc/cmake/build/projects/qt_ruckig_gui /home/user/linuxcnc/cmake/build/projects/qt_ruckig_gui/CMakeFiles/sc_pid_gui_autogen.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : projects/qt_ruckig_gui/CMakeFiles/sc_pid_gui_autogen.dir/depend
