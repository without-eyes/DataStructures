#include <stdio.h>
#include <string.h>
#include "../include/linkedlists/singlelinkedlist.h"

void showMenu() {
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

int main(void) {
    showMenu();
    int choice;
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            puts("\nDo you want your single-linked list to be circular?");
            puts("1 - Yes");
            puts("2 - No");
            do {
                printf("Your choice -> ");
                scanf("%d", &choice);
                if (choice == 1) {
                    // circular
                } else if (choice == 2) {
                    createSingleLinkedList();
                } else {
                    puts("Wrong input!");
                }
            } while (choice != 1 && choice != 2);

        default: break;
    }


    return 0;
}
