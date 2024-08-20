#include "../../include/linkedlists/singlelinkedlist.h"
#include <malloc.h>

void createSingleLinkedList() {
    int listSize;
    printf("\nEnter size of single-linked list -> ");
    scanf("%d", &listSize);

    Node* head;
    for (int i = 0; i < listSize; i++) {
        if (i == 0) {
            head = createNode();
        } else {
            Node* previousNode = head;
            while (previousNode->next != NULL) {
                previousNode = previousNode->next;
            }

            Node* newNode = createNode();
            previousNode->next = newNode;
        }
    }

    freeSingleLinkedList(head);
}

Node* createNode() {
    Node* node = (Node*)malloc(sizeof(Node));

    printf("Enter the value: ");
    scanf("%d", &node->value);
    node->next = NULL;

    return node;
}

void freeSingleLinkedList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}