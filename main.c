/*
This algorithm was implemented by Bruno Orlandi. 2014
*/

#include <stdio.h>
#include "huffman.h"
#include <string.h>
#include "fileio.h"

int main(int argc, char *argv[]){
    //return main_test(argc,argv)

    if(argc < 3){ // the file must be in the arguments
        printf("Usage: <input file> [optional -d] <output file>\n\t -d\tThe input file will be decompressed to output file.");
        return 0;
    }
    char *inputFile = argv[1];
    char *outputFile;

    char decompress = 0;
    if(!strcmp(argv[2],"-d")){
        decompress = 1;
        if(argc < 4){
            printf("Missing <output file>\n");
            return 0;
        }
        outputFile = argv[3];
    }
    else{
        outputFile = argv[2];
    }

    Huffman h;

    Huffman_init(&h);

    if(decompress){

        printf("Decompressing: %s\n", inputFile);

        unsigned int size; // size of the file to be calculated
        unsigned char *data; // new data after decompress

        Huffman_file_decompress(&h,inputFile);
        data = h.uc_data[0];
        size = h.uc_sizes[0];

        // here can make others manipulations to the data

        printf("Saving the decompressed file.\n");
        fileWrite(outputFile,data,size);
        printf("File decompressed to: %s\n",outputFile);
    }
    else
    {
        unsigned int size; // size of the file to be calculated
        unsigned char *data; // the data read from the file

        data = fileRead(inputFile,&size); // read the file and stores in data

        printf("Compressing: %s\n", inputFile);
        Huffman_add_data_block(&h,data,size);

        Huffman_apply(&h);

        Huffman_compress_data_to_file(&h,outputFile);
        printf("File compressed to: %s\n",outputFile);
    }
    Huffman_free(&h);
    return 0;
}
