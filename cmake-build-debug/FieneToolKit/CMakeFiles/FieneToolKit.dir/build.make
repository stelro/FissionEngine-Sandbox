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
include FieneToolKit/CMakeFiles/FieneToolKit.dir/depend.make

# Include the progress variables for this target.
include FieneToolKit/CMakeFiles/FieneToolKit.dir/progress.make

# Include the compile flags for this target's objects.
include FieneToolKit/CMakeFiles/FieneToolKit.dir/flags.make

FieneToolKit/CMakeFiles/FieneToolKit.dir/Source/main.cpp.o: FieneToolKit/CMakeFiles/FieneToolKit.dir/flags.make
FieneToolKit/CMakeFiles/FieneToolKit.dir/Source/main.cpp.o: ../FieneToolKit/Source/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/stel/Game/Game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object FieneToolKit/CMakeFiles/FieneToolKit.dir/Source/main.cpp.o"
	cd /home/stel/Game/Game/cmake-build-debug/FieneToolKit && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/FieneToolKit.dir/Source/main.cpp.o -c /home/stel/Game/Game/FieneToolKit/Source/main.cpp

FieneToolKit/CMakeFiles/FieneToolKit.dir/Source/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FieneToolKit.dir/Source/main.cpp.i"
	cd /home/stel/Game/Game/cmake-build-debug/FieneToolKit && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/stel/Game/Game/FieneToolKit/Source/main.cpp > CMakeFiles/FieneToolKit.dir/Source/main.cpp.i

FieneToolKit/CMakeFiles/FieneToolKit.dir/Source/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FieneToolKit.dir/Source/main.cpp.s"
	cd /home/stel/Game/Game/cmake-build-debug/FieneToolKit && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/stel/Game/Game/FieneToolKit/Source/main.cpp -o CMakeFiles/FieneToolKit.dir/Source/main.cpp.s

FieneToolKit/CMakeFiles/FieneToolKit.dir/Source/main.cpp.o.requires:

.PHONY : FieneToolKit/CMakeFiles/FieneToolKit.dir/Source/main.cpp.o.requires

FieneToolKit/CMakeFiles/FieneToolKit.dir/Source/main.cpp.o.provides: FieneToolKit/CMakeFiles/FieneToolKit.dir/Source/main.cpp.o.requires
	$(MAKE) -f FieneToolKit/CMakeFiles/FieneToolKit.dir/build.make FieneToolKit/CMakeFiles/FieneToolKit.dir/Source/main.cpp.o.provides.build
.PHONY : FieneToolKit/CMakeFiles/FieneToolKit.dir/Source/main.cpp.o.provides

FieneToolKit/CMakeFiles/FieneToolKit.dir/Source/main.cpp.o.provides.build: FieneToolKit/CMakeFiles/FieneToolKit.dir/Source/main.cpp.o


FieneToolKit/CMakeFiles/FieneToolKit.dir/Source/MainWindow.cpp.o: FieneToolKit/CMakeFiles/FieneToolKit.dir/flags.make
FieneToolKit/CMakeFiles/FieneToolKit.dir/Source/MainWindow.cpp.o: ../FieneToolKit/Source/MainWindow.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/stel/Game/Game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object FieneToolKit/CMakeFiles/FieneToolKit.dir/Source/MainWindow.cpp.o"
	cd /home/stel/Game/Game/cmake-build-debug/FieneToolKit && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/FieneToolKit.dir/Source/MainWindow.cpp.o -c /home/stel/Game/Game/FieneToolKit/Source/MainWindow.cpp

FieneToolKit/CMakeFiles/FieneToolKit.dir/Source/MainWindow.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FieneToolKit.dir/Source/MainWindow.cpp.i"
	cd /home/stel/Game/Game/cmake-build-debug/FieneToolKit && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/stel/Game/Game/FieneToolKit/Source/MainWindow.cpp > CMakeFiles/FieneToolKit.dir/Source/MainWindow.cpp.i

FieneToolKit/CMakeFiles/FieneToolKit.dir/Source/MainWindow.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FieneToolKit.dir/Source/MainWindow.cpp.s"
	cd /home/stel/Game/Game/cmake-build-debug/FieneToolKit && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/stel/Game/Game/FieneToolKit/Source/MainWindow.cpp -o CMakeFiles/FieneToolKit.dir/Source/MainWindow.cpp.s

FieneToolKit/CMakeFiles/FieneToolKit.dir/Source/MainWindow.cpp.o.requires:

.PHONY : FieneToolKit/CMakeFiles/FieneToolKit.dir/Source/MainWindow.cpp.o.requires

