# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.6

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/chan/ClionProjects/MarkDownParser

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/chan/ClionProjects/MarkDownParser/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/MarkDownParser.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/MarkDownParser.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MarkDownParser.dir/flags.make

CMakeFiles/MarkDownParser.dir/main.cpp.o: CMakeFiles/MarkDownParser.dir/flags.make
CMakeFiles/MarkDownParser.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/chan/ClionProjects/MarkDownParser/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/MarkDownParser.dir/main.cpp.o"
	/Applications/Xcode-beta.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MarkDownParser.dir/main.cpp.o -c /Users/chan/ClionProjects/MarkDownParser/main.cpp

CMakeFiles/MarkDownParser.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MarkDownParser.dir/main.cpp.i"
	/Applications/Xcode-beta.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/chan/ClionProjects/MarkDownParser/main.cpp > CMakeFiles/MarkDownParser.dir/main.cpp.i

CMakeFiles/MarkDownParser.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MarkDownParser.dir/main.cpp.s"
	/Applications/Xcode-beta.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/chan/ClionProjects/MarkDownParser/main.cpp -o CMakeFiles/MarkDownParser.dir/main.cpp.s

CMakeFiles/MarkDownParser.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/MarkDownParser.dir/main.cpp.o.requires

CMakeFiles/MarkDownParser.dir/main.cpp.o.provides: CMakeFiles/MarkDownParser.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/MarkDownParser.dir/build.make CMakeFiles/MarkDownParser.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/MarkDownParser.dir/main.cpp.o.provides

CMakeFiles/MarkDownParser.dir/main.cpp.o.provides.build: CMakeFiles/MarkDownParser.dir/main.cpp.o


CMakeFiles/MarkDownParser.dir/lexica/LexicalParser.cpp.o: CMakeFiles/MarkDownParser.dir/flags.make
CMakeFiles/MarkDownParser.dir/lexica/LexicalParser.cpp.o: ../lexica/LexicalParser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/chan/ClionProjects/MarkDownParser/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/MarkDownParser.dir/lexica/LexicalParser.cpp.o"
	/Applications/Xcode-beta.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MarkDownParser.dir/lexica/LexicalParser.cpp.o -c /Users/chan/ClionProjects/MarkDownParser/lexica/LexicalParser.cpp

CMakeFiles/MarkDownParser.dir/lexica/LexicalParser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MarkDownParser.dir/lexica/LexicalParser.cpp.i"
	/Applications/Xcode-beta.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/chan/ClionProjects/MarkDownParser/lexica/LexicalParser.cpp > CMakeFiles/MarkDownParser.dir/lexica/LexicalParser.cpp.i

CMakeFiles/MarkDownParser.dir/lexica/LexicalParser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MarkDownParser.dir/lexica/LexicalParser.cpp.s"
	/Applications/Xcode-beta.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/chan/ClionProjects/MarkDownParser/lexica/LexicalParser.cpp -o CMakeFiles/MarkDownParser.dir/lexica/LexicalParser.cpp.s

CMakeFiles/MarkDownParser.dir/lexica/LexicalParser.cpp.o.requires:

.PHONY : CMakeFiles/MarkDownParser.dir/lexica/LexicalParser.cpp.o.requires

CMakeFiles/MarkDownParser.dir/lexica/LexicalParser.cpp.o.provides: CMakeFiles/MarkDownParser.dir/lexica/LexicalParser.cpp.o.requires
	$(MAKE) -f CMakeFiles/MarkDownParser.dir/build.make CMakeFiles/MarkDownParser.dir/lexica/LexicalParser.cpp.o.provides.build
.PHONY : CMakeFiles/MarkDownParser.dir/lexica/LexicalParser.cpp.o.provides

CMakeFiles/MarkDownParser.dir/lexica/LexicalParser.cpp.o.provides.build: CMakeFiles/MarkDownParser.dir/lexica/LexicalParser.cpp.o


CMakeFiles/MarkDownParser.dir/grammer/GrammarParser.cpp.o: CMakeFiles/MarkDownParser.dir/flags.make
CMakeFiles/MarkDownParser.dir/grammer/GrammarParser.cpp.o: ../grammer/GrammarParser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/chan/ClionProjects/MarkDownParser/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/MarkDownParser.dir/grammer/GrammarParser.cpp.o"
	/Applications/Xcode-beta.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MarkDownParser.dir/grammer/GrammarParser.cpp.o -c /Users/chan/ClionProjects/MarkDownParser/grammer/GrammarParser.cpp

