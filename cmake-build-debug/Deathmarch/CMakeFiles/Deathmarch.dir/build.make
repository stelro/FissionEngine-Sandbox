# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

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
CMAKE_COMMAND = /home/stel/clion-2017.3.3/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/stel/clion-2017.3.3/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/stel/Game/Game

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/stel/Game/Game/cmake-build-debug

# Include any dependencies generated for this target.
include Deathmarch/CMakeFiles/Deathmarch.dir/depend.make

# Include the progress variables for this target.
include Deathmarch/CMakeFiles/Deathmarch.dir/progress.make

# Include the compile flags for this target's objects.
include Deathmarch/CMakeFiles/Deathmarch.dir/flags.make

Deathmarch/CMakeFiles/Deathmarch.dir/Source/main.cpp.o: Deathmarch/CMakeFiles/Deathmarch.dir/flags.make
Deathmarch/CMakeFiles/Deathmarch.dir/Source/main.cpp.o: ../Deathmarch/Source/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/stel/Game/Game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Deathmarch/CMakeFiles/Deathmarch.dir/Source/main.cpp.o"
	cd /home/stel/Game/Game/cmake-build-debug/Deathmarch && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Deathmarch.dir/Source/main.cpp.o -c /home/stel/Game/Game/Deathmarch/Source/main.cpp

Deathmarch/CMakeFiles/Deathmarch.dir/Source/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Deathmarch.dir/Source/main.cpp.i"
	cd /home/stel/Game/Game/cmake-build-debug/Deathmarch && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/stel/Game/Game/Deathmarch/Source/main.cpp > CMakeFiles/Deathmarch.dir/Source/main.cpp.i

Deathmarch/CMakeFiles/Deathmarch.dir/Source/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Deathmarch.dir/Source/main.cpp.s"
	cd /home/stel/Game/Game/cmake-build-debug/Deathmarch && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/stel/Game/Game/Deathmarch/Source/main.cpp -o CMakeFiles/Deathmarch.dir/Source/main.cpp.s

Deathmarch/CMakeFiles/Deathmarch.dir/Source/main.cpp.o.requires:

.PHONY : Deathmarch/CMakeFiles/Deathmarch.dir/Source/main.cpp.o.requires

Deathmarch/CMakeFiles/Deathmarch.dir/Source/main.cpp.o.provides: Deathmarch/CMakeFiles/Deathmarch.dir/Source/main.cpp.o.requires
	$(MAKE) -f Deathmarch/CMakeFiles/Deathmarch.dir/build.make Deathmarch/CMakeFiles/Deathmarch.dir/Source/main.cpp.o.provides.build
.PHONY : Deathmarch/CMakeFiles/Deathmarch.dir/Source/main.cpp.o.provides

Deathmarch/CMakeFiles/Deathmarch.dir/Source/main.cpp.o.provides.build: Deathmarch/CMakeFiles/Deathmarch.dir/Source/main.cpp.o


Deathmarch/CMakeFiles/Deathmarch.dir/Source/App.cpp.o: Deathmarch/CMakeFiles/Deathmarch.dir/flags.make
Deathmarch/CMakeFiles/Deathmarch.dir/Source/App.cpp.o: ../Deathmarch/Source/App.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/stel/Game/Game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object Deathmarch/CMakeFiles/Deathmarch.dir/Source/App.cpp.o"
	cd /home/stel/Game/Game/cmake-build-debug/Deathmarch && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Deathmarch.dir/Source/App.cpp.o -c /home/stel/Game/Game/Deathmarch/Source/App.cpp

Deathmarch/CMakeFiles/Deathmarch.dir/Source/App.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Deathmarch.dir/Source/App.cpp.i"
	cd /home/stel/Game/Game/cmake-build-debug/Deathmarch && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/stel/Game/Game/Deathmarch/Source/App.cpp > CMakeFiles/Deathmarch.dir/Source/App.cpp.i

Deathmarch/CMakeFiles/Deathmarch.dir/Source/App.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Deathmarch.dir/Source/App.cpp.s"
	cd /home/stel/Game/Game/cmake-build-debug/Deathmarch && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/stel/Game/Game/Deathmarch/Source/App.cpp -o CMakeFiles/Deathmarch.dir/Source/App.cpp.s

Deathmarch/CMakeFiles/Deathmarch.dir/Source/App.cpp.o.requires:

.PHONY : Deathmarch/CMakeFiles/Deathmarch.dir/Source/App.cpp.o.requires

Deathmarch/CMakeFiles/Deathmarch.dir/Source/App.cpp.o.provides: Deathmarch/CMakeFiles/Deathmarch.dir/Source/App.cpp.o.requires
	$(MAKE) -f Deathmarch/CMakeFiles/Deathmarch.dir/build.make Deathmarch/CMakeFiles/Deathmarch.dir/Source/App.cpp.o.provides.build
.PHONY : Deathmarch/CMakeFiles/Deathmarch.dir/Source/App.cpp.o.provides

Deathmarch/CMakeFiles/Deathmarch.dir/Source/App.cpp.o.provides.build: Deathmarch/CMakeFiles/Deathmarch.dir/Source/App.cpp.o


# Object files for target Deathmarch
Deathmarch_OBJECTS = \
"CMakeFiles/Deathmarch.dir/Source/main.cpp.o" \
"CMakeFiles/Deathmarch.dir/Source/App.cpp.o"

