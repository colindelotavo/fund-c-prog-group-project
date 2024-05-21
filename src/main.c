/******************************************************************************

 * 48430 Fundamentals of C Programming - Assignment 3

 * Group Number: 56

 * Lab Number: 04

 * Group Members: Colin Tria Delotavo and Samarth Kunal Singh
 
 * Date of submission: 22/05/2024

******************************************************************************/

/******************************************************************************

 * Header files along with used functions

******************************************************************************/

#include <stdio.h> /* printf, scanf, getchar */
#include "../include/compression.h" /* compress_file, decompress_file */
#include "../include/encryption.h" /* encrypt_file, decrypt_file */
#include "../include/fileio.h" /* user_input, display_file, 
                                  compare_file_size */

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
void exit_program(void);

/******************************************************************************

 * Overview of program here

    gcc -o ../task.out main.c compression.c encryption.c fileio.c -I../include

******************************************************************************/

int main(void) {
    
    int choice = 0;
    int shift_key; /* note in report users would go through all options */

    while (choice != 5) {
        print_menu();
        scanf(" %d", &choice); getchar();
        if (choice == 1) {
            user_input(INPUT_FILE);
            compress_file(INPUT_FILE, COMPRESSED_FILE);
            display_file(INPUT_FILE, COMPRESSED_FILE);
            compare_file_size(INPUT_FILE, COMPRESSED_FILE);
        } else if (choice == 2) {
            decompress_file(COMPRESSED_FILE, DECOMPRESSED_FILE);
            display_file(COMPRESSED_FILE, DECOMPRESSED_FILE);
        } else if (choice == 3) {
            user_input(INPUT_FILE);
            printf("Enter shift key for encryption> ");
            scanf(" %d", &shift_key);
            encrypt_file(INPUT_FILE, ENCRYPTED_FILE, shift_key);
            display_file(INPUT_FILE, ENCRYPTED_FILE);
        } else if (choice == 4) {
            printf("Enter shift key for decryption> ");
            scanf(" %d", &shift_key);
            decrypt_file(ENCRYPTED_FILE, DECRYPTED_FILE, shift_key);
            display_file(ENCRYPTED_FILE, DECRYPTED_FILE);
        } else if (choice == 5) {
            exit_program();
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
    printf("\n\nCompression and Encryption Tooling - Menu\n"
        "1 - Compress File Contents\n"
        "2 - Decompress File Contents\n"
        "3 - Encrypt File Contents\n"
        "4 - Decrypt File Contents\n"
        "5 - Exit the program\n"
        "Enter your choice> ");
}

void exit_program(void) {
    printf("Thanks for learning with us. Have a great day!\n\n");
}