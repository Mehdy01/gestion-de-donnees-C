# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.21

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.3.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.3.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\hp\Desktop\Data Management"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\hp\Desktop\Data Management\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Data_Management.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Data_Management.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Data_Management.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Data_Management.dir/flags.make

CMakeFiles/Data_Management.dir/employe.c.obj: CMakeFiles/Data_Management.dir/flags.make
CMakeFiles/Data_Management.dir/employe.c.obj: ../employe.c
CMakeFiles/Data_Management.dir/employe.c.obj: CMakeFiles/Data_Management.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\hp\Desktop\Data Management\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Data_Management.dir/employe.c.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.2\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Data_Management.dir/employe.c.obj -MF CMakeFiles\Data_Management.dir\employe.c.obj.d -o CMakeFiles\Data_Management.dir\employe.c.obj -c "C:\Users\hp\Desktop\Data Management\employe.c"

CMakeFiles/Data_Management.dir/employe.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Data_Management.dir/employe.c.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.2\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\hp\Desktop\Data Management\employe.c" > CMakeFiles\Data_Management.dir\employe.c.i

CMakeFiles/Data_Management.dir/employe.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Data_Management.dir/employe.c.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.2\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\hp\Desktop\Data Management\employe.c" -o CMakeFiles\Data_Management.dir\employe.c.s

CMakeFiles/Data_Management.dir/main.c.obj: CMakeFiles/Data_Management.dir/flags.make
CMakeFiles/Data_Management.dir/main.c.obj: ../main.c
CMakeFiles/Data_Management.dir/main.c.obj: CMakeFiles/Data_Management.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\hp\Desktop\Data Management\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/Data_Management.dir/main.c.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.2\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Data_Management.dir/main.c.obj -MF CMakeFiles\Data_Management.dir\main.c.obj.d -o CMakeFiles\Data_Management.dir\main.c.obj -c "C:\Users\hp\Desktop\Data Management\main.c"

CMakeFiles/Data_Management.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Data_Management.dir/main.c.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.2\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\hp\Desktop\Data Management\main.c" > CMakeFiles\Data_Management.dir\main.c.i

CMakeFiles/Data_Management.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Data_Management.dir/main.c.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.2\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\hp\Desktop\Data Management\main.c" -o CMakeFiles\Data_Management.dir\main.c.s

# Object files for target Data_Management
Data_Management_OBJECTS = \
"CMakeFiles/Data_Management.dir/employe.c.obj" \
"CMakeFiles/Data_Management.dir/main.c.obj"

# External object files for target Data_Management
Data_Management_EXTERNAL_OBJECTS =

Data_Management.exe: CMakeFiles/Data_Management.dir/employe.c.obj
Data_Management.exe: CMakeFiles/Data_Management.dir/main.c.obj
Data_Management.exe: CMakeFiles/Data_Management.dir/build.make
Data_Management.exe: CMakeFiles/Data_Management.dir/linklibs.rsp
Data_Management.exe: CMakeFiles/Data_Management.dir/objects1.rsp
Data_Management.exe: CMakeFiles/Data_Management.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\hp\Desktop\Data Management\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable Data_Management.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Data_Management.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Data_Management.dir/build: Data_Management.exe
.PHONY : CMakeFiles/Data_Management.dir/build

CMakeFiles/Data_Management.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Data_Management.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Data_Management.dir/clean

CMakeFiles/Data_Management.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\hp\Desktop\Data Management" "C:\Users\hp\Desktop\Data Management" "C:\Users\hp\Desktop\Data Management\cmake-build-debug" "C:\Users\hp\Desktop\Data Management\cmake-build-debug" "C:\Users\hp\Desktop\Data Management\cmake-build-debug\CMakeFiles\Data_Management.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Data_Management.dir/depend

