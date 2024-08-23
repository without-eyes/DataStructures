#include <stdio.h>
#include "../include/utils.h"

void showMenu() {
    printBorder();
    puts("What data structure do you want to use:");
    puts("1 - Single-linked list");
    puts("2 - Double-linked list");
    puts("3 - Double-linked list");
    puts("4 - Stack");
    puts("5 - Queue");
    puts("6 - Tree");
    puts("7 - Hash table");
    puts("8 - Graph");
    printf("Your choice -> ");
}

void printBorder() {
    puts("\n=====================================================\n");
}