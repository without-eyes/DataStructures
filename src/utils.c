#include <stdio.h>
#include "../include/utils.h"

void showMenu() {
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

void printBorder() {
    puts("\n=====================================================\n");
}