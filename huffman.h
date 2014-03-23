#ifndef HUFFMAN_H
#define HUFFMAN_H

#include "tree.h"

Node *huffman(unsigned char bytes[],unsigned int frequences[], int size);
void sortNodes(Node **nodes, int size); // an Insertion Sort implementation
char ** huffmanCodes(Node *tree, int size, unsigned char bytes[]);

int endsWith(char name[], char end[]);

#endif // HUFFMAN_H
