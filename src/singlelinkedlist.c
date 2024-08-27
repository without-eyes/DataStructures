#include "../include/singlelinkedlist.h"
#include "../include/utils.h"
#include <malloc.h>

// Non-circular single-linked list
void createNCSLL() {
    SLLNode* head = NULL;
    initializeNCSLL(&head);
    while (SLLMenu(&head, false));
    freeNCSLL(head);
}

void initializeNCSLL(SLLNode** head) {
    int listSize = setSLLSize();
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
}

void printNCSLL(SLLNode* head) {
    printBorder();
    puts("Single-linked list:");
    while (head->next != NULL) {
        printf("%d —> ", head->value);
        head = head->next;
    }
    printf("%d\n", head->value);
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
    SLLNode* head = NULL;
    initializeCSLL(&head);
    while (SLLMenu(&head, true));
    freeCSLL(head);
}

void initializeCSLL(SLLNode** head) {
    int listSize = setSLLSize();
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
    printBorder();
    puts("Single-linked list:");
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

int SLLMenu(SLLNode** head, bool isSSLCircular) {
    printBorder();
    puts("Actions:");
    puts("1 - Add item");
    puts("2 - Delete item");
    puts("3 - Print SLL");
    puts("4 - Exit");
    printf("Your choice -> ");

    int choice;
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printBorder();
            printf("Enter position of new node -> ");
            int newNodePosition;
            scanf("%d", &newNodePosition);
            addItem(head, newNodePosition);
            break;

        case 2:
            printBorder();
            printf("Enter position of node that you want to delete -> ");
            int deleteNodePosition;
            scanf("%d", &deleteNodePosition);\
            deleteItem(head, deleteNodePosition);
            break;

        case 3:
            isSSLCircular ? printCSLL(*head) : printNCSLL(*head);
            break;

        case 4:
            return 0;

        default:
            break;
    }

    return 1;
}

void addItem(SLLNode** head, int newNodePosition) {
    SLLNode* newNode = createSLLNode();
    if (newNodePosition == 1) {
        newNode->next = *head;
        *head = newNode;
    }

    SLLNode* curr = *head;
    int currentPosition = 1;
    while (currentPosition < newNodePosition - 1) {
        curr = curr->next;
        currentPosition++;
    }

    newNode->next = curr->next;
    curr->next = newNode;
}

void deleteItem(SLLNode** head, int deleteNodePosition) {
    SLLNode* temp;
    if (deleteNodePosition == 1) {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }

    SLLNode* curr = *head;
    int currentPosition = 1;
    while (currentPosition < deleteNodePosition - 1) {
        curr = curr->next;
        currentPosition++;
    }

    temp = curr->next;
    curr->next = curr->next->next;
    free(temp);
}

