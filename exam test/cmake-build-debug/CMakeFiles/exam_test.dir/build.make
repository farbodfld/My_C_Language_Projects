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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.2.5\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.2.5\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\lenovo\CLionProjects\exam test"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\lenovo\CLionProjects\exam test\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/exam_test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/exam_test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/exam_test.dir/flags.make

CMakeFiles/exam_test.dir/main.cpp.obj: CMakeFiles/exam_test.dir/flags.make
CMakeFiles/exam_test.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\lenovo\CLionProjects\exam test\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/exam_test.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\exam_test.dir\main.cpp.obj -c "C:\Users\lenovo\CLionProjects\exam test\main.cpp"

CMakeFiles/exam_test.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/exam_test.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\lenovo\CLionProjects\exam test\main.cpp" > CMakeFiles\exam_test.dir\main.cpp.i

CMakeFiles/exam_test.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/exam_test.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\lenovo\CLionProjects\exam test\main.cpp" -o CMakeFiles\exam_test.dir\main.cpp.s

# Object files for target exam_test
exam_test_OBJECTS = \
"CMakeFiles/exam_test.dir/main.cpp.obj"

# External object files for target exam_test
exam_test_EXTERNAL_OBJECTS =

exam_test.exe: CMakeFiles/exam_test.dir/main.cpp.obj
exam_test.exe: CMakeFiles/exam_test.dir/build.make
exam_test.exe: CMakeFiles/exam_test.dir/linklibs.rsp
exam_test.exe: CMakeFiles/exam_test.dir/objects1.rsp
exam_test.exe: CMakeFiles/exam_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\lenovo\CLionProjects\exam test\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable exam_test.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\exam_test.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/exam_test.dir/build: exam_test.exe

.PHONY : CMakeFiles/exam_test.dir/build

CMakeFiles/exam_test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\exam_test.dir\cmake_clean.cmake
.PHONY : CMakeFiles/exam_test.dir/clean

CMakeFiles/exam_test.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\lenovo\CLionProjects\exam test" "C:\Users\lenovo\CLionProjects\exam test" "C:\Users\lenovo\CLionProjects\exam test\cmake-build-debug" "C:\Users\lenovo\CLionProjects\exam test\cmake-build-debug" "C:\Users\lenovo\CLionProjects\exam test\cmake-build-debug\CMakeFiles\exam_test.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/exam_test.dir/depend

