#include "tree.h"
#include <stdlib.h>

Node* newNode(unsigned char byte,unsigned int frequence, char isLeaf){
    Node *n = (Node *)malloc(sizeof(Node));
    n->l = n->r = NULL;
    n->byte = byte;
    n->frequence = frequence;
    n->isLeaf = isLeaf;
    return n;
}

void insertNodeLeft(Node* node, Node* toInsert){
    node->l = toInsert;
}

void insertNodeRight(Node* node, Node* toInsert){
    node->r = toInsert;
}
