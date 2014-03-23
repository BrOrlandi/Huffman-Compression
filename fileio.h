#ifndef FILEIO_H
#define FILEIO_H

#include "tree.h"

unsigned char *fileRead(char name[], unsigned int *size); // return the data and writes the size
Node *huffmanFileRead(char name[], unsigned char **data, unsigned int *size); // returns the huffman tree, writes the data and the size
void huffmanFileWrite(char name[], unsigned char bytes[],unsigned int frequences[],unsigned char *data, unsigned int size);
void fileWrie(char name[],unsigned char *data, unsigned int size);
#endif // FILEIO_H
