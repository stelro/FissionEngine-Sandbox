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
include UnitTest/CMakeFiles/UnitTest.dir/depend.make

# Include the progress variables for this target.
include UnitTest/CMakeFiles/UnitTest.dir/progress.make

# Include the compile flags for this target's objects.
include UnitTest/CMakeFiles/UnitTest.dir/flags.make

UnitTest/CMakeFiles/UnitTest.dir/main.cpp.o: UnitTest/CMakeFiles/UnitTest.dir/flags.make
UnitTest/CMakeFiles/UnitTest.dir/main.cpp.o: ../UnitTest/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/stel/Game/Game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object UnitTest/CMakeFiles/UnitTest.dir/main.cpp.o"
	cd /home/stel/Game/Game/cmake-build-debug/UnitTest && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/UnitTest.dir/main.cpp.o -c /home/stel/Game/Game/UnitTest/main.cpp

UnitTest/CMakeFiles/UnitTest.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/UnitTest.dir/main.cpp.i"
	cd /home/stel/Game/Game/cmake-build-debug/UnitTest && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/stel/Game/Game/UnitTest/main.cpp > CMakeFiles/UnitTest.dir/main.cpp.i

UnitTest/CMakeFiles/UnitTest.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/UnitTest.dir/main.cpp.s"
	cd /home/stel/Game/Game/cmake-build-debug/UnitTest && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/stel/Game/Game/UnitTest/main.cpp -o CMakeFiles/UnitTest.dir/main.cpp.s

UnitTest/CMakeFiles/UnitTest.dir/main.cpp.o.requires:

.PHONY : UnitTest/CMakeFiles/UnitTest.dir/main.cpp.o.requires

UnitTest/CMakeFiles/UnitTest.dir/main.cpp.o.provides: UnitTest/CMakeFiles/UnitTest.dir/main.cpp.o.requires
	$(MAKE) -f UnitTest/CMakeFiles/UnitTest.dir/build.make UnitTest/CMakeFiles/UnitTest.dir/main.cpp.o.provides.build
.PHONY : UnitTest/CMakeFiles/UnitTest.dir/main.cpp.o.provides

UnitTest/CMakeFiles/UnitTest.dir/main.cpp.o.provides.build: UnitTest/CMakeFiles/UnitTest.dir/main.cpp.o


UnitTest/CMakeFiles/UnitTest.dir/vec.t.cpp.o: UnitTest/CMakeFiles/UnitTest.dir/flags.make
UnitTest/CMakeFiles/UnitTest.dir/vec.t.cpp.o: ../UnitTest/vec.t.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/stel/Game/Game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object UnitTest/CMakeFiles/UnitTest.dir/vec.t.cpp.o"
	cd /home/stel/Game/Game/cmake-build-debug/UnitTest && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/UnitTest.dir/vec.t.cpp.o -c /home/stel/Game/Game/UnitTest/vec.t.cpp

UnitTest/CMakeFiles/UnitTest.dir/vec.t.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/UnitTest.dir/vec.t.cpp.i"
	cd /home/stel/Game/Game/cmake-build-debug/UnitTest && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/stel/Game/Game/UnitTest/vec.t.cpp > CMakeFiles/UnitTest.dir/vec.t.cpp.i

UnitTest/CMakeFiles/UnitTest.dir/vec.t.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/UnitTest.dir/vec.t.cpp.s"
	cd /home/stel/Game/Game/cmake-build-debug/UnitTest && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/stel/Game/Game/UnitTest/vec.t.cpp -o CMakeFiles/UnitTest.dir/vec.t.cpp.s

UnitTest/CMakeFiles/UnitTest.dir/vec.t.cpp.o.requires:

.PHONY : UnitTest/CMakeFiles/UnitTest.dir/vec.t.cpp.o.requires

UnitTest/CMakeFiles/UnitTest.dir/vec.t.cpp.o.provides: UnitTest/CMakeFiles/UnitTest.dir/vec.t.cpp.o.requires
	$(MAKE) -f UnitTest/CMakeFiles/UnitTest.dir/build.make UnitTest/CMakeFiles/UnitTest.dir/vec.t.cpp.o.provides.build
.PHONY : UnitTest/CMakeFiles/UnitTest.dir/vec.t.cpp.o.provides

UnitTest/CMakeFiles/UnitTest.dir/vec.t.cpp.o.provides.build: UnitTest/CMakeFiles/UnitTest.dir/vec.t.cpp.o


UnitTest/CMakeFiles/UnitTest.dir/__/SnakeGame/Source/main.cpp.o: UnitTest/CMakeFiles/UnitTest.dir/flags.make
UnitTest/CMakeFiles/UnitTest.dir/__/SnakeGame/Source/main.cpp.o: ../SnakeGame/Source/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/stel/Game/Game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object UnitTest/CMakeFiles/UnitTest.dir/__/SnakeGame/Source/main.cpp.o"
	cd /home/stel/Game/Game/cmake-build-debug/UnitTest && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/UnitTest.dir/__/SnakeGame/Source/main.cpp.o -c /home/stel/Game/Game/SnakeGame/Source/main.cpp

