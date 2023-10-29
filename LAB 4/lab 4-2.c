// Add 100 randomly generated numbers to the list, write the c code that sorts all the
// numbers entered from largest to smallest and prints them on the screen.

#include <stdio.h>
#include <stdlib.h>

// Define the structure for the node
struct Node {
    int data;
    struct Node* next;
};

// Function to insert node at the beginning of the list
struct Node* insertnode(struct Node* head, int x) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = head;
    head = newNode;
    return head;
}

// Function to swap the data of two nodes
void swap(struct Node* a, struct Node* b) {
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

// Function to sort the linked list using bubble sort
void sortLinkedList(struct Node* head) {
    int swapped, i;
    struct Node* ptr1;
    struct Node* lptr = NULL;

    /* Checking for empty list */
    if (head == NULL)
        return;

    do {
        swapped = 0;
        ptr1 = head;

        while (ptr1->next != lptr) {
            if (ptr1->data < ptr1->next->data) {
                swap(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

int main() {
    // Initialize variables
    struct Node* head = NULL;
    int i,j;

    // Add 100 random numbers to the linked list
    printf("Adding 100 random numbers to the list...\n");
    for (j = 0; j < 100; j++) {
        i = rand() % 1000; // Generate a random number between 0 and 999
        head = insertnode(head, i);
    }

    // Sort the linked list
    printf("Sorting the list...\n");
    sortLinkedList(head);

    // Print the sorted list
    printf("Sorted list in descending order: ");
    struct Node* temp = head;
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

