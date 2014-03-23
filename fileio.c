#include <stdio.h.>
#include <stdlib.h.>
#include "fileio.h"

unsigned char *fileRead(char name[], unsigned int *size){
    FILE *f = fopen(name, "rb");
    if(f == NULL){
        printf("File Error: %s\n",name);
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

}

void huffmanFileWrite(char name[], unsigned char bytes[],unsigned int frequences[],unsigned char *data, unsigned int size){

}

void fileWrie(char name[],unsigned char *data, unsigned int size){

}
