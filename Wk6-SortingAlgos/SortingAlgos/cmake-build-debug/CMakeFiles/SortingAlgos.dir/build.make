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
CMAKE_SOURCE_DIR = /Users/danielcender/Documents/GCU/2019/CST-201/CST-201/Wk6-SortingAlgos/SortingAlgos

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/danielcender/Documents/GCU/2019/CST-201/CST-201/Wk6-SortingAlgos/SortingAlgos/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/SortingAlgos.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/SortingAlgos.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SortingAlgos.dir/flags.make

CMakeFiles/SortingAlgos.dir/main.cpp.o: CMakeFiles/SortingAlgos.dir/flags.make
CMakeFiles/SortingAlgos.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/danielcender/Documents/GCU/2019/CST-201/CST-201/Wk6-SortingAlgos/SortingAlgos/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SortingAlgos.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SortingAlgos.dir/main.cpp.o -c /Users/danielcender/Documents/GCU/2019/CST-201/CST-201/Wk6-SortingAlgos/SortingAlgos/main.cpp

CMakeFiles/SortingAlgos.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SortingAlgos.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/danielcender/Documents/GCU/2019/CST-201/CST-201/Wk6-SortingAlgos/SortingAlgos/main.cpp > CMakeFiles/SortingAlgos.dir/main.cpp.i

CMakeFiles/SortingAlgos.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SortingAlgos.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/danielcender/Documents/GCU/2019/CST-201/CST-201/Wk6-SortingAlgos/SortingAlgos/main.cpp -o CMakeFiles/SortingAlgos.dir/main.cpp.s

# Object files for target SortingAlgos
SortingAlgos_OBJECTS = \
"CMakeFiles/SortingAlgos.dir/main.cpp.o"

# External object files for target SortingAlgos
SortingAlgos_EXTERNAL_OBJECTS =

SortingAlgos: CMakeFiles/SortingAlgos.dir/main.cpp.o
SortingAlgos: CMakeFiles/SortingAlgos.dir/build.make
SortingAlgos: CMakeFiles/SortingAlgos.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/danielcender/Documents/GCU/2019/CST-201/CST-201/Wk6-SortingAlgos/SortingAlgos/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable SortingAlgos"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SortingAlgos.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SortingAlgos.dir/build: SortingAlgos

.PHONY : CMakeFiles/SortingAlgos.dir/build

CMakeFiles/SortingAlgos.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SortingAlgos.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SortingAlgos.dir/clean

CMakeFiles/SortingAlgos.dir/depend:
	cd /Users/danielcender/Documents/GCU/2019/CST-201/CST-201/Wk6-SortingAlgos/SortingAlgos/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/danielcender/Documents/GCU/2019/CST-201/CST-201/Wk6-SortingAlgos/SortingAlgos /Users/danielcender/Documents/GCU/2019/CST-201/CST-201/Wk6-SortingAlgos/SortingAlgos /Users/danielcender/Documents/GCU/2019/CST-201/CST-201/Wk6-SortingAlgos/SortingAlgos/cmake-build-debug /Users/danielcender/Documents/GCU/2019/CST-201/CST-201/Wk6-SortingAlgos/SortingAlgos/cmake-build-debug /Users/danielcender/Documents/GCU/2019/CST-201/CST-201/Wk6-SortingAlgos/SortingAlgos/cmake-build-debug/CMakeFiles/SortingAlgos.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SortingAlgos.dir/depend

