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
include lib/CMakeFiles/emu.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include lib/CMakeFiles/emu.dir/compiler_depend.make

# Include the progress variables for this target.
include lib/CMakeFiles/emu.dir/progress.make

# Include the compile flags for this target's objects.
include lib/CMakeFiles/emu.dir/flags.make

lib/CMakeFiles/emu.dir/Bus.c.o: lib/CMakeFiles/emu.dir/flags.make
lib/CMakeFiles/emu.dir/Bus.c.o: ../lib/Bus.c
lib/CMakeFiles/emu.dir/Bus.c.o: lib/CMakeFiles/emu.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object lib/CMakeFiles/emu.dir/Bus.c.o"
	cd /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/build/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT lib/CMakeFiles/emu.dir/Bus.c.o -MF CMakeFiles/emu.dir/Bus.c.o.d -o CMakeFiles/emu.dir/Bus.c.o -c /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/lib/Bus.c

lib/CMakeFiles/emu.dir/Bus.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/emu.dir/Bus.c.i"
	cd /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/build/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/lib/Bus.c > CMakeFiles/emu.dir/Bus.c.i

lib/CMakeFiles/emu.dir/Bus.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/emu.dir/Bus.c.s"
	cd /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/build/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/lib/Bus.c -o CMakeFiles/emu.dir/Bus.c.s

lib/CMakeFiles/emu.dir/CPU.c.o: lib/CMakeFiles/emu.dir/flags.make
lib/CMakeFiles/emu.dir/CPU.c.o: ../lib/CPU.c
lib/CMakeFiles/emu.dir/CPU.c.o: lib/CMakeFiles/emu.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object lib/CMakeFiles/emu.dir/CPU.c.o"
	cd /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/build/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT lib/CMakeFiles/emu.dir/CPU.c.o -MF CMakeFiles/emu.dir/CPU.c.o.d -o CMakeFiles/emu.dir/CPU.c.o -c /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/lib/CPU.c

lib/CMakeFiles/emu.dir/CPU.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/emu.dir/CPU.c.i"
	cd /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/build/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/lib/CPU.c > CMakeFiles/emu.dir/CPU.c.i

lib/CMakeFiles/emu.dir/CPU.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/emu.dir/CPU.c.s"
	cd /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/build/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/lib/CPU.c -o CMakeFiles/emu.dir/CPU.c.s

lib/CMakeFiles/emu.dir/CPU_Fetch.c.o: lib/CMakeFiles/emu.dir/flags.make
lib/CMakeFiles/emu.dir/CPU_Fetch.c.o: ../lib/CPU_Fetch.c
lib/CMakeFiles/emu.dir/CPU_Fetch.c.o: lib/CMakeFiles/emu.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object lib/CMakeFiles/emu.dir/CPU_Fetch.c.o"
	cd /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/build/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT lib/CMakeFiles/emu.dir/CPU_Fetch.c.o -MF CMakeFiles/emu.dir/CPU_Fetch.c.o.d -o CMakeFiles/emu.dir/CPU_Fetch.c.o -c /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/lib/CPU_Fetch.c

lib/CMakeFiles/emu.dir/CPU_Fetch.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/emu.dir/CPU_Fetch.c.i"
	cd /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/build/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/lib/CPU_Fetch.c > CMakeFiles/emu.dir/CPU_Fetch.c.i

lib/CMakeFiles/emu.dir/CPU_Fetch.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/emu.dir/CPU_Fetch.c.s"
	cd /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/build/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/lib/CPU_Fetch.c -o CMakeFiles/emu.dir/CPU_Fetch.c.s

