# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.31

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\carry\Desktop\optimization-pt3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\carry\Desktop\optimization-pt3\build

# Include any dependencies generated for this target.
include CMakeFiles/matrix.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/matrix.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/matrix.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/matrix.dir/flags.make

CMakeFiles/matrix.dir/codegen:
.PHONY : CMakeFiles/matrix.dir/codegen

CMakeFiles/matrix.dir/src/headers/matrix.cpp.obj: CMakeFiles/matrix.dir/flags.make
CMakeFiles/matrix.dir/src/headers/matrix.cpp.obj: CMakeFiles/matrix.dir/includes_CXX.rsp
CMakeFiles/matrix.dir/src/headers/matrix.cpp.obj: C:/Users/carry/Desktop/optimization-pt3/src/headers/matrix.cpp
CMakeFiles/matrix.dir/src/headers/matrix.cpp.obj: CMakeFiles/matrix.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\carry\Desktop\optimization-pt3\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/matrix.dir/src/headers/matrix.cpp.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/matrix.dir/src/headers/matrix.cpp.obj -MF CMakeFiles\matrix.dir\src\headers\matrix.cpp.obj.d -o CMakeFiles\matrix.dir\src\headers\matrix.cpp.obj -c C:\Users\carry\Desktop\optimization-pt3\src\headers\matrix.cpp

CMakeFiles/matrix.dir/src/headers/matrix.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/matrix.dir/src/headers/matrix.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\carry\Desktop\optimization-pt3\src\headers\matrix.cpp > CMakeFiles\matrix.dir\src\headers\matrix.cpp.i

CMakeFiles/matrix.dir/src/headers/matrix.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/matrix.dir/src/headers/matrix.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\carry\Desktop\optimization-pt3\src\headers\matrix.cpp -o CMakeFiles\matrix.dir\src\headers\matrix.cpp.s

# Object files for target matrix
matrix_OBJECTS = \
"CMakeFiles/matrix.dir/src/headers/matrix.cpp.obj"

# External object files for target matrix
matrix_EXTERNAL_OBJECTS =

libmatrix.a: CMakeFiles/matrix.dir/src/headers/matrix.cpp.obj
libmatrix.a: CMakeFiles/matrix.dir/build.make
libmatrix.a: CMakeFiles/matrix.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\carry\Desktop\optimization-pt3\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libmatrix.a"
	$(CMAKE_COMMAND) -P CMakeFiles\matrix.dir\cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\matrix.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/matrix.dir/build: libmatrix.a
.PHONY : CMakeFiles/matrix.dir/build

CMakeFiles/matrix.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\matrix.dir\cmake_clean.cmake
.PHONY : CMakeFiles/matrix.dir/clean

CMakeFiles/matrix.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\carry\Desktop\optimization-pt3 C:\Users\carry\Desktop\optimization-pt3 C:\Users\carry\Desktop\optimization-pt3\build C:\Users\carry\Desktop\optimization-pt3\build C:\Users\carry\Desktop\optimization-pt3\build\CMakeFiles\matrix.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/matrix.dir/depend

