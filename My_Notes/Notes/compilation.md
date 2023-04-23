# Compilation

## Preprocessing
- `-E`
    - Stop after the preprocessing stage; do not run the compiler proper.
    - The output is in the form of preprocessed source code, which is sent to the standard output.

        ```bash
        $ gcc -E struct.c -o pre_proc.c
        ```

## Compilation
- `-S`
    - Stop after the stage of compilation proper; do not assemble.
    - The output is in the form of an assembler code file for each non-assembler input file specified.

        ```bash
        $ gcc -S struct_pre_proc.c -o compile.c
        ```

## Assembly
- `-c`
    - Compile or assemble the source files, but do not link.
    - The linking stage simply is not done.  The ultimate output is in the form of an object file for each source file.

        ```bash
        $ gcc -c pre_proc.c -o assembly.c
        ```

## Linking
- `-o file`
    - Place output in file file.
    - This applies to whatever sort of output is being produced, whether it be an executable file, an object file, an assembler file or preprocessed C code.
    - If `-o` is not specified, the default is to put an executable file in `a.out`, the object file for source.- suffix in `source.o`, its assembler file.
    - In `source.s`, a precompiled header file in `source.suffix.gch`, and all preprocessed C source on standard output.

        ```bash
        $ gcc -o struct struct.out
        ```