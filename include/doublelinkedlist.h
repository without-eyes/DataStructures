#ifndef DATASTRUCTURES_DOUBLELINKEDLIST_H
#define DATASTRUCTURES_DOUBLELINKEDLIST_H

typedef struct DLLNode DLLNode;

struct DLLNode {
    int value;
    DLLNode* prev;
    DLLNode* next;
};

void createDLL();

void initializeDLL(DLLNode** head);

int setDLLSize();

DLLNode* createDLLNode();

void printDLL(DLLNode* head);

void reversePrintDLL(DLLNode* head);

void freeDLL(DLLNode* head);

#endif //DATASTRUCTURES_DOUBLELINKEDLIST_H
