/******************************************************************************

 * 48430 Fundamentals of C Programming - Assignment 3

 * Group Number: 56

 * Lab Number: 04

 * Group Members: Colin Tria Delotavo and Samarth Kunal Singh
 
 * Date of submission: dd/05/2024

******************************************************************************/

/******************************************************************************

 * Header files along with used functions

******************************************************************************/

/* These are the only ones we're allowed to use */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "../include/compression.h"
#include "../include/encryption.h"

/******************************************************************************

 * List preprocessing directives - you may define your own.
 * Each defined with max size + null terminator.

******************************************************************************/

#define INPUT_FILE "../data/input_file.txt"
#define COMPRESSED_FILE "../data/compressed_file.cmp"
#define DECOMPRESSED_FILE "../data/decompressed_file.txt"
#define ENCRYPTED_FILE "../data/encrypted_file.enc"
#define DECRYPTED_FILE "../data/decrypted_file.txt"

/******************************************************************************

 * Function prototypes

******************************************************************************/

void print_menu(void);

/******************************************************************************

 * Overview of program here

******************************************************************************/

int main(void) {

    // /* Original File */
    // const char *input_filename = "path/to/your/inputfile.txt";

    // /* Files for Compression Operations */
    // const char *compressed_file = "path/to/your/outputfile.txt";
    // const char *decompressed_file = "path/to/your/outputfile.txt";

    // /* Files for Encryption Operations */
    // const char *encrypt_file = "path/to/your/outputfile.txt";
    // const char *decrypt_file = "path/to/your/outputfile.txt";

    // encrypt_file(

    int choice = 0;

    while (choice != 5) {
        print_menu();
        scanf(" %d", &choice); getchar();
        if (choice == 1) {
            // compress
            break;
        } else if (choice == 2) {
            // decompress
            break;
        } else if (choice == 3) {
            // encrypt
            break;
        } else if (choice == 4) {
            // decrypt
            break;
        } else if (choice == 5) {
            // exit
            break;
        } else {
            printf("Invalid choice.\n");
        }
    }
    return 0;
}

/******************************************************************************
 
 * This function prints the menu options with instructions on how to use
   the simple compression and encryption tool.

 * inputs:
   - none

 * outputs:
   - Prints menu options to user

******************************************************************************/

void print_menu(void) {
    printf("\nCompression and Encryption Tooling - Menu\n"
        "1. Compress File Contents\n"
        "2. Decompress File Contents\n"
        "3. Encrypt File Contents\n"
        "4. Decrypt File Contents\n"
        "5. Exit the program\n"
        "Enter your choice>\n");
}