lib/CMakeFiles/emu.dir/CPU_Proc.c.o: lib/CMakeFiles/emu.dir/flags.make
lib/CMakeFiles/emu.dir/CPU_Proc.c.o: ../lib/CPU_Proc.c
lib/CMakeFiles/emu.dir/CPU_Proc.c.o: lib/CMakeFiles/emu.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object lib/CMakeFiles/emu.dir/CPU_Proc.c.o"
	cd /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/build/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT lib/CMakeFiles/emu.dir/CPU_Proc.c.o -MF CMakeFiles/emu.dir/CPU_Proc.c.o.d -o CMakeFiles/emu.dir/CPU_Proc.c.o -c /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/lib/CPU_Proc.c

lib/CMakeFiles/emu.dir/CPU_Proc.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/emu.dir/CPU_Proc.c.i"
	cd /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/build/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/lib/CPU_Proc.c > CMakeFiles/emu.dir/CPU_Proc.c.i

lib/CMakeFiles/emu.dir/CPU_Proc.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/emu.dir/CPU_Proc.c.s"
	cd /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/build/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/lib/CPU_Proc.c -o CMakeFiles/emu.dir/CPU_Proc.c.s

lib/CMakeFiles/emu.dir/CPU_Util.c.o: lib/CMakeFiles/emu.dir/flags.make
lib/CMakeFiles/emu.dir/CPU_Util.c.o: ../lib/CPU_Util.c
lib/CMakeFiles/emu.dir/CPU_Util.c.o: lib/CMakeFiles/emu.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object lib/CMakeFiles/emu.dir/CPU_Util.c.o"
	cd /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/build/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT lib/CMakeFiles/emu.dir/CPU_Util.c.o -MF CMakeFiles/emu.dir/CPU_Util.c.o.d -o CMakeFiles/emu.dir/CPU_Util.c.o -c /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/lib/CPU_Util.c

lib/CMakeFiles/emu.dir/CPU_Util.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/emu.dir/CPU_Util.c.i"
	cd /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/build/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/lib/CPU_Util.c > CMakeFiles/emu.dir/CPU_Util.c.i

lib/CMakeFiles/emu.dir/CPU_Util.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/emu.dir/CPU_Util.c.s"
	cd /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/build/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/lib/CPU_Util.c -o CMakeFiles/emu.dir/CPU_Util.c.s

lib/CMakeFiles/emu.dir/Cartridge.c.o: lib/CMakeFiles/emu.dir/flags.make
lib/CMakeFiles/emu.dir/Cartridge.c.o: ../lib/Cartridge.c
lib/CMakeFiles/emu.dir/Cartridge.c.o: lib/CMakeFiles/emu.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object lib/CMakeFiles/emu.dir/Cartridge.c.o"
	cd /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/build/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT lib/CMakeFiles/emu.dir/Cartridge.c.o -MF CMakeFiles/emu.dir/Cartridge.c.o.d -o CMakeFiles/emu.dir/Cartridge.c.o -c /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/lib/Cartridge.c

lib/CMakeFiles/emu.dir/Cartridge.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/emu.dir/Cartridge.c.i"
	cd /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/build/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/lib/Cartridge.c > CMakeFiles/emu.dir/Cartridge.c.i

lib/CMakeFiles/emu.dir/Cartridge.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/emu.dir/Cartridge.c.s"
	cd /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/build/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/lib/Cartridge.c -o CMakeFiles/emu.dir/Cartridge.c.s

lib/CMakeFiles/emu.dir/Debug.c.o: lib/CMakeFiles/emu.dir/flags.make
lib/CMakeFiles/emu.dir/Debug.c.o: ../lib/Debug.c
lib/CMakeFiles/emu.dir/Debug.c.o: lib/CMakeFiles/emu.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object lib/CMakeFiles/emu.dir/Debug.c.o"
	cd /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/build/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT lib/CMakeFiles/emu.dir/Debug.c.o -MF CMakeFiles/emu.dir/Debug.c.o.d -o CMakeFiles/emu.dir/Debug.c.o -c /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/lib/Debug.c

lib/CMakeFiles/emu.dir/Debug.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/emu.dir/Debug.c.i"
	cd /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/build/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/lib/Debug.c > CMakeFiles/emu.dir/Debug.c.i

