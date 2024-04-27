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
#include "compression.h"
#include "encryption.h"

/******************************************************************************

 * List preprocessing directives - you may define your own.
 * Each defined with max size + null terminator.

******************************************************************************/

/******************************************************************************

 * Function prototypes

******************************************************************************/

void run_length_compress(const char input_filename[], 
                         const char output_filename[]);

void run_length_decompress(const char input_filename[], 
                           const char output_filename[]);

void caeser_cipher_encrypt(const char input_filename[], 
                           const char output_filename[], int shift_key);

void caeser_cipher_decrypt(const char input_filename[], 
                           const char output_filename[], int shift_key);

/* Should we create potential helper functions like save_file / load_file? */

/******************************************************************************

 * Overview of program here

******************************************************************************/

int main(void) {
    return 0;
}