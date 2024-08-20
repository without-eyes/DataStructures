#ifndef DATASTRUCTURES_SINGLELINKEDLIST_H
#define DATASTRUCTURES_SINGLELINKEDLIST_H

typedef struct Node Node;

struct Node{
    int value;
    Node* next;
};

void createSingleLinkedList();

Node* createNode();

void freeSingleLinkedList(Node* head);

#endif //DATASTRUCTURES_SINGLELINKEDLIST_H
