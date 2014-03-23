#ifndef HUFFMAN_H
#define HUFFMAN_H

#include "tree.h"

Node *huffman(unsigned char bytes[], int frequences[], int size);
void sortNodes(Node **nodes, int size); // an Insertion Sort implementation
char ** huffmanCodes(Node *tree, int size, unsigned char bytes[]);

#endif // HUFFMAN_H
