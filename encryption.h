#ifndef CAESER_CIPHER_H_   /* Include guard */
#define CAESER_CIPHER_H_

/******************************************************************************



******************************************************************************/

void caeser_cipher_encrypt(const char input_filename[], 
                           const char output_filename[], int shift_key);

void caeser_cipher_decrypt(const char input_filename[], 
                           const char output_filename[], int shift_key);

#endif // CAESER_CIPHER_H_
