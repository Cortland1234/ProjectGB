# CMAKE generated file: DO NOT EDIT!
# Generated by CMake Version 3.22
cmake_policy(SET CMP0009 NEW)

# headers at lib/CMakeLists.txt:5 (file)
file(GLOB NEW_GLOB LIST_DIRECTORIES true "/mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/include/*.h")
set(OLD_GLOB
  "/mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/include/bus.h"
  "/mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/include/cartridge.h"
  "/mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/include/common.h"
  "/mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/include/cpu.h"
  "/mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/include/emu.h"
  "/mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/include/ppu.h"
  "/mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/include/timer.h"
  )
if(NOT "${NEW_GLOB}" STREQUAL "${OLD_GLOB}")
  message("-- GLOB mismatch!")
  file(TOUCH_NOCREATE "/mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/build/CMakeFiles/cmake.verify_globs")
endif()

# sources at lib/CMakeLists.txt:3 (file)
file(GLOB NEW_GLOB LIST_DIRECTORIES true "/mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/lib/*.c")
set(OLD_GLOB
  "/mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/lib/bus.c"
  "/mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/lib/cartridge.c"
  "/mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/lib/cpu.c"
  "/mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/lib/emu.c"
  "/mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/lib/ppu.c"
  "/mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/lib/timer.c"
  )
if(NOT "${NEW_GLOB}" STREQUAL "${OLD_GLOB}")
  message("-- GLOB mismatch!")
  file(TOUCH_NOCREATE "/mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/build/CMakeFiles/cmake.verify_globs")
endif()
