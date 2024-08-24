#ifndef DATASTRUCTURES_SINGLELINKEDLIST_H
#define DATASTRUCTURES_SINGLELINKEDLIST_H

typedef struct SLLNode SLLNode;

struct SLLNode {
    int value;
    SLLNode* next;
};

// Non-circular single-linked list
void createNCSLL();

void initializeNCSLL(SLLNode** head, int listSize);

void printNCSLL(SLLNode* head);

void freeNCSLL(SLLNode* head);

// Circular single-linked list
void createCSLL();

void initializeCSLL(SLLNode** head, int listSize);

void printCSLL(SLLNode* head);

void freeCSLL(SLLNode* head);

// Both
int setSLLSize();

SLLNode* createSLLNode();

#endif //DATASTRUCTURES_SINGLELINKEDLIST_H
