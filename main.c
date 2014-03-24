/*
This algorithm was implemented by Bruno Orlandi. 2014
*/

#include <stdio.h>
#include "huffman.h"
#include "fileio.h"

int main(int argc, char *argv[]){

    /*if(argc < 2){ // the file must be in the arguments
        printf("Usage: [input file] , if the input file ends with '.hff' it will be decompressed otherwise will be compressed in a '.hff' file.\n");
        return 0;
    }*/

    //char *fileName = argv[1]; // name of the file to be compressed or decompressed
    char *fileName = "lorem.txt";

    unsigned int fsize; // size of the file to be calculated
    unsigned char *data; // the data read from the file

    if(endsWith(fileName,".hff")){ // check if the file is an '.hff' file, if it is, decompress
        printf("%s is huffman file.\n",fileName);
    }
    else{ // otherwise, the file will be compressed in a hff file

        int i;
        data = fileRead(fileName,&fsize); // read the file and stores in data
        printf("Compressing file %s...\n",fileName);

        unsigned char bytes[256]; // array to store the bytes reads from the file
        unsigned int frequences[256]; // array to store the frequency of the bytes that appear in the file
        int n_bytes = 0; // will be used to count the bytes inserted in the arrays above

        unsigned int *tmpfreq = (unsigned int *)calloc(sizeof(unsigned int),256); // temporary to count bytes frequences in file data

        for(i=0;i<fsize;i++){
            tmpfreq[data[i]]++; // counting number of times each byte appears on the file
        }

        for(i=0;i<256;i++){ // store in the arrays all the bytes with frequency greater than zero and their frequency
            if(tmpfreq[i] > 0){
                bytes[n_bytes] = (unsigned char)i;
                frequences[n_bytes] = tmpfreq[i];
                n_bytes++;
            }
        }

        //unsigned char bytes[] = {1, 2, 3, 4, 5, 6};
        //unsigned int frequences[] = {45, 13, 12, 16, 9, 5};

        Node *tree; // huffman tre

        //int size = sizeof(bytes)/sizeof(bytes[0]);

        tree = huffman(bytes,frequences,n_bytes);

        unsigned char **codes = huffmanCodes(tree,n_bytes,bytes);
/*
        int j;
        for(i=0;i<n_bytes;i++){
            printf("Byte: %c -> ",bytes[i]);
            for(j=0; codes[i][j] != 2;j++){
                printf("%d",codes[i][j]);
            }
            printf("\n");
        }
*/
        unsigned int nSize;

        huffmanCompressData(data,fsize,bytes,codes,n_bytes,&nSize);

    }

    return 0;
}

