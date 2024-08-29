#include <stdio.h>
#include "../include/utils.h"

void showMainMenu() {
    printBorder();
    puts("What data structure do you want to use:");
    puts("1 - Single-linked list");
    puts("2 - Double-linked list");
    puts("3 - Stack");
    puts("4 - Queue");
    puts("5 - Tree");
    puts("6 - Hash table");
    puts("7 - Graph");
    printf("Your choice -> ");
}

void showSLLMenu() {
    printBorder();
    puts("Actions:");
    puts("1 - Add item");
    puts("2 - Delete item");
    puts("3 - Print SLL");
    puts("4 - Exit");
    printf("Your choice -> ");
}

void showDLLMenu() {
    printBorder();
    puts("Actions:");
    puts("1 - Add item");
    puts("2 - Delete item");
    puts("3 - Print DLL");
    puts("4 - Exit");
    printf("Your choice -> ");
}

void printBorder() {
    puts("\n=====================================================\n");
}

int setListSize() {
    printf("Enter size of  list -> ");
    int listSize;
    scanf("%d", &listSize);
    printBorder();
    return listSize;
}