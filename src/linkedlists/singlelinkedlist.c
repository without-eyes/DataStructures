#include "../../include/linkedlists/singlelinkedlist.h"
#include <malloc.h>

void createSingleLinkedList() {
    int listSize = setListSize();
    Node* head = NULL;
    initializeList(&head, listSize);
    printList(head);
    freeSingleLinkedList(head);
}

int setListSize() {
    int listSize;
    printf("Enter size of single-linked list -> ");
    scanf("%d", &listSize);
    puts("\n=====================================================\n");
    return listSize;
}

Node* createNode() {
    Node* node = (Node*)malloc(sizeof(Node));

    printf("Enter the value: ");
    scanf("%d", &node->value);
    node->next = NULL;

    return node;
}

void initializeList(Node** head, int listSize) {
    for (int i = 0; i < listSize; i++) {
        if (i == 0) {
            *head = createNode();
        } else {
            Node* previousNode = *head;
            while (previousNode->next != NULL) {
                previousNode = previousNode->next;
            }

            Node* newNode = createNode();
            previousNode->next = newNode;
        }
    }
    puts("\n=====================================================\n");
}

void printList(Node* head) {
    while (head->next != NULL) {
        printf("%d -> ", head->value);
        head = head->next;
    }
    printf("%d", head->value);
}

void freeSingleLinkedList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}