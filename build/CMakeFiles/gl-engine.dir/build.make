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
CMAKE_SOURCE_DIR = /home/alex/fun/3d-graphics/cpp/gl-engine

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/alex/fun/3d-graphics/cpp/gl-engine/build

# Include any dependencies generated for this target.
include CMakeFiles/gl-engine.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/gl-engine.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/gl-engine.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/gl-engine.dir/flags.make

CMakeFiles/gl-engine.dir/gl-engine.cpp.o: CMakeFiles/gl-engine.dir/flags.make
CMakeFiles/gl-engine.dir/gl-engine.cpp.o: ../gl-engine.cpp
CMakeFiles/gl-engine.dir/gl-engine.cpp.o: CMakeFiles/gl-engine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alex/fun/3d-graphics/cpp/gl-engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/gl-engine.dir/gl-engine.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/gl-engine.dir/gl-engine.cpp.o -MF CMakeFiles/gl-engine.dir/gl-engine.cpp.o.d -o CMakeFiles/gl-engine.dir/gl-engine.cpp.o -c /home/alex/fun/3d-graphics/cpp/gl-engine/gl-engine.cpp

CMakeFiles/gl-engine.dir/gl-engine.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gl-engine.dir/gl-engine.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alex/fun/3d-graphics/cpp/gl-engine/gl-engine.cpp > CMakeFiles/gl-engine.dir/gl-engine.cpp.i

CMakeFiles/gl-engine.dir/gl-engine.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gl-engine.dir/gl-engine.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alex/fun/3d-graphics/cpp/gl-engine/gl-engine.cpp -o CMakeFiles/gl-engine.dir/gl-engine.cpp.s

CMakeFiles/gl-engine.dir/src/glad/glad.c.o: CMakeFiles/gl-engine.dir/flags.make
CMakeFiles/gl-engine.dir/src/glad/glad.c.o: ../src/glad/glad.c
CMakeFiles/gl-engine.dir/src/glad/glad.c.o: CMakeFiles/gl-engine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alex/fun/3d-graphics/cpp/gl-engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/gl-engine.dir/src/glad/glad.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/gl-engine.dir/src/glad/glad.c.o -MF CMakeFiles/gl-engine.dir/src/glad/glad.c.o.d -o CMakeFiles/gl-engine.dir/src/glad/glad.c.o -c /home/alex/fun/3d-graphics/cpp/gl-engine/src/glad/glad.c

CMakeFiles/gl-engine.dir/src/glad/glad.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/gl-engine.dir/src/glad/glad.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/alex/fun/3d-graphics/cpp/gl-engine/src/glad/glad.c > CMakeFiles/gl-engine.dir/src/glad/glad.c.i

CMakeFiles/gl-engine.dir/src/glad/glad.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/gl-engine.dir/src/glad/glad.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/alex/fun/3d-graphics/cpp/gl-engine/src/glad/glad.c -o CMakeFiles/gl-engine.dir/src/glad/glad.c.s

CMakeFiles/gl-engine.dir/src/shader/shader.cpp.o: CMakeFiles/gl-engine.dir/flags.make
CMakeFiles/gl-engine.dir/src/shader/shader.cpp.o: ../src/shader/shader.cpp
CMakeFiles/gl-engine.dir/src/shader/shader.cpp.o: CMakeFiles/gl-engine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alex/fun/3d-graphics/cpp/gl-engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/gl-engine.dir/src/shader/shader.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/gl-engine.dir/src/shader/shader.cpp.o -MF CMakeFiles/gl-engine.dir/src/shader/shader.cpp.o.d -o CMakeFiles/gl-engine.dir/src/shader/shader.cpp.o -c /home/alex/fun/3d-graphics/cpp/gl-engine/src/shader/shader.cpp

