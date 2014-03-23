#ifndef TREE_H
#define TREE_H
#define TRUE 1
#define FALSE 0

typedef struct Node{
    unsigned char byte;
    unsigned int frequence;
    char isLeaf;
    struct Node *l, *r;
}Node;

Node* newNode(unsigned char byte,unsigned int frequence, char isLeaf);
void insertNodeLeft(Node* node, Node* toInsert);
void insertNodeRight(Node* node, Node* toInsert);

#endif // TREE_H
