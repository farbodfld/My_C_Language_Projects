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
CMAKE_SOURCE_DIR = C:\Users\lenovo\CLionProjects\tafrih

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\lenovo\CLionProjects\tafrih\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Arrays__algorithm_.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Arrays__algorithm_.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Arrays__algorithm_.dir/flags.make

CMakeFiles/Arrays__algorithm_.dir/main.cpp.obj: CMakeFiles/Arrays__algorithm_.dir/flags.make
CMakeFiles/Arrays__algorithm_.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\lenovo\CLionProjects\tafrih\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Arrays__algorithm_.dir/main.cpp.obj"
	C:\PROGRA~1\X86_64~1.0-W\mingw64\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Arrays__algorithm_.dir\main.cpp.obj -c C:\Users\lenovo\CLionProjects\tafrih\main.cpp

CMakeFiles/Arrays__algorithm_.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Arrays__algorithm_.dir/main.cpp.i"
	C:\PROGRA~1\X86_64~1.0-W\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\lenovo\CLionProjects\tafrih\main.cpp > CMakeFiles\Arrays__algorithm_.dir\main.cpp.i

CMakeFiles/Arrays__algorithm_.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Arrays__algorithm_.dir/main.cpp.s"
	C:\PROGRA~1\X86_64~1.0-W\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\lenovo\CLionProjects\tafrih\main.cpp -o CMakeFiles\Arrays__algorithm_.dir\main.cpp.s

# Object files for target Arrays__algorithm_
Arrays__algorithm__OBJECTS = \
"CMakeFiles/Arrays__algorithm_.dir/main.cpp.obj"

# External object files for target Arrays__algorithm_
Arrays__algorithm__EXTERNAL_OBJECTS =

Arrays__algorithm_.exe: CMakeFiles/Arrays__algorithm_.dir/main.cpp.obj
Arrays__algorithm_.exe: CMakeFiles/Arrays__algorithm_.dir/build.make
Arrays__algorithm_.exe: CMakeFiles/Arrays__algorithm_.dir/linklibs.rsp
Arrays__algorithm_.exe: CMakeFiles/Arrays__algorithm_.dir/objects1.rsp
Arrays__algorithm_.exe: CMakeFiles/Arrays__algorithm_.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\lenovo\CLionProjects\tafrih\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Arrays__algorithm_.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Arrays__algorithm_.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Arrays__algorithm_.dir/build: Arrays__algorithm_.exe

.PHONY : CMakeFiles/Arrays__algorithm_.dir/build

CMakeFiles/Arrays__algorithm_.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Arrays__algorithm_.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Arrays__algorithm_.dir/clean

CMakeFiles/Arrays__algorithm_.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\lenovo\CLionProjects\tafrih C:\Users\lenovo\CLionProjects\tafrih C:\Users\lenovo\CLionProjects\tafrih\cmake-build-debug C:\Users\lenovo\CLionProjects\tafrih\cmake-build-debug C:\Users\lenovo\CLionProjects\tafrih\cmake-build-debug\CMakeFiles\Arrays__algorithm_.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Arrays__algorithm_.dir/depend

