# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.2.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.2.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\evajq\CLionProjects\Embd Lab\Lab 4\mainB.cpp"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\evajq\CLionProjects\Embd Lab\Lab 4\mainB.cpp\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles\mainB_cpp.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\mainB_cpp.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\mainB_cpp.dir\flags.make

CMakeFiles\mainB_cpp.dir\main.cpp.obj: CMakeFiles\mainB_cpp.dir\flags.make
CMakeFiles\mainB_cpp.dir\main.cpp.obj: ..\main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\evajq\CLionProjects\Embd Lab\Lab 4\mainB.cpp\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/mainB_cpp.dir/main.cpp.obj"
	C:\PROGRA~2\MICROS~3\2019\COMMUN~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\mainB_cpp.dir\main.cpp.obj /FdCMakeFiles\mainB_cpp.dir\ /FS -c "C:\Users\evajq\CLionProjects\Embd Lab\Lab 4\mainB.cpp\main.cpp"
<<

CMakeFiles\mainB_cpp.dir\main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mainB_cpp.dir/main.cpp.i"
	C:\PROGRA~2\MICROS~3\2019\COMMUN~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\cl.exe > CMakeFiles\mainB_cpp.dir\main.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\evajq\CLionProjects\Embd Lab\Lab 4\mainB.cpp\main.cpp"
<<

CMakeFiles\mainB_cpp.dir\main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mainB_cpp.dir/main.cpp.s"
	C:\PROGRA~2\MICROS~3\2019\COMMUN~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\mainB_cpp.dir\main.cpp.s /c "C:\Users\evajq\CLionProjects\Embd Lab\Lab 4\mainB.cpp\main.cpp"
<<

# Object files for target mainB_cpp
mainB_cpp_OBJECTS = \
"CMakeFiles\mainB_cpp.dir\main.cpp.obj"

# External object files for target mainB_cpp
mainB_cpp_EXTERNAL_OBJECTS =

mainB_cpp.exe: CMakeFiles\mainB_cpp.dir\main.cpp.obj
mainB_cpp.exe: CMakeFiles\mainB_cpp.dir\build.make
mainB_cpp.exe: CMakeFiles\mainB_cpp.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\evajq\CLionProjects\Embd Lab\Lab 4\mainB.cpp\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable mainB_cpp.exe"
	"C:\Program Files\JetBrains\CLion 2020.2.1\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\mainB_cpp.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100183~1.0\x86\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100183~1.0\x86\mt.exe --manifests  -- C:\PROGRA~2\MICROS~3\2019\COMMUN~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\mainB_cpp.dir\objects1.rsp @<<
 /out:mainB_cpp.exe /implib:mainB_cpp.lib /pdb:"C:\Users\evajq\CLionProjects\Embd Lab\Lab 4\mainB.cpp\cmake-build-debug\mainB_cpp.pdb" /version:0.0  /machine:X86 /debug /INCREMENTAL /subsystem:console  kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\mainB_cpp.dir\build: mainB_cpp.exe

.PHONY : CMakeFiles\mainB_cpp.dir\build

CMakeFiles\mainB_cpp.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\mainB_cpp.dir\cmake_clean.cmake
.PHONY : CMakeFiles\mainB_cpp.dir\clean

CMakeFiles\mainB_cpp.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" "C:\Users\evajq\CLionProjects\Embd Lab\Lab 4\mainB.cpp" "C:\Users\evajq\CLionProjects\Embd Lab\Lab 4\mainB.cpp" "C:\Users\evajq\CLionProjects\Embd Lab\Lab 4\mainB.cpp\cmake-build-debug" "C:\Users\evajq\CLionProjects\Embd Lab\Lab 4\mainB.cpp\cmake-build-debug" "C:\Users\evajq\CLionProjects\Embd Lab\Lab 4\mainB.cpp\cmake-build-debug\CMakeFiles\mainB_cpp.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles\mainB_cpp.dir\depend

