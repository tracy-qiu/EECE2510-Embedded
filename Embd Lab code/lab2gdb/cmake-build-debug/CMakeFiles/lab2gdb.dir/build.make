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
CMAKE_SOURCE_DIR = "C:\Users\evajq\CLionProjects\Embd Lab\lab2gdb"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\evajq\CLionProjects\Embd Lab\lab2gdb\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles\lab2gdb.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\lab2gdb.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\lab2gdb.dir\flags.make

CMakeFiles\lab2gdb.dir\main.cpp.obj: CMakeFiles\lab2gdb.dir\flags.make
CMakeFiles\lab2gdb.dir\main.cpp.obj: ..\main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\evajq\CLionProjects\Embd Lab\lab2gdb\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/lab2gdb.dir/main.cpp.obj"
	C:\PROGRA~2\MICROS~3\2019\COMMUN~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\lab2gdb.dir\main.cpp.obj /FdCMakeFiles\lab2gdb.dir\ /FS -c "C:\Users\evajq\CLionProjects\Embd Lab\lab2gdb\main.cpp"
<<

CMakeFiles\lab2gdb.dir\main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab2gdb.dir/main.cpp.i"
	C:\PROGRA~2\MICROS~3\2019\COMMUN~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\cl.exe > CMakeFiles\lab2gdb.dir\main.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\evajq\CLionProjects\Embd Lab\lab2gdb\main.cpp"
<<

CMakeFiles\lab2gdb.dir\main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab2gdb.dir/main.cpp.s"
	C:\PROGRA~2\MICROS~3\2019\COMMUN~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\lab2gdb.dir\main.cpp.s /c "C:\Users\evajq\CLionProjects\Embd Lab\lab2gdb\main.cpp"
<<

# Object files for target lab2gdb
lab2gdb_OBJECTS = \
"CMakeFiles\lab2gdb.dir\main.cpp.obj"

# External object files for target lab2gdb
lab2gdb_EXTERNAL_OBJECTS =

lab2gdb.exe: CMakeFiles\lab2gdb.dir\main.cpp.obj
lab2gdb.exe: CMakeFiles\lab2gdb.dir\build.make
lab2gdb.exe: CMakeFiles\lab2gdb.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\evajq\CLionProjects\Embd Lab\lab2gdb\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable lab2gdb.exe"
	"C:\Program Files\JetBrains\CLion 2020.2.1\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\lab2gdb.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100183~1.0\x86\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100183~1.0\x86\mt.exe --manifests  -- C:\PROGRA~2\MICROS~3\2019\COMMUN~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\lab2gdb.dir\objects1.rsp @<<
 /out:lab2gdb.exe /implib:lab2gdb.lib /pdb:"C:\Users\evajq\CLionProjects\Embd Lab\lab2gdb\cmake-build-debug\lab2gdb.pdb" /version:0.0  /machine:X86 /debug /INCREMENTAL /subsystem:console  kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\lab2gdb.dir\build: lab2gdb.exe

.PHONY : CMakeFiles\lab2gdb.dir\build

CMakeFiles\lab2gdb.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\lab2gdb.dir\cmake_clean.cmake
.PHONY : CMakeFiles\lab2gdb.dir\clean

CMakeFiles\lab2gdb.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" "C:\Users\evajq\CLionProjects\Embd Lab\lab2gdb" "C:\Users\evajq\CLionProjects\Embd Lab\lab2gdb" "C:\Users\evajq\CLionProjects\Embd Lab\lab2gdb\cmake-build-debug" "C:\Users\evajq\CLionProjects\Embd Lab\lab2gdb\cmake-build-debug" "C:\Users\evajq\CLionProjects\Embd Lab\lab2gdb\cmake-build-debug\CMakeFiles\lab2gdb.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles\lab2gdb.dir\depend

