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
include projects/qt_nml/CMakeFiles/qt_nml.dir/depend.make

# Include the progress variables for this target.
include projects/qt_nml/CMakeFiles/qt_nml.dir/progress.make

# Include the compile flags for this target's objects.
include projects/qt_nml/CMakeFiles/qt_nml.dir/flags.make

projects/qt_nml/CMakeFiles/qt_nml.dir/qt_nml_autogen/mocs_compilation.cpp.o: projects/qt_nml/CMakeFiles/qt_nml.dir/flags.make
projects/qt_nml/CMakeFiles/qt_nml.dir/qt_nml_autogen/mocs_compilation.cpp.o: projects/qt_nml/qt_nml_autogen/mocs_compilation.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/user/linuxcnc/cmake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object projects/qt_nml/CMakeFiles/qt_nml.dir/qt_nml_autogen/mocs_compilation.cpp.o"
	cd /home/user/linuxcnc/cmake/build/projects/qt_nml && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/qt_nml.dir/qt_nml_autogen/mocs_compilation.cpp.o -c /home/user/linuxcnc/cmake/build/projects/qt_nml/qt_nml_autogen/mocs_compilation.cpp

projects/qt_nml/CMakeFiles/qt_nml.dir/qt_nml_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/qt_nml.dir/qt_nml_autogen/mocs_compilation.cpp.i"
	cd /home/user/linuxcnc/cmake/build/projects/qt_nml && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/user/linuxcnc/cmake/build/projects/qt_nml/qt_nml_autogen/mocs_compilation.cpp > CMakeFiles/qt_nml.dir/qt_nml_autogen/mocs_compilation.cpp.i

projects/qt_nml/CMakeFiles/qt_nml.dir/qt_nml_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/qt_nml.dir/qt_nml_autogen/mocs_compilation.cpp.s"
	cd /home/user/linuxcnc/cmake/build/projects/qt_nml && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/user/linuxcnc/cmake/build/projects/qt_nml/qt_nml_autogen/mocs_compilation.cpp -o CMakeFiles/qt_nml.dir/qt_nml_autogen/mocs_compilation.cpp.s

projects/qt_nml/CMakeFiles/qt_nml.dir/main.cpp.o: projects/qt_nml/CMakeFiles/qt_nml.dir/flags.make
projects/qt_nml/CMakeFiles/qt_nml.dir/main.cpp.o: ../projects/qt_nml/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/user/linuxcnc/cmake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object projects/qt_nml/CMakeFiles/qt_nml.dir/main.cpp.o"
	cd /home/user/linuxcnc/cmake/build/projects/qt_nml && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/qt_nml.dir/main.cpp.o -c /home/user/linuxcnc/cmake/projects/qt_nml/main.cpp

projects/qt_nml/CMakeFiles/qt_nml.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/qt_nml.dir/main.cpp.i"
	cd /home/user/linuxcnc/cmake/build/projects/qt_nml && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/user/linuxcnc/cmake/projects/qt_nml/main.cpp > CMakeFiles/qt_nml.dir/main.cpp.i

projects/qt_nml/CMakeFiles/qt_nml.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/qt_nml.dir/main.cpp.s"
	cd /home/user/linuxcnc/cmake/build/projects/qt_nml && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/user/linuxcnc/cmake/projects/qt_nml/main.cpp -o CMakeFiles/qt_nml.dir/main.cpp.s

projects/qt_nml/CMakeFiles/qt_nml.dir/mainwindow.cpp.o: projects/qt_nml/CMakeFiles/qt_nml.dir/flags.make
projects/qt_nml/CMakeFiles/qt_nml.dir/mainwindow.cpp.o: ../projects/qt_nml/mainwindow.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/user/linuxcnc/cmake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object projects/qt_nml/CMakeFiles/qt_nml.dir/mainwindow.cpp.o"
	cd /home/user/linuxcnc/cmake/build/projects/qt_nml && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/qt_nml.dir/mainwindow.cpp.o -c /home/user/linuxcnc/cmake/projects/qt_nml/mainwindow.cpp

