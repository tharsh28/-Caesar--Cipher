#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "queue.h"

void encryptMessage(CircularQueue *q, char *msg, int key) {
    printf("*****************************\nEncrypted Message: ");
    for (int i = 0; msg[i] != '\0'; i++) {
        printf("%c", getShiftedChar(q, msg[i], key));
    }
    printf("\n\n");
}

void decryptMessage(CircularQueue *q, char *msg, int key) {
    printf("*****************************\nOriginal Message: ");
    for (int i = 0; msg[i] != '\0'; i++) {
        printf("%c", getShiftedChar(q, msg[i], -key));
    }
    printf("\n\n");
}

int main() {
    CircularQueue queue;
    initQueue(&queue);
    char choice;
    char message[1000];
    int key;

    while (1) {
        printf("Encryption (E) or Decryption (D)? (Q to quit): ");
        scanf(" %c", &choice);
        getchar();  // Consume newline

        if (choice == 'Q' || choice == 'q') break;

        if (choice == 'E' || choice == 'e') {
            printf("Enter your message: ");
            fgets(message, sizeof(message), stdin);
            message[strcspn(message, "\n")] = '\0';  // Remove newline

            printf("Enter shift key: ");
            scanf("%d", &key);
            getchar();  // Consume newline

            encryptMessage(&queue, message, key);
        } else if (choice == 'D' || choice == 'd') {
            printf("Encrypted Message: ");
            fgets(message, sizeof(message), stdin);
            message[strcspn(message, "\n")] = '\0';

            printf("Enter shift key: ");
            scanf("%d", &key);
            getchar();  // Consume newline

            decryptMessage(&queue, message, key);
        } else {
            printf("Invalid choice. Please enter E, D, or Q.\n");
        }
    }

    printf("Program exited.\n");
    return 0;
}