UnitTest/CMakeFiles/UnitTest.dir/__/SnakeGame/Source/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/UnitTest.dir/__/SnakeGame/Source/main.cpp.i"
	cd /home/stel/Game/Game/cmake-build-debug/UnitTest && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/stel/Game/Game/SnakeGame/Source/main.cpp > CMakeFiles/UnitTest.dir/__/SnakeGame/Source/main.cpp.i

UnitTest/CMakeFiles/UnitTest.dir/__/SnakeGame/Source/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/UnitTest.dir/__/SnakeGame/Source/main.cpp.s"
	cd /home/stel/Game/Game/cmake-build-debug/UnitTest && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/stel/Game/Game/SnakeGame/Source/main.cpp -o CMakeFiles/UnitTest.dir/__/SnakeGame/Source/main.cpp.s

UnitTest/CMakeFiles/UnitTest.dir/__/SnakeGame/Source/main.cpp.o.requires:

.PHONY : UnitTest/CMakeFiles/UnitTest.dir/__/SnakeGame/Source/main.cpp.o.requires

UnitTest/CMakeFiles/UnitTest.dir/__/SnakeGame/Source/main.cpp.o.provides: UnitTest/CMakeFiles/UnitTest.dir/__/SnakeGame/Source/main.cpp.o.requires
	$(MAKE) -f UnitTest/CMakeFiles/UnitTest.dir/build.make UnitTest/CMakeFiles/UnitTest.dir/__/SnakeGame/Source/main.cpp.o.provides.build
.PHONY : UnitTest/CMakeFiles/UnitTest.dir/__/SnakeGame/Source/main.cpp.o.provides

UnitTest/CMakeFiles/UnitTest.dir/__/SnakeGame/Source/main.cpp.o.provides.build: UnitTest/CMakeFiles/UnitTest.dir/__/SnakeGame/Source/main.cpp.o


# Object files for target UnitTest
UnitTest_OBJECTS = \
"CMakeFiles/UnitTest.dir/main.cpp.o" \
"CMakeFiles/UnitTest.dir/vec.t.cpp.o" \
"CMakeFiles/UnitTest.dir/__/SnakeGame/Source/main.cpp.o"

# External object files for target UnitTest
UnitTest_EXTERNAL_OBJECTS =

../UnitTest/UnitTest: UnitTest/CMakeFiles/UnitTest.dir/main.cpp.o
../UnitTest/UnitTest: UnitTest/CMakeFiles/UnitTest.dir/vec.t.cpp.o
../UnitTest/UnitTest: UnitTest/CMakeFiles/UnitTest.dir/__/SnakeGame/Source/main.cpp.o
../UnitTest/UnitTest: UnitTest/CMakeFiles/UnitTest.dir/build.make
../UnitTest/UnitTest: FissionEngine/libFissionEngine.a
../UnitTest/UnitTest: /usr/lib/x86_64-linux-gnu/libSDL2main.a
../UnitTest/UnitTest: /usr/lib/x86_64-linux-gnu/libSDL2.so
../UnitTest/UnitTest: /usr/lib/x86_64-linux-gnu/libSDL2_ttf.so
../UnitTest/UnitTest: /usr/lib/x86_64-linux-gnu/libSDL2_image.so
../UnitTest/UnitTest: /usr/lib/x86_64-linux-gnu/libSDL2_mixer.so
../UnitTest/UnitTest: /usr/lib/x86_64-linux-gnu/libGLU.so
../UnitTest/UnitTest: /usr/lib/x86_64-linux-gnu/libGL.so
../UnitTest/UnitTest: /usr/lib/x86_64-linux-gnu/liblua5.3.so
../UnitTest/UnitTest: UnitTest/CMakeFiles/UnitTest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/stel/Game/Game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable ../../UnitTest/UnitTest"
	cd /home/stel/Game/Game/cmake-build-debug/UnitTest && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/UnitTest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
UnitTest/CMakeFiles/UnitTest.dir/build: ../UnitTest/UnitTest

.PHONY : UnitTest/CMakeFiles/UnitTest.dir/build

UnitTest/CMakeFiles/UnitTest.dir/requires: UnitTest/CMakeFiles/UnitTest.dir/main.cpp.o.requires
UnitTest/CMakeFiles/UnitTest.dir/requires: UnitTest/CMakeFiles/UnitTest.dir/vec.t.cpp.o.requires
UnitTest/CMakeFiles/UnitTest.dir/requires: UnitTest/CMakeFiles/UnitTest.dir/__/SnakeGame/Source/main.cpp.o.requires

.PHONY : UnitTest/CMakeFiles/UnitTest.dir/requires

UnitTest/CMakeFiles/UnitTest.dir/clean:
	cd /home/stel/Game/Game/cmake-build-debug/UnitTest && $(CMAKE_COMMAND) -P CMakeFiles/UnitTest.dir/cmake_clean.cmake
.PHONY : UnitTest/CMakeFiles/UnitTest.dir/clean

UnitTest/CMakeFiles/UnitTest.dir/depend:
	cd /home/stel/Game/Game/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/stel/Game/Game /home/stel/Game/Game/UnitTest /home/stel/Game/Game/cmake-build-debug /home/stel/Game/Game/cmake-build-debug/UnitTest /home/stel/Game/Game/cmake-build-debug/UnitTest/CMakeFiles/UnitTest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : UnitTest/CMakeFiles/UnitTest.dir/depend