projects/qt_nml/CMakeFiles/qt_nml.dir/mainwindow.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/qt_nml.dir/mainwindow.cpp.i"
	cd /home/user/linuxcnc/cmake/build/projects/qt_nml && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/user/linuxcnc/cmake/projects/qt_nml/mainwindow.cpp > CMakeFiles/qt_nml.dir/mainwindow.cpp.i

projects/qt_nml/CMakeFiles/qt_nml.dir/mainwindow.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/qt_nml.dir/mainwindow.cpp.s"
	cd /home/user/linuxcnc/cmake/build/projects/qt_nml && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/user/linuxcnc/cmake/projects/qt_nml/mainwindow.cpp -o CMakeFiles/qt_nml.dir/mainwindow.cpp.s

# Object files for target qt_nml
qt_nml_OBJECTS = \
"CMakeFiles/qt_nml.dir/qt_nml_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/qt_nml.dir/main.cpp.o" \
"CMakeFiles/qt_nml.dir/mainwindow.cpp.o"

# External object files for target qt_nml
qt_nml_EXTERNAL_OBJECTS =

projects/qt_nml/qt_nml: projects/qt_nml/CMakeFiles/qt_nml.dir/qt_nml_autogen/mocs_compilation.cpp.o
projects/qt_nml/qt_nml: projects/qt_nml/CMakeFiles/qt_nml.dir/main.cpp.o
projects/qt_nml/qt_nml: projects/qt_nml/CMakeFiles/qt_nml.dir/mainwindow.cpp.o
projects/qt_nml/qt_nml: projects/qt_nml/CMakeFiles/qt_nml.dir/build.make
projects/qt_nml/qt_nml: /opt/qt-creator/5.15.1/gcc_64/lib/libQt5Widgets.so.5.15.1
projects/qt_nml/qt_nml: ../projects/qt_nml/../../build/liblinuxcnchal/liblinuxcnchal.so
projects/qt_nml/qt_nml: ../projects/qt_nml/../../build/liblinuxcncini/liblinuxcncini.so
projects/qt_nml/qt_nml: ../projects/qt_nml/../../build/liblinuxcnc/liblinuxcnc.a
projects/qt_nml/qt_nml: ../projects/qt_nml/../../build/libnml/libnml.so
projects/qt_nml/qt_nml: ../projects/qt_nml/../../build/librs274/librs274.so
projects/qt_nml/qt_nml: ../projects/qt_nml/../../build/libtooldata/libtooldata.so
projects/qt_nml/qt_nml: /opt/qt-creator/5.15.1/gcc_64/lib/libQt5Gui.so.5.15.1
projects/qt_nml/qt_nml: /opt/qt-creator/5.15.1/gcc_64/lib/libQt5Core.so.5.15.1
projects/qt_nml/qt_nml: projects/qt_nml/CMakeFiles/qt_nml.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/user/linuxcnc/cmake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable qt_nml"
	cd /home/user/linuxcnc/cmake/build/projects/qt_nml && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/qt_nml.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
projects/qt_nml/CMakeFiles/qt_nml.dir/build: projects/qt_nml/qt_nml

.PHONY : projects/qt_nml/CMakeFiles/qt_nml.dir/build

projects/qt_nml/CMakeFiles/qt_nml.dir/clean:
	cd /home/user/linuxcnc/cmake/build/projects/qt_nml && $(CMAKE_COMMAND) -P CMakeFiles/qt_nml.dir/cmake_clean.cmake
.PHONY : projects/qt_nml/CMakeFiles/qt_nml.dir/clean

projects/qt_nml/CMakeFiles/qt_nml.dir/depend:
	cd /home/user/linuxcnc/cmake/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/user/linuxcnc/cmake /home/user/linuxcnc/cmake/projects/qt_nml /home/user/linuxcnc/cmake/build /home/user/linuxcnc/cmake/build/projects/qt_nml /home/user/linuxcnc/cmake/build/projects/qt_nml/CMakeFiles/qt_nml.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : projects/qt_nml/CMakeFiles/qt_nml.dir/depend

