# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.0

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

# Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/anthony/sekai

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/anthony/sekai

# Include any dependencies generated for this target.
include units/CMakeFiles/units.dir/depend.make

# Include the progress variables for this target.
include units/CMakeFiles/units.dir/progress.make

# Include the compile flags for this target's objects.
include units/CMakeFiles/units.dir/flags.make

units/CMakeFiles/units.dir/unit.cpp.o: units/CMakeFiles/units.dir/flags.make
units/CMakeFiles/units.dir/unit.cpp.o: units/unit.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/anthony/sekai/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object units/CMakeFiles/units.dir/unit.cpp.o"
	cd /home/anthony/sekai/units && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/units.dir/unit.cpp.o -c /home/anthony/sekai/units/unit.cpp

units/CMakeFiles/units.dir/unit.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/units.dir/unit.cpp.i"
	cd /home/anthony/sekai/units && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/anthony/sekai/units/unit.cpp > CMakeFiles/units.dir/unit.cpp.i

units/CMakeFiles/units.dir/unit.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/units.dir/unit.cpp.s"
	cd /home/anthony/sekai/units && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/anthony/sekai/units/unit.cpp -o CMakeFiles/units.dir/unit.cpp.s

units/CMakeFiles/units.dir/unit.cpp.o.requires:
.PHONY : units/CMakeFiles/units.dir/unit.cpp.o.requires

units/CMakeFiles/units.dir/unit.cpp.o.provides: units/CMakeFiles/units.dir/unit.cpp.o.requires
	$(MAKE) -f units/CMakeFiles/units.dir/build.make units/CMakeFiles/units.dir/unit.cpp.o.provides.build
.PHONY : units/CMakeFiles/units.dir/unit.cpp.o.provides

units/CMakeFiles/units.dir/unit.cpp.o.provides.build: units/CMakeFiles/units.dir/unit.cpp.o

units/CMakeFiles/units.dir/saylith.cpp.o: units/CMakeFiles/units.dir/flags.make
units/CMakeFiles/units.dir/saylith.cpp.o: units/saylith.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/anthony/sekai/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object units/CMakeFiles/units.dir/saylith.cpp.o"
	cd /home/anthony/sekai/units && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/units.dir/saylith.cpp.o -c /home/anthony/sekai/units/saylith.cpp

units/CMakeFiles/units.dir/saylith.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/units.dir/saylith.cpp.i"
	cd /home/anthony/sekai/units && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/anthony/sekai/units/saylith.cpp > CMakeFiles/units.dir/saylith.cpp.i

units/CMakeFiles/units.dir/saylith.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/units.dir/saylith.cpp.s"
	cd /home/anthony/sekai/units && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/anthony/sekai/units/saylith.cpp -o CMakeFiles/units.dir/saylith.cpp.s

units/CMakeFiles/units.dir/saylith.cpp.o.requires:
.PHONY : units/CMakeFiles/units.dir/saylith.cpp.o.requires

units/CMakeFiles/units.dir/saylith.cpp.o.provides: units/CMakeFiles/units.dir/saylith.cpp.o.requires
	$(MAKE) -f units/CMakeFiles/units.dir/build.make units/CMakeFiles/units.dir/saylith.cpp.o.provides.build
.PHONY : units/CMakeFiles/units.dir/saylith.cpp.o.provides

units/CMakeFiles/units.dir/saylith.cpp.o.provides.build: units/CMakeFiles/units.dir/saylith.cpp.o

# Object files for target units
units_OBJECTS = \
"CMakeFiles/units.dir/unit.cpp.o" \
"CMakeFiles/units.dir/saylith.cpp.o"

# External object files for target units
units_EXTERNAL_OBJECTS =

units/libunits.a: units/CMakeFiles/units.dir/unit.cpp.o
units/libunits.a: units/CMakeFiles/units.dir/saylith.cpp.o
units/libunits.a: units/CMakeFiles/units.dir/build.make
units/libunits.a: units/CMakeFiles/units.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX static library libunits.a"
	cd /home/anthony/sekai/units && $(CMAKE_COMMAND) -P CMakeFiles/units.dir/cmake_clean_target.cmake
	cd /home/anthony/sekai/units && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/units.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
units/CMakeFiles/units.dir/build: units/libunits.a
.PHONY : units/CMakeFiles/units.dir/build

units/CMakeFiles/units.dir/requires: units/CMakeFiles/units.dir/unit.cpp.o.requires
units/CMakeFiles/units.dir/requires: units/CMakeFiles/units.dir/saylith.cpp.o.requires
.PHONY : units/CMakeFiles/units.dir/requires

units/CMakeFiles/units.dir/clean:
	cd /home/anthony/sekai/units && $(CMAKE_COMMAND) -P CMakeFiles/units.dir/cmake_clean.cmake
.PHONY : units/CMakeFiles/units.dir/clean

units/CMakeFiles/units.dir/depend:
	cd /home/anthony/sekai && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/anthony/sekai /home/anthony/sekai/units /home/anthony/sekai /home/anthony/sekai/units /home/anthony/sekai/units/CMakeFiles/units.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : units/CMakeFiles/units.dir/depend

