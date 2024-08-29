#include "../include/singlelinkedlist.h"
#include "../include/utils.h"
#include <malloc.h>

void createSLL(bool isCircular) {
    SingleLinkedList *singleLinkedList = (SingleLinkedList*)malloc(sizeof(SingleLinkedList));
    singleLinkedList->isCircular = isCircular;
    initializeSLL(singleLinkedList);
    while (SLLAction(singleLinkedList));
    freeSLL(singleLinkedList);
}

void initializeSLL(SingleLinkedList* singleLinkedList) {
    int listSize = setListSize();
    if (listSize > 0) {
        singleLinkedList->head = createSLLNode();
    }

    for (int i = 1; i < listSize; i++) {
        SLLNode* newNode = createSLLNode();
        if (singleLinkedList->isCircular && i == listSize - 1) {
            newNode->next = singleLinkedList->head;
        }

        SLLNode* previousNode = singleLinkedList->head;
        while (previousNode->next != NULL) {
            previousNode = previousNode->next;
        }
        previousNode->next = newNode;
    }
}

SLLNode* createSLLNode() {
    SLLNode* node = (SLLNode*)malloc(sizeof(SLLNode));

    printf("Enter the value of node: ");
    scanf("%d", &node->value);
    node->next = NULL;

    return node;
}

int SLLAction(SingleLinkedList* singleLinkedList) {
    showSLLMenu();

    int choice;
    scanf("%d", &choice);
    printBorder();

    switch (choice) {
        case 1:
            printf("Enter position of new node -> ");
            int newNodePosition;
            scanf("%d", &newNodePosition);
            addItemSLL(singleLinkedList, newNodePosition);
            break;

        case 2:
            printf("Enter position of node that you want to delete -> ");
            int deleteNodePosition;
            scanf("%d", &deleteNodePosition);
            deleteItemSLL(singleLinkedList, deleteNodePosition);
            break;

        case 3:
            printSLL(singleLinkedList);
            break;

        case 4:
            return 0;

        default:
            break;
    }

    return 1;
}

void addItemSLL(SingleLinkedList* singleLinkedList, int newNodePosition) {
    SLLNode* newNode = createSLLNode();

    if (newNodePosition == 1) {
        addNodeAtHead(singleLinkedList, newNode);
    } else {
        SLLNode* prevNode = getSLLNodeAtPosition(singleLinkedList->head, newNodePosition);
        newNode->next = prevNode->next;
        prevNode->next = newNode;
    }
}

void addNodeAtHead(SingleLinkedList* singleLinkedList, SLLNode* newNode) {
    if (singleLinkedList->isCircular) {
        SLLNode* temp = singleLinkedList->head;
        while (temp->next != singleLinkedList->head) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    newNode->next = singleLinkedList->head;
    singleLinkedList->head = newNode;
}

void deleteItemSLL(SingleLinkedList* singleLinkedList, int deleteNodePosition) {
    if (deleteNodePosition == 1) {
        deleteNodeAtHead(singleLinkedList);
    } else {
        SLLNode* prevNode = getSLLNodeAtPosition(singleLinkedList->head, deleteNodePosition);
        SLLNode* temp = prevNode->next;
        prevNode->next = prevNode->next->next;
        free(temp);
    }
}

void deleteNodeAtHead(SingleLinkedList* singleLinkedList) {
    SLLNode* temp = singleLinkedList->head;
    while (singleLinkedList->isCircular && temp->next != singleLinkedList->head) {
        temp = temp->next;
    }

    singleLinkedList->head = singleLinkedList->head->next;

    if (singleLinkedList->isCircular) {
        free(temp->next);
        temp->next = singleLinkedList->head;
    } else {
        free(temp);
    }
}

SLLNode* getSLLNodeAtPosition(SLLNode* head, int position) {
    SLLNode* curr = head;
    int currentPosition = 1;
    while (currentPosition < position - 1) {
        curr = curr->next;
        currentPosition++;
    }
    return curr;
}

void printSLL(SingleLinkedList* singleLinkedList) {
    puts("Single-linked list:");
    if (singleLinkedList->isCircular) {
        SLLNode* curr = singleLinkedList->head;
        do {
            printf("%d —> ", curr->value);
            curr = curr->next;
        } while (curr != singleLinkedList->head);
        printf("%d(head)\n", singleLinkedList->head->value);
    } else {
        while (singleLinkedList->head->next != NULL) {
            printf("%d —> ", singleLinkedList->head->value);
            singleLinkedList->head = singleLinkedList->head->next;
        }
        printf("%d\n", singleLinkedList->head->value);
    }
}

void freeSLL(SingleLinkedList* singleLinkedList) {
    if (singleLinkedList->isCircular) {
        SLLNode *temp = singleLinkedList->head;
        SLLNode *nextNode;
        do {
            nextNode = temp->next;
            free(temp);
            temp = nextNode;
        } while (temp != singleLinkedList->head);
        singleLinkedList->head = NULL;
    } else {
        SLLNode *temp;
        while (singleLinkedList->head != NULL) {
            temp = singleLinkedList->head;
            singleLinkedList->head = singleLinkedList->head->next;
            free(temp);
            temp = NULL;
        }
    }
    free(singleLinkedList);
    singleLinkedList = NULL;
}