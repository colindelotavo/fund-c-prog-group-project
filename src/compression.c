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

******************************************************************************/

void compress_file(const char input_filename[], 
                   const char output_filename[]) {

    FILE *input_file_ptr = fopen(input_filename, "rb"); // Open the input file for reading in binary mode
    if (input_file_ptr == NULL) {
        perror("Error opening input file");
        return;
    }

    FILE *output_file_ptr = fopen(output_filename, "wb"); // Open the output file for writing in binary mode
    if (output_file_ptr == NULL) {
        perror("Error opening output file");
        fclose(input_file_ptr); // Don't forget to close the already opened input file
        return;
    }

    // Variables for reading from the file and run length encoding
    int current_char;
    int previous_char = EOF; // Use EOF as a starting value to signify no previous character
    int count = 1;

    // Read the first character
    current_char = fgetc(input_file_ptr);

    // Loop through the file, reading one character at a time
    while (current_char != EOF) {
        int next_char = fgetc(input_file_ptr); // Read the next character

        // Check if the next character is the same as the current one
        if (next_char == current_char) {
            count++; // Increment the count of the current character
        } else {
            // Write the count and the current character to the output file
            fprintf(output_file_ptr, "%d%c", count, current_char);

            // Reset the count and update the current character
            count = 1;
            current_char = next_char;
        }
    }

    // Close the input and output files
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