lib/CMakeFiles/emu.dir/Debug.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/emu.dir/Debug.c.s"
	cd /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/build/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/lib/Debug.c -o CMakeFiles/emu.dir/Debug.c.s

lib/CMakeFiles/emu.dir/Dma.c.o: lib/CMakeFiles/emu.dir/flags.make
lib/CMakeFiles/emu.dir/Dma.c.o: ../lib/Dma.c
lib/CMakeFiles/emu.dir/Dma.c.o: lib/CMakeFiles/emu.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object lib/CMakeFiles/emu.dir/Dma.c.o"
	cd /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/build/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT lib/CMakeFiles/emu.dir/Dma.c.o -MF CMakeFiles/emu.dir/Dma.c.o.d -o CMakeFiles/emu.dir/Dma.c.o -c /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/lib/Dma.c

lib/CMakeFiles/emu.dir/Dma.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/emu.dir/Dma.c.i"
	cd /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/build/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/lib/Dma.c > CMakeFiles/emu.dir/Dma.c.i

lib/CMakeFiles/emu.dir/Dma.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/emu.dir/Dma.c.s"
	cd /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/build/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/lib/Dma.c -o CMakeFiles/emu.dir/Dma.c.s

lib/CMakeFiles/emu.dir/Emu.c.o: lib/CMakeFiles/emu.dir/flags.make
lib/CMakeFiles/emu.dir/Emu.c.o: ../lib/Emu.c
lib/CMakeFiles/emu.dir/Emu.c.o: lib/CMakeFiles/emu.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object lib/CMakeFiles/emu.dir/Emu.c.o"
	cd /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/build/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT lib/CMakeFiles/emu.dir/Emu.c.o -MF CMakeFiles/emu.dir/Emu.c.o.d -o CMakeFiles/emu.dir/Emu.c.o -c /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/lib/Emu.c

lib/CMakeFiles/emu.dir/Emu.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/emu.dir/Emu.c.i"
	cd /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/build/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/lib/Emu.c > CMakeFiles/emu.dir/Emu.c.i

lib/CMakeFiles/emu.dir/Emu.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/emu.dir/Emu.c.s"
	cd /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/build/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/lib/Emu.c -o CMakeFiles/emu.dir/Emu.c.s

lib/CMakeFiles/emu.dir/Gamepad.c.o: lib/CMakeFiles/emu.dir/flags.make
lib/CMakeFiles/emu.dir/Gamepad.c.o: ../lib/Gamepad.c
lib/CMakeFiles/emu.dir/Gamepad.c.o: lib/CMakeFiles/emu.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building C object lib/CMakeFiles/emu.dir/Gamepad.c.o"
	cd /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/build/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT lib/CMakeFiles/emu.dir/Gamepad.c.o -MF CMakeFiles/emu.dir/Gamepad.c.o.d -o CMakeFiles/emu.dir/Gamepad.c.o -c /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/lib/Gamepad.c

lib/CMakeFiles/emu.dir/Gamepad.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/emu.dir/Gamepad.c.i"
	cd /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/build/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/lib/Gamepad.c > CMakeFiles/emu.dir/Gamepad.c.i

lib/CMakeFiles/emu.dir/Gamepad.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/emu.dir/Gamepad.c.s"
	cd /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/build/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/lib/Gamepad.c -o CMakeFiles/emu.dir/Gamepad.c.s

lib/CMakeFiles/emu.dir/IO.c.o: lib/CMakeFiles/emu.dir/flags.make
lib/CMakeFiles/emu.dir/IO.c.o: ../lib/IO.c
lib/CMakeFiles/emu.dir/IO.c.o: lib/CMakeFiles/emu.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building C object lib/CMakeFiles/emu.dir/IO.c.o"
	cd /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/build/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT lib/CMakeFiles/emu.dir/IO.c.o -MF CMakeFiles/emu.dir/IO.c.o.d -o CMakeFiles/emu.dir/IO.c.o -c /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/lib/IO.c

