/*
This algorithm was implemented by Bruno Orlandi. 2014
*/

#include <stdio.h>
#include "huffman.h"
#include "fileio.h"

int main(int argc, char *argv[]){

    if(argc < 2){ // the file must be in the arguments
        printf("Usage: [input file] , if the input file ends with '.hff' it will be decompressed otherwise will be compressed in a '.hff' file.\n");
        return 0;
    }

    char *fileName = argv[1]; // name of the file to be compressed or decompressed

    if(endsWith(fileName,".hff")){ // check if the file is an '.hff' file, if it is, decompress

        unsigned int size; // size of the file to be calculated
        unsigned char *data; // new data after decompress

        huffmanFileRead(fileName,&data,&size);

        // here can make others manipulations to the data

        printf("Saving the uncompressed file.\n");
        int len = strlen(fileName);
        fileName[len-4] = '\0';
        fileWrite(fileName,data,size);
        printf("File decompressed: %s\n",fileName);
    }
    else{ // otherwise, the file will be compres8sed in a hff file

        unsigned int size; // size of the file to be calculated
        unsigned char *data; // the data read from the file

        data = fileRead(fileName,&size); // read the file and stores in data


        huffmanFileWrite(fileName,data,size);

    }


    return 0;
}