CMakeFiles/MarkDownParser.dir/grammer/GrammarParser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MarkDownParser.dir/grammer/GrammarParser.cpp.i"
	/Applications/Xcode-beta.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/chan/ClionProjects/MarkDownParser/grammer/GrammarParser.cpp > CMakeFiles/MarkDownParser.dir/grammer/GrammarParser.cpp.i

CMakeFiles/MarkDownParser.dir/grammer/GrammarParser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MarkDownParser.dir/grammer/GrammarParser.cpp.s"
	/Applications/Xcode-beta.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/chan/ClionProjects/MarkDownParser/grammer/GrammarParser.cpp -o CMakeFiles/MarkDownParser.dir/grammer/GrammarParser.cpp.s

CMakeFiles/MarkDownParser.dir/grammer/GrammarParser.cpp.o.requires:

.PHONY : CMakeFiles/MarkDownParser.dir/grammer/GrammarParser.cpp.o.requires

CMakeFiles/MarkDownParser.dir/grammer/GrammarParser.cpp.o.provides: CMakeFiles/MarkDownParser.dir/grammer/GrammarParser.cpp.o.requires
	$(MAKE) -f CMakeFiles/MarkDownParser.dir/build.make CMakeFiles/MarkDownParser.dir/grammer/GrammarParser.cpp.o.provides.build
.PHONY : CMakeFiles/MarkDownParser.dir/grammer/GrammarParser.cpp.o.provides

CMakeFiles/MarkDownParser.dir/grammer/GrammarParser.cpp.o.provides.build: CMakeFiles/MarkDownParser.dir/grammer/GrammarParser.cpp.o


CMakeFiles/MarkDownParser.dir/render/HtmlRenderer.cpp.o: CMakeFiles/MarkDownParser.dir/flags.make
CMakeFiles/MarkDownParser.dir/render/HtmlRenderer.cpp.o: ../render/HtmlRenderer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/chan/ClionProjects/MarkDownParser/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/MarkDownParser.dir/render/HtmlRenderer.cpp.o"
	/Applications/Xcode-beta.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MarkDownParser.dir/render/HtmlRenderer.cpp.o -c /Users/chan/ClionProjects/MarkDownParser/render/HtmlRenderer.cpp

CMakeFiles/MarkDownParser.dir/render/HtmlRenderer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MarkDownParser.dir/render/HtmlRenderer.cpp.i"
	/Applications/Xcode-beta.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/chan/ClionProjects/MarkDownParser/render/HtmlRenderer.cpp > CMakeFiles/MarkDownParser.dir/render/HtmlRenderer.cpp.i

CMakeFiles/MarkDownParser.dir/render/HtmlRenderer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MarkDownParser.dir/render/HtmlRenderer.cpp.s"
	/Applications/Xcode-beta.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/chan/ClionProjects/MarkDownParser/render/HtmlRenderer.cpp -o CMakeFiles/MarkDownParser.dir/render/HtmlRenderer.cpp.s

CMakeFiles/MarkDownParser.dir/render/HtmlRenderer.cpp.o.requires:

.PHONY : CMakeFiles/MarkDownParser.dir/render/HtmlRenderer.cpp.o.requires

CMakeFiles/MarkDownParser.dir/render/HtmlRenderer.cpp.o.provides: CMakeFiles/MarkDownParser.dir/render/HtmlRenderer.cpp.o.requires
	$(MAKE) -f CMakeFiles/MarkDownParser.dir/build.make CMakeFiles/MarkDownParser.dir/render/HtmlRenderer.cpp.o.provides.build
.PHONY : CMakeFiles/MarkDownParser.dir/render/HtmlRenderer.cpp.o.provides

CMakeFiles/MarkDownParser.dir/render/HtmlRenderer.cpp.o.provides.build: CMakeFiles/MarkDownParser.dir/render/HtmlRenderer.cpp.o


CMakeFiles/MarkDownParser.dir/render/AndroidRenderer.cpp.o: CMakeFiles/MarkDownParser.dir/flags.make
CMakeFiles/MarkDownParser.dir/render/AndroidRenderer.cpp.o: ../render/AndroidRenderer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/chan/ClionProjects/MarkDownParser/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/MarkDownParser.dir/render/AndroidRenderer.cpp.o"
	/Applications/Xcode-beta.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MarkDownParser.dir/render/AndroidRenderer.cpp.o -c /Users/chan/ClionProjects/MarkDownParser/render/AndroidRenderer.cpp

