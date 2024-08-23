#include "../include/singlelinkedlist.h"
#include "../include/utils.h"
#include <malloc.h>

void createSingleLinkedList() {
    int listSize = setSingleLinkedListSize();
    SingleLinkedListNode* head = NULL;
    initializeSingleLinkedList(&head, listSize);
    printSingleLinkedList(head);
    freeSingleLinkedList(head);
}

int setSingleLinkedListSize() {
    int listSize;
    printf("Enter size of single-linked list -> ");
    scanf("%d", &listSize);
    printBorder();
    return listSize;
}

SingleLinkedListNode* createSingleLinkedListNode() {
    SingleLinkedListNode* node = (SingleLinkedListNode*)malloc(sizeof(SingleLinkedListNode));

    printf("Enter the value: ");
    scanf("%d", &node->value);
    node->next = NULL;

    return node;
}

void initializeSingleLinkedList(SingleLinkedListNode** head, int listSize) {
    for (int i = 0; i < listSize; i++) {
        if (i == 0) {
            *head = createSingleLinkedListNode();
        } else {
            SingleLinkedListNode* previousNode = *head;
            while (previousNode->next != NULL) {
                previousNode = previousNode->next;
            }

            SingleLinkedListNode* newNode = createSingleLinkedListNode();
            previousNode->next = newNode;
        }
    }
    printBorder();
}

void printSingleLinkedList(SingleLinkedListNode* head) {
    while (head->next != NULL) {
        printf("%d -> ", head->value);
        head = head->next;
    }
    printf("%d", head->value);
}

void freeSingleLinkedList(SingleLinkedListNode* head) {
    SingleLinkedListNode* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}