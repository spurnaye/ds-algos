# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

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

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.19.3/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.19.3/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/aarna/devel/ds-algos

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/aarna/devel/ds-algos

# Include any dependencies generated for this target.
include test/LinkedListTests/CMakeFiles/LinkedListTests.dir/depend.make

# Include the progress variables for this target.
include test/LinkedListTests/CMakeFiles/LinkedListTests.dir/progress.make

# Include the compile flags for this target's objects.
include test/LinkedListTests/CMakeFiles/LinkedListTests.dir/flags.make

test/LinkedListTests/CMakeFiles/LinkedListTests.dir/LinkedListTest.cpp.o: test/LinkedListTests/CMakeFiles/LinkedListTests.dir/flags.make
test/LinkedListTests/CMakeFiles/LinkedListTests.dir/LinkedListTest.cpp.o: test/LinkedListTests/LinkedListTest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/aarna/devel/ds-algos/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/LinkedListTests/CMakeFiles/LinkedListTests.dir/LinkedListTest.cpp.o"
	cd /Users/aarna/devel/ds-algos/test/LinkedListTests && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LinkedListTests.dir/LinkedListTest.cpp.o -c /Users/aarna/devel/ds-algos/test/LinkedListTests/LinkedListTest.cpp

test/LinkedListTests/CMakeFiles/LinkedListTests.dir/LinkedListTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LinkedListTests.dir/LinkedListTest.cpp.i"
	cd /Users/aarna/devel/ds-algos/test/LinkedListTests && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/aarna/devel/ds-algos/test/LinkedListTests/LinkedListTest.cpp > CMakeFiles/LinkedListTests.dir/LinkedListTest.cpp.i

test/LinkedListTests/CMakeFiles/LinkedListTests.dir/LinkedListTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LinkedListTests.dir/LinkedListTest.cpp.s"
	cd /Users/aarna/devel/ds-algos/test/LinkedListTests && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/aarna/devel/ds-algos/test/LinkedListTests/LinkedListTest.cpp -o CMakeFiles/LinkedListTests.dir/LinkedListTest.cpp.s

# Object files for target LinkedListTests
LinkedListTests_OBJECTS = \
"CMakeFiles/LinkedListTests.dir/LinkedListTest.cpp.o"

# External object files for target LinkedListTests
LinkedListTests_EXTERNAL_OBJECTS =

LinkedListTests: test/LinkedListTests/CMakeFiles/LinkedListTests.dir/LinkedListTest.cpp.o
LinkedListTests: test/LinkedListTests/CMakeFiles/LinkedListTests.dir/build.make
LinkedListTests: src/ds/libDataStructures.dylib
LinkedListTests: lib/libgtest.a
LinkedListTests: lib/libgtest_main.a
LinkedListTests: lib/libgmock_main.a
LinkedListTests: lib/libgmock.a
LinkedListTests: lib/libgtest.a
LinkedListTests: test/LinkedListTests/CMakeFiles/LinkedListTests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/aarna/devel/ds-algos/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../../LinkedListTests"
	cd /Users/aarna/devel/ds-algos/test/LinkedListTests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/LinkedListTests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/LinkedListTests/CMakeFiles/LinkedListTests.dir/build: LinkedListTests

.PHONY : test/LinkedListTests/CMakeFiles/LinkedListTests.dir/build

test/LinkedListTests/CMakeFiles/LinkedListTests.dir/clean:
	cd /Users/aarna/devel/ds-algos/test/LinkedListTests && $(CMAKE_COMMAND) -P CMakeFiles/LinkedListTests.dir/cmake_clean.cmake
.PHONY : test/LinkedListTests/CMakeFiles/LinkedListTests.dir/clean

test/LinkedListTests/CMakeFiles/LinkedListTests.dir/depend:
	cd /Users/aarna/devel/ds-algos && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/aarna/devel/ds-algos /Users/aarna/devel/ds-algos/test/LinkedListTests /Users/aarna/devel/ds-algos /Users/aarna/devel/ds-algos/test/LinkedListTests /Users/aarna/devel/ds-algos/test/LinkedListTests/CMakeFiles/LinkedListTests.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/LinkedListTests/CMakeFiles/LinkedListTests.dir/depend

