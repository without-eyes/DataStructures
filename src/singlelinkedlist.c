#include "../include/singlelinkedlist.h"
#include "../include/utils.h"
#include <malloc.h>

// Non-circular single-linked list
void createNCSLL() {
    int listSize = setSLLSize();
    SLLNode* head = NULL;
    initializeNCSLL(&head, listSize);
    printNCSLL(head);
    freeNCSLL(head);
}

void initializeNCSLL(SLLNode** head, int listSize) {
    for (int i = 0; i < listSize; i++) {
        if (i == 0) {
            *head = createSLLNode();
        } else {
            SLLNode* previousNode = *head;
            while (previousNode->next != NULL) {
                previousNode = previousNode->next;
            }

            SLLNode* newNode = createSLLNode();
            previousNode->next = newNode;
        }
    }
    printBorder();
}

void printNCSLL(SLLNode* head) {
    while (head->next != NULL) {
        printf("%d -> ", head->value);
        head = head->next;
    }
    printf("%d", head->value);
}

void freeNCSLL(SLLNode* head) {
    SLLNode* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// Circular single-linked list
void createCSLL() {
    int listSize = setSLLSize();
    SLLNode* head = NULL;
    initializeCSLL(&head, listSize);
    printCSLL(head);
    freeCSLL(head);
}

void initializeCSLL(SLLNode** head, int listSize) {
    for (int i = 0; i < listSize; i++) {
        if (i == 0) {
            *head = createSLLNode();
        } else {
            SLLNode* previousNode = *head;
            while (previousNode->next != NULL) {
                previousNode = previousNode->next;
            }

            SLLNode* newNode = createSLLNode();
            if (i == listSize - 1) newNode->next = *head;
            previousNode->next = newNode;
        }
    }
    printBorder();
}

void printCSLL(SLLNode* head) {
    SLLNode* curr = head;
    do {
        printf("%d —> ", curr->value);
        curr = curr->next;
    } while (curr != head);
    printf("%d(head)\n", head->value);
}

void freeCSLL(SLLNode* head) {
    if (head == NULL) return;

    SLLNode* temp = head;
    SLLNode* nextNode;

    do {
        nextNode = temp->next;
        free(temp);
        temp = nextNode;
    } while (temp != head);

    head = NULL;
}

// Both
int setSLLSize() {
    printf("Enter size of single-linked list -> ");
    int listSize;
    scanf("%d", &listSize);

    printBorder();

    return listSize;
}

SLLNode* createSLLNode() {
    SLLNode* node = (SLLNode*)malloc(sizeof(SLLNode));

    printf("Enter the value: ");
    scanf("%d", &node->value);
    node->next = NULL;

    return node;
}

