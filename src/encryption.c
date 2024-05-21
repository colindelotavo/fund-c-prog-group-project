#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "../include/encryption.h"

/******************************************************************************

 * What function does

 * inputs:
   - x
 * outputs:
   - y

******************************************************************************/

void encrypt_file(const char input_filename[], 
                  const char output_filename[], int shift_key) {
    FILE *input = fopen(input_filename, "rb");
    if (input == NULL) {
        printf("Failed to open input file for reading.\n");
        return;
    }

    FILE *output = fopen(output_filename, "wb");
    if (output == NULL) {
        printf("Failed to open output file for writing.\n");
        fclose(input);
        return;
    }

    int ch;
    while ((ch = fgetc(input)) != EOF) {
        if (isalpha(ch)) {
            char base = islower(ch) ? 'a' : 'A';
            ch = (ch - base + shift_key) % 26 + base;
        }
        fputc(ch, output);
    }

    fclose(input);
    fclose(output);
}


/******************************************************************************

 * What function does

 * inputs:
   - x
 * outputs:
   - y

******************************************************************************/

void decrypt_file(const char input_filename[],
                  const char output_filename[], int shift_key) {
    FILE *input = fopen(input_filename, "rb");
    if (input == NULL) {
        printf("Failed to open input file for reading.\n");
        return;
    }

    FILE *output = fopen(output_filename, "wb");
    if (output == NULL) {
        printf("Failed to open output file for writing.\n");
        fclose(input);
        return;
    }

    int ch;
    while ((ch = fgetc(input)) != EOF) {
        if (isalpha(ch)) {
            char base = islower(ch) ? 'a' : 'A';
            ch = (ch - base - shift_key + 26) % 26 + base;
        }
        fputc(ch, output);
    }

    fclose(input);
    fclose(output);
}