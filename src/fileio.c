#include <stdio.h> /* fopen, fprintf, fgets, fgetc, putchar, 
                      fclose, printf, stderr */
#include <stdlib.h> /* exit */
#include <string.h> /* strlen */
#include "../include/fileio.h"

/******************************************************************************

 * Takes in user input and inserts it into the input_file for further
   data transformation in tandem with compression and encryption protocols.
   Replaces rather than appends for clean user input each call.

 * inputs:
   - user input
   - these allow special cases such as numbers and special chars to be 
     included

 * outputs:
   - outputs appropriate error messages as needed and successful writes

******************************************************************************/

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

 * Handles logic to output the Before and After of user inputs for clarity and
   also for educational purposes

 * inputs:
   - input_file
   - output_file

 * outputs:
   - prints to console the contents of the input_file and output_file in
     the following format

    BEFORE
    ---------------------------------------------------------------------------
    <input_file contents>


    AFTER
    ---------------------------------------------------------------------------
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