FieneToolKit/CMakeFiles/FieneToolKit.dir/Source/MainWindow.cpp.o.provides: FieneToolKit/CMakeFiles/FieneToolKit.dir/Source/MainWindow.cpp.o.requires
	$(MAKE) -f FieneToolKit/CMakeFiles/FieneToolKit.dir/build.make FieneToolKit/CMakeFiles/FieneToolKit.dir/Source/MainWindow.cpp.o.provides.build
.PHONY : FieneToolKit/CMakeFiles/FieneToolKit.dir/Source/MainWindow.cpp.o.provides

FieneToolKit/CMakeFiles/FieneToolKit.dir/Source/MainWindow.cpp.o.provides.build: FieneToolKit/CMakeFiles/FieneToolKit.dir/Source/MainWindow.cpp.o


FieneToolKit/CMakeFiles/FieneToolKit.dir/Source/MapEditor.cpp.o: FieneToolKit/CMakeFiles/FieneToolKit.dir/flags.make
FieneToolKit/CMakeFiles/FieneToolKit.dir/Source/MapEditor.cpp.o: ../FieneToolKit/Source/MapEditor.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/stel/Game/Game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object FieneToolKit/CMakeFiles/FieneToolKit.dir/Source/MapEditor.cpp.o"
	cd /home/stel/Game/Game/cmake-build-debug/FieneToolKit && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/FieneToolKit.dir/Source/MapEditor.cpp.o -c /home/stel/Game/Game/FieneToolKit/Source/MapEditor.cpp

FieneToolKit/CMakeFiles/FieneToolKit.dir/Source/MapEditor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FieneToolKit.dir/Source/MapEditor.cpp.i"
	cd /home/stel/Game/Game/cmake-build-debug/FieneToolKit && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/stel/Game/Game/FieneToolKit/Source/MapEditor.cpp > CMakeFiles/FieneToolKit.dir/Source/MapEditor.cpp.i

FieneToolKit/CMakeFiles/FieneToolKit.dir/Source/MapEditor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FieneToolKit.dir/Source/MapEditor.cpp.s"
	cd /home/stel/Game/Game/cmake-build-debug/FieneToolKit && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/stel/Game/Game/FieneToolKit/Source/MapEditor.cpp -o CMakeFiles/FieneToolKit.dir/Source/MapEditor.cpp.s

FieneToolKit/CMakeFiles/FieneToolKit.dir/Source/MapEditor.cpp.o.requires:

.PHONY : FieneToolKit/CMakeFiles/FieneToolKit.dir/Source/MapEditor.cpp.o.requires

FieneToolKit/CMakeFiles/FieneToolKit.dir/Source/MapEditor.cpp.o.provides: FieneToolKit/CMakeFiles/FieneToolKit.dir/Source/MapEditor.cpp.o.requires
	$(MAKE) -f FieneToolKit/CMakeFiles/FieneToolKit.dir/build.make FieneToolKit/CMakeFiles/FieneToolKit.dir/Source/MapEditor.cpp.o.provides.build
.PHONY : FieneToolKit/CMakeFiles/FieneToolKit.dir/Source/MapEditor.cpp.o.provides

FieneToolKit/CMakeFiles/FieneToolKit.dir/Source/MapEditor.cpp.o.provides.build: FieneToolKit/CMakeFiles/FieneToolKit.dir/Source/MapEditor.cpp.o


FieneToolKit/CMakeFiles/FieneToolKit.dir/Source/MapDocument.cpp.o: FieneToolKit/CMakeFiles/FieneToolKit.dir/flags.make
FieneToolKit/CMakeFiles/FieneToolKit.dir/Source/MapDocument.cpp.o: ../FieneToolKit/Source/MapDocument.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/stel/Game/Game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object FieneToolKit/CMakeFiles/FieneToolKit.dir/Source/MapDocument.cpp.o"
	cd /home/stel/Game/Game/cmake-build-debug/FieneToolKit && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/FieneToolKit.dir/Source/MapDocument.cpp.o -c /home/stel/Game/Game/FieneToolKit/Source/MapDocument.cpp

FieneToolKit/CMakeFiles/FieneToolKit.dir/Source/MapDocument.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FieneToolKit.dir/Source/MapDocument.cpp.i"
	cd /home/stel/Game/Game/cmake-build-debug/FieneToolKit && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/stel/Game/Game/FieneToolKit/Source/MapDocument.cpp > CMakeFiles/FieneToolKit.dir/Source/MapDocument.cpp.i

FieneToolKit/CMakeFiles/FieneToolKit.dir/Source/MapDocument.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FieneToolKit.dir/Source/MapDocument.cpp.s"
	cd /home/stel/Game/Game/cmake-build-debug/FieneToolKit && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/stel/Game/Game/FieneToolKit/Source/MapDocument.cpp -o CMakeFiles/FieneToolKit.dir/Source/MapDocument.cpp.s

