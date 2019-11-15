# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.10.1/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.10.1/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/Meow/Documents/physics/research/MoS2_graphene/cxx

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/Meow/Documents/physics/research/MoS2_graphene/cxx

# Include any dependencies generated for this target.
include CMakeFiles/SlaterKosterExt.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/SlaterKosterExt.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SlaterKosterExt.dir/flags.make

CMakeFiles/SlaterKosterExt.dir/src/SlatorKosterExt.cpp.o: CMakeFiles/SlaterKosterExt.dir/flags.make
CMakeFiles/SlaterKosterExt.dir/src/SlatorKosterExt.cpp.o: src/SlatorKosterExt.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Meow/Documents/physics/research/MoS2_graphene/cxx/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SlaterKosterExt.dir/src/SlatorKosterExt.cpp.o"
	clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SlaterKosterExt.dir/src/SlatorKosterExt.cpp.o -c /Users/Meow/Documents/physics/research/MoS2_graphene/cxx/src/SlatorKosterExt.cpp

CMakeFiles/SlaterKosterExt.dir/src/SlatorKosterExt.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SlaterKosterExt.dir/src/SlatorKosterExt.cpp.i"
	clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/Meow/Documents/physics/research/MoS2_graphene/cxx/src/SlatorKosterExt.cpp > CMakeFiles/SlaterKosterExt.dir/src/SlatorKosterExt.cpp.i

CMakeFiles/SlaterKosterExt.dir/src/SlatorKosterExt.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SlaterKosterExt.dir/src/SlatorKosterExt.cpp.s"
	clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/Meow/Documents/physics/research/MoS2_graphene/cxx/src/SlatorKosterExt.cpp -o CMakeFiles/SlaterKosterExt.dir/src/SlatorKosterExt.cpp.s

CMakeFiles/SlaterKosterExt.dir/src/SlatorKosterExt.cpp.o.requires:

.PHONY : CMakeFiles/SlaterKosterExt.dir/src/SlatorKosterExt.cpp.o.requires

CMakeFiles/SlaterKosterExt.dir/src/SlatorKosterExt.cpp.o.provides: CMakeFiles/SlaterKosterExt.dir/src/SlatorKosterExt.cpp.o.requires
	$(MAKE) -f CMakeFiles/SlaterKosterExt.dir/build.make CMakeFiles/SlaterKosterExt.dir/src/SlatorKosterExt.cpp.o.provides.build
.PHONY : CMakeFiles/SlaterKosterExt.dir/src/SlatorKosterExt.cpp.o.provides

CMakeFiles/SlaterKosterExt.dir/src/SlatorKosterExt.cpp.o.provides.build: CMakeFiles/SlaterKosterExt.dir/src/SlatorKosterExt.cpp.o


# Object files for target SlaterKosterExt
SlaterKosterExt_OBJECTS = \
"CMakeFiles/SlaterKosterExt.dir/src/SlatorKosterExt.cpp.o"

# External object files for target SlaterKosterExt
SlaterKosterExt_EXTERNAL_OBJECTS =

SlaterKosterExt.dylib: CMakeFiles/SlaterKosterExt.dir/src/SlatorKosterExt.cpp.o
SlaterKosterExt.dylib: CMakeFiles/SlaterKosterExt.dir/build.make
SlaterKosterExt.dylib: /usr/local/opt/python3/Frameworks/Python.framework/Versions/3.6/Python
SlaterKosterExt.dylib: /usr/local/lib/libboost_python3-mt.dylib
SlaterKosterExt.dylib: SlaterKoster.dylib
SlaterKosterExt.dylib: CMakeFiles/SlaterKosterExt.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/Meow/Documents/physics/research/MoS2_graphene/cxx/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library SlaterKosterExt.dylib"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SlaterKosterExt.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SlaterKosterExt.dir/build: SlaterKosterExt.dylib

.PHONY : CMakeFiles/SlaterKosterExt.dir/build

CMakeFiles/SlaterKosterExt.dir/requires: CMakeFiles/SlaterKosterExt.dir/src/SlatorKosterExt.cpp.o.requires

.PHONY : CMakeFiles/SlaterKosterExt.dir/requires

CMakeFiles/SlaterKosterExt.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SlaterKosterExt.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SlaterKosterExt.dir/clean

CMakeFiles/SlaterKosterExt.dir/depend:
	cd /Users/Meow/Documents/physics/research/MoS2_graphene/cxx && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/Meow/Documents/physics/research/MoS2_graphene/cxx /Users/Meow/Documents/physics/research/MoS2_graphene/cxx /Users/Meow/Documents/physics/research/MoS2_graphene/cxx /Users/Meow/Documents/physics/research/MoS2_graphene/cxx /Users/Meow/Documents/physics/research/MoS2_graphene/cxx/CMakeFiles/SlaterKosterExt.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SlaterKosterExt.dir/depend