lib/CMakeFiles/emu.dir/IO.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/emu.dir/IO.c.i"
	cd /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/build/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/lib/IO.c > CMakeFiles/emu.dir/IO.c.i

lib/CMakeFiles/emu.dir/IO.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/emu.dir/IO.c.s"
	cd /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/build/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/lib/IO.c -o CMakeFiles/emu.dir/IO.c.s

lib/CMakeFiles/emu.dir/Instructions.c.o: lib/CMakeFiles/emu.dir/flags.make
lib/CMakeFiles/emu.dir/Instructions.c.o: ../lib/Instructions.c
lib/CMakeFiles/emu.dir/Instructions.c.o: lib/CMakeFiles/emu.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building C object lib/CMakeFiles/emu.dir/Instructions.c.o"
	cd /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/build/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT lib/CMakeFiles/emu.dir/Instructions.c.o -MF CMakeFiles/emu.dir/Instructions.c.o.d -o CMakeFiles/emu.dir/Instructions.c.o -c /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/lib/Instructions.c

lib/CMakeFiles/emu.dir/Instructions.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/emu.dir/Instructions.c.i"
	cd /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/build/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/lib/Instructions.c > CMakeFiles/emu.dir/Instructions.c.i

lib/CMakeFiles/emu.dir/Instructions.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/emu.dir/Instructions.c.s"
	cd /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/build/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/lib/Instructions.c -o CMakeFiles/emu.dir/Instructions.c.s

lib/CMakeFiles/emu.dir/Interrupts.c.o: lib/CMakeFiles/emu.dir/flags.make
lib/CMakeFiles/emu.dir/Interrupts.c.o: ../lib/Interrupts.c
lib/CMakeFiles/emu.dir/Interrupts.c.o: lib/CMakeFiles/emu.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building C object lib/CMakeFiles/emu.dir/Interrupts.c.o"
	cd /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/build/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT lib/CMakeFiles/emu.dir/Interrupts.c.o -MF CMakeFiles/emu.dir/Interrupts.c.o.d -o CMakeFiles/emu.dir/Interrupts.c.o -c /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/lib/Interrupts.c

lib/CMakeFiles/emu.dir/Interrupts.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/emu.dir/Interrupts.c.i"
	cd /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/build/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/lib/Interrupts.c > CMakeFiles/emu.dir/Interrupts.c.i

lib/CMakeFiles/emu.dir/Interrupts.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/emu.dir/Interrupts.c.s"
	cd /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/build/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/lib/Interrupts.c -o CMakeFiles/emu.dir/Interrupts.c.s

lib/CMakeFiles/emu.dir/LCD.c.o: lib/CMakeFiles/emu.dir/flags.make
lib/CMakeFiles/emu.dir/LCD.c.o: ../lib/LCD.c
lib/CMakeFiles/emu.dir/LCD.c.o: lib/CMakeFiles/emu.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building C object lib/CMakeFiles/emu.dir/LCD.c.o"
	cd /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/build/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT lib/CMakeFiles/emu.dir/LCD.c.o -MF CMakeFiles/emu.dir/LCD.c.o.d -o CMakeFiles/emu.dir/LCD.c.o -c /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/lib/LCD.c

lib/CMakeFiles/emu.dir/LCD.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/emu.dir/LCD.c.i"
	cd /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/build/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/lib/LCD.c > CMakeFiles/emu.dir/LCD.c.i

lib/CMakeFiles/emu.dir/LCD.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/emu.dir/LCD.c.s"
	cd /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/build/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/lib/LCD.c -o CMakeFiles/emu.dir/LCD.c.s

