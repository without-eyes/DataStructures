#ifndef DATASTRUCTURES_SINGLELINKEDLIST_H
#define DATASTRUCTURES_SINGLELINKEDLIST_H

#include <stdbool.h>

typedef struct SLLNode SLLNode;

struct SLLNode {
    int value;
    SLLNode* next;
};

typedef struct {
    SLLNode* head;
    bool isCircular;
} SingleLinkedList;

void createSLL(bool isCircular);

void initializeSLL(SingleLinkedList* singleLinkedList);

SLLNode* createSLLNode();

int SLLAction(SingleLinkedList* singleLinkedList);

void addItemSLL(SingleLinkedList* singleLinkedList, int newNodePosition);

void addNodeAtHead(SingleLinkedList* singleLinkedList, SLLNode* newNode);

void deleteItemSLL(SingleLinkedList* singleLinkedList, int deleteNodePosition);

void deleteNodeAtHead(SingleLinkedList* singleLinkedList);

SLLNode* getSLLNodeAtPosition(SLLNode* head, int position);

void printSLL(SingleLinkedList* singleLinkedList);

void freeSLL(SingleLinkedList* singleLinkedList);

#endif //DATASTRUCTURES_SINGLELINKEDLIST_H
