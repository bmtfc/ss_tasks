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
include src/CMakeFiles/task3.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/task3.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/task3.dir/flags.make

src/CMakeFiles/task3.dir/main.cpp.o: src/CMakeFiles/task3.dir/flags.make
src/CMakeFiles/task3.dir/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mac/softserve/ss_tasks/task3/cmake-build-debug-coverage/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/task3.dir/main.cpp.o"
	cd /Users/mac/softserve/ss_tasks/task3/cmake-build-debug-coverage/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/task3.dir/main.cpp.o -c /Users/mac/softserve/ss_tasks/task3/src/main.cpp

src/CMakeFiles/task3.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/task3.dir/main.cpp.i"
	cd /Users/mac/softserve/ss_tasks/task3/cmake-build-debug-coverage/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mac/softserve/ss_tasks/task3/src/main.cpp > CMakeFiles/task3.dir/main.cpp.i

src/CMakeFiles/task3.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/task3.dir/main.cpp.s"
	cd /Users/mac/softserve/ss_tasks/task3/cmake-build-debug-coverage/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mac/softserve/ss_tasks/task3/src/main.cpp -o CMakeFiles/task3.dir/main.cpp.s

src/CMakeFiles/task3.dir/ProjectAnalyser.cpp.o: src/CMakeFiles/task3.dir/flags.make
src/CMakeFiles/task3.dir/ProjectAnalyser.cpp.o: ../src/ProjectAnalyser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mac/softserve/ss_tasks/task3/cmake-build-debug-coverage/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/task3.dir/ProjectAnalyser.cpp.o"
	cd /Users/mac/softserve/ss_tasks/task3/cmake-build-debug-coverage/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/task3.dir/ProjectAnalyser.cpp.o -c /Users/mac/softserve/ss_tasks/task3/src/ProjectAnalyser.cpp

src/CMakeFiles/task3.dir/ProjectAnalyser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/task3.dir/ProjectAnalyser.cpp.i"
	cd /Users/mac/softserve/ss_tasks/task3/cmake-build-debug-coverage/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mac/softserve/ss_tasks/task3/src/ProjectAnalyser.cpp > CMakeFiles/task3.dir/ProjectAnalyser.cpp.i

src/CMakeFiles/task3.dir/ProjectAnalyser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/task3.dir/ProjectAnalyser.cpp.s"
	cd /Users/mac/softserve/ss_tasks/task3/cmake-build-debug-coverage/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mac/softserve/ss_tasks/task3/src/ProjectAnalyser.cpp -o CMakeFiles/task3.dir/ProjectAnalyser.cpp.s

src/CMakeFiles/task3.dir/FileAnalyser.cpp.o: src/CMakeFiles/task3.dir/flags.make
src/CMakeFiles/task3.dir/FileAnalyser.cpp.o: ../src/FileAnalyser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mac/softserve/ss_tasks/task3/cmake-build-debug-coverage/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/CMakeFiles/task3.dir/FileAnalyser.cpp.o"
	cd /Users/mac/softserve/ss_tasks/task3/cmake-build-debug-coverage/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/task3.dir/FileAnalyser.cpp.o -c /Users/mac/softserve/ss_tasks/task3/src/FileAnalyser.cpp

src/CMakeFiles/task3.dir/FileAnalyser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/task3.dir/FileAnalyser.cpp.i"
	cd /Users/mac/softserve/ss_tasks/task3/cmake-build-debug-coverage/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mac/softserve/ss_tasks/task3/src/FileAnalyser.cpp > CMakeFiles/task3.dir/FileAnalyser.cpp.i

src/CMakeFiles/task3.dir/FileAnalyser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/task3.dir/FileAnalyser.cpp.s"
	cd /Users/mac/softserve/ss_tasks/task3/cmake-build-debug-coverage/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mac/softserve/ss_tasks/task3/src/FileAnalyser.cpp -o CMakeFiles/task3.dir/FileAnalyser.cpp.s

# Object files for target task3
task3_OBJECTS = \
"CMakeFiles/task3.dir/main.cpp.o" \
"CMakeFiles/task3.dir/ProjectAnalyser.cpp.o" \
"CMakeFiles/task3.dir/FileAnalyser.cpp.o"

# External object files for target task3
task3_EXTERNAL_OBJECTS =

src/task3: src/CMakeFiles/task3.dir/main.cpp.o
src/task3: src/CMakeFiles/task3.dir/ProjectAnalyser.cpp.o
src/task3: src/CMakeFiles/task3.dir/FileAnalyser.cpp.o
src/task3: src/CMakeFiles/task3.dir/build.make
src/task3: src/CMakeFiles/task3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/mac/softserve/ss_tasks/task3/cmake-build-debug-coverage/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable task3"
	cd /Users/mac/softserve/ss_tasks/task3/cmake-build-debug-coverage/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/task3.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/task3.dir/build: src/task3

.PHONY : src/CMakeFiles/task3.dir/build

src/CMakeFiles/task3.dir/clean:
	cd /Users/mac/softserve/ss_tasks/task3/cmake-build-debug-coverage/src && $(CMAKE_COMMAND) -P CMakeFiles/task3.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/task3.dir/clean

src/CMakeFiles/task3.dir/depend:
	cd /Users/mac/softserve/ss_tasks/task3/cmake-build-debug-coverage && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/mac/softserve/ss_tasks/task3 /Users/mac/softserve/ss_tasks/task3/src /Users/mac/softserve/ss_tasks/task3/cmake-build-debug-coverage /Users/mac/softserve/ss_tasks/task3/cmake-build-debug-coverage/src /Users/mac/softserve/ss_tasks/task3/cmake-build-debug-coverage/src/CMakeFiles/task3.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/task3.dir/depend

