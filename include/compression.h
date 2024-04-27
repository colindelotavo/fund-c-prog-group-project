#ifndef RUN_LENGTH_H_   /* Include guard */
#define RUN_LENGTH_H_

/******************************************************************************



******************************************************************************/

void compress_file(const char input_filename[], 
                         const char output_filename[]);

void decompress_file(const char input_filename[], 
                           const char output_filename[]);

#endif // RUN_LENGTH_H_
