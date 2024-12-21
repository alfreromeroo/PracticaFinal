# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_SOURCE_DIR = /home/alfredo/Documentos/ED/Practicas/practica_final/estudiante

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/alfredo/Documentos/ED/Practicas/practica_final/estudiante

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/alfredo/Documentos/ED/Practicas/practica_final/estudiante/CMakeFiles /home/alfredo/Documentos/ED/Practicas/practica_final/estudiante//CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/alfredo/Documentos/ED/Practicas/practica_final/estudiante/CMakeFiles 0
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
# Target rules for targets named quienesquien

# Build rule for target.
quienesquien: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 quienesquien
.PHONY : quienesquien

# fast build rule for target.
quienesquien/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/quienesquien.dir/build.make CMakeFiles/quienesquien.dir/build
.PHONY : quienesquien/fast

#=============================================================================
# Target rules for targets named doc_doxygen

# Build rule for target.
doc_doxygen: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 doc_doxygen
.PHONY : doc_doxygen

# fast build rule for target.
doc_doxygen/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/doc_doxygen.dir/build.make CMakeFiles/doc_doxygen.dir/build
.PHONY : doc_doxygen/fast

#=============================================================================
# Target rules for targets named mrproper

# Build rule for target.
mrproper: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 mrproper
.PHONY : mrproper

# fast build rule for target.
mrproper/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mrproper.dir/build.make CMakeFiles/mrproper.dir/build
.PHONY : mrproper/fast

#=============================================================================
# Target rules for targets named zip

# Build rule for target.
zip: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 zip
.PHONY : zip

# fast build rule for target.
zip/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/zip.dir/build.make CMakeFiles/zip.dir/build
.PHONY : zip/fast

#=============================================================================
# Target rules for targets named quienesquien_autogen

# Build rule for target.
quienesquien_autogen: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 quienesquien_autogen
.PHONY : quienesquien_autogen

# fast build rule for target.
quienesquien_autogen/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/quienesquien_autogen.dir/build.make CMakeFiles/quienesquien_autogen.dir/build
.PHONY : quienesquien_autogen/fast

quienesquien_autogen/mocs_compilation.o: quienesquien_autogen/mocs_compilation.cpp.o
.PHONY : quienesquien_autogen/mocs_compilation.o

# target to build an object file
quienesquien_autogen/mocs_compilation.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/quienesquien.dir/build.make CMakeFiles/quienesquien.dir/quienesquien_autogen/mocs_compilation.cpp.o
.PHONY : quienesquien_autogen/mocs_compilation.cpp.o

quienesquien_autogen/mocs_compilation.i: quienesquien_autogen/mocs_compilation.cpp.i
.PHONY : quienesquien_autogen/mocs_compilation.i

# target to preprocess a source file
quienesquien_autogen/mocs_compilation.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/quienesquien.dir/build.make CMakeFiles/quienesquien.dir/quienesquien_autogen/mocs_compilation.cpp.i
.PHONY : quienesquien_autogen/mocs_compilation.cpp.i

quienesquien_autogen/mocs_compilation.s: quienesquien_autogen/mocs_compilation.cpp.s
.PHONY : quienesquien_autogen/mocs_compilation.s

# target to generate assembly for a file
quienesquien_autogen/mocs_compilation.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/quienesquien.dir/build.make CMakeFiles/quienesquien.dir/quienesquien_autogen/mocs_compilation.cpp.s
.PHONY : quienesquien_autogen/mocs_compilation.cpp.s

src/consola.o: src/consola.cpp.o
.PHONY : src/consola.o

# target to build an object file
src/consola.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/quienesquien.dir/build.make CMakeFiles/quienesquien.dir/src/consola.cpp.o
.PHONY : src/consola.cpp.o

src/consola.i: src/consola.cpp.i
.PHONY : src/consola.i

# target to preprocess a source file
src/consola.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/quienesquien.dir/build.make CMakeFiles/quienesquien.dir/src/consola.cpp.i
.PHONY : src/consola.cpp.i

src/consola.s: src/consola.cpp.s
.PHONY : src/consola.s

# target to generate assembly for a file
src/consola.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/quienesquien.dir/build.make CMakeFiles/quienesquien.dir/src/consola.cpp.s
.PHONY : src/consola.cpp.s

src/main.o: src/main.cpp.o
.PHONY : src/main.o

# target to build an object file
src/main.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/quienesquien.dir/build.make CMakeFiles/quienesquien.dir/src/main.cpp.o
.PHONY : src/main.cpp.o

src/main.i: src/main.cpp.i
.PHONY : src/main.i

# target to preprocess a source file
src/main.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/quienesquien.dir/build.make CMakeFiles/quienesquien.dir/src/main.cpp.i
.PHONY : src/main.cpp.i

src/main.s: src/main.cpp.s
.PHONY : src/main.s

