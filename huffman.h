#ifndef HUFFMAN_H
#define HUFFMAN_H

#include "tree.h"

Node *huffman(unsigned char bytes[],unsigned int frequences[], int size);
unsigned char ** huffmanCodes(Node *tree, int size, unsigned char bytes[]);
unsigned char *huffmanCompressData(unsigned char *data, unsigned int sizeOfData, unsigned char *bytes,unsigned char **codes, unsigned int size, int *newSize);
int endsWith(char name[], char end[]);

#endif // HUFFMAN_H
