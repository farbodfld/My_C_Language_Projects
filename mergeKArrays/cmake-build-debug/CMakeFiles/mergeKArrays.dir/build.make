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
CMAKE_SOURCE_DIR = C:\Users\lenovo\CLionProjects\mergeKArrays

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\lenovo\CLionProjects\mergeKArrays\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/mergeKArrays.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/mergeKArrays.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/mergeKArrays.dir/flags.make

CMakeFiles/mergeKArrays.dir/main.cpp.obj: CMakeFiles/mergeKArrays.dir/flags.make
CMakeFiles/mergeKArrays.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\lenovo\CLionProjects\mergeKArrays\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/mergeKArrays.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\mergeKArrays.dir\main.cpp.obj -c C:\Users\lenovo\CLionProjects\mergeKArrays\main.cpp

CMakeFiles/mergeKArrays.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mergeKArrays.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\lenovo\CLionProjects\mergeKArrays\main.cpp > CMakeFiles\mergeKArrays.dir\main.cpp.i

CMakeFiles/mergeKArrays.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mergeKArrays.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\lenovo\CLionProjects\mergeKArrays\main.cpp -o CMakeFiles\mergeKArrays.dir\main.cpp.s

# Object files for target mergeKArrays
mergeKArrays_OBJECTS = \
"CMakeFiles/mergeKArrays.dir/main.cpp.obj"

# External object files for target mergeKArrays
mergeKArrays_EXTERNAL_OBJECTS =

mergeKArrays.exe: CMakeFiles/mergeKArrays.dir/main.cpp.obj
mergeKArrays.exe: CMakeFiles/mergeKArrays.dir/build.make
mergeKArrays.exe: CMakeFiles/mergeKArrays.dir/linklibs.rsp
mergeKArrays.exe: CMakeFiles/mergeKArrays.dir/objects1.rsp
mergeKArrays.exe: CMakeFiles/mergeKArrays.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\lenovo\CLionProjects\mergeKArrays\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable mergeKArrays.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\mergeKArrays.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/mergeKArrays.dir/build: mergeKArrays.exe

.PHONY : CMakeFiles/mergeKArrays.dir/build

CMakeFiles/mergeKArrays.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\mergeKArrays.dir\cmake_clean.cmake
.PHONY : CMakeFiles/mergeKArrays.dir/clean

CMakeFiles/mergeKArrays.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\lenovo\CLionProjects\mergeKArrays C:\Users\lenovo\CLionProjects\mergeKArrays C:\Users\lenovo\CLionProjects\mergeKArrays\cmake-build-debug C:\Users\lenovo\CLionProjects\mergeKArrays\cmake-build-debug C:\Users\lenovo\CLionProjects\mergeKArrays\cmake-build-debug\CMakeFiles\mergeKArrays.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/mergeKArrays.dir/depend