# target to generate assembly for a file
src/main.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/quienesquien.dir/build.make CMakeFiles/quienesquien.dir/src/main.cpp.s
.PHONY : src/main.cpp.s

src/pregunta.o: src/pregunta.cpp.o
.PHONY : src/pregunta.o

# target to build an object file
src/pregunta.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/quienesquien.dir/build.make CMakeFiles/quienesquien.dir/src/pregunta.cpp.o
.PHONY : src/pregunta.cpp.o

src/pregunta.i: src/pregunta.cpp.i
.PHONY : src/pregunta.i

# target to preprocess a source file
src/pregunta.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/quienesquien.dir/build.make CMakeFiles/quienesquien.dir/src/pregunta.cpp.i
.PHONY : src/pregunta.cpp.i

src/pregunta.s: src/pregunta.cpp.s
.PHONY : src/pregunta.s

# target to generate assembly for a file
src/pregunta.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/quienesquien.dir/build.make CMakeFiles/quienesquien.dir/src/pregunta.cpp.s
.PHONY : src/pregunta.cpp.s

src/quienesquien.o: src/quienesquien.cpp.o
.PHONY : src/quienesquien.o

# target to build an object file
src/quienesquien.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/quienesquien.dir/build.make CMakeFiles/quienesquien.dir/src/quienesquien.cpp.o
.PHONY : src/quienesquien.cpp.o

src/quienesquien.i: src/quienesquien.cpp.i
.PHONY : src/quienesquien.i

# target to preprocess a source file
src/quienesquien.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/quienesquien.dir/build.make CMakeFiles/quienesquien.dir/src/quienesquien.cpp.i
.PHONY : src/quienesquien.cpp.i

src/quienesquien.s: src/quienesquien.cpp.s
.PHONY : src/quienesquien.s

# target to generate assembly for a file
src/quienesquien.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/quienesquien.dir/build.make CMakeFiles/quienesquien.dir/src/quienesquien.cpp.s
.PHONY : src/quienesquien.cpp.s

src/tablerografico.o: src/tablerografico.cpp.o
.PHONY : src/tablerografico.o

# target to build an object file
src/tablerografico.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/quienesquien.dir/build.make CMakeFiles/quienesquien.dir/src/tablerografico.cpp.o
.PHONY : src/tablerografico.cpp.o

src/tablerografico.i: src/tablerografico.cpp.i
.PHONY : src/tablerografico.i

# target to preprocess a source file
src/tablerografico.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/quienesquien.dir/build.make CMakeFiles/quienesquien.dir/src/tablerografico.cpp.i
.PHONY : src/tablerografico.cpp.i

src/tablerografico.s: src/tablerografico.cpp.s
.PHONY : src/tablerografico.s

# target to generate assembly for a file
src/tablerografico.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/quienesquien.dir/build.make CMakeFiles/quienesquien.dir/src/tablerografico.cpp.s
.PHONY : src/tablerografico.cpp.s

src/ventana.o: src/ventana.cpp.o
.PHONY : src/ventana.o

# target to build an object file
src/ventana.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/quienesquien.dir/build.make CMakeFiles/quienesquien.dir/src/ventana.cpp.o
.PHONY : src/ventana.cpp.o

src/ventana.i: src/ventana.cpp.i
.PHONY : src/ventana.i

# target to preprocess a source file
src/ventana.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/quienesquien.dir/build.make CMakeFiles/quienesquien.dir/src/ventana.cpp.i
.PHONY : src/ventana.cpp.i

src/ventana.s: src/ventana.cpp.s
.PHONY : src/ventana.s

# target to generate assembly for a file
src/ventana.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/quienesquien.dir/build.make CMakeFiles/quienesquien.dir/src/ventana.cpp.s
.PHONY : src/ventana.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... doc_doxygen"
	@echo "... mrproper"
	@echo "... quienesquien_autogen"
	@echo "... zip"
	@echo "... quienesquien"
	@echo "... quienesquien_autogen/mocs_compilation.o"
	@echo "... quienesquien_autogen/mocs_compilation.i"
	@echo "... quienesquien_autogen/mocs_compilation.s"
	@echo "... src/consola.o"
	@echo "... src/consola.i"
	@echo "... src/consola.s"
	@echo "... src/main.o"
	@echo "... src/main.i"
	@echo "... src/main.s"
	@echo "... src/pregunta.o"
	@echo "... src/pregunta.i"
	@echo "... src/pregunta.s"
	@echo "... src/quienesquien.o"
	@echo "... src/quienesquien.i"
	@echo "... src/quienesquien.s"
	@echo "... src/tablerografico.o"
	@echo "... src/tablerografico.i"
	@echo "... src/tablerografico.s"
	@echo "... src/ventana.o"
	@echo "... src/ventana.i"
	@echo "... src/ventana.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

