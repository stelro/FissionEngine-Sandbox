# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.6

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
CMAKE_COMMAND = /home/stel/clion-2016.2.1/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/stel/clion-2016.2.1/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/stel/Game/Game

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/stel/Game/Game/cmake-build-debug

# Include any dependencies generated for this target.
include SnakeGame/CMakeFiles/SnakeGame.dir/depend.make

# Include the progress variables for this target.
include SnakeGame/CMakeFiles/SnakeGame.dir/progress.make

# Include the compile flags for this target's objects.
include SnakeGame/CMakeFiles/SnakeGame.dir/flags.make

SnakeGame/CMakeFiles/SnakeGame.dir/Source/main.cpp.o: SnakeGame/CMakeFiles/SnakeGame.dir/flags.make
SnakeGame/CMakeFiles/SnakeGame.dir/Source/main.cpp.o: ../SnakeGame/Source/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/stel/Game/Game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object SnakeGame/CMakeFiles/SnakeGame.dir/Source/main.cpp.o"
	cd /home/stel/Game/Game/cmake-build-debug/SnakeGame && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SnakeGame.dir/Source/main.cpp.o -c /home/stel/Game/Game/SnakeGame/Source/main.cpp

SnakeGame/CMakeFiles/SnakeGame.dir/Source/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SnakeGame.dir/Source/main.cpp.i"
	cd /home/stel/Game/Game/cmake-build-debug/SnakeGame && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/stel/Game/Game/SnakeGame/Source/main.cpp > CMakeFiles/SnakeGame.dir/Source/main.cpp.i

SnakeGame/CMakeFiles/SnakeGame.dir/Source/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SnakeGame.dir/Source/main.cpp.s"
	cd /home/stel/Game/Game/cmake-build-debug/SnakeGame && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/stel/Game/Game/SnakeGame/Source/main.cpp -o CMakeFiles/SnakeGame.dir/Source/main.cpp.s

SnakeGame/CMakeFiles/SnakeGame.dir/Source/main.cpp.o.requires:

.PHONY : SnakeGame/CMakeFiles/SnakeGame.dir/Source/main.cpp.o.requires

SnakeGame/CMakeFiles/SnakeGame.dir/Source/main.cpp.o.provides: SnakeGame/CMakeFiles/SnakeGame.dir/Source/main.cpp.o.requires
	$(MAKE) -f SnakeGame/CMakeFiles/SnakeGame.dir/build.make SnakeGame/CMakeFiles/SnakeGame.dir/Source/main.cpp.o.provides.build
.PHONY : SnakeGame/CMakeFiles/SnakeGame.dir/Source/main.cpp.o.provides

SnakeGame/CMakeFiles/SnakeGame.dir/Source/main.cpp.o.provides.build: SnakeGame/CMakeFiles/SnakeGame.dir/Source/main.cpp.o


SnakeGame/CMakeFiles/SnakeGame.dir/Source/MainGame.cpp.o: SnakeGame/CMakeFiles/SnakeGame.dir/flags.make
SnakeGame/CMakeFiles/SnakeGame.dir/Source/MainGame.cpp.o: ../SnakeGame/Source/MainGame.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/stel/Game/Game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object SnakeGame/CMakeFiles/SnakeGame.dir/Source/MainGame.cpp.o"
	cd /home/stel/Game/Game/cmake-build-debug/SnakeGame && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SnakeGame.dir/Source/MainGame.cpp.o -c /home/stel/Game/Game/SnakeGame/Source/MainGame.cpp

SnakeGame/CMakeFiles/SnakeGame.dir/Source/MainGame.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SnakeGame.dir/Source/MainGame.cpp.i"
	cd /home/stel/Game/Game/cmake-build-debug/SnakeGame && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/stel/Game/Game/SnakeGame/Source/MainGame.cpp > CMakeFiles/SnakeGame.dir/Source/MainGame.cpp.i

