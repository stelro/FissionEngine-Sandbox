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
include openGLExamples/CMakeFiles/openGLExamples.dir/depend.make

# Include the progress variables for this target.
include openGLExamples/CMakeFiles/openGLExamples.dir/progress.make

# Include the compile flags for this target's objects.
include openGLExamples/CMakeFiles/openGLExamples.dir/flags.make

openGLExamples/CMakeFiles/openGLExamples.dir/main.cpp.o: openGLExamples/CMakeFiles/openGLExamples.dir/flags.make
openGLExamples/CMakeFiles/openGLExamples.dir/main.cpp.o: ../openGLExamples/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/stel/Game/Game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object openGLExamples/CMakeFiles/openGLExamples.dir/main.cpp.o"
	cd /home/stel/Game/Game/cmake-build-debug/openGLExamples && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/openGLExamples.dir/main.cpp.o -c /home/stel/Game/Game/openGLExamples/main.cpp

openGLExamples/CMakeFiles/openGLExamples.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/openGLExamples.dir/main.cpp.i"
	cd /home/stel/Game/Game/cmake-build-debug/openGLExamples && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/stel/Game/Game/openGLExamples/main.cpp > CMakeFiles/openGLExamples.dir/main.cpp.i

openGLExamples/CMakeFiles/openGLExamples.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/openGLExamples.dir/main.cpp.s"
	cd /home/stel/Game/Game/cmake-build-debug/openGLExamples && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/stel/Game/Game/openGLExamples/main.cpp -o CMakeFiles/openGLExamples.dir/main.cpp.s

openGLExamples/CMakeFiles/openGLExamples.dir/main.cpp.o.requires:

.PHONY : openGLExamples/CMakeFiles/openGLExamples.dir/main.cpp.o.requires

openGLExamples/CMakeFiles/openGLExamples.dir/main.cpp.o.provides: openGLExamples/CMakeFiles/openGLExamples.dir/main.cpp.o.requires
	$(MAKE) -f openGLExamples/CMakeFiles/openGLExamples.dir/build.make openGLExamples/CMakeFiles/openGLExamples.dir/main.cpp.o.provides.build
.PHONY : openGLExamples/CMakeFiles/openGLExamples.dir/main.cpp.o.provides

openGLExamples/CMakeFiles/openGLExamples.dir/main.cpp.o.provides.build: openGLExamples/CMakeFiles/openGLExamples.dir/main.cpp.o


openGLExamples/CMakeFiles/openGLExamples.dir/__/Editor/main.cpp.o: openGLExamples/CMakeFiles/openGLExamples.dir/flags.make
openGLExamples/CMakeFiles/openGLExamples.dir/__/Editor/main.cpp.o: ../Editor/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/stel/Game/Game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object openGLExamples/CMakeFiles/openGLExamples.dir/__/Editor/main.cpp.o"
	cd /home/stel/Game/Game/cmake-build-debug/openGLExamples && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/openGLExamples.dir/__/Editor/main.cpp.o -c /home/stel/Game/Game/Editor/main.cpp

openGLExamples/CMakeFiles/openGLExamples.dir/__/Editor/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/openGLExamples.dir/__/Editor/main.cpp.i"
	cd /home/stel/Game/Game/cmake-build-debug/openGLExamples && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/stel/Game/Game/Editor/main.cpp > CMakeFiles/openGLExamples.dir/__/Editor/main.cpp.i

openGLExamples/CMakeFiles/openGLExamples.dir/__/Editor/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/openGLExamples.dir/__/Editor/main.cpp.s"
	cd /home/stel/Game/Game/cmake-build-debug/openGLExamples && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/stel/Game/Game/Editor/main.cpp -o CMakeFiles/openGLExamples.dir/__/Editor/main.cpp.s

openGLExamples/CMakeFiles/openGLExamples.dir/__/Editor/main.cpp.o.requires:

.PHONY : openGLExamples/CMakeFiles/openGLExamples.dir/__/Editor/main.cpp.o.requires

openGLExamples/CMakeFiles/openGLExamples.dir/__/Editor/main.cpp.o.provides: openGLExamples/CMakeFiles/openGLExamples.dir/__/Editor/main.cpp.o.requires
	$(MAKE) -f openGLExamples/CMakeFiles/openGLExamples.dir/build.make openGLExamples/CMakeFiles/openGLExamples.dir/__/Editor/main.cpp.o.provides.build
