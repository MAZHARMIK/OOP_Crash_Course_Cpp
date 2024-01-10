/*
  This is a notes only.
*/

#ifndef EXAMPLE_H
#define EXAMPLE_H

#endif


Example : 
// Example.h (header file)
#ifndef EXAMPLE_H
#define EXAMPLE_H

// Header content (declarations, definitions, etc.)

#endif

These lines are part of a technique called inclusion guards or header guards. They are used to prevent a header
file from being included multiple times in the same translation unit, which can lead to issues like duplicate symbol definitions and compilation errors.

Here's a breakdown of these lines:

    #ifndef EXAMPLE_H: This line checks if the symbol EXAMPLE_H has not been defined before in the code. If it has not been defined, the preprocessor proceeds to the next line. If it has been defined (possibly because the header has been included before), the code between #ifndef and #endif will be skipped.

    #define EXAMPLE_H: If the symbol EXAMPLE_H was not defined, this line defines it. This prevents the code within the header file from being included again if it's encountered later in the same compilation unit.

    Header Content: The actual content of the header file goes here, including declarations, definitions, and other code.

    #endif: This line marks the end of the conditional block. If the symbol EXAMPLE_H was not defined (first encounter of the header file), the preprocessor will process the code in the header. If it was defined, the code will be skipped.

This combination of #ifndef, #define, and #endif ensures that the content of the header file is processed only once in each compilation unit, preventing issues related to multiple inclusions.
