// Write a function that adds all odd numbers to the beginning of the list and all even
// numbers to the end of the list until -1 is entered from the keyboard.

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* insertnode(struct Node* head, int x) {
    if (x % 2 != 0) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = x;
        newNode->next = head;
        head = newNode;
    } else {
        struct Node* last = head;
        if (last != NULL) {
            while (last->next != NULL) {
                last = last->next;
            }
            struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
            newNode->data = x;
            last->next = newNode;
            newNode->next = NULL;
        } else {
            struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
            newNode->data = x;
            newNode->next = NULL;
            head = newNode;
        }
    }
    return head;
}

int main() {
    int i;
    struct Node* head = NULL; // Initialize head to NULL
    printf("Enter integers. Enter -1 to exit:\n");
    while (1) {
        if (scanf("%d", &i) != 1 || i == -1) {
            break;
        }
        head = insertnode(head, i);
    }

    // Print the elements of the linked list for verification
    struct Node* temp = head;
    printf("Elements in the linked list are: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");

    // Free the allocated memory
    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}