.PHONY : openGLExamples/CMakeFiles/openGLExamples.dir/__/Editor/main.cpp.o.provides

openGLExamples/CMakeFiles/openGLExamples.dir/__/Editor/main.cpp.o.provides.build: openGLExamples/CMakeFiles/openGLExamples.dir/__/Editor/main.cpp.o


# Object files for target openGLExamples
openGLExamples_OBJECTS = \
"CMakeFiles/openGLExamples.dir/main.cpp.o" \
"CMakeFiles/openGLExamples.dir/__/Editor/main.cpp.o"

# External object files for target openGLExamples
openGLExamples_EXTERNAL_OBJECTS =

../openGLExamples/openGLExamples: openGLExamples/CMakeFiles/openGLExamples.dir/main.cpp.o
../openGLExamples/openGLExamples: openGLExamples/CMakeFiles/openGLExamples.dir/__/Editor/main.cpp.o
../openGLExamples/openGLExamples: openGLExamples/CMakeFiles/openGLExamples.dir/build.make
../openGLExamples/openGLExamples: FissionEngine/libFissionEngine.a
../openGLExamples/openGLExamples: /usr/lib/x86_64-linux-gnu/libSDL2main.a
../openGLExamples/openGLExamples: /usr/lib/x86_64-linux-gnu/libSDL2.so
../openGLExamples/openGLExamples: /usr/lib/x86_64-linux-gnu/libSDL2_ttf.so
../openGLExamples/openGLExamples: /usr/lib/x86_64-linux-gnu/libSDL2_image.so
../openGLExamples/openGLExamples: /usr/lib/x86_64-linux-gnu/libSDL2_mixer.so
../openGLExamples/openGLExamples: /usr/lib/x86_64-linux-gnu/libGLU.so
../openGLExamples/openGLExamples: /usr/lib/x86_64-linux-gnu/libGL.so
../openGLExamples/openGLExamples: /usr/lib/x86_64-linux-gnu/liblua5.3.so
../openGLExamples/openGLExamples: openGLExamples/CMakeFiles/openGLExamples.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/stel/Game/Game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable ../../openGLExamples/openGLExamples"
	cd /home/stel/Game/Game/cmake-build-debug/openGLExamples && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/openGLExamples.dir/link.txt --verbose=$(VERBOSE)
	cd /home/stel/Game/Game/cmake-build-debug/openGLExamples && /home/stel/clion-2017.1.1/bin/cmake/bin/cmake -E copy_directory /home/stel/Game/Game/Shaders /home/stel/Game/Game/openGLExamples/Shaders

# Rule to build all files generated by this target.
openGLExamples/CMakeFiles/openGLExamples.dir/build: ../openGLExamples/openGLExamples

.PHONY : openGLExamples/CMakeFiles/openGLExamples.dir/build

openGLExamples/CMakeFiles/openGLExamples.dir/requires: openGLExamples/CMakeFiles/openGLExamples.dir/main.cpp.o.requires
openGLExamples/CMakeFiles/openGLExamples.dir/requires: openGLExamples/CMakeFiles/openGLExamples.dir/__/Editor/main.cpp.o.requires

.PHONY : openGLExamples/CMakeFiles/openGLExamples.dir/requires

openGLExamples/CMakeFiles/openGLExamples.dir/clean:
	cd /home/stel/Game/Game/cmake-build-debug/openGLExamples && $(CMAKE_COMMAND) -P CMakeFiles/openGLExamples.dir/cmake_clean.cmake
.PHONY : openGLExamples/CMakeFiles/openGLExamples.dir/clean

openGLExamples/CMakeFiles/openGLExamples.dir/depend:
	cd /home/stel/Game/Game/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/stel/Game/Game /home/stel/Game/Game/openGLExamples /home/stel/Game/Game/cmake-build-debug /home/stel/Game/Game/cmake-build-debug/openGLExamples /home/stel/Game/Game/cmake-build-debug/openGLExamples/CMakeFiles/openGLExamples.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : openGLExamples/CMakeFiles/openGLExamples.dir/depend