# External object files for target Deathmarch
Deathmarch_EXTERNAL_OBJECTS =

../Deathmarch/Deathmarch: Deathmarch/CMakeFiles/Deathmarch.dir/Source/main.cpp.o
../Deathmarch/Deathmarch: Deathmarch/CMakeFiles/Deathmarch.dir/Source/App.cpp.o
../Deathmarch/Deathmarch: Deathmarch/CMakeFiles/Deathmarch.dir/build.make
../Deathmarch/Deathmarch: lib/libFissionEngine.so
../Deathmarch/Deathmarch: /usr/lib/x86_64-linux-gnu/libSDL2main.a
../Deathmarch/Deathmarch: /usr/lib/x86_64-linux-gnu/libSDL2.so
../Deathmarch/Deathmarch: /usr/lib/x86_64-linux-gnu/libSDL2_ttf.so
../Deathmarch/Deathmarch: /usr/lib/x86_64-linux-gnu/libSDL2_image.so
../Deathmarch/Deathmarch: /usr/lib/x86_64-linux-gnu/libSDL2_mixer.so
../Deathmarch/Deathmarch: /usr/lib/x86_64-linux-gnu/libGLU.so
../Deathmarch/Deathmarch: /usr/lib/x86_64-linux-gnu/libGL.so
../Deathmarch/Deathmarch: /usr/lib/x86_64-linux-gnu/liblua5.3.so
../Deathmarch/Deathmarch: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so
../Deathmarch/Deathmarch: /usr/lib/x86_64-linux-gnu/libboost_system.so
../Deathmarch/Deathmarch: Deathmarch/CMakeFiles/Deathmarch.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/stel/Game/Game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable ../../Deathmarch/Deathmarch"
	cd /home/stel/Game/Game/cmake-build-debug/Deathmarch && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Deathmarch.dir/link.txt --verbose=$(VERBOSE)
	cd /home/stel/Game/Game/cmake-build-debug/Deathmarch && /home/stel/clion-2017.3.3/bin/cmake/bin/cmake -E copy_directory /home/stel/Game/Game/Shaders /home/stel/Game/Game/Deathmarch/Shaders
	cd /home/stel/Game/Game/cmake-build-debug/Deathmarch && /home/stel/clion-2017.3.3/bin/cmake/bin/cmake -E copy_directory /home/stel/Game/Game/Textures /home/stel/Game/Game/Deathmarch/Textures
	cd /home/stel/Game/Game/cmake-build-debug/Deathmarch && /home/stel/clion-2017.3.3/bin/cmake/bin/cmake -E copy_directory /home/stel/Game/Game/Levels /home/stel/Game/Game/Deathmarch/Levels
	cd /home/stel/Game/Game/cmake-build-debug/Deathmarch && /home/stel/clion-2017.3.3/bin/cmake/bin/cmake -E copy_directory /home/stel/Game/Game/Fonts /home/stel/Game/Game/Deathmarch/Fonts
	cd /home/stel/Game/Game/cmake-build-debug/Deathmarch && /home/stel/clion-2017.3.3/bin/cmake/bin/cmake -E copy_directory /home/stel/Game/Game/Sounds /home/stel/Game/Game/Deathmarch/Sounds
	cd /home/stel/Game/Game/cmake-build-debug/Deathmarch && /home/stel/clion-2017.3.3/bin/cmake/bin/cmake -E copy_directory /home/stel/Game/Game/Scripts /home/stel/Game/Game/Deathmarch/Scripts
	cd /home/stel/Game/Game/cmake-build-debug/Deathmarch && /home/stel/clion-2017.3.3/bin/cmake/bin/cmake -E copy_directory /home/stel/Game/Game/maps /home/stel/Game/Game/Deathmarch/maps

# Rule to build all files generated by this target.
Deathmarch/CMakeFiles/Deathmarch.dir/build: ../Deathmarch/Deathmarch

.PHONY : Deathmarch/CMakeFiles/Deathmarch.dir/build

Deathmarch/CMakeFiles/Deathmarch.dir/requires: Deathmarch/CMakeFiles/Deathmarch.dir/Source/main.cpp.o.requires
Deathmarch/CMakeFiles/Deathmarch.dir/requires: Deathmarch/CMakeFiles/Deathmarch.dir/Source/App.cpp.o.requires

.PHONY : Deathmarch/CMakeFiles/Deathmarch.dir/requires

Deathmarch/CMakeFiles/Deathmarch.dir/clean:
	cd /home/stel/Game/Game/cmake-build-debug/Deathmarch && $(CMAKE_COMMAND) -P CMakeFiles/Deathmarch.dir/cmake_clean.cmake
.PHONY : Deathmarch/CMakeFiles/Deathmarch.dir/clean

Deathmarch/CMakeFiles/Deathmarch.dir/depend:
	cd /home/stel/Game/Game/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/stel/Game/Game /home/stel/Game/Game/Deathmarch /home/stel/Game/Game/cmake-build-debug /home/stel/Game/Game/cmake-build-debug/Deathmarch /home/stel/Game/Game/cmake-build-debug/Deathmarch/CMakeFiles/Deathmarch.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Deathmarch/CMakeFiles/Deathmarch.dir/depend
