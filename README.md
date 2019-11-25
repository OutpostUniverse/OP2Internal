# OP2Internal

OP2Internal (formerly named ForcedExports) allows direct access to internal functions and data defined in Outpost2.exe, particularly those that may not be exported through the regular API. It is typically compiled for Windows using Visual Studio.

OP2Internal relies on the Netwide Assembler (NASM) to compile an assembly language file (.asm). NASM is not bundled with Visual Studio, so it will need to be installed separately. Before compiling:

 1. Install nasm (https://www.nasm.us/)
 2. Setup the path environment variable to include the directory containing nasm.exe

To compile the assembly language file (.asm), the Visual Studio project contains a custom build step, which references NASM. The custom build step is already defined in the project file. It should not need any adjustment, provided you follow the above steps.
