# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/build

# Include any dependencies generated for this target.
include Src/CMakeFiles/Emulator.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include Src/CMakeFiles/Emulator.dir/compiler_depend.make

# Include the progress variables for this target.
include Src/CMakeFiles/Emulator.dir/progress.make

# Include the compile flags for this target's objects.
include Src/CMakeFiles/Emulator.dir/flags.make

Src/CMakeFiles/Emulator.dir/Bus.c.o: Src/CMakeFiles/Emulator.dir/flags.make
Src/CMakeFiles/Emulator.dir/Bus.c.o: ../Src/Bus.c
Src/CMakeFiles/Emulator.dir/Bus.c.o: Src/CMakeFiles/Emulator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object Src/CMakeFiles/Emulator.dir/Bus.c.o"
	cd /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/build/Src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT Src/CMakeFiles/Emulator.dir/Bus.c.o -MF CMakeFiles/Emulator.dir/Bus.c.o.d -o CMakeFiles/Emulator.dir/Bus.c.o -c /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/Src/Bus.c

Src/CMakeFiles/Emulator.dir/Bus.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Emulator.dir/Bus.c.i"
	cd /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/build/Src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/Src/Bus.c > CMakeFiles/Emulator.dir/Bus.c.i

Src/CMakeFiles/Emulator.dir/Bus.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Emulator.dir/Bus.c.s"
	cd /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/build/Src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/Src/Bus.c -o CMakeFiles/Emulator.dir/Bus.c.s

Src/CMakeFiles/Emulator.dir/CPU.c.o: Src/CMakeFiles/Emulator.dir/flags.make
Src/CMakeFiles/Emulator.dir/CPU.c.o: ../Src/CPU.c
Src/CMakeFiles/Emulator.dir/CPU.c.o: Src/CMakeFiles/Emulator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object Src/CMakeFiles/Emulator.dir/CPU.c.o"
	cd /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/build/Src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT Src/CMakeFiles/Emulator.dir/CPU.c.o -MF CMakeFiles/Emulator.dir/CPU.c.o.d -o CMakeFiles/Emulator.dir/CPU.c.o -c /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/Src/CPU.c

Src/CMakeFiles/Emulator.dir/CPU.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Emulator.dir/CPU.c.i"
	cd /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/build/Src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/Src/CPU.c > CMakeFiles/Emulator.dir/CPU.c.i

Src/CMakeFiles/Emulator.dir/CPU.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Emulator.dir/CPU.c.s"
	cd /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/build/Src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/Src/CPU.c -o CMakeFiles/Emulator.dir/CPU.c.s

Src/CMakeFiles/Emulator.dir/Cartridge.c.o: Src/CMakeFiles/Emulator.dir/flags.make
Src/CMakeFiles/Emulator.dir/Cartridge.c.o: ../Src/Cartridge.c
Src/CMakeFiles/Emulator.dir/Cartridge.c.o: Src/CMakeFiles/Emulator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object Src/CMakeFiles/Emulator.dir/Cartridge.c.o"
	cd /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/build/Src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT Src/CMakeFiles/Emulator.dir/Cartridge.c.o -MF CMakeFiles/Emulator.dir/Cartridge.c.o.d -o CMakeFiles/Emulator.dir/Cartridge.c.o -c /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/Src/Cartridge.c

Src/CMakeFiles/Emulator.dir/Cartridge.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Emulator.dir/Cartridge.c.i"
	cd /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/build/Src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/Src/Cartridge.c > CMakeFiles/Emulator.dir/Cartridge.c.i

Src/CMakeFiles/Emulator.dir/Cartridge.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Emulator.dir/Cartridge.c.s"
	cd /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/build/Src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/Src/Cartridge.c -o CMakeFiles/Emulator.dir/Cartridge.c.s

Src/CMakeFiles/Emulator.dir/Emulator.c.o: Src/CMakeFiles/Emulator.dir/flags.make
Src/CMakeFiles/Emulator.dir/Emulator.c.o: ../Src/Emulator.c
Src/CMakeFiles/Emulator.dir/Emulator.c.o: Src/CMakeFiles/Emulator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object Src/CMakeFiles/Emulator.dir/Emulator.c.o"
	cd /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/build/Src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT Src/CMakeFiles/Emulator.dir/Emulator.c.o -MF CMakeFiles/Emulator.dir/Emulator.c.o.d -o CMakeFiles/Emulator.dir/Emulator.c.o -c /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/Src/Emulator.c

Src/CMakeFiles/Emulator.dir/Emulator.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Emulator.dir/Emulator.c.i"
	cd /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/build/Src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/Src/Emulator.c > CMakeFiles/Emulator.dir/Emulator.c.i

