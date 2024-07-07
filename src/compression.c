#include <stdio.h> /* fopen, fclose, fgetc, fputc, fprintf, fscanf, printf */
#include "../include/compression.h"

/******************************************************************************

 * Primary function for compression to enable run-length encoding based on
   the input_file (which contains user input)

 * inputs:
   - input_file text contents

 * outputs:
   - output_file text compressed/transformed into run-length encoded data

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

 * Primary function for decompression to reverse run-length encoding based on
   the input_file (which is the compressed text)

 * inputs:
   - input_file contains compressed file contents

 * outputs:
   - output_file contains reversed RLE data, in other words, the user
     input that was previously inputted when the compressed option
     was selected

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

 * Primary function to test if compression was successful, comparing the
   string length of the input versus output, which is used in the main program
   as the compressed versus decompressed file contents, respectively

 * inputs:
   - input_file and output_file text data

 * outputs:
   - helpful console print message to confirm whether compression of user input
     was successful 

******************************************************************************/

void compare_file_size(const char input_filename[],
                       const char output_filename[]) {

    /* attempt to open the input file in binary mode */
    FILE *input_file_ptr = fopen(input_filename, "rb");
    /* attempt to open the output file in binary mode */
    FILE *output_file_ptr = fopen(output_filename, "rb");

    /* check if the input file opened successfully */
    if (!input_file_ptr) {
        fprintf(stderr, "Error opening input file: %s\n", input_filename);
        return;
    }
    /* check if the output file opened successfully */
    if (!output_file_ptr) {
        fprintf(stderr, "Error opening output file: %s\n", output_filename);
        fclose(input_file_ptr);
        return;
    }

    /* variables to store the length of input and output files */
    int input_length = 0;
    int output_length = 0;
    char ch;

    /* calculate the length of the input file */
    while ((ch = fgetc(input_file_ptr)) != EOF) {
        input_length++;
    }

    /* calculate the length of the output file */ 
    while ((ch = fgetc(output_file_ptr)) != EOF) {
        output_length++;
    }

    /* compare the lengths and print the result */
    if (output_length <= input_length) {
        printf("\n\n\nCompression is successful.\n");
    } else {
        printf("\n\n\nCompression has failed.\n");
        printf("\nTry something RLE-relevant, AAAAABBB for example!");
        printf("\n*checks are made to see char length before/after");
    }

    /* close the input and output files */
    fclose(input_file_ptr);
    fclose(output_file_ptr);
}

