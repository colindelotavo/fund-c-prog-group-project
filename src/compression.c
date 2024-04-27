#include <stdlib.h> /* strtol */
#include <stdio.h>
#include "../include/compression.h"

/******************************************************************************

 * What function does (e.g. using run-length encoding etc)

 * inputs:
   - a
   - b

 * outputs:
   - y
   - z

test run: 
cd src
gcc -o ../task.out main.c compression.c -I../include
../task.out

 * edge cases to handle
   - empty line just writes as '1' in output file
   - what if RLE is more space, ie. string does not use repeated chars
   - should it only consider uppercase/lowercase..? or keep as is

******************************************************************************/

void compress_file(const char input_filename[], 
                   const char output_filename[]) {

    /* attempt to open file (input_file.txt) to read in binary mode */
    FILE *input_file_ptr = fopen(input_filename, "rb");
    if (input_file_ptr == NULL) {
        perror("Error opening input file");
        return;
    }

    /* attempt to open file (compressed_file.cmp) to write in binary mode */
    FILE *output_file_ptr = fopen(output_filename, "wb");

    /* check if file was successfully opened */
    if (output_file_ptr == NULL) {
        perror("Error opening output file");
        fclose(input_file_ptr);
        return;
    }

    /* vars to read from file and keep track for RLE */
    int current_char;
    int count = 1;

    /* pick first character in str */
    current_char = fgetc(input_file_ptr);

    /* loop through str to undergo RLE */
    while (current_char != EOF) {
        int next_char = fgetc(input_file_ptr);

        /* checks if the next character is the same as the current one */
        if (next_char == current_char) {
            count++;
        } else {
            /* writes count and current character to compressed_file.cmp */
            fprintf(output_file_ptr, "%d%c", count, current_char);
            count = 1;
            current_char = next_char;
        }
    }

    /* close input and output files */
    fclose(input_file_ptr);
    fclose(output_file_ptr);
    
}

/******************************************************************************

 * What function does (e.g. using run-length encoding etc)

 * inputs:
   - a
   - b

 * outputs:
   - y
   - z

******************************************************************************/

void decompress_file(const char input_filename[],
                     const char output_filename[]) {

}
