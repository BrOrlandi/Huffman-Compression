#include "huffman.h"
#include "tree.h"
#include <string.h>

#define MAX_CODE_LENGTH 50
#define NULL 0


void sortNodes(Node **nodes, int size){ // an Insertion Sort implementation
    int i,j;
    Node *aux;
    Node *greatest;
    int greatestPos;
    for(i=0;i<size;i++){
        greatest = nodes[i];
        greatestPos = i;
        for(j=i+1;j<size;j++){
            if(nodes[j]->frequence > greatest->frequence){
                greatest = nodes[j];
                greatestPos = j;
            }
        }
        aux = nodes[i];
        nodes[i] = nodes[greatestPos];
        nodes[greatestPos] = aux;
    }
}

Node *huffman(unsigned char bytes[],unsigned int frequences[], int size){

    Node **array = (Node **) malloc(sizeof(Node *)*size);

    int i;
    for(i=0;i<size;i++){
        array[i] = newNode(bytes[i],frequences[i],TRUE);
    }

    sortNodes(array,size);

/*    for(i=0;i<size;i++){
        printf("char %c  freq %u\n",array[i]->byte,array[i]->frequence);
    }
    printf("\n");
//*/
    Node * newnode;

    while(size > 1){
        newnode = newNode(0,array[size-1]->frequence + array[size-2]->frequence, FALSE);
        insertNodeLeft(newnode,array[size-1]);
        insertNodeRight(newnode,array[size-2]);
        array[size-1] = NULL;
        array[size-2] = newnode;
        size--;

        sortNodes(array,size);

/*        for(i=0;i<size;i++){
            printf("char %d  freq %d\n",array[i]->byte,array[i]->frequence);
        }
        printf("\n"); */
    }

    return array[0];
}

void deepCodes(Node *root, char tcode[], int last, unsigned char bytes[], char **codes, int *lastCode){
    if(root->l != NULL){
        tcode[last] = 0;
        deepCodes(root->l,tcode,last+1,bytes,codes,lastCode);
    }
    if(root->r != NULL){
        tcode[last] = 1;
        deepCodes(root->r,tcode,last+1,bytes,codes,lastCode);
    }
    if(root->isLeaf == TRUE){
        int i;
        for(i=0;i<last;i++){
            codes[*lastCode][i] = tcode[i];
        }
        codes[*lastCode][last] = 2;
        bytes[*lastCode] = root->byte;
        (*lastCode)++;
    }
}

unsigned char **huffmanCodes(Node *tree, int size, unsigned char bytes[]){

    unsigned char **codes = (char **) malloc(sizeof(char *)*size);
    int i;
    for(i=0;i<size;i++){
        codes[i] = (char *)malloc(sizeof(char)*MAX_CODE_LENGTH);
    }

    int lastCode = 0;

    char tcode[MAX_CODE_LENGTH];
    deepCodes(tree,tcode,0,bytes,codes,&lastCode);

    return codes;
}

int endsWith(char name[], char end[]){
    int len = strlen(name);
    int elen = strlen(end);
    if(len < elen)
        return 0;
    return strncmp(name + len - elen, end, elen) == 0;
}

unsigned char *huffmanCompressData(unsigned char *data, unsigned int sizeOfData, unsigned char *bytes,unsigned char **codes, unsigned int sizeOfCodes, int *newSize){
    unsigned char *byteToCode[256];
    unsigned int i,j;

    unsigned char *code;
    for(i=0;i<sizeOfCodes;i++){
        byteToCode[(int)bytes[i]] = codes[i];
    }
/*
    for(i=0;i<256;i++){
        code = byteToCode[i];
        if(code != NULL){
            printf("%c = ", (char)i);

            for(j=0; code[j] != 2;j++){
                printf("%d",code[j]);
            }
            printf("\n");
        }
    }*/
    for(i=0;i<sizeOfData;i++){
        code = byteToCode[data[i]];
        /*
        printf("%c = ", data[i]);

        for(j=0; code[j] != 2;j++){
            printf("%d",code[j]);
        }
        printf("\n");
        */
    }

    return 0;
}
