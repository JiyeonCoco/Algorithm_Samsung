# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/jungjiyeon/CLionProjects/SamsungSW

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/jungjiyeon/CLionProjects/SamsungSW/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/SamsungSW.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/SamsungSW.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SamsungSW.dir/flags.make

CMakeFiles/SamsungSW.dir/14889.cpp.o: CMakeFiles/SamsungSW.dir/flags.make
CMakeFiles/SamsungSW.dir/14889.cpp.o: ../14889.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jungjiyeon/CLionProjects/SamsungSW/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SamsungSW.dir/14889.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SamsungSW.dir/14889.cpp.o -c /Users/jungjiyeon/CLionProjects/SamsungSW/14889.cpp

CMakeFiles/SamsungSW.dir/14889.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SamsungSW.dir/14889.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/jungjiyeon/CLionProjects/SamsungSW/14889.cpp > CMakeFiles/SamsungSW.dir/14889.cpp.i

CMakeFiles/SamsungSW.dir/14889.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SamsungSW.dir/14889.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/jungjiyeon/CLionProjects/SamsungSW/14889.cpp -o CMakeFiles/SamsungSW.dir/14889.cpp.s

# Object files for target SamsungSW
SamsungSW_OBJECTS = \
"CMakeFiles/SamsungSW.dir/14889.cpp.o"

# External object files for target SamsungSW
SamsungSW_EXTERNAL_OBJECTS =

SamsungSW: CMakeFiles/SamsungSW.dir/14889.cpp.o
SamsungSW: CMakeFiles/SamsungSW.dir/build.make
SamsungSW: CMakeFiles/SamsungSW.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/jungjiyeon/CLionProjects/SamsungSW/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable SamsungSW"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SamsungSW.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SamsungSW.dir/build: SamsungSW

.PHONY : CMakeFiles/SamsungSW.dir/build

CMakeFiles/SamsungSW.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SamsungSW.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SamsungSW.dir/clean

CMakeFiles/SamsungSW.dir/depend:
	cd /Users/jungjiyeon/CLionProjects/SamsungSW/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/jungjiyeon/CLionProjects/SamsungSW /Users/jungjiyeon/CLionProjects/SamsungSW /Users/jungjiyeon/CLionProjects/SamsungSW/cmake-build-debug /Users/jungjiyeon/CLionProjects/SamsungSW/cmake-build-debug /Users/jungjiyeon/CLionProjects/SamsungSW/cmake-build-debug/CMakeFiles/SamsungSW.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SamsungSW.dir/depend

