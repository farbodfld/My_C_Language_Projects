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
CMAKE_SOURCE_DIR = C:\Users\lenovo\CLionProjects\DS_FINAL

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\lenovo\CLionProjects\DS_FINAL\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/DS_FINAL.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/DS_FINAL.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/DS_FINAL.dir/flags.make

CMakeFiles/DS_FINAL.dir/main.cpp.obj: CMakeFiles/DS_FINAL.dir/flags.make
CMakeFiles/DS_FINAL.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\lenovo\CLionProjects\DS_FINAL\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/DS_FINAL.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\DS_FINAL.dir\main.cpp.obj -c C:\Users\lenovo\CLionProjects\DS_FINAL\main.cpp

CMakeFiles/DS_FINAL.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DS_FINAL.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\lenovo\CLionProjects\DS_FINAL\main.cpp > CMakeFiles\DS_FINAL.dir\main.cpp.i

CMakeFiles/DS_FINAL.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DS_FINAL.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\lenovo\CLionProjects\DS_FINAL\main.cpp -o CMakeFiles\DS_FINAL.dir\main.cpp.s

# Object files for target DS_FINAL
DS_FINAL_OBJECTS = \
"CMakeFiles/DS_FINAL.dir/main.cpp.obj"

# External object files for target DS_FINAL
DS_FINAL_EXTERNAL_OBJECTS =

DS_FINAL.exe: CMakeFiles/DS_FINAL.dir/main.cpp.obj
DS_FINAL.exe: CMakeFiles/DS_FINAL.dir/build.make
DS_FINAL.exe: CMakeFiles/DS_FINAL.dir/linklibs.rsp
DS_FINAL.exe: CMakeFiles/DS_FINAL.dir/objects1.rsp
DS_FINAL.exe: CMakeFiles/DS_FINAL.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\lenovo\CLionProjects\DS_FINAL\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable DS_FINAL.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\DS_FINAL.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/DS_FINAL.dir/build: DS_FINAL.exe

.PHONY : CMakeFiles/DS_FINAL.dir/build

CMakeFiles/DS_FINAL.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\DS_FINAL.dir\cmake_clean.cmake
.PHONY : CMakeFiles/DS_FINAL.dir/clean

CMakeFiles/DS_FINAL.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\lenovo\CLionProjects\DS_FINAL C:\Users\lenovo\CLionProjects\DS_FINAL C:\Users\lenovo\CLionProjects\DS_FINAL\cmake-build-debug C:\Users\lenovo\CLionProjects\DS_FINAL\cmake-build-debug C:\Users\lenovo\CLionProjects\DS_FINAL\cmake-build-debug\CMakeFiles\DS_FINAL.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/DS_FINAL.dir/depend
