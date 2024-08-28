#include <stdio.h>
#include "../include/singlelinkedlist.h"
#include "../include/utils.h"
#include "../include/doublelinkedlist.h"

int main(void) {
    showMainMenu();

    int choice;
    scanf("%d", &choice);
    printBorder();

    switch (choice) {
        case 1:
            puts("Do you want your single-linked list to be circular?");
            puts("1 - Yes");
            puts("2 - No");
            printf("Your choice -> ");
            scanf("%d", &choice);
            printBorder();
            if (choice == 1) {
                createSLL(true);
            } else if (choice == 2) {
                createSLL(false);
            }
            break;

        case 2:
            createDLL();
            break;

        default: break;
    }
}
