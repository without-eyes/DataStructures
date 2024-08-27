#ifndef DATASTRUCTURES_SINGLELINKEDLIST_H
#define DATASTRUCTURES_SINGLELINKEDLIST_H

#include <stdbool.h>

typedef struct SLLNode SLLNode;

struct SLLNode {
    int value;
    SLLNode* next;
};

// Non-circular single-linked list
void createNCSLL();

void initializeNCSLL(SLLNode** head);

void printNCSLL(SLLNode* head);

void freeNCSLL(SLLNode* head);

// Circular single-linked list
void createCSLL();

void initializeCSLL(SLLNode** head);

void printCSLL(SLLNode* head);

void freeCSLL(SLLNode* head);

// Both
int setSLLSize();

SLLNode* createSLLNode();

int SLLMenu(SLLNode** head, bool isSSLCircular);

void addItem(SLLNode** head, int newNodePosition);

void deleteItem(SLLNode** head, int deleteNodePosition);

#endif //DATASTRUCTURES_SINGLELINKEDLIST_H
