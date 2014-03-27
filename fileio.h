#ifndef FILEIO_H
#define FILEIO_H

#include "tree.h"

unsigned char *fileRead(char name[], unsigned int *size); // return the data and writes the size
Node *huffmanFileRead(char name[], unsigned char **data, unsigned int *size); // returns the huffman tree, writes the data and the size

#endif // FILEIO_H
