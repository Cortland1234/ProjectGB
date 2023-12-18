# CMAKE generated file: DO NOT EDIT!
# Generated by CMake Version 3.22
cmake_policy(SET CMP0009 NEW)

# headers at lib/CMakeLists.txt:5 (file)
file(GLOB NEW_GLOB LIST_DIRECTORIES true "/mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/include/*.h")
set(OLD_GLOB
  "/mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/include/Bus.h"
  "/mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/include/Cartridge.h"
  "/mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/include/Common.h"
  "/mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/include/Cpu.h"
  "/mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/include/Debug.h"
  "/mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/include/Emu.h"
  "/mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/include/IO.h"
  "/mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/include/Instructions.h"
  "/mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/include/Interrupts.h"
  "/mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/include/Ppu.h"
  "/mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/include/Ram.h"
  "/mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/include/Stack.h"
  "/mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/include/Timer.h"
  "/mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/include/UI.h"
  )
if(NOT "${NEW_GLOB}" STREQUAL "${OLD_GLOB}")
  message("-- GLOB mismatch!")
  file(TOUCH_NOCREATE "/mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/build/CMakeFiles/cmake.verify_globs")
endif()

# sources at lib/CMakeLists.txt:3 (file)
file(GLOB NEW_GLOB LIST_DIRECTORIES true "/mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/lib/*.c")
set(OLD_GLOB
  "/mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/lib/Bus.c"
  "/mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/lib/Cartridge.c"
  "/mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/lib/Cpu.c"
  "/mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/lib/Cpu_Fetch.c"
  "/mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/lib/Cpu_Process.c"
  "/mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/lib/Cpu_utilities.c"
  "/mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/lib/Debug.c"
  "/mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/lib/Emu.c"
  "/mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/lib/IO.c"
  "/mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/lib/Instructions.c"
  "/mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/lib/Interrupts.c"
  "/mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/lib/Ppu.c"
  "/mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/lib/Ram.c"
  "/mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/lib/Stack.c"
  "/mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/lib/Timer.c"
  "/mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/lib/UI.c"
  )
if(NOT "${NEW_GLOB}" STREQUAL "${OLD_GLOB}")
  message("-- GLOB mismatch!")
  file(TOUCH_NOCREATE "/mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/build/CMakeFiles/cmake.verify_globs")
endif()
