# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/gnemirko/Documents/GitHub/GANemirko_33

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/gnemirko/Documents/GitHub/GANemirko_33/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/lab2c__.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/lab2c__.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lab2c__.dir/flags.make

CMakeFiles/lab2c__.dir/lab2.cpp.o: CMakeFiles/lab2c__.dir/flags.make
CMakeFiles/lab2c__.dir/lab2.cpp.o: ../lab2.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/gnemirko/Documents/GitHub/GANemirko_33/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/lab2c__.dir/lab2.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lab2c__.dir/lab2.cpp.o -c /Users/gnemirko/Documents/GitHub/GANemirko_33/lab2.cpp

CMakeFiles/lab2c__.dir/lab2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab2c__.dir/lab2.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/gnemirko/Documents/GitHub/GANemirko_33/lab2.cpp > CMakeFiles/lab2c__.dir/lab2.cpp.i

CMakeFiles/lab2c__.dir/lab2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab2c__.dir/lab2.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/gnemirko/Documents/GitHub/GANemirko_33/lab2.cpp -o CMakeFiles/lab2c__.dir/lab2.cpp.s

# Object files for target lab2c__
lab2c___OBJECTS = \
"CMakeFiles/lab2c__.dir/lab2.cpp.o"

# External object files for target lab2c__
lab2c___EXTERNAL_OBJECTS =

lab2c__: CMakeFiles/lab2c__.dir/lab2.cpp.o
lab2c__: CMakeFiles/lab2c__.dir/build.make
lab2c__: CMakeFiles/lab2c__.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/gnemirko/Documents/GitHub/GANemirko_33/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable lab2c__"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lab2c__.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lab2c__.dir/build: lab2c__

.PHONY : CMakeFiles/lab2c__.dir/build

CMakeFiles/lab2c__.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lab2c__.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lab2c__.dir/clean

CMakeFiles/lab2c__.dir/depend:
	cd /Users/gnemirko/Documents/GitHub/GANemirko_33/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/gnemirko/Documents/GitHub/GANemirko_33 /Users/gnemirko/Documents/GitHub/GANemirko_33 /Users/gnemirko/Documents/GitHub/GANemirko_33/cmake-build-debug /Users/gnemirko/Documents/GitHub/GANemirko_33/cmake-build-debug /Users/gnemirko/Documents/GitHub/GANemirko_33/cmake-build-debug/CMakeFiles/lab2c__.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lab2c__.dir/depend