CMakeFiles/gl-engine.dir/src/shader/shader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gl-engine.dir/src/shader/shader.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alex/fun/3d-graphics/cpp/gl-engine/src/shader/shader.cpp > CMakeFiles/gl-engine.dir/src/shader/shader.cpp.i

CMakeFiles/gl-engine.dir/src/shader/shader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gl-engine.dir/src/shader/shader.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alex/fun/3d-graphics/cpp/gl-engine/src/shader/shader.cpp -o CMakeFiles/gl-engine.dir/src/shader/shader.cpp.s

CMakeFiles/gl-engine.dir/src/lights/dirlight.cpp.o: CMakeFiles/gl-engine.dir/flags.make
CMakeFiles/gl-engine.dir/src/lights/dirlight.cpp.o: ../src/lights/dirlight.cpp
CMakeFiles/gl-engine.dir/src/lights/dirlight.cpp.o: CMakeFiles/gl-engine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alex/fun/3d-graphics/cpp/gl-engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/gl-engine.dir/src/lights/dirlight.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/gl-engine.dir/src/lights/dirlight.cpp.o -MF CMakeFiles/gl-engine.dir/src/lights/dirlight.cpp.o.d -o CMakeFiles/gl-engine.dir/src/lights/dirlight.cpp.o -c /home/alex/fun/3d-graphics/cpp/gl-engine/src/lights/dirlight.cpp

CMakeFiles/gl-engine.dir/src/lights/dirlight.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gl-engine.dir/src/lights/dirlight.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alex/fun/3d-graphics/cpp/gl-engine/src/lights/dirlight.cpp > CMakeFiles/gl-engine.dir/src/lights/dirlight.cpp.i

CMakeFiles/gl-engine.dir/src/lights/dirlight.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gl-engine.dir/src/lights/dirlight.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alex/fun/3d-graphics/cpp/gl-engine/src/lights/dirlight.cpp -o CMakeFiles/gl-engine.dir/src/lights/dirlight.cpp.s

# Object files for target gl-engine
gl__engine_OBJECTS = \
"CMakeFiles/gl-engine.dir/gl-engine.cpp.o" \
"CMakeFiles/gl-engine.dir/src/glad/glad.c.o" \
"CMakeFiles/gl-engine.dir/src/shader/shader.cpp.o" \
"CMakeFiles/gl-engine.dir/src/lights/dirlight.cpp.o"

# External object files for target gl-engine
gl__engine_EXTERNAL_OBJECTS =

gl-engine: CMakeFiles/gl-engine.dir/gl-engine.cpp.o
gl-engine: CMakeFiles/gl-engine.dir/src/glad/glad.c.o
gl-engine: CMakeFiles/gl-engine.dir/src/shader/shader.cpp.o
gl-engine: CMakeFiles/gl-engine.dir/src/lights/dirlight.cpp.o
gl-engine: CMakeFiles/gl-engine.dir/build.make
gl-engine: /usr/lib/libglfw.so.3.3
gl-engine: /usr/lib/libGLX.so
gl-engine: /usr/lib/libOpenGL.so
gl-engine: CMakeFiles/gl-engine.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/alex/fun/3d-graphics/cpp/gl-engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable gl-engine"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gl-engine.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/gl-engine.dir/build: gl-engine
.PHONY : CMakeFiles/gl-engine.dir/build

CMakeFiles/gl-engine.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/gl-engine.dir/cmake_clean.cmake
.PHONY : CMakeFiles/gl-engine.dir/clean

CMakeFiles/gl-engine.dir/depend:
	cd /home/alex/fun/3d-graphics/cpp/gl-engine/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/alex/fun/3d-graphics/cpp/gl-engine /home/alex/fun/3d-graphics/cpp/gl-engine /home/alex/fun/3d-graphics/cpp/gl-engine/build /home/alex/fun/3d-graphics/cpp/gl-engine/build /home/alex/fun/3d-graphics/cpp/gl-engine/build/CMakeFiles/gl-engine.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/gl-engine.dir/depend

