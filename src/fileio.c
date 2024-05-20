#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "../include/fileio.h"

/******************************************************************************

 * What function does (e.g. using caeser cipher etc)

 * inputs:

 * outputs:

******************************************************************************/

/* Loops BEFORE/AFTER after first selection of options 1-4...? */

void user_input(const char input_filename[]) {
    size_t str_length;
    char buffer[256];
    FILE *input_file_ptr = fopen(input_filename, "wb");
    
    if (input_file_ptr == NULL) {
        fprintf(stderr, "Error opening file.\n");
        exit(1);
    }

    printf("Enter text to write to the file: ");
    fgets(buffer, sizeof(buffer), stdin); 

    str_length = strlen(buffer);
    if (str_length > 0 && buffer[str_length - 1] == '\n') {
        buffer[str_length - 1] = '\0';
    }

    fprintf(input_file_ptr, "%s", buffer);

    fclose(input_file_ptr);
    printf("Data written successfully.\n");
}

/******************************************************************************

 * What function does (e.g. using caeser cipher etc)

 * inputs:
   - a
   - b

 * outputs:

    BEFORE
    -------------------------------------------------------------------------------
    <input_file contents>


    AFTER
    -------------------------------------------------------------------------------
    <output_file contents>

******************************************************************************/

void display_file(const char input_filename[], 
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