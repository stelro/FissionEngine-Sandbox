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
include bomberman/CMakeFiles/bomberman.dir/depend.make

# Include the progress variables for this target.
include bomberman/CMakeFiles/bomberman.dir/progress.make

# Include the compile flags for this target's objects.
include bomberman/CMakeFiles/bomberman.dir/flags.make

# Object files for target bomberman
bomberman_OBJECTS =

# External object files for target bomberman
bomberman_EXTERNAL_OBJECTS =

../bomberman/bomberman: bomberman/CMakeFiles/bomberman.dir/build.make
../bomberman/bomberman: FissionEngine/libFissionEngine.a
../bomberman/bomberman: /usr/lib/x86_64-linux-gnu/libSDL2main.a
../bomberman/bomberman: /usr/lib/x86_64-linux-gnu/libSDL2.so
../bomberman/bomberman: /usr/lib/x86_64-linux-gnu/libSDL2_ttf.so
../bomberman/bomberman: /usr/lib/x86_64-linux-gnu/libSDL2_image.so
../bomberman/bomberman: /usr/lib/x86_64-linux-gnu/libSDL2_mixer.so
../bomberman/bomberman: /usr/lib/x86_64-linux-gnu/libGLU.so
../bomberman/bomberman: /usr/lib/x86_64-linux-gnu/libGL.so
../bomberman/bomberman: bomberman/CMakeFiles/bomberman.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/stel/Game/Game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Linking CXX executable ../../bomberman/bomberman"
	cd /home/stel/Game/Game/cmake-build-debug/bomberman && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/bomberman.dir/link.txt --verbose=$(VERBOSE)
	cd /home/stel/Game/Game/cmake-build-debug/bomberman && /home/stel/clion-2016.2.1/bin/cmake/bin/cmake -E copy_directory /home/stel/Game/Game/Shaders /home/stel/Game/Game/bomberman/Shaders
	cd /home/stel/Game/Game/cmake-build-debug/bomberman && /home/stel/clion-2016.2.1/bin/cmake/bin/cmake -E copy_directory /home/stel/Game/Game/Textures /home/stel/Game/Game/bomberman/Textures
	cd /home/stel/Game/Game/cmake-build-debug/bomberman && /home/stel/clion-2016.2.1/bin/cmake/bin/cmake -E copy_directory /home/stel/Game/Game/Levels /home/stel/Game/Game/bomberman/Levels
	cd /home/stel/Game/Game/cmake-build-debug/bomberman && /home/stel/clion-2016.2.1/bin/cmake/bin/cmake -E copy_directory /home/stel/Game/Game/Fonts /home/stel/Game/Game/bomberman/Fonts
	cd /home/stel/Game/Game/cmake-build-debug/bomberman && /home/stel/clion-2016.2.1/bin/cmake/bin/cmake -E copy_directory /home/stel/Game/Game/Sounds /home/stel/Game/Game/bomberman/Sounds

# Rule to build all files generated by this target.
bomberman/CMakeFiles/bomberman.dir/build: ../bomberman/bomberman

.PHONY : bomberman/CMakeFiles/bomberman.dir/build

bomberman/CMakeFiles/bomberman.dir/requires:

.PHONY : bomberman/CMakeFiles/bomberman.dir/requires

bomberman/CMakeFiles/bomberman.dir/clean:
	cd /home/stel/Game/Game/cmake-build-debug/bomberman && $(CMAKE_COMMAND) -P CMakeFiles/bomberman.dir/cmake_clean.cmake
.PHONY : bomberman/CMakeFiles/bomberman.dir/clean

bomberman/CMakeFiles/bomberman.dir/depend:
	cd /home/stel/Game/Game/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/stel/Game/Game /home/stel/Game/Game/bomberman /home/stel/Game/Game/cmake-build-debug /home/stel/Game/Game/cmake-build-debug/bomberman /home/stel/Game/Game/cmake-build-debug/bomberman/CMakeFiles/bomberman.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : bomberman/CMakeFiles/bomberman.dir/depend

