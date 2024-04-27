#ifndef RUN_LENGTH_H_   /* Include guard */
#define RUN_LENGTH_H_

void run_length_compress(const char input_filename[], 
                         const char output_filename[]);

void run_length_decompress(const char input_filename[], 
                           const char output_filename[]);

#endif // RUN_LENGTH_H_
