# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.28

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
CMAKE_COMMAND = D:\CLion\bin\cmake\win\x64\bin\cmake.exe

# The command to remove a file.
RM = D:\CLion\bin\cmake\win\x64\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\CLionProject\Study

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\CLionProject\Study\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/WLT.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/WLT.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/WLT.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/WLT.dir/flags.make

CMakeFiles/WLT.dir/WLT.cpp.obj: CMakeFiles/WLT.dir/flags.make
CMakeFiles/WLT.dir/WLT.cpp.obj: D:/CLionProject/Study/WLT.cpp
CMakeFiles/WLT.dir/WLT.cpp.obj: CMakeFiles/WLT.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=D:\CLionProject\Study\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/WLT.dir/WLT.cpp.obj"
	D:\MinGW\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/WLT.dir/WLT.cpp.obj -MF CMakeFiles\WLT.dir\WLT.cpp.obj.d -o CMakeFiles\WLT.dir\WLT.cpp.obj -c D:\CLionProject\Study\WLT.cpp

CMakeFiles/WLT.dir/WLT.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/WLT.dir/WLT.cpp.i"
	D:\MinGW\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\CLionProject\Study\WLT.cpp > CMakeFiles\WLT.dir\WLT.cpp.i

CMakeFiles/WLT.dir/WLT.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/WLT.dir/WLT.cpp.s"
	D:\MinGW\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\CLionProject\Study\WLT.cpp -o CMakeFiles\WLT.dir\WLT.cpp.s

# Object files for target WLT
WLT_OBJECTS = \
"CMakeFiles/WLT.dir/WLT.cpp.obj"

# External object files for target WLT
WLT_EXTERNAL_OBJECTS =

WLT.exe: CMakeFiles/WLT.dir/WLT.cpp.obj
WLT.exe: CMakeFiles/WLT.dir/build.make
WLT.exe: CMakeFiles/WLT.dir/linkLibs.rsp
WLT.exe: CMakeFiles/WLT.dir/objects1.rsp
WLT.exe: CMakeFiles/WLT.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=D:\CLionProject\Study\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable WLT.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\WLT.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/WLT.dir/build: WLT.exe
.PHONY : CMakeFiles/WLT.dir/build

CMakeFiles/WLT.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\WLT.dir\cmake_clean.cmake
.PHONY : CMakeFiles/WLT.dir/clean

CMakeFiles/WLT.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\CLionProject\Study D:\CLionProject\Study D:\CLionProject\Study\cmake-build-debug D:\CLionProject\Study\cmake-build-debug D:\CLionProject\Study\cmake-build-debug\CMakeFiles\WLT.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/WLT.dir/depend

