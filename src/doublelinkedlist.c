#include "../include/doublelinkedlist.h"
#include "../include/utils.h"
#include <malloc.h>

void createDLL() {
    int listSize = setDLLSize();
    DLLNode* head = NULL;
    initializeDLL(&head, listSize);
    printDLL(head);
    freeDLL(head);
}

void initializeDLL(DLLNode** head, int listSize) {
    for (int i = 0; i < listSize; i++) {
        if (i == 0) {
            *head = createDLLNode();
        } else {
            DLLNode* previousNode = *head;
            while (previousNode->next != NULL) {
                previousNode = previousNode->next;
            }

            DLLNode* newNode = createDLLNode();
            newNode->prev = previousNode;
            previousNode->next = newNode;
        }
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
    while (head->next != NULL) {
        printf("%d <—> ", head->value);
        head = head->next;
    }
    printf("%d", head->value);
}

void freeDLL(DLLNode* head) {
    DLLNode* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}