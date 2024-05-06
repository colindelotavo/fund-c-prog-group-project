#ifndef COMPRESSION_H_   /* Include guard */
#define COMPRESSION_H_

/******************************************************************************



******************************************************************************/

void compress_file(const char input_filename[], 
                   const char output_filename[]);

void decompress_file(const char input_filename[], 
                     const char output_filename[]);

#endif // RUN_LENGTH_H_
