#ifndef HUFFMAN_H
#define HUFFMAN_H

#include "tree.h"

Node *huffman(unsigned char bytes[],unsigned int frequencies[], int size);
unsigned char ** huffmanCodes(Node *tree, int size, unsigned char bytes[]);
void huffmanCompressData(unsigned char *data, unsigned int sizeOfData, unsigned char *bytes, unsigned int *frequencies, unsigned char **codes, unsigned int sizeOfCodes, char fileToSave[]);
int endsWith(char name[], char end[]);

#endif // HUFFMAN_H
