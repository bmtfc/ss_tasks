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
CMAKE_COMMAND = "/Users/mac/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/203.6682.181/CLion.app/Contents/bin/cmake/mac/bin/cmake"

# The command to remove a file.
RM = "/Users/mac/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/203.6682.181/CLion.app/Contents/bin/cmake/mac/bin/cmake" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/mac/softserve/ss_tasks/task3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/mac/softserve/ss_tasks/task3/cmake-build-debug-coverage

# Include any dependencies generated for this target.
include tests/CMakeFiles/task3_test.dir/depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/task3_test.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/task3_test.dir/flags.make

tests/CMakeFiles/task3_test.dir/main.cpp.o: tests/CMakeFiles/task3_test.dir/flags.make
tests/CMakeFiles/task3_test.dir/main.cpp.o: ../tests/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mac/softserve/ss_tasks/task3/cmake-build-debug-coverage/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tests/CMakeFiles/task3_test.dir/main.cpp.o"
	cd /Users/mac/softserve/ss_tasks/task3/cmake-build-debug-coverage/tests && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/task3_test.dir/main.cpp.o -c /Users/mac/softserve/ss_tasks/task3/tests/main.cpp

tests/CMakeFiles/task3_test.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/task3_test.dir/main.cpp.i"
	cd /Users/mac/softserve/ss_tasks/task3/cmake-build-debug-coverage/tests && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mac/softserve/ss_tasks/task3/tests/main.cpp > CMakeFiles/task3_test.dir/main.cpp.i

tests/CMakeFiles/task3_test.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/task3_test.dir/main.cpp.s"
	cd /Users/mac/softserve/ss_tasks/task3/cmake-build-debug-coverage/tests && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mac/softserve/ss_tasks/task3/tests/main.cpp -o CMakeFiles/task3_test.dir/main.cpp.s

tests/CMakeFiles/task3_test.dir/tests.cpp.o: tests/CMakeFiles/task3_test.dir/flags.make
tests/CMakeFiles/task3_test.dir/tests.cpp.o: ../tests/tests.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mac/softserve/ss_tasks/task3/cmake-build-debug-coverage/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object tests/CMakeFiles/task3_test.dir/tests.cpp.o"
	cd /Users/mac/softserve/ss_tasks/task3/cmake-build-debug-coverage/tests && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/task3_test.dir/tests.cpp.o -c /Users/mac/softserve/ss_tasks/task3/tests/tests.cpp

tests/CMakeFiles/task3_test.dir/tests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/task3_test.dir/tests.cpp.i"
	cd /Users/mac/softserve/ss_tasks/task3/cmake-build-debug-coverage/tests && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mac/softserve/ss_tasks/task3/tests/tests.cpp > CMakeFiles/task3_test.dir/tests.cpp.i

tests/CMakeFiles/task3_test.dir/tests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/task3_test.dir/tests.cpp.s"
	cd /Users/mac/softserve/ss_tasks/task3/cmake-build-debug-coverage/tests && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mac/softserve/ss_tasks/task3/tests/tests.cpp -o CMakeFiles/task3_test.dir/tests.cpp.s

# Object files for target task3_test
task3_test_OBJECTS = \
"CMakeFiles/task3_test.dir/main.cpp.o" \
"CMakeFiles/task3_test.dir/tests.cpp.o"

# External object files for target task3_test
task3_test_EXTERNAL_OBJECTS =

tests/task3_test: tests/CMakeFiles/task3_test.dir/main.cpp.o
tests/task3_test: tests/CMakeFiles/task3_test.dir/tests.cpp.o
tests/task3_test: tests/CMakeFiles/task3_test.dir/build.make
tests/task3_test: src/libtask3_lib.a
tests/task3_test: lib/libgtestd.a
tests/task3_test: tests/CMakeFiles/task3_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/mac/softserve/ss_tasks/task3/cmake-build-debug-coverage/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable task3_test"
	cd /Users/mac/softserve/ss_tasks/task3/cmake-build-debug-coverage/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/task3_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/task3_test.dir/build: tests/task3_test

.PHONY : tests/CMakeFiles/task3_test.dir/build

tests/CMakeFiles/task3_test.dir/clean:
	cd /Users/mac/softserve/ss_tasks/task3/cmake-build-debug-coverage/tests && $(CMAKE_COMMAND) -P CMakeFiles/task3_test.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/task3_test.dir/clean

tests/CMakeFiles/task3_test.dir/depend:
	cd /Users/mac/softserve/ss_tasks/task3/cmake-build-debug-coverage && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/mac/softserve/ss_tasks/task3 /Users/mac/softserve/ss_tasks/task3/tests /Users/mac/softserve/ss_tasks/task3/cmake-build-debug-coverage /Users/mac/softserve/ss_tasks/task3/cmake-build-debug-coverage/tests /Users/mac/softserve/ss_tasks/task3/cmake-build-debug-coverage/tests/CMakeFiles/task3_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/CMakeFiles/task3_test.dir/depend

