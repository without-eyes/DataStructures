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

DLLNode* createDLLNode();

int DLLAction(DLLNode** head);

void addItemDLL(DLLNode** head, int newNodePosition);

void deleteItemDLL(DLLNode** head, int deleteNodePosition);

DLLNode* getDLLNodeAtPosition(DLLNode* head, int position);

void printDLL(DLLNode* head);

void reversePrintDLL(DLLNode* head);

void freeDLL(DLLNode* head);

#endif //DATASTRUCTURES_DOUBLELINKEDLIST_H