lib/CMakeFiles/emu.dir/PPU.c.o: lib/CMakeFiles/emu.dir/flags.make
lib/CMakeFiles/emu.dir/PPU.c.o: ../lib/PPU.c
lib/CMakeFiles/emu.dir/PPU.c.o: lib/CMakeFiles/emu.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building C object lib/CMakeFiles/emu.dir/PPU.c.o"
	cd /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/build/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT lib/CMakeFiles/emu.dir/PPU.c.o -MF CMakeFiles/emu.dir/PPU.c.o.d -o CMakeFiles/emu.dir/PPU.c.o -c /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/lib/PPU.c

lib/CMakeFiles/emu.dir/PPU.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/emu.dir/PPU.c.i"
	cd /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/build/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/lib/PPU.c > CMakeFiles/emu.dir/PPU.c.i

lib/CMakeFiles/emu.dir/PPU.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/emu.dir/PPU.c.s"
	cd /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/build/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/lib/PPU.c -o CMakeFiles/emu.dir/PPU.c.s

lib/CMakeFiles/emu.dir/PPUPipeline.c.o: lib/CMakeFiles/emu.dir/flags.make
lib/CMakeFiles/emu.dir/PPUPipeline.c.o: ../lib/PPUPipeline.c
lib/CMakeFiles/emu.dir/PPUPipeline.c.o: lib/CMakeFiles/emu.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Building C object lib/CMakeFiles/emu.dir/PPUPipeline.c.o"
	cd /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/build/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT lib/CMakeFiles/emu.dir/PPUPipeline.c.o -MF CMakeFiles/emu.dir/PPUPipeline.c.o.d -o CMakeFiles/emu.dir/PPUPipeline.c.o -c /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/lib/PPUPipeline.c

lib/CMakeFiles/emu.dir/PPUPipeline.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/emu.dir/PPUPipeline.c.i"
	cd /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/build/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/lib/PPUPipeline.c > CMakeFiles/emu.dir/PPUPipeline.c.i

lib/CMakeFiles/emu.dir/PPUPipeline.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/emu.dir/PPUPipeline.c.s"
	cd /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/build/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/lib/PPUPipeline.c -o CMakeFiles/emu.dir/PPUPipeline.c.s

lib/CMakeFiles/emu.dir/PPUsm.c.o: lib/CMakeFiles/emu.dir/flags.make
lib/CMakeFiles/emu.dir/PPUsm.c.o: ../lib/PPUsm.c
lib/CMakeFiles/emu.dir/PPUsm.c.o: lib/CMakeFiles/emu.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_17) "Building C object lib/CMakeFiles/emu.dir/PPUsm.c.o"
	cd /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/build/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT lib/CMakeFiles/emu.dir/PPUsm.c.o -MF CMakeFiles/emu.dir/PPUsm.c.o.d -o CMakeFiles/emu.dir/PPUsm.c.o -c /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/lib/PPUsm.c

lib/CMakeFiles/emu.dir/PPUsm.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/emu.dir/PPUsm.c.i"
	cd /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/build/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/lib/PPUsm.c > CMakeFiles/emu.dir/PPUsm.c.i

lib/CMakeFiles/emu.dir/PPUsm.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/emu.dir/PPUsm.c.s"
	cd /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/build/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/lib/PPUsm.c -o CMakeFiles/emu.dir/PPUsm.c.s

lib/CMakeFiles/emu.dir/RAM.c.o: lib/CMakeFiles/emu.dir/flags.make
lib/CMakeFiles/emu.dir/RAM.c.o: ../lib/RAM.c
lib/CMakeFiles/emu.dir/RAM.c.o: lib/CMakeFiles/emu.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_18) "Building C object lib/CMakeFiles/emu.dir/RAM.c.o"
	cd /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/build/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT lib/CMakeFiles/emu.dir/RAM.c.o -MF CMakeFiles/emu.dir/RAM.c.o.d -o CMakeFiles/emu.dir/RAM.c.o -c /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/lib/RAM.c

