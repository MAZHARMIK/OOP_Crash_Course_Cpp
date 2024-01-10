/*
This is notes only
*/

C++ code compilation involves several steps, and the process can be broadly divided into the following stages:
1. Preprocessing - Preprocessed code (with comments removed, macros expanded, and header files included).
Command: g++ -E source_file.cpp -o output_file.i

2. Compilation - Assembly code (for a specific target architecture).
Command: g++ -S source_file.i -o output_file.s

3. Assembly - Object file (machine code in binary form). (Assembly code to machine code)
Command : as source_file.s -o output_file.o

4. Linking - combines object files and resolves symbols (produces executable file)
Command : g++ file1.o file2.o -o executable

Now you run it like below :- 
  ./executable
