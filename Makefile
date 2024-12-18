# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.31

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:

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
CMAKE_SOURCE_DIR = /home/shuumo/Documents/code420/password_manager

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/shuumo/Documents/code420/password_manager

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --cyan "Running CMake cache editor..."
	/usr/bin/ccmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/shuumo/Documents/code420/password_manager/CMakeFiles /home/shuumo/Documents/code420/password_manager//CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/shuumo/Documents/code420/password_manager/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named password_manager

# Build rule for target.
password_manager: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 password_manager
.PHONY : password_manager

# fast build rule for target.
password_manager/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/password_manager.dir/build.make CMakeFiles/password_manager.dir/build
.PHONY : password_manager/fast

#=============================================================================
# Target rules for targets named password_manager_autogen_timestamp_deps

# Build rule for target.
password_manager_autogen_timestamp_deps: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 password_manager_autogen_timestamp_deps
.PHONY : password_manager_autogen_timestamp_deps

# fast build rule for target.
password_manager_autogen_timestamp_deps/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/password_manager_autogen_timestamp_deps.dir/build.make CMakeFiles/password_manager_autogen_timestamp_deps.dir/build
.PHONY : password_manager_autogen_timestamp_deps/fast

#=============================================================================
# Target rules for targets named password_manager_autogen

# Build rule for target.
password_manager_autogen: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 password_manager_autogen
.PHONY : password_manager_autogen

# fast build rule for target.
password_manager_autogen/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/password_manager_autogen.dir/build.make CMakeFiles/password_manager_autogen.dir/build
.PHONY : password_manager_autogen/fast

password_manager_autogen/mocs_compilation.o: password_manager_autogen/mocs_compilation.cpp.o
.PHONY : password_manager_autogen/mocs_compilation.o

# target to build an object file
password_manager_autogen/mocs_compilation.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/password_manager.dir/build.make CMakeFiles/password_manager.dir/password_manager_autogen/mocs_compilation.cpp.o
.PHONY : password_manager_autogen/mocs_compilation.cpp.o

password_manager_autogen/mocs_compilation.i: password_manager_autogen/mocs_compilation.cpp.i
.PHONY : password_manager_autogen/mocs_compilation.i

# target to preprocess a source file
password_manager_autogen/mocs_compilation.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/password_manager.dir/build.make CMakeFiles/password_manager.dir/password_manager_autogen/mocs_compilation.cpp.i
.PHONY : password_manager_autogen/mocs_compilation.cpp.i

password_manager_autogen/mocs_compilation.s: password_manager_autogen/mocs_compilation.cpp.s
.PHONY : password_manager_autogen/mocs_compilation.s

# target to generate assembly for a file
password_manager_autogen/mocs_compilation.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/password_manager.dir/build.make CMakeFiles/password_manager.dir/password_manager_autogen/mocs_compilation.cpp.s
.PHONY : password_manager_autogen/mocs_compilation.cpp.s

src/main.o: src/main.cpp.o
.PHONY : src/main.o

# target to build an object file
src/main.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/password_manager.dir/build.make CMakeFiles/password_manager.dir/src/main.cpp.o
.PHONY : src/main.cpp.o

src/main.i: src/main.cpp.i
.PHONY : src/main.i

# target to preprocess a source file
src/main.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/password_manager.dir/build.make CMakeFiles/password_manager.dir/src/main.cpp.i
.PHONY : src/main.cpp.i

src/main.s: src/main.cpp.s
.PHONY : src/main.s

# target to generate assembly for a file
src/main.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/password_manager.dir/build.make CMakeFiles/password_manager.dir/src/main.cpp.s
.PHONY : src/main.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... password_manager_autogen"
	@echo "... password_manager_autogen_timestamp_deps"
	@echo "... password_manager"
	@echo "... password_manager_autogen/mocs_compilation.o"
	@echo "... password_manager_autogen/mocs_compilation.i"
	@echo "... password_manager_autogen/mocs_compilation.s"
	@echo "... src/main.o"
	@echo "... src/main.i"
	@echo "... src/main.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

