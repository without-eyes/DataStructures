#include "../include/doublelinkedlist.h"
#include "../include/utils.h"
#include <malloc.h>

void createDLL() {
    DLLNode* head = NULL;
    initializeDLL(&head);
    printDLL(head);
    reversePrintDLL(head);
    freeDLL(head);
}

void initializeDLL(DLLNode** head) {
    int listSize = setDLLSize();
    if (listSize > 0) {
        *head = createDLLNode();
    }

    for (int i = 1; i < listSize; i++) {
        DLLNode* prev = *head;
        while (prev->next != NULL) {
            prev = prev->next;
        }

        DLLNode* newNode = createDLLNode();
        newNode->prev = prev;
        prev->next = newNode;
    }
    printBorder();
}

int setDLLSize() {
    printf("Enter size of double-linked list -> ");
    int listSize;
    scanf("%d", &listSize);
    printBorder();
    return listSize;
}

DLLNode* createDLLNode() {
    DLLNode* node = (DLLNode*)malloc(sizeof(DLLNode));

    printf("Enter the value: ");
    scanf("%d", &node->value);
    node->next = NULL;
    node->prev = NULL;

    return node;
}

void printDLL(DLLNode* head) {
    puts("Normal output:");
    while (head->next != NULL) {
        printf("%d <—> ", head->value);
        head = head->next;
    }
    printf("%d", head->value);
}

void reversePrintDLL(DLLNode* head) {
    puts("\n\nReverse output:");
    DLLNode* last = head;
    while (last->next != NULL) {
        last = last->next;
    }
    while (last->prev != NULL) {
        printf("%d <—> ", last->value);
        last = last->prev;
    }
    printf("%d", last->value);
}

void freeDLL(DLLNode* head) {
    DLLNode* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}