FieneToolKit/CMakeFiles/FieneToolKit.dir/Source/MapDocument.cpp.o.requires:

.PHONY : FieneToolKit/CMakeFiles/FieneToolKit.dir/Source/MapDocument.cpp.o.requires

FieneToolKit/CMakeFiles/FieneToolKit.dir/Source/MapDocument.cpp.o.provides: FieneToolKit/CMakeFiles/FieneToolKit.dir/Source/MapDocument.cpp.o.requires
	$(MAKE) -f FieneToolKit/CMakeFiles/FieneToolKit.dir/build.make FieneToolKit/CMakeFiles/FieneToolKit.dir/Source/MapDocument.cpp.o.provides.build
.PHONY : FieneToolKit/CMakeFiles/FieneToolKit.dir/Source/MapDocument.cpp.o.provides

FieneToolKit/CMakeFiles/FieneToolKit.dir/Source/MapDocument.cpp.o.provides.build: FieneToolKit/CMakeFiles/FieneToolKit.dir/Source/MapDocument.cpp.o


FieneToolKit/CMakeFiles/FieneToolKit.dir/Source/AssetsBrowser.cpp.o: FieneToolKit/CMakeFiles/FieneToolKit.dir/flags.make
FieneToolKit/CMakeFiles/FieneToolKit.dir/Source/AssetsBrowser.cpp.o: ../FieneToolKit/Source/AssetsBrowser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/stel/Game/Game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object FieneToolKit/CMakeFiles/FieneToolKit.dir/Source/AssetsBrowser.cpp.o"
	cd /home/stel/Game/Game/cmake-build-debug/FieneToolKit && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/FieneToolKit.dir/Source/AssetsBrowser.cpp.o -c /home/stel/Game/Game/FieneToolKit/Source/AssetsBrowser.cpp

FieneToolKit/CMakeFiles/FieneToolKit.dir/Source/AssetsBrowser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FieneToolKit.dir/Source/AssetsBrowser.cpp.i"
	cd /home/stel/Game/Game/cmake-build-debug/FieneToolKit && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/stel/Game/Game/FieneToolKit/Source/AssetsBrowser.cpp > CMakeFiles/FieneToolKit.dir/Source/AssetsBrowser.cpp.i

FieneToolKit/CMakeFiles/FieneToolKit.dir/Source/AssetsBrowser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FieneToolKit.dir/Source/AssetsBrowser.cpp.s"
	cd /home/stel/Game/Game/cmake-build-debug/FieneToolKit && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/stel/Game/Game/FieneToolKit/Source/AssetsBrowser.cpp -o CMakeFiles/FieneToolKit.dir/Source/AssetsBrowser.cpp.s

FieneToolKit/CMakeFiles/FieneToolKit.dir/Source/AssetsBrowser.cpp.o.requires:

.PHONY : FieneToolKit/CMakeFiles/FieneToolKit.dir/Source/AssetsBrowser.cpp.o.requires

FieneToolKit/CMakeFiles/FieneToolKit.dir/Source/AssetsBrowser.cpp.o.provides: FieneToolKit/CMakeFiles/FieneToolKit.dir/Source/AssetsBrowser.cpp.o.requires
	$(MAKE) -f FieneToolKit/CMakeFiles/FieneToolKit.dir/build.make FieneToolKit/CMakeFiles/FieneToolKit.dir/Source/AssetsBrowser.cpp.o.provides.build
.PHONY : FieneToolKit/CMakeFiles/FieneToolKit.dir/Source/AssetsBrowser.cpp.o.provides

FieneToolKit/CMakeFiles/FieneToolKit.dir/Source/AssetsBrowser.cpp.o.provides.build: FieneToolKit/CMakeFiles/FieneToolKit.dir/Source/AssetsBrowser.cpp.o


# Object files for target FieneToolKit
FieneToolKit_OBJECTS = \
"CMakeFiles/FieneToolKit.dir/Source/main.cpp.o" \
"CMakeFiles/FieneToolKit.dir/Source/MainWindow.cpp.o" \
"CMakeFiles/FieneToolKit.dir/Source/MapEditor.cpp.o" \
"CMakeFiles/FieneToolKit.dir/Source/MapDocument.cpp.o" \
"CMakeFiles/FieneToolKit.dir/Source/AssetsBrowser.cpp.o"

# External object files for target FieneToolKit
FieneToolKit_EXTERNAL_OBJECTS =

