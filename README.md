# OP2Internal

Outpost 2 Internal (formally forced exports) allows access to the Outpost 2 SDK. It is typically compiled for Windows using Visual Studio.

OP2Internal relies on the netwide assembler (nasm) to compile an asm file. nasm is not bundled with Visual Studio and requires a custom build step. The custom build step is already defined in the project file, but nasm must be installed. Before compiling:

 1. Install nasm (https://www.nasm.us/)
 2. Setup a path environment variable for the directory containing nasm.exe
