#include "../include/doublelinkedlist.h"
#include "../include/utils.h"
#include <malloc.h>

void createDLL() {
    DLLNode* head = NULL;
    initializeDLL(&head);
    while(DLLAction(&head));
    freeDLL(head);
}

void initializeDLL(DLLNode** head) {
    int listSize = setListSize();
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
}

DLLNode* createDLLNode() {
    DLLNode* node = (DLLNode*)malloc(sizeof(DLLNode));

    printf("Enter the value: ");
    scanf("%d", &node->value);
    node->next = NULL;
    node->prev = NULL;

    return node;
}

int DLLAction(DLLNode** head) {
    showDLLMenu();

    int choice;
    scanf("%d", &choice);
    printBorder();

    switch (choice) {
        case 1:
            printf("Enter position of new node -> ");
            int newNodePosition;
            scanf("%d", &newNodePosition);
            addItemDLL(head, newNodePosition);
            break;

        case 2:
            printf("Enter position of node that you want to delete -> ");
            int deleteNodePosition;
            scanf("%d", &deleteNodePosition);
            deleteItemDLL(head, deleteNodePosition);
            break;

        case 3:
            printDLL(*head);
            reversePrintDLL(*head);
            break;

        case 4:
            return 0;

        default:
            break;
    }
    return 1;
}

void addItemDLL(DLLNode** head, int newNodePosition) {
    DLLNode* newNode = createDLLNode();

    if (newNodePosition == 1) {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    } else {
        DLLNode* prevNode = getDLLNodeAtPosition(*head, newNodePosition);
        newNode->next = prevNode->next;
        prevNode->next = newNode;
        newNode->prev = prevNode;
        newNode->next->prev = newNode;
    }
}

void deleteItemDLL(DLLNode** head, int deleteNodePosition) {
    DLLNode* temp;
    if (deleteNodePosition == 1) {
        temp = *head;
        *head = (*head)->next;
        (*head)->prev = NULL;
        free(temp);
    } else {
        DLLNode* prevNode = getDLLNodeAtPosition(*head, deleteNodePosition);
        temp = prevNode->next;
        prevNode->next = prevNode->next->next;
        prevNode->next->prev = prevNode;
        free(temp);
    }
}

DLLNode* getDLLNodeAtPosition(DLLNode* head, int position) {
    DLLNode* curr = head;
    int currentPosition = 1;
    while (currentPosition < position - 1) {
        curr = curr->next;
        currentPosition++;
    }
    return curr;
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
    printf("%d\n", last->value);
}

void freeDLL(DLLNode* head) {
    DLLNode* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