../FieneToolKit/FieneToolKit: FieneToolKit/CMakeFiles/FieneToolKit.dir/Source/main.cpp.o
../FieneToolKit/FieneToolKit: FieneToolKit/CMakeFiles/FieneToolKit.dir/Source/MainWindow.cpp.o
../FieneToolKit/FieneToolKit: FieneToolKit/CMakeFiles/FieneToolKit.dir/Source/MapEditor.cpp.o
../FieneToolKit/FieneToolKit: FieneToolKit/CMakeFiles/FieneToolKit.dir/Source/MapDocument.cpp.o
../FieneToolKit/FieneToolKit: FieneToolKit/CMakeFiles/FieneToolKit.dir/Source/AssetsBrowser.cpp.o
../FieneToolKit/FieneToolKit: FieneToolKit/CMakeFiles/FieneToolKit.dir/build.make
../FieneToolKit/FieneToolKit: lib/libFissionEngine.so
../FieneToolKit/FieneToolKit: /usr/lib/x86_64-linux-gnu/libSDL2main.a
../FieneToolKit/FieneToolKit: /usr/lib/x86_64-linux-gnu/libSDL2.so
../FieneToolKit/FieneToolKit: /usr/lib/x86_64-linux-gnu/libSDL2_ttf.so
../FieneToolKit/FieneToolKit: /usr/lib/x86_64-linux-gnu/libSDL2_image.so
../FieneToolKit/FieneToolKit: /usr/lib/x86_64-linux-gnu/libSDL2_mixer.so
../FieneToolKit/FieneToolKit: /usr/lib/x86_64-linux-gnu/libGLU.so
../FieneToolKit/FieneToolKit: /usr/lib/x86_64-linux-gnu/libGL.so
../FieneToolKit/FieneToolKit: /usr/lib/x86_64-linux-gnu/liblua5.3.so
../FieneToolKit/FieneToolKit: FieneToolKit/CMakeFiles/FieneToolKit.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/stel/Game/Game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable ../../FieneToolKit/FieneToolKit"
	cd /home/stel/Game/Game/cmake-build-debug/FieneToolKit && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/FieneToolKit.dir/link.txt --verbose=$(VERBOSE)
	cd /home/stel/Game/Game/cmake-build-debug/FieneToolKit && /home/stel/clion-2017.1.1/bin/cmake/bin/cmake -E copy_directory /home/stel/Game/Game/Assets /home/stel/Game/Game/FieneToolKit/Assets
	cd /home/stel/Game/Game/cmake-build-debug/FieneToolKit && /home/stel/clion-2017.1.1/bin/cmake/bin/cmake -E copy_directory /home/stel/Game/Game/Shaders /home/stel/Game/Game/FieneToolKit/Shaders

# Rule to build all files generated by this target.
FieneToolKit/CMakeFiles/FieneToolKit.dir/build: ../FieneToolKit/FieneToolKit

.PHONY : FieneToolKit/CMakeFiles/FieneToolKit.dir/build

FieneToolKit/CMakeFiles/FieneToolKit.dir/requires: FieneToolKit/CMakeFiles/FieneToolKit.dir/Source/main.cpp.o.requires
FieneToolKit/CMakeFiles/FieneToolKit.dir/requires: FieneToolKit/CMakeFiles/FieneToolKit.dir/Source/MainWindow.cpp.o.requires
FieneToolKit/CMakeFiles/FieneToolKit.dir/requires: FieneToolKit/CMakeFiles/FieneToolKit.dir/Source/MapEditor.cpp.o.requires
FieneToolKit/CMakeFiles/FieneToolKit.dir/requires: FieneToolKit/CMakeFiles/FieneToolKit.dir/Source/MapDocument.cpp.o.requires
FieneToolKit/CMakeFiles/FieneToolKit.dir/requires: FieneToolKit/CMakeFiles/FieneToolKit.dir/Source/AssetsBrowser.cpp.o.requires

.PHONY : FieneToolKit/CMakeFiles/FieneToolKit.dir/requires

FieneToolKit/CMakeFiles/FieneToolKit.dir/clean:
	cd /home/stel/Game/Game/cmake-build-debug/FieneToolKit && $(CMAKE_COMMAND) -P CMakeFiles/FieneToolKit.dir/cmake_clean.cmake
.PHONY : FieneToolKit/CMakeFiles/FieneToolKit.dir/clean

FieneToolKit/CMakeFiles/FieneToolKit.dir/depend:
	cd /home/stel/Game/Game/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/stel/Game/Game /home/stel/Game/Game/FieneToolKit /home/stel/Game/Game/cmake-build-debug /home/stel/Game/Game/cmake-build-debug/FieneToolKit /home/stel/Game/Game/cmake-build-debug/FieneToolKit/CMakeFiles/FieneToolKit.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : FieneToolKit/CMakeFiles/FieneToolKit.dir/depend

