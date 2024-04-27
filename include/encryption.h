#ifndef CAESER_CIPHER_H_   /* Include guard */
#define CAESER_CIPHER_H_

/******************************************************************************



******************************************************************************/

void encrypt_file(const char input_filename[], 
                           const char output_filename[], int shift_key);

void decrypt_file(const char input_filename[], 
                           const char output_filename[], int shift_key);

#endif // CAESER_CIPHER_H_