Src/CMakeFiles/Emulator.dir/Emulator.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Emulator.dir/Emulator.c.s"
	cd /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/build/Src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/Src/Emulator.c -o CMakeFiles/Emulator.dir/Emulator.c.s

Src/CMakeFiles/Emulator.dir/PPU.c.o: Src/CMakeFiles/Emulator.dir/flags.make
Src/CMakeFiles/Emulator.dir/PPU.c.o: ../Src/PPU.c
Src/CMakeFiles/Emulator.dir/PPU.c.o: Src/CMakeFiles/Emulator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object Src/CMakeFiles/Emulator.dir/PPU.c.o"
	cd /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/build/Src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT Src/CMakeFiles/Emulator.dir/PPU.c.o -MF CMakeFiles/Emulator.dir/PPU.c.o.d -o CMakeFiles/Emulator.dir/PPU.c.o -c /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/Src/PPU.c

Src/CMakeFiles/Emulator.dir/PPU.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Emulator.dir/PPU.c.i"
	cd /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/build/Src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/Src/PPU.c > CMakeFiles/Emulator.dir/PPU.c.i

Src/CMakeFiles/Emulator.dir/PPU.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Emulator.dir/PPU.c.s"
	cd /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/build/Src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/Src/PPU.c -o CMakeFiles/Emulator.dir/PPU.c.s

Src/CMakeFiles/Emulator.dir/Timer.c.o: Src/CMakeFiles/Emulator.dir/flags.make
Src/CMakeFiles/Emulator.dir/Timer.c.o: ../Src/Timer.c
Src/CMakeFiles/Emulator.dir/Timer.c.o: Src/CMakeFiles/Emulator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object Src/CMakeFiles/Emulator.dir/Timer.c.o"
	cd /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/build/Src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT Src/CMakeFiles/Emulator.dir/Timer.c.o -MF CMakeFiles/Emulator.dir/Timer.c.o.d -o CMakeFiles/Emulator.dir/Timer.c.o -c /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/Src/Timer.c

Src/CMakeFiles/Emulator.dir/Timer.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Emulator.dir/Timer.c.i"
	cd /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/build/Src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/Src/Timer.c > CMakeFiles/Emulator.dir/Timer.c.i

Src/CMakeFiles/Emulator.dir/Timer.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Emulator.dir/Timer.c.s"
	cd /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/build/Src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/Src/Timer.c -o CMakeFiles/Emulator.dir/Timer.c.s

# Object files for target Emulator
Emulator_OBJECTS = \
"CMakeFiles/Emulator.dir/Bus.c.o" \
"CMakeFiles/Emulator.dir/CPU.c.o" \
"CMakeFiles/Emulator.dir/Cartridge.c.o" \
"CMakeFiles/Emulator.dir/Emulator.c.o" \
"CMakeFiles/Emulator.dir/PPU.c.o" \
"CMakeFiles/Emulator.dir/Timer.c.o"

# External object files for target Emulator
Emulator_EXTERNAL_OBJECTS =

Src/libEmulator.a: Src/CMakeFiles/Emulator.dir/Bus.c.o
Src/libEmulator.a: Src/CMakeFiles/Emulator.dir/CPU.c.o
Src/libEmulator.a: Src/CMakeFiles/Emulator.dir/Cartridge.c.o
Src/libEmulator.a: Src/CMakeFiles/Emulator.dir/Emulator.c.o
Src/libEmulator.a: Src/CMakeFiles/Emulator.dir/PPU.c.o
Src/libEmulator.a: Src/CMakeFiles/Emulator.dir/Timer.c.o
Src/libEmulator.a: Src/CMakeFiles/Emulator.dir/build.make
Src/libEmulator.a: Src/CMakeFiles/Emulator.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking C static library libEmulator.a"
	cd /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/build/Src && $(CMAKE_COMMAND) -P CMakeFiles/Emulator.dir/cmake_clean_target.cmake
	cd /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/build/Src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Emulator.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Src/CMakeFiles/Emulator.dir/build: Src/libEmulator.a
.PHONY : Src/CMakeFiles/Emulator.dir/build

Src/CMakeFiles/Emulator.dir/clean:
	cd /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/build/Src && $(CMAKE_COMMAND) -P CMakeFiles/Emulator.dir/cmake_clean.cmake
.PHONY : Src/CMakeFiles/Emulator.dir/clean

Src/CMakeFiles/Emulator.dir/depend:
	cd /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/Src /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/build /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/build/Src /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/build/Src/CMakeFiles/Emulator.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Src/CMakeFiles/Emulator.dir/depend