lib/CMakeFiles/emu.dir/RAM.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/emu.dir/RAM.c.i"
	cd /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/build/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/lib/RAM.c > CMakeFiles/emu.dir/RAM.c.i

lib/CMakeFiles/emu.dir/RAM.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/emu.dir/RAM.c.s"
	cd /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/build/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/lib/RAM.c -o CMakeFiles/emu.dir/RAM.c.s

lib/CMakeFiles/emu.dir/Stack.c.o: lib/CMakeFiles/emu.dir/flags.make
lib/CMakeFiles/emu.dir/Stack.c.o: ../lib/Stack.c
lib/CMakeFiles/emu.dir/Stack.c.o: lib/CMakeFiles/emu.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_19) "Building C object lib/CMakeFiles/emu.dir/Stack.c.o"
	cd /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/build/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT lib/CMakeFiles/emu.dir/Stack.c.o -MF CMakeFiles/emu.dir/Stack.c.o.d -o CMakeFiles/emu.dir/Stack.c.o -c /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/lib/Stack.c

lib/CMakeFiles/emu.dir/Stack.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/emu.dir/Stack.c.i"
	cd /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/build/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/lib/Stack.c > CMakeFiles/emu.dir/Stack.c.i

lib/CMakeFiles/emu.dir/Stack.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/emu.dir/Stack.c.s"
	cd /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/build/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/lib/Stack.c -o CMakeFiles/emu.dir/Stack.c.s

lib/CMakeFiles/emu.dir/Timer.c.o: lib/CMakeFiles/emu.dir/flags.make
lib/CMakeFiles/emu.dir/Timer.c.o: ../lib/Timer.c
lib/CMakeFiles/emu.dir/Timer.c.o: lib/CMakeFiles/emu.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_20) "Building C object lib/CMakeFiles/emu.dir/Timer.c.o"
	cd /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/build/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT lib/CMakeFiles/emu.dir/Timer.c.o -MF CMakeFiles/emu.dir/Timer.c.o.d -o CMakeFiles/emu.dir/Timer.c.o -c /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/lib/Timer.c

lib/CMakeFiles/emu.dir/Timer.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/emu.dir/Timer.c.i"
	cd /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/build/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/lib/Timer.c > CMakeFiles/emu.dir/Timer.c.i

lib/CMakeFiles/emu.dir/Timer.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/emu.dir/Timer.c.s"
	cd /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/build/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/lib/Timer.c -o CMakeFiles/emu.dir/Timer.c.s

lib/CMakeFiles/emu.dir/UI.c.o: lib/CMakeFiles/emu.dir/flags.make
lib/CMakeFiles/emu.dir/UI.c.o: ../lib/UI.c
lib/CMakeFiles/emu.dir/UI.c.o: lib/CMakeFiles/emu.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_21) "Building C object lib/CMakeFiles/emu.dir/UI.c.o"
	cd /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/build/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT lib/CMakeFiles/emu.dir/UI.c.o -MF CMakeFiles/emu.dir/UI.c.o.d -o CMakeFiles/emu.dir/UI.c.o -c /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/lib/UI.c

lib/CMakeFiles/emu.dir/UI.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/emu.dir/UI.c.i"
	cd /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/build/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/lib/UI.c > CMakeFiles/emu.dir/UI.c.i

lib/CMakeFiles/emu.dir/UI.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/emu.dir/UI.c.s"
	cd /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/build/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/lib/UI.c -o CMakeFiles/emu.dir/UI.c.s

