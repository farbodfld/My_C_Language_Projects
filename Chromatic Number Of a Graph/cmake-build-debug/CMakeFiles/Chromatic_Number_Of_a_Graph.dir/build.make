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
CMAKE_COMMAND = "E:\CLion\Instalation\CLion 2019.2.5\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "E:\CLion\Instalation\CLion 2019.2.5\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\lenovo\CLionProjects\Chromatic Number Of a Graph"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\lenovo\CLionProjects\Chromatic Number Of a Graph\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Chromatic_Number_Of_a_Graph.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Chromatic_Number_Of_a_Graph.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Chromatic_Number_Of_a_Graph.dir/flags.make

CMakeFiles/Chromatic_Number_Of_a_Graph.dir/main.cpp.obj: CMakeFiles/Chromatic_Number_Of_a_Graph.dir/flags.make
CMakeFiles/Chromatic_Number_Of_a_Graph.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\lenovo\CLionProjects\Chromatic Number Of a Graph\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Chromatic_Number_Of_a_Graph.dir/main.cpp.obj"
	C:\PROGRA~1\X86_64~1.0-W\mingw64\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Chromatic_Number_Of_a_Graph.dir\main.cpp.obj -c "C:\Users\lenovo\CLionProjects\Chromatic Number Of a Graph\main.cpp"

CMakeFiles/Chromatic_Number_Of_a_Graph.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Chromatic_Number_Of_a_Graph.dir/main.cpp.i"
	C:\PROGRA~1\X86_64~1.0-W\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\lenovo\CLionProjects\Chromatic Number Of a Graph\main.cpp" > CMakeFiles\Chromatic_Number_Of_a_Graph.dir\main.cpp.i

CMakeFiles/Chromatic_Number_Of_a_Graph.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Chromatic_Number_Of_a_Graph.dir/main.cpp.s"
	C:\PROGRA~1\X86_64~1.0-W\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\lenovo\CLionProjects\Chromatic Number Of a Graph\main.cpp" -o CMakeFiles\Chromatic_Number_Of_a_Graph.dir\main.cpp.s

# Object files for target Chromatic_Number_Of_a_Graph
Chromatic_Number_Of_a_Graph_OBJECTS = \
"CMakeFiles/Chromatic_Number_Of_a_Graph.dir/main.cpp.obj"

# External object files for target Chromatic_Number_Of_a_Graph
Chromatic_Number_Of_a_Graph_EXTERNAL_OBJECTS =

Chromatic_Number_Of_a_Graph.exe: CMakeFiles/Chromatic_Number_Of_a_Graph.dir/main.cpp.obj
Chromatic_Number_Of_a_Graph.exe: CMakeFiles/Chromatic_Number_Of_a_Graph.dir/build.make
Chromatic_Number_Of_a_Graph.exe: CMakeFiles/Chromatic_Number_Of_a_Graph.dir/linklibs.rsp
Chromatic_Number_Of_a_Graph.exe: CMakeFiles/Chromatic_Number_Of_a_Graph.dir/objects1.rsp
Chromatic_Number_Of_a_Graph.exe: CMakeFiles/Chromatic_Number_Of_a_Graph.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\lenovo\CLionProjects\Chromatic Number Of a Graph\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Chromatic_Number_Of_a_Graph.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Chromatic_Number_Of_a_Graph.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Chromatic_Number_Of_a_Graph.dir/build: Chromatic_Number_Of_a_Graph.exe

.PHONY : CMakeFiles/Chromatic_Number_Of_a_Graph.dir/build

CMakeFiles/Chromatic_Number_Of_a_Graph.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Chromatic_Number_Of_a_Graph.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Chromatic_Number_Of_a_Graph.dir/clean

CMakeFiles/Chromatic_Number_Of_a_Graph.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\lenovo\CLionProjects\Chromatic Number Of a Graph" "C:\Users\lenovo\CLionProjects\Chromatic Number Of a Graph" "C:\Users\lenovo\CLionProjects\Chromatic Number Of a Graph\cmake-build-debug" "C:\Users\lenovo\CLionProjects\Chromatic Number Of a Graph\cmake-build-debug" "C:\Users\lenovo\CLionProjects\Chromatic Number Of a Graph\cmake-build-debug\CMakeFiles\Chromatic_Number_Of_a_Graph.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Chromatic_Number_Of_a_Graph.dir/depend

