#ifndef DATASTRUCTURES_SINGLELINKEDLIST_H
#define DATASTRUCTURES_SINGLELINKEDLIST_H

typedef struct SingleLinkedListNode SingleLinkedListNode;

struct SingleLinkedListNode {
    int value;
    SingleLinkedListNode* next;
};

void createSingleLinkedList();

int setSingleLinkedListSize();

SingleLinkedListNode* createSingleLinkedListNode();

void initializeSingleLinkedList(SingleLinkedListNode** head, int listSize);

void printSingleLinkedList(SingleLinkedListNode* head);

void freeSingleLinkedList(SingleLinkedListNode* head);

#endif //DATASTRUCTURES_SINGLELINKEDLIST_H
