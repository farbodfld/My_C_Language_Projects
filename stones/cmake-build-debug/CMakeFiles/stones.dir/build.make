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
CMAKE_SOURCE_DIR = C:\Users\lenovo\CLionProjects\stones

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\lenovo\CLionProjects\stones\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/stones.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/stones.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/stones.dir/flags.make

CMakeFiles/stones.dir/main.cpp.obj: CMakeFiles/stones.dir/flags.make
CMakeFiles/stones.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\lenovo\CLionProjects\stones\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/stones.dir/main.cpp.obj"
	C:\PROGRA~1\X86_64~1.0-W\mingw64\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\stones.dir\main.cpp.obj -c C:\Users\lenovo\CLionProjects\stones\main.cpp

CMakeFiles/stones.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/stones.dir/main.cpp.i"
	C:\PROGRA~1\X86_64~1.0-W\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\lenovo\CLionProjects\stones\main.cpp > CMakeFiles\stones.dir\main.cpp.i

CMakeFiles/stones.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/stones.dir/main.cpp.s"
	C:\PROGRA~1\X86_64~1.0-W\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\lenovo\CLionProjects\stones\main.cpp -o CMakeFiles\stones.dir\main.cpp.s

# Object files for target stones
stones_OBJECTS = \
"CMakeFiles/stones.dir/main.cpp.obj"

# External object files for target stones
stones_EXTERNAL_OBJECTS =

stones.exe: CMakeFiles/stones.dir/main.cpp.obj
stones.exe: CMakeFiles/stones.dir/build.make
stones.exe: CMakeFiles/stones.dir/linklibs.rsp
stones.exe: CMakeFiles/stones.dir/objects1.rsp
stones.exe: CMakeFiles/stones.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\lenovo\CLionProjects\stones\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable stones.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\stones.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/stones.dir/build: stones.exe

.PHONY : CMakeFiles/stones.dir/build

CMakeFiles/stones.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\stones.dir\cmake_clean.cmake
.PHONY : CMakeFiles/stones.dir/clean

CMakeFiles/stones.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\lenovo\CLionProjects\stones C:\Users\lenovo\CLionProjects\stones C:\Users\lenovo\CLionProjects\stones\cmake-build-debug C:\Users\lenovo\CLionProjects\stones\cmake-build-debug C:\Users\lenovo\CLionProjects\stones\cmake-build-debug\CMakeFiles\stones.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/stones.dir/depend

