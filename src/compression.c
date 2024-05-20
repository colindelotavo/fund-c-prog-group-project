#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "../include/compression.h"

/******************************************************************************

 * What function does (e.g. using run-length encoding etc)

 * inputs:
   -

 * outputs:
   - 

steps to run as a test:

cd src

gcc -o ../task.out main.c compression.c encryption.c fileio.c -I../include

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
        printf("Read error\n");
        return;
    }

    /* attempt to open file (compressed_file.cmp) to write in binary mode */
    FILE *output_file_ptr = fopen(output_filename, "wb");

    if (output_file_ptr == NULL) {
        printf("Write error\n");
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
   - 

 * outputs:
   - 

steps to run as a test:
cd src
gcc -o ../task.out main.c compression.c -I../include
../task.out

******************************************************************************/

void decompress_file(const char input_filename[],
                     const char output_filename[]) {

    /* attempt to open file (compressed_file.cmp) to read in binary mode */
    FILE *input_file_ptr = fopen(input_filename, "rb");
    
    if (input_file_ptr == NULL) {
        printf("Read error\n");
        return;
    }

    /* attempt to open file (output_file.txt) to write in binary mode */
    FILE *output_file_ptr = fopen(output_filename, "wb");
    
    if (output_file_ptr == NULL) {
        printf("Write error\n");
        return;
    }

    /* vars to read count and character from the compressed file */
    int count = 0;
    char current_char;

    /* checking if fscanf has actually read two items, in other words,
       count, char pair RLE format */
    while (fscanf(input_file_ptr, "%d%c", &count, &current_char) == 2) {
        for (int i = 0; i < count; i++) {
            fputc(current_char, output_file_ptr);
        }
    }

    /* close input and output files */
    fclose(input_file_ptr);
    fclose(output_file_ptr);
    
}

/******************************************************************************

 * What function does (e.g. using run-length encoding etc)

 * inputs:
   -

 * outputs:
   - 

******************************************************************************/

void compare_file_size(const char input_filename[],
                          const char output_filename[]) {

    FILE *input_file_ptr = fopen(input_filename, "rb");
    FILE *output_file_ptr = fopen(output_filename, "rb");

    if (!input_file_ptr) {
        fprintf(stderr, "Error opening input file: %s\n", input_filename);
        return;
    }
    if (!output_file_ptr) {
        fprintf(stderr, "Error opening output file: %s\n", output_filename);
        fclose(input_file_ptr);
        return;
    }

    int input_length = 0;
    int output_length = 0;
    char ch;

    while ((ch = fgetc(input_file_ptr)) != EOF) {
        input_length++;
    }

    while ((ch = fgetc(output_file_ptr)) != EOF) {
        output_length++;
    }

    if (output_length <= input_length) {
        printf("\n\n\nCompression is successful.\n");
    } else {
        printf("\n\n\nCompression has failed.\n");
    }

    fclose(input_file_ptr);
    fclose(output_file_ptr);
}
