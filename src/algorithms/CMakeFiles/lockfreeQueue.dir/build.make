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
include src/algorithms/CMakeFiles/lockfreeQueue.dir/depend.make

# Include the progress variables for this target.
include src/algorithms/CMakeFiles/lockfreeQueue.dir/progress.make

# Include the compile flags for this target's objects.
include src/algorithms/CMakeFiles/lockfreeQueue.dir/flags.make

src/algorithms/CMakeFiles/lockfreeQueue.dir/lockfreeQueue.cpp.o: src/algorithms/CMakeFiles/lockfreeQueue.dir/flags.make
src/algorithms/CMakeFiles/lockfreeQueue.dir/lockfreeQueue.cpp.o: src/algorithms/lockfreeQueue.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/aarna/devel/ds-algos/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/algorithms/CMakeFiles/lockfreeQueue.dir/lockfreeQueue.cpp.o"
	cd /Users/aarna/devel/ds-algos/src/algorithms && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lockfreeQueue.dir/lockfreeQueue.cpp.o -c /Users/aarna/devel/ds-algos/src/algorithms/lockfreeQueue.cpp

src/algorithms/CMakeFiles/lockfreeQueue.dir/lockfreeQueue.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lockfreeQueue.dir/lockfreeQueue.cpp.i"
	cd /Users/aarna/devel/ds-algos/src/algorithms && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/aarna/devel/ds-algos/src/algorithms/lockfreeQueue.cpp > CMakeFiles/lockfreeQueue.dir/lockfreeQueue.cpp.i

src/algorithms/CMakeFiles/lockfreeQueue.dir/lockfreeQueue.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lockfreeQueue.dir/lockfreeQueue.cpp.s"
	cd /Users/aarna/devel/ds-algos/src/algorithms && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/aarna/devel/ds-algos/src/algorithms/lockfreeQueue.cpp -o CMakeFiles/lockfreeQueue.dir/lockfreeQueue.cpp.s

# Object files for target lockfreeQueue
lockfreeQueue_OBJECTS = \
"CMakeFiles/lockfreeQueue.dir/lockfreeQueue.cpp.o"

# External object files for target lockfreeQueue
lockfreeQueue_EXTERNAL_OBJECTS =

lockfreeQueue: src/algorithms/CMakeFiles/lockfreeQueue.dir/lockfreeQueue.cpp.o
lockfreeQueue: src/algorithms/CMakeFiles/lockfreeQueue.dir/build.make
lockfreeQueue: src/algorithms/CMakeFiles/lockfreeQueue.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/aarna/devel/ds-algos/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../../lockfreeQueue"
	cd /Users/aarna/devel/ds-algos/src/algorithms && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lockfreeQueue.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/algorithms/CMakeFiles/lockfreeQueue.dir/build: lockfreeQueue

.PHONY : src/algorithms/CMakeFiles/lockfreeQueue.dir/build

src/algorithms/CMakeFiles/lockfreeQueue.dir/clean:
	cd /Users/aarna/devel/ds-algos/src/algorithms && $(CMAKE_COMMAND) -P CMakeFiles/lockfreeQueue.dir/cmake_clean.cmake
.PHONY : src/algorithms/CMakeFiles/lockfreeQueue.dir/clean

src/algorithms/CMakeFiles/lockfreeQueue.dir/depend:
	cd /Users/aarna/devel/ds-algos && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/aarna/devel/ds-algos /Users/aarna/devel/ds-algos/src/algorithms /Users/aarna/devel/ds-algos /Users/aarna/devel/ds-algos/src/algorithms /Users/aarna/devel/ds-algos/src/algorithms/CMakeFiles/lockfreeQueue.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/algorithms/CMakeFiles/lockfreeQueue.dir/depend

