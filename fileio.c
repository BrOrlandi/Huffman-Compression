#include <stdio.h.>
#include <stdlib.h.>
#include "fileio.h"

unsigned char *fileRead(char name[], unsigned int *size){
    FILE *f = fopen(name, "rb");
    if(f == NULL){
        printf("File not found: %s\n",name);
        exit(1);
    }

    fseek(f,0L,SEEK_END);
    *size = ftell(f);
    fseek(f, 0, SEEK_SET);

    unsigned char *data = (unsigned char *)malloc(sizeof(unsigned char)*(*size));
    if(data == NULL){
        printf("Memory Error: %s\n",name);
        exit(1);
    }

    unsigned int readed = fread(data,1,*size,f);
    if(readed != *size){
        printf("Reading Error: %s\n",name);
        exit(1);
    }
    fclose(f);
    return data;
}

Node *huffmanFileRead(char name[], unsigned char **data, unsigned int *size){

    FILE *f = fopen(name,"rb");
    if(f == NULL){
        printf("File not found: %s\n",name);
        exit(1);
    }

    int n_bytes; // stores how many bytes are coded
    // the following arrays has the same function of the compression, but now those data will be read from file
    unsigned char bytes[256];
    unsigned int frequencies[256];

    fread(&n_bytes,(sizeof(int)),1,f);

    int i;
    for(i=0;i<n_bytes;i++){
        fread(&(bytes[i]),sizeof(unsigned char),1,f); // read the byte
        fread(&(frequencies[i]),sizeof(unsigned int),1,f); // read his frequency

        //printf("byte = %c    freq = %d\n",bytes[i],frequencies[i]);
    }

    Node *tree; // huffman tre

    tree = huffman(bytes,frequencies,n_bytes);

    fseek(f,0L,SEEK_END);
    *size = ftell(f);
    fseek(f, 0, SEEK_SET);

    *data = (unsigned char *)malloc(sizeof(unsigned char)*(*size));
    if(*data == NULL){
        printf("Memory Error: %s\n",name);
        exit(1);
    }

    unsigned int readed = fread(*data,1,*size,f);
    if(readed != *size){
        printf("Reading Error: %s\n",name);
        exit(1);
    }
    fclose(f);

    return tree;
}
