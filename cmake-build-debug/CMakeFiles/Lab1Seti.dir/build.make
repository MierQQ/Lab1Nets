# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/c/Users/MEB/CLionProjects/Lab1Seti

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/Users/MEB/CLionProjects/Lab1Seti/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Lab1Seti.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Lab1Seti.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Lab1Seti.dir/flags.make

CMakeFiles/Lab1Seti.dir/main.cpp.o: CMakeFiles/Lab1Seti.dir/flags.make
CMakeFiles/Lab1Seti.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/MEB/CLionProjects/Lab1Seti/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Lab1Seti.dir/main.cpp.o"
	/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Lab1Seti.dir/main.cpp.o -c /mnt/c/Users/MEB/CLionProjects/Lab1Seti/main.cpp

CMakeFiles/Lab1Seti.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Lab1Seti.dir/main.cpp.i"
	/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/MEB/CLionProjects/Lab1Seti/main.cpp > CMakeFiles/Lab1Seti.dir/main.cpp.i

CMakeFiles/Lab1Seti.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Lab1Seti.dir/main.cpp.s"
	/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/MEB/CLionProjects/Lab1Seti/main.cpp -o CMakeFiles/Lab1Seti.dir/main.cpp.s

CMakeFiles/Lab1Seti.dir/MulticastCopyAnalyzer.cpp.o: CMakeFiles/Lab1Seti.dir/flags.make
CMakeFiles/Lab1Seti.dir/MulticastCopyAnalyzer.cpp.o: ../MulticastCopyAnalyzer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/MEB/CLionProjects/Lab1Seti/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Lab1Seti.dir/MulticastCopyAnalyzer.cpp.o"
	/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Lab1Seti.dir/MulticastCopyAnalyzer.cpp.o -c /mnt/c/Users/MEB/CLionProjects/Lab1Seti/MulticastCopyAnalyzer.cpp

CMakeFiles/Lab1Seti.dir/MulticastCopyAnalyzer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Lab1Seti.dir/MulticastCopyAnalyzer.cpp.i"
	/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/MEB/CLionProjects/Lab1Seti/MulticastCopyAnalyzer.cpp > CMakeFiles/Lab1Seti.dir/MulticastCopyAnalyzer.cpp.i

CMakeFiles/Lab1Seti.dir/MulticastCopyAnalyzer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Lab1Seti.dir/MulticastCopyAnalyzer.cpp.s"
	/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/MEB/CLionProjects/Lab1Seti/MulticastCopyAnalyzer.cpp -o CMakeFiles/Lab1Seti.dir/MulticastCopyAnalyzer.cpp.s

# Object files for target Lab1Seti
Lab1Seti_OBJECTS = \
"CMakeFiles/Lab1Seti.dir/main.cpp.o" \
"CMakeFiles/Lab1Seti.dir/MulticastCopyAnalyzer.cpp.o"

# External object files for target Lab1Seti
Lab1Seti_EXTERNAL_OBJECTS =

Lab1Seti: CMakeFiles/Lab1Seti.dir/main.cpp.o
Lab1Seti: CMakeFiles/Lab1Seti.dir/MulticastCopyAnalyzer.cpp.o
Lab1Seti: CMakeFiles/Lab1Seti.dir/build.make
Lab1Seti: CMakeFiles/Lab1Seti.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/c/Users/MEB/CLionProjects/Lab1Seti/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable Lab1Seti"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Lab1Seti.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Lab1Seti.dir/build: Lab1Seti

.PHONY : CMakeFiles/Lab1Seti.dir/build

CMakeFiles/Lab1Seti.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Lab1Seti.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Lab1Seti.dir/clean

CMakeFiles/Lab1Seti.dir/depend:
	cd /mnt/c/Users/MEB/CLionProjects/Lab1Seti/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/Users/MEB/CLionProjects/Lab1Seti /mnt/c/Users/MEB/CLionProjects/Lab1Seti /mnt/c/Users/MEB/CLionProjects/Lab1Seti/cmake-build-debug /mnt/c/Users/MEB/CLionProjects/Lab1Seti/cmake-build-debug /mnt/c/Users/MEB/CLionProjects/Lab1Seti/cmake-build-debug/CMakeFiles/Lab1Seti.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Lab1Seti.dir/depend
