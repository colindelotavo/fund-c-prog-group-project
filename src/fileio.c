#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "../include/fileio.h"

/******************************************************************************

 * What function does (e.g. using caeser cipher etc)

 * inputs:
   - a
   - b

 * outputs:
   - y
   - z

******************************************************************************/

/* prints:

BEFORE
-------------------------------------------------------------------------------

<input_file contents>


AFTER
-------------------------------------------------------------------------------
<output_file contents>

file contents of input file to console */
void display_file(const char input_filename[], 
                  const char output_filename[]) {

    FILE *input_file_ptr = fopen(input_filename, "r");
    FILE *output_file_ptr = fopen(output_filename, "r");

    if (!input_file_ptr) {
        fprintf(stderr, "Error opening input file: %s\n", input_filename);
        return;
    }
    if (!output_file_ptr) {
        fprintf(stderr, "Error opening output file: %s\n", output_filename);
        fclose(input_file_ptr);
        return;
    }

    printf("\nBEFORE\n");
    printf("--------------------------------------------------------------\n");
    
    char ch;
    while ((ch = fgetc(input_file_ptr)) != EOF) {
        putchar(ch);
    }

    printf("\n\nAFTER\n");
    printf("--------------------------------------------------------------\n");

    while ((ch = fgetc(output_file_ptr)) != EOF) {
        putchar(ch);
    }

    fclose(input_file_ptr);
    fclose(output_file_ptr);

}