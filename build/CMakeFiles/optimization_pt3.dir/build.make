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
include CMakeFiles/optimization_pt3.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/optimization_pt3.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/optimization_pt3.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/optimization_pt3.dir/flags.make

CMakeFiles/optimization_pt3.dir/codegen:
.PHONY : CMakeFiles/optimization_pt3.dir/codegen

CMakeFiles/optimization_pt3.dir/src/main.cpp.obj: CMakeFiles/optimization_pt3.dir/flags.make
CMakeFiles/optimization_pt3.dir/src/main.cpp.obj: CMakeFiles/optimization_pt3.dir/includes_CXX.rsp
CMakeFiles/optimization_pt3.dir/src/main.cpp.obj: C:/Users/carry/Desktop/optimization-pt3/src/main.cpp
CMakeFiles/optimization_pt3.dir/src/main.cpp.obj: CMakeFiles/optimization_pt3.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\carry\Desktop\optimization-pt3\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/optimization_pt3.dir/src/main.cpp.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/optimization_pt3.dir/src/main.cpp.obj -MF CMakeFiles\optimization_pt3.dir\src\main.cpp.obj.d -o CMakeFiles\optimization_pt3.dir\src\main.cpp.obj -c C:\Users\carry\Desktop\optimization-pt3\src\main.cpp

CMakeFiles/optimization_pt3.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/optimization_pt3.dir/src/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\carry\Desktop\optimization-pt3\src\main.cpp > CMakeFiles\optimization_pt3.dir\src\main.cpp.i

CMakeFiles/optimization_pt3.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/optimization_pt3.dir/src/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\carry\Desktop\optimization-pt3\src\main.cpp -o CMakeFiles\optimization_pt3.dir\src\main.cpp.s

# Object files for target optimization_pt3
optimization_pt3_OBJECTS = \
"CMakeFiles/optimization_pt3.dir/src/main.cpp.obj"

# External object files for target optimization_pt3
optimization_pt3_EXTERNAL_OBJECTS =

optimization_pt3.exe: CMakeFiles/optimization_pt3.dir/src/main.cpp.obj
optimization_pt3.exe: CMakeFiles/optimization_pt3.dir/build.make
optimization_pt3.exe: libmatrix.a
optimization_pt3.exe: libvogel.a
optimization_pt3.exe: CMakeFiles/optimization_pt3.dir/linkLibs.rsp
optimization_pt3.exe: CMakeFiles/optimization_pt3.dir/objects1.rsp
optimization_pt3.exe: CMakeFiles/optimization_pt3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\carry\Desktop\optimization-pt3\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable optimization_pt3.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\optimization_pt3.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/optimization_pt3.dir/build: optimization_pt3.exe
.PHONY : CMakeFiles/optimization_pt3.dir/build

CMakeFiles/optimization_pt3.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\optimization_pt3.dir\cmake_clean.cmake
.PHONY : CMakeFiles/optimization_pt3.dir/clean

CMakeFiles/optimization_pt3.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\carry\Desktop\optimization-pt3 C:\Users\carry\Desktop\optimization-pt3 C:\Users\carry\Desktop\optimization-pt3\build C:\Users\carry\Desktop\optimization-pt3\build C:\Users\carry\Desktop\optimization-pt3\build\CMakeFiles\optimization_pt3.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/optimization_pt3.dir/depend

