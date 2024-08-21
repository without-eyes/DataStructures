#ifndef DATASTRUCTURES_SINGLELINKEDLIST_H
#define DATASTRUCTURES_SINGLELINKEDLIST_H

typedef struct Node Node;

struct Node{
    int value;
    Node* next;
};

void createSingleLinkedList();

int setListSize();

Node* createNode();

void initializeList(Node** head, int listSize);

void printList(Node* head);

void freeSingleLinkedList(Node* head);

#endif //DATASTRUCTURES_SINGLELINKEDLIST_H