SnakeGame/CMakeFiles/SnakeGame.dir/Source/MainGame.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SnakeGame.dir/Source/MainGame.cpp.s"
	cd /home/stel/Game/Game/cmake-build-debug/SnakeGame && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/stel/Game/Game/SnakeGame/Source/MainGame.cpp -o CMakeFiles/SnakeGame.dir/Source/MainGame.cpp.s

SnakeGame/CMakeFiles/SnakeGame.dir/Source/MainGame.cpp.o.requires:

.PHONY : SnakeGame/CMakeFiles/SnakeGame.dir/Source/MainGame.cpp.o.requires

SnakeGame/CMakeFiles/SnakeGame.dir/Source/MainGame.cpp.o.provides: SnakeGame/CMakeFiles/SnakeGame.dir/Source/MainGame.cpp.o.requires
	$(MAKE) -f SnakeGame/CMakeFiles/SnakeGame.dir/build.make SnakeGame/CMakeFiles/SnakeGame.dir/Source/MainGame.cpp.o.provides.build
.PHONY : SnakeGame/CMakeFiles/SnakeGame.dir/Source/MainGame.cpp.o.provides

SnakeGame/CMakeFiles/SnakeGame.dir/Source/MainGame.cpp.o.provides.build: SnakeGame/CMakeFiles/SnakeGame.dir/Source/MainGame.cpp.o


SnakeGame/CMakeFiles/SnakeGame.dir/Source/Snake.cpp.o: SnakeGame/CMakeFiles/SnakeGame.dir/flags.make
SnakeGame/CMakeFiles/SnakeGame.dir/Source/Snake.cpp.o: ../SnakeGame/Source/Snake.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/stel/Game/Game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object SnakeGame/CMakeFiles/SnakeGame.dir/Source/Snake.cpp.o"
	cd /home/stel/Game/Game/cmake-build-debug/SnakeGame && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SnakeGame.dir/Source/Snake.cpp.o -c /home/stel/Game/Game/SnakeGame/Source/Snake.cpp

SnakeGame/CMakeFiles/SnakeGame.dir/Source/Snake.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SnakeGame.dir/Source/Snake.cpp.i"
	cd /home/stel/Game/Game/cmake-build-debug/SnakeGame && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/stel/Game/Game/SnakeGame/Source/Snake.cpp > CMakeFiles/SnakeGame.dir/Source/Snake.cpp.i

SnakeGame/CMakeFiles/SnakeGame.dir/Source/Snake.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SnakeGame.dir/Source/Snake.cpp.s"
	cd /home/stel/Game/Game/cmake-build-debug/SnakeGame && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/stel/Game/Game/SnakeGame/Source/Snake.cpp -o CMakeFiles/SnakeGame.dir/Source/Snake.cpp.s

SnakeGame/CMakeFiles/SnakeGame.dir/Source/Snake.cpp.o.requires:

.PHONY : SnakeGame/CMakeFiles/SnakeGame.dir/Source/Snake.cpp.o.requires

SnakeGame/CMakeFiles/SnakeGame.dir/Source/Snake.cpp.o.provides: SnakeGame/CMakeFiles/SnakeGame.dir/Source/Snake.cpp.o.requires
	$(MAKE) -f SnakeGame/CMakeFiles/SnakeGame.dir/build.make SnakeGame/CMakeFiles/SnakeGame.dir/Source/Snake.cpp.o.provides.build
.PHONY : SnakeGame/CMakeFiles/SnakeGame.dir/Source/Snake.cpp.o.provides

SnakeGame/CMakeFiles/SnakeGame.dir/Source/Snake.cpp.o.provides.build: SnakeGame/CMakeFiles/SnakeGame.dir/Source/Snake.cpp.o


# Object files for target SnakeGame
SnakeGame_OBJECTS = \
"CMakeFiles/SnakeGame.dir/Source/main.cpp.o" \
"CMakeFiles/SnakeGame.dir/Source/MainGame.cpp.o" \
"CMakeFiles/SnakeGame.dir/Source/Snake.cpp.o"

# External object files for target SnakeGame
SnakeGame_EXTERNAL_OBJECTS =