# Object files for target emu
emu_OBJECTS = \
"CMakeFiles/emu.dir/Bus.c.o" \
"CMakeFiles/emu.dir/CPU.c.o" \
"CMakeFiles/emu.dir/CPU_Fetch.c.o" \
"CMakeFiles/emu.dir/CPU_Proc.c.o" \
"CMakeFiles/emu.dir/CPU_Util.c.o" \
"CMakeFiles/emu.dir/Cartridge.c.o" \
"CMakeFiles/emu.dir/Debug.c.o" \
"CMakeFiles/emu.dir/Dma.c.o" \
"CMakeFiles/emu.dir/Emu.c.o" \
"CMakeFiles/emu.dir/Gamepad.c.o" \
"CMakeFiles/emu.dir/IO.c.o" \
"CMakeFiles/emu.dir/Instructions.c.o" \
"CMakeFiles/emu.dir/Interrupts.c.o" \
"CMakeFiles/emu.dir/LCD.c.o" \
"CMakeFiles/emu.dir/PPU.c.o" \
"CMakeFiles/emu.dir/PPUPipeline.c.o" \
"CMakeFiles/emu.dir/PPUsm.c.o" \
"CMakeFiles/emu.dir/RAM.c.o" \
"CMakeFiles/emu.dir/Stack.c.o" \
"CMakeFiles/emu.dir/Timer.c.o" \
"CMakeFiles/emu.dir/UI.c.o"

# External object files for target emu
emu_EXTERNAL_OBJECTS =

lib/libemu.a: lib/CMakeFiles/emu.dir/Bus.c.o
lib/libemu.a: lib/CMakeFiles/emu.dir/CPU.c.o
lib/libemu.a: lib/CMakeFiles/emu.dir/CPU_Fetch.c.o
lib/libemu.a: lib/CMakeFiles/emu.dir/CPU_Proc.c.o
lib/libemu.a: lib/CMakeFiles/emu.dir/CPU_Util.c.o
lib/libemu.a: lib/CMakeFiles/emu.dir/Cartridge.c.o
lib/libemu.a: lib/CMakeFiles/emu.dir/Debug.c.o
lib/libemu.a: lib/CMakeFiles/emu.dir/Dma.c.o
lib/libemu.a: lib/CMakeFiles/emu.dir/Emu.c.o
lib/libemu.a: lib/CMakeFiles/emu.dir/Gamepad.c.o
lib/libemu.a: lib/CMakeFiles/emu.dir/IO.c.o
lib/libemu.a: lib/CMakeFiles/emu.dir/Instructions.c.o
lib/libemu.a: lib/CMakeFiles/emu.dir/Interrupts.c.o
lib/libemu.a: lib/CMakeFiles/emu.dir/LCD.c.o
lib/libemu.a: lib/CMakeFiles/emu.dir/PPU.c.o
lib/libemu.a: lib/CMakeFiles/emu.dir/PPUPipeline.c.o
lib/libemu.a: lib/CMakeFiles/emu.dir/PPUsm.c.o
lib/libemu.a: lib/CMakeFiles/emu.dir/RAM.c.o
lib/libemu.a: lib/CMakeFiles/emu.dir/Stack.c.o
lib/libemu.a: lib/CMakeFiles/emu.dir/Timer.c.o
lib/libemu.a: lib/CMakeFiles/emu.dir/UI.c.o
lib/libemu.a: lib/CMakeFiles/emu.dir/build.make
lib/libemu.a: lib/CMakeFiles/emu.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_22) "Linking C static library libemu.a"
	cd /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/build/lib && $(CMAKE_COMMAND) -P CMakeFiles/emu.dir/cmake_clean_target.cmake
	cd /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/build/lib && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/emu.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/CMakeFiles/emu.dir/build: lib/libemu.a
.PHONY : lib/CMakeFiles/emu.dir/build

lib/CMakeFiles/emu.dir/clean:
	cd /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/build/lib && $(CMAKE_COMMAND) -P CMakeFiles/emu.dir/cmake_clean.cmake
.PHONY : lib/CMakeFiles/emu.dir/clean

lib/CMakeFiles/emu.dir/depend:
	cd /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/lib /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/build /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/build/lib /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/build/lib/CMakeFiles/emu.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : lib/CMakeFiles/emu.dir/depend

