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
CMAKE_SOURCE_DIR = "C:\Users\lenovo\CLionProjects\Fashion Show"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\lenovo\CLionProjects\Fashion Show\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Fashion_Show.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Fashion_Show.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Fashion_Show.dir/flags.make

CMakeFiles/Fashion_Show.dir/main.cpp.obj: CMakeFiles/Fashion_Show.dir/flags.make
CMakeFiles/Fashion_Show.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\lenovo\CLionProjects\Fashion Show\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Fashion_Show.dir/main.cpp.obj"
	C:\PROGRA~1\X86_64~1.0-W\mingw64\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Fashion_Show.dir\main.cpp.obj -c "C:\Users\lenovo\CLionProjects\Fashion Show\main.cpp"

CMakeFiles/Fashion_Show.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Fashion_Show.dir/main.cpp.i"
	C:\PROGRA~1\X86_64~1.0-W\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\lenovo\CLionProjects\Fashion Show\main.cpp" > CMakeFiles\Fashion_Show.dir\main.cpp.i

CMakeFiles/Fashion_Show.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Fashion_Show.dir/main.cpp.s"
	C:\PROGRA~1\X86_64~1.0-W\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\lenovo\CLionProjects\Fashion Show\main.cpp" -o CMakeFiles\Fashion_Show.dir\main.cpp.s

# Object files for target Fashion_Show
Fashion_Show_OBJECTS = \
"CMakeFiles/Fashion_Show.dir/main.cpp.obj"

# External object files for target Fashion_Show
Fashion_Show_EXTERNAL_OBJECTS =

Fashion_Show.exe: CMakeFiles/Fashion_Show.dir/main.cpp.obj
Fashion_Show.exe: CMakeFiles/Fashion_Show.dir/build.make
Fashion_Show.exe: CMakeFiles/Fashion_Show.dir/linklibs.rsp
Fashion_Show.exe: CMakeFiles/Fashion_Show.dir/objects1.rsp
Fashion_Show.exe: CMakeFiles/Fashion_Show.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\lenovo\CLionProjects\Fashion Show\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Fashion_Show.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Fashion_Show.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Fashion_Show.dir/build: Fashion_Show.exe

.PHONY : CMakeFiles/Fashion_Show.dir/build

CMakeFiles/Fashion_Show.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Fashion_Show.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Fashion_Show.dir/clean

CMakeFiles/Fashion_Show.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\lenovo\CLionProjects\Fashion Show" "C:\Users\lenovo\CLionProjects\Fashion Show" "C:\Users\lenovo\CLionProjects\Fashion Show\cmake-build-debug" "C:\Users\lenovo\CLionProjects\Fashion Show\cmake-build-debug" "C:\Users\lenovo\CLionProjects\Fashion Show\cmake-build-debug\CMakeFiles\Fashion_Show.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Fashion_Show.dir/depend
