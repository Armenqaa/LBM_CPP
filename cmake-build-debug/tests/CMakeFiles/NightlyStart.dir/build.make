# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.2.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.2.3\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\LBM_CPP

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\LBM_CPP\cmake-build-debug

# Utility rule file for NightlyStart.

# Include the progress variables for this target.
include tests/CMakeFiles/NightlyStart.dir/progress.make

tests/CMakeFiles/NightlyStart:
	cd /d D:\LBM_CPP\cmake-build-debug\tests && "C:\Program Files\JetBrains\CLion 2019.2.3\bin\cmake\win\bin\ctest.exe" -D NightlyStart

NightlyStart: tests/CMakeFiles/NightlyStart
NightlyStart: tests/CMakeFiles/NightlyStart.dir/build.make

.PHONY : NightlyStart

# Rule to build all files generated by this target.
tests/CMakeFiles/NightlyStart.dir/build: NightlyStart

.PHONY : tests/CMakeFiles/NightlyStart.dir/build

tests/CMakeFiles/NightlyStart.dir/clean:
	cd /d D:\LBM_CPP\cmake-build-debug\tests && $(CMAKE_COMMAND) -P CMakeFiles\NightlyStart.dir\cmake_clean.cmake
.PHONY : tests/CMakeFiles/NightlyStart.dir/clean

tests/CMakeFiles/NightlyStart.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\LBM_CPP D:\LBM_CPP\tests D:\LBM_CPP\cmake-build-debug D:\LBM_CPP\cmake-build-debug\tests D:\LBM_CPP\cmake-build-debug\tests\CMakeFiles\NightlyStart.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : tests/CMakeFiles/NightlyStart.dir/depend

