# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Produce verbose output by default.
VERBOSE = 1

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
CMAKE_COMMAND = /home/stel/clion-2017.1.1/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/stel/clion-2017.1.1/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/stel/Game/Game

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/stel/Game/Game/cmake-build-debug

# Include any dependencies generated for this target.
include SpaceX/CMakeFiles/SpaceX.dir/depend.make

# Include the progress variables for this target.
include SpaceX/CMakeFiles/SpaceX.dir/progress.make

# Include the compile flags for this target's objects.
include SpaceX/CMakeFiles/SpaceX.dir/flags.make

SpaceX/CMakeFiles/SpaceX.dir/main.cpp.o: SpaceX/CMakeFiles/SpaceX.dir/flags.make
SpaceX/CMakeFiles/SpaceX.dir/main.cpp.o: ../SpaceX/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/stel/Game/Game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object SpaceX/CMakeFiles/SpaceX.dir/main.cpp.o"
	cd /home/stel/Game/Game/cmake-build-debug/SpaceX && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SpaceX.dir/main.cpp.o -c /home/stel/Game/Game/SpaceX/main.cpp

SpaceX/CMakeFiles/SpaceX.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SpaceX.dir/main.cpp.i"
	cd /home/stel/Game/Game/cmake-build-debug/SpaceX && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/stel/Game/Game/SpaceX/main.cpp > CMakeFiles/SpaceX.dir/main.cpp.i

SpaceX/CMakeFiles/SpaceX.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SpaceX.dir/main.cpp.s"
	cd /home/stel/Game/Game/cmake-build-debug/SpaceX && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/stel/Game/Game/SpaceX/main.cpp -o CMakeFiles/SpaceX.dir/main.cpp.s

SpaceX/CMakeFiles/SpaceX.dir/main.cpp.o.requires:

.PHONY : SpaceX/CMakeFiles/SpaceX.dir/main.cpp.o.requires

SpaceX/CMakeFiles/SpaceX.dir/main.cpp.o.provides: SpaceX/CMakeFiles/SpaceX.dir/main.cpp.o.requires
	$(MAKE) -f SpaceX/CMakeFiles/SpaceX.dir/build.make SpaceX/CMakeFiles/SpaceX.dir/main.cpp.o.provides.build
.PHONY : SpaceX/CMakeFiles/SpaceX.dir/main.cpp.o.provides

SpaceX/CMakeFiles/SpaceX.dir/main.cpp.o.provides.build: SpaceX/CMakeFiles/SpaceX.dir/main.cpp.o


# Object files for target SpaceX
SpaceX_OBJECTS = \
"CMakeFiles/SpaceX.dir/main.cpp.o"

# External object files for target SpaceX
SpaceX_EXTERNAL_OBJECTS =

../SpaceX/SpaceX: SpaceX/CMakeFiles/SpaceX.dir/main.cpp.o
../SpaceX/SpaceX: SpaceX/CMakeFiles/SpaceX.dir/build.make
../SpaceX/SpaceX: lib/libFissionEngine.so
../SpaceX/SpaceX: /usr/lib/x86_64-linux-gnu/libSDL2main.a
../SpaceX/SpaceX: /usr/lib/x86_64-linux-gnu/libSDL2.so
../SpaceX/SpaceX: /usr/lib/x86_64-linux-gnu/libSDL2_ttf.so
../SpaceX/SpaceX: /usr/lib/x86_64-linux-gnu/libSDL2_image.so
../SpaceX/SpaceX: /usr/lib/x86_64-linux-gnu/libSDL2_mixer.so
../SpaceX/SpaceX: /usr/lib/x86_64-linux-gnu/libGLU.so
../SpaceX/SpaceX: /usr/lib/x86_64-linux-gnu/libGL.so
../SpaceX/SpaceX: /usr/lib/x86_64-linux-gnu/liblua5.3.so
../SpaceX/SpaceX: SpaceX/CMakeFiles/SpaceX.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/stel/Game/Game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../../SpaceX/SpaceX"
	cd /home/stel/Game/Game/cmake-build-debug/SpaceX && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SpaceX.dir/link.txt --verbose=$(VERBOSE)
	cd /home/stel/Game/Game/cmake-build-debug/SpaceX && /home/stel/clion-2017.1.1/bin/cmake/bin/cmake -E copy_directory /home/stel/Game/Game/Shaders /home/stel/Game/Game/SpaceX/Shaders
	cd /home/stel/Game/Game/cmake-build-debug/SpaceX && /home/stel/clion-2017.1.1/bin/cmake/bin/cmake -E copy_directory /home/stel/Game/Game/Assets /home/stel/Game/Game/SpaceX/Assets
	cd /home/stel/Game/Game/cmake-build-debug/SpaceX && /home/stel/clion-2017.1.1/bin/cmake/bin/cmake -E copy_directory /home/stel/Game/Game/Levels /home/stel/Game/Game/SpaceX/Levels
	cd /home/stel/Game/Game/cmake-build-debug/SpaceX && /home/stel/clion-2017.1.1/bin/cmake/bin/cmake -E copy_directory /home/stel/Game/Game/Scripts /home/stel/Game/Game/SpaceX/Scripts
	cd /home/stel/Game/Game/cmake-build-debug/SpaceX && /home/stel/clion-2017.1.1/bin/cmake/bin/cmake -E copy_directory /home/stel/Game/Game/Maps /home/stel/Game/Game/SpaceX/Maps

# Rule to build all files generated by this target.
SpaceX/CMakeFiles/SpaceX.dir/build: ../SpaceX/SpaceX

.PHONY : SpaceX/CMakeFiles/SpaceX.dir/build

SpaceX/CMakeFiles/SpaceX.dir/requires: SpaceX/CMakeFiles/SpaceX.dir/main.cpp.o.requires

.PHONY : SpaceX/CMakeFiles/SpaceX.dir/requires

SpaceX/CMakeFiles/SpaceX.dir/clean:
	cd /home/stel/Game/Game/cmake-build-debug/SpaceX && $(CMAKE_COMMAND) -P CMakeFiles/SpaceX.dir/cmake_clean.cmake
.PHONY : SpaceX/CMakeFiles/SpaceX.dir/clean

SpaceX/CMakeFiles/SpaceX.dir/depend:
	cd /home/stel/Game/Game/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/stel/Game/Game /home/stel/Game/Game/SpaceX /home/stel/Game/Game/cmake-build-debug /home/stel/Game/Game/cmake-build-debug/SpaceX /home/stel/Game/Game/cmake-build-debug/SpaceX/CMakeFiles/SpaceX.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : SpaceX/CMakeFiles/SpaceX.dir/depend

