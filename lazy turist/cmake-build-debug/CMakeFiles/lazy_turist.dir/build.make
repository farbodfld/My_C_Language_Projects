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
CMAKE_SOURCE_DIR = "C:\Users\lenovo\CLionProjects\lazy turist"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\lenovo\CLionProjects\lazy turist\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/lazy_turist.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/lazy_turist.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lazy_turist.dir/flags.make

CMakeFiles/lazy_turist.dir/main.cpp.obj: CMakeFiles/lazy_turist.dir/flags.make
CMakeFiles/lazy_turist.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\lenovo\CLionProjects\lazy turist\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/lazy_turist.dir/main.cpp.obj"
	C:\PROGRA~1\X86_64~1.0-W\mingw64\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\lazy_turist.dir\main.cpp.obj -c "C:\Users\lenovo\CLionProjects\lazy turist\main.cpp"

CMakeFiles/lazy_turist.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lazy_turist.dir/main.cpp.i"
	C:\PROGRA~1\X86_64~1.0-W\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\lenovo\CLionProjects\lazy turist\main.cpp" > CMakeFiles\lazy_turist.dir\main.cpp.i

CMakeFiles/lazy_turist.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lazy_turist.dir/main.cpp.s"
	C:\PROGRA~1\X86_64~1.0-W\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\lenovo\CLionProjects\lazy turist\main.cpp" -o CMakeFiles\lazy_turist.dir\main.cpp.s

# Object files for target lazy_turist
lazy_turist_OBJECTS = \
"CMakeFiles/lazy_turist.dir/main.cpp.obj"

# External object files for target lazy_turist
lazy_turist_EXTERNAL_OBJECTS =

lazy_turist.exe: CMakeFiles/lazy_turist.dir/main.cpp.obj
lazy_turist.exe: CMakeFiles/lazy_turist.dir/build.make
lazy_turist.exe: CMakeFiles/lazy_turist.dir/linklibs.rsp
lazy_turist.exe: CMakeFiles/lazy_turist.dir/objects1.rsp
lazy_turist.exe: CMakeFiles/lazy_turist.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\lenovo\CLionProjects\lazy turist\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable lazy_turist.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\lazy_turist.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lazy_turist.dir/build: lazy_turist.exe

.PHONY : CMakeFiles/lazy_turist.dir/build

CMakeFiles/lazy_turist.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\lazy_turist.dir\cmake_clean.cmake
.PHONY : CMakeFiles/lazy_turist.dir/clean

CMakeFiles/lazy_turist.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\lenovo\CLionProjects\lazy turist" "C:\Users\lenovo\CLionProjects\lazy turist" "C:\Users\lenovo\CLionProjects\lazy turist\cmake-build-debug" "C:\Users\lenovo\CLionProjects\lazy turist\cmake-build-debug" "C:\Users\lenovo\CLionProjects\lazy turist\cmake-build-debug\CMakeFiles\lazy_turist.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/lazy_turist.dir/depend

