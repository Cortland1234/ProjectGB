# CMake generated Testfile for 
# Source directory: /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu
# Build directory: /mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(check_gbe "/mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/build/tests/check_gbe")
set_tests_properties(check_gbe PROPERTIES  _BACKTRACE_TRIPLES "/mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/CMakeLists.txt;96;add_test;/mnt/c/Users/cortl/OneDrive/Documents/GitHub/ProjectGB/ProjectGB_Emu/CMakeLists.txt;0;")
subdirs("lib")
subdirs("gbemu")
subdirs("tests")
