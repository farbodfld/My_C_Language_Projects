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
CMAKE_SOURCE_DIR = C:\Users\lenovo\CLionProjects\RT

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\lenovo\CLionProjects\RT\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/RT.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/RT.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/RT.dir/flags.make

CMakeFiles/RT.dir/main.cpp.obj: CMakeFiles/RT.dir/flags.make
CMakeFiles/RT.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\lenovo\CLionProjects\RT\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/RT.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\RT.dir\main.cpp.obj -c C:\Users\lenovo\CLionProjects\RT\main.cpp

CMakeFiles/RT.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RT.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\lenovo\CLionProjects\RT\main.cpp > CMakeFiles\RT.dir\main.cpp.i

CMakeFiles/RT.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RT.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\lenovo\CLionProjects\RT\main.cpp -o CMakeFiles\RT.dir\main.cpp.s

# Object files for target RT
RT_OBJECTS = \
"CMakeFiles/RT.dir/main.cpp.obj"

# External object files for target RT
RT_EXTERNAL_OBJECTS =

RT.exe: CMakeFiles/RT.dir/main.cpp.obj
RT.exe: CMakeFiles/RT.dir/build.make
RT.exe: CMakeFiles/RT.dir/linklibs.rsp
RT.exe: CMakeFiles/RT.dir/objects1.rsp
RT.exe: CMakeFiles/RT.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\lenovo\CLionProjects\RT\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable RT.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\RT.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/RT.dir/build: RT.exe

.PHONY : CMakeFiles/RT.dir/build

CMakeFiles/RT.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\RT.dir\cmake_clean.cmake
.PHONY : CMakeFiles/RT.dir/clean

CMakeFiles/RT.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\lenovo\CLionProjects\RT C:\Users\lenovo\CLionProjects\RT C:\Users\lenovo\CLionProjects\RT\cmake-build-debug C:\Users\lenovo\CLionProjects\RT\cmake-build-debug C:\Users\lenovo\CLionProjects\RT\cmake-build-debug\CMakeFiles\RT.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/RT.dir/depend
