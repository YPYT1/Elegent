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
include CMakeFiles/stack.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/stack.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/stack.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/stack.dir/flags.make

CMakeFiles/stack.dir/Mycodeschool/stack.c.obj: CMakeFiles/stack.dir/flags.make
CMakeFiles/stack.dir/Mycodeschool/stack.c.obj: D:/CLionProject/Study/Mycodeschool/stack.c
CMakeFiles/stack.dir/Mycodeschool/stack.c.obj: CMakeFiles/stack.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=D:\CLionProject\Study\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/stack.dir/Mycodeschool/stack.c.obj"
	D:\MinGW\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/stack.dir/Mycodeschool/stack.c.obj -MF CMakeFiles\stack.dir\Mycodeschool\stack.c.obj.d -o CMakeFiles\stack.dir\Mycodeschool\stack.c.obj -c D:\CLionProject\Study\Mycodeschool\stack.c

CMakeFiles/stack.dir/Mycodeschool/stack.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/stack.dir/Mycodeschool/stack.c.i"
	D:\MinGW\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\CLionProject\Study\Mycodeschool\stack.c > CMakeFiles\stack.dir\Mycodeschool\stack.c.i

CMakeFiles/stack.dir/Mycodeschool/stack.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/stack.dir/Mycodeschool/stack.c.s"
	D:\MinGW\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\CLionProject\Study\Mycodeschool\stack.c -o CMakeFiles\stack.dir\Mycodeschool\stack.c.s

# Object files for target stack
stack_OBJECTS = \
"CMakeFiles/stack.dir/Mycodeschool/stack.c.obj"

# External object files for target stack
stack_EXTERNAL_OBJECTS =

stack.exe: CMakeFiles/stack.dir/Mycodeschool/stack.c.obj
stack.exe: CMakeFiles/stack.dir/build.make
stack.exe: CMakeFiles/stack.dir/linkLibs.rsp
stack.exe: CMakeFiles/stack.dir/objects1.rsp
stack.exe: CMakeFiles/stack.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=D:\CLionProject\Study\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable stack.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\stack.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/stack.dir/build: stack.exe
.PHONY : CMakeFiles/stack.dir/build

CMakeFiles/stack.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\stack.dir\cmake_clean.cmake
.PHONY : CMakeFiles/stack.dir/clean

CMakeFiles/stack.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\CLionProject\Study D:\CLionProject\Study D:\CLionProject\Study\cmake-build-debug D:\CLionProject\Study\cmake-build-debug D:\CLionProject\Study\cmake-build-debug\CMakeFiles\stack.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/stack.dir/depend

