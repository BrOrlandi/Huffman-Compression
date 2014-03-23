#include <stdio.h>
#include "huffman.h"
#include "fileio.h"

int main(int argc, char *argv[]){

    /*if(argc < 2){
        printf("Usage: [input file] , if the input file ends with '.hff' it will be decompressed otherwise will be compressed in a '.hff' file.\n");
        return 0;
    }*/

    //char *fileName = argv[1];
    char *fileName = "lorem.txt";

    unsigned int fsize;
    unsigned char *data;

    if(endsWith(fileName,".hff")){
        printf("%s is huffman file.\n",fileName);
    }
    else{
        printf("%s is not huffman file.\n",fileName);
        data = fileRead(fileName,&fsize);

        int i;
        for(i=0;i<fsize;i++){
            printf("%c",data[i]);
        }

        //unsigned char *bytes = (unsigned char *)calloc(sizeof(unsigned char),256);
        unsigned char bytes[] = {1, 2, 3, 4, 5, 6};
        unsigned int frequences[] = {45, 13, 12, 16, 9, 5};

        Node *tree;

        int size = sizeof(bytes)/sizeof(bytes[0]);

        tree = huffman(bytes,frequences,size);

        char **codes = huffmanCodes(tree,size,bytes);

        int j;
        for(i=0;i<size;i++){
            printf("Byte: %d -> ",bytes[i]);
            for(j=0; codes[i][j] != 2;j++){
                printf("%d",codes[i][j]);
            }
            printf("\n");
        }

    }

    return 0;
}

