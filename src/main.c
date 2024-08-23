#include <stdio.h>
#include "../include/singlelinkedlist.h"
#include "../include/utils.h"

int main(void) {
    showMenu();
    int choice;
    scanf("%d", &choice);
    printBorder();

    switch (choice) {
        case 1:
            puts("Do you want your single-linked list to be circular?");
            puts("1 - Yes");
            puts("2 - No");
            do {
                printf("Your choice -> ");
                scanf("%d", &choice);
                printBorder();
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
}
