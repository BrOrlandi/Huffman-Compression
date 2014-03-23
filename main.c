#include <stdio.h>
#include "huffman.h"

int main(void){

    unsigned char bytes[] = {1, 2, 3, 4, 5, 6};
    int frequences[] = {45, 13, 12, 16, 9, 5};

    Node *tree;

    int size = sizeof(bytes)/sizeof(bytes[0]);

    tree = huffman(bytes,frequences,size);

    char **codes = huffmanCodes(tree,size,bytes);

    int i,j;
    for(i=0;i<size;i++){
        printf("Byte: %d -> ",bytes[i]);
        for(j=0; codes[i][j] != 2;j++){
            printf("%d",codes[i][j]);
        }
        printf("\n");
    }

    return 0;
}