CMakeFiles/MarkDownParser.dir/render/AndroidRenderer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MarkDownParser.dir/render/AndroidRenderer.cpp.i"
	/Applications/Xcode-beta.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/chan/ClionProjects/MarkDownParser/render/AndroidRenderer.cpp > CMakeFiles/MarkDownParser.dir/render/AndroidRenderer.cpp.i

CMakeFiles/MarkDownParser.dir/render/AndroidRenderer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MarkDownParser.dir/render/AndroidRenderer.cpp.s"
	/Applications/Xcode-beta.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/chan/ClionProjects/MarkDownParser/render/AndroidRenderer.cpp -o CMakeFiles/MarkDownParser.dir/render/AndroidRenderer.cpp.s

CMakeFiles/MarkDownParser.dir/render/AndroidRenderer.cpp.o.requires:

.PHONY : CMakeFiles/MarkDownParser.dir/render/AndroidRenderer.cpp.o.requires

CMakeFiles/MarkDownParser.dir/render/AndroidRenderer.cpp.o.provides: CMakeFiles/MarkDownParser.dir/render/AndroidRenderer.cpp.o.requires
	$(MAKE) -f CMakeFiles/MarkDownParser.dir/build.make CMakeFiles/MarkDownParser.dir/render/AndroidRenderer.cpp.o.provides.build
.PHONY : CMakeFiles/MarkDownParser.dir/render/AndroidRenderer.cpp.o.provides

CMakeFiles/MarkDownParser.dir/render/AndroidRenderer.cpp.o.provides.build: CMakeFiles/MarkDownParser.dir/render/AndroidRenderer.cpp.o


# Object files for target MarkDownParser
MarkDownParser_OBJECTS = \
"CMakeFiles/MarkDownParser.dir/main.cpp.o" \
"CMakeFiles/MarkDownParser.dir/lexica/LexicalParser.cpp.o" \
"CMakeFiles/MarkDownParser.dir/grammer/GrammarParser.cpp.o" \
"CMakeFiles/MarkDownParser.dir/render/HtmlRenderer.cpp.o" \
"CMakeFiles/MarkDownParser.dir/render/AndroidRenderer.cpp.o"

# External object files for target MarkDownParser
MarkDownParser_EXTERNAL_OBJECTS =

MarkDownParser: CMakeFiles/MarkDownParser.dir/main.cpp.o
MarkDownParser: CMakeFiles/MarkDownParser.dir/lexica/LexicalParser.cpp.o
MarkDownParser: CMakeFiles/MarkDownParser.dir/grammer/GrammarParser.cpp.o
MarkDownParser: CMakeFiles/MarkDownParser.dir/render/HtmlRenderer.cpp.o
MarkDownParser: CMakeFiles/MarkDownParser.dir/render/AndroidRenderer.cpp.o
MarkDownParser: CMakeFiles/MarkDownParser.dir/build.make
MarkDownParser: CMakeFiles/MarkDownParser.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/chan/ClionProjects/MarkDownParser/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable MarkDownParser"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MarkDownParser.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MarkDownParser.dir/build: MarkDownParser

.PHONY : CMakeFiles/MarkDownParser.dir/build

CMakeFiles/MarkDownParser.dir/requires: CMakeFiles/MarkDownParser.dir/main.cpp.o.requires
CMakeFiles/MarkDownParser.dir/requires: CMakeFiles/MarkDownParser.dir/lexica/LexicalParser.cpp.o.requires
CMakeFiles/MarkDownParser.dir/requires: CMakeFiles/MarkDownParser.dir/grammer/GrammarParser.cpp.o.requires
CMakeFiles/MarkDownParser.dir/requires: CMakeFiles/MarkDownParser.dir/render/HtmlRenderer.cpp.o.requires
CMakeFiles/MarkDownParser.dir/requires: CMakeFiles/MarkDownParser.dir/render/AndroidRenderer.cpp.o.requires

.PHONY : CMakeFiles/MarkDownParser.dir/requires

CMakeFiles/MarkDownParser.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/MarkDownParser.dir/cmake_clean.cmake
.PHONY : CMakeFiles/MarkDownParser.dir/clean

CMakeFiles/MarkDownParser.dir/depend:
	cd /Users/chan/ClionProjects/MarkDownParser/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/chan/ClionProjects/MarkDownParser /Users/chan/ClionProjects/MarkDownParser /Users/chan/ClionProjects/MarkDownParser/cmake-build-debug /Users/chan/ClionProjects/MarkDownParser/cmake-build-debug /Users/chan/ClionProjects/MarkDownParser/cmake-build-debug/CMakeFiles/MarkDownParser.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/MarkDownParser.dir/depend

