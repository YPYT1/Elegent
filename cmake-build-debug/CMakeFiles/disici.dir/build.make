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
include CMakeFiles/disici.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/disici.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/disici.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/disici.dir/flags.make

CMakeFiles/disici.dir/work/disici.c.obj: CMakeFiles/disici.dir/flags.make
CMakeFiles/disici.dir/work/disici.c.obj: D:/CLionProject/Study/work/disici.c
CMakeFiles/disici.dir/work/disici.c.obj: CMakeFiles/disici.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=D:\CLionProject\Study\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/disici.dir/work/disici.c.obj"
	D:\MinGW\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/disici.dir/work/disici.c.obj -MF CMakeFiles\disici.dir\work\disici.c.obj.d -o CMakeFiles\disici.dir\work\disici.c.obj -c D:\CLionProject\Study\work\disici.c

CMakeFiles/disici.dir/work/disici.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/disici.dir/work/disici.c.i"
	D:\MinGW\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\CLionProject\Study\work\disici.c > CMakeFiles\disici.dir\work\disici.c.i

CMakeFiles/disici.dir/work/disici.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/disici.dir/work/disici.c.s"
	D:\MinGW\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\CLionProject\Study\work\disici.c -o CMakeFiles\disici.dir\work\disici.c.s

# Object files for target disici
disici_OBJECTS = \
"CMakeFiles/disici.dir/work/disici.c.obj"

# External object files for target disici
disici_EXTERNAL_OBJECTS =

disici.exe: CMakeFiles/disici.dir/work/disici.c.obj
disici.exe: CMakeFiles/disici.dir/build.make
disici.exe: CMakeFiles/disici.dir/linkLibs.rsp
disici.exe: CMakeFiles/disici.dir/objects1.rsp
disici.exe: CMakeFiles/disici.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=D:\CLionProject\Study\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable disici.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\disici.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/disici.dir/build: disici.exe
.PHONY : CMakeFiles/disici.dir/build

CMakeFiles/disici.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\disici.dir\cmake_clean.cmake
.PHONY : CMakeFiles/disici.dir/clean

CMakeFiles/disici.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\CLionProject\Study D:\CLionProject\Study D:\CLionProject\Study\cmake-build-debug D:\CLionProject\Study\cmake-build-debug D:\CLionProject\Study\cmake-build-debug\CMakeFiles\disici.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/disici.dir/depend