../SnakeGame/SnakeGame: SnakeGame/CMakeFiles/SnakeGame.dir/Source/main.cpp.o
../SnakeGame/SnakeGame: SnakeGame/CMakeFiles/SnakeGame.dir/Source/MainGame.cpp.o
../SnakeGame/SnakeGame: SnakeGame/CMakeFiles/SnakeGame.dir/Source/Snake.cpp.o
../SnakeGame/SnakeGame: SnakeGame/CMakeFiles/SnakeGame.dir/build.make
../SnakeGame/SnakeGame: FissionEngine/libFissionEngine.a
../SnakeGame/SnakeGame: /usr/lib/x86_64-linux-gnu/libSDL2main.a
../SnakeGame/SnakeGame: /usr/lib/x86_64-linux-gnu/libSDL2.so
../SnakeGame/SnakeGame: /usr/lib/x86_64-linux-gnu/libSDL2_ttf.so
../SnakeGame/SnakeGame: /usr/lib/x86_64-linux-gnu/libSDL2_image.so
../SnakeGame/SnakeGame: /usr/lib/x86_64-linux-gnu/libSDL2_mixer.so
../SnakeGame/SnakeGame: /usr/lib/x86_64-linux-gnu/libGLU.so
../SnakeGame/SnakeGame: /usr/lib/x86_64-linux-gnu/libGL.so
../SnakeGame/SnakeGame: SnakeGame/CMakeFiles/SnakeGame.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/stel/Game/Game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable ../../SnakeGame/SnakeGame"
	cd /home/stel/Game/Game/cmake-build-debug/SnakeGame && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SnakeGame.dir/link.txt --verbose=$(VERBOSE)
	cd /home/stel/Game/Game/cmake-build-debug/SnakeGame && /home/stel/clion-2016.2.1/bin/cmake/bin/cmake -E copy_directory /home/stel/Game/Game/Shaders /home/stel/Game/Game/SnakeGame/Shaders
	cd /home/stel/Game/Game/cmake-build-debug/SnakeGame && /home/stel/clion-2016.2.1/bin/cmake/bin/cmake -E copy_directory /home/stel/Game/Game/Fonts /home/stel/Game/Game/SnakeGame/Fonts
	cd /home/stel/Game/Game/cmake-build-debug/SnakeGame && /home/stel/clion-2016.2.1/bin/cmake/bin/cmake -E copy_directory /home/stel/Game/Game/Sounds /home/stel/Game/Game/SnakeGame/Sounds

# Rule to build all files generated by this target.
SnakeGame/CMakeFiles/SnakeGame.dir/build: ../SnakeGame/SnakeGame

.PHONY : SnakeGame/CMakeFiles/SnakeGame.dir/build

SnakeGame/CMakeFiles/SnakeGame.dir/requires: SnakeGame/CMakeFiles/SnakeGame.dir/Source/main.cpp.o.requires
SnakeGame/CMakeFiles/SnakeGame.dir/requires: SnakeGame/CMakeFiles/SnakeGame.dir/Source/MainGame.cpp.o.requires
SnakeGame/CMakeFiles/SnakeGame.dir/requires: SnakeGame/CMakeFiles/SnakeGame.dir/Source/Snake.cpp.o.requires

.PHONY : SnakeGame/CMakeFiles/SnakeGame.dir/requires

SnakeGame/CMakeFiles/SnakeGame.dir/clean:
	cd /home/stel/Game/Game/cmake-build-debug/SnakeGame && $(CMAKE_COMMAND) -P CMakeFiles/SnakeGame.dir/cmake_clean.cmake
.PHONY : SnakeGame/CMakeFiles/SnakeGame.dir/clean

SnakeGame/CMakeFiles/SnakeGame.dir/depend:
	cd /home/stel/Game/Game/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/stel/Game/Game /home/stel/Game/Game/SnakeGame /home/stel/Game/Game/cmake-build-debug /home/stel/Game/Game/cmake-build-debug/SnakeGame /home/stel/Game/Game/cmake-build-debug/SnakeGame/CMakeFiles/SnakeGame.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : SnakeGame/CMakeFiles/SnakeGame.dir/depend

