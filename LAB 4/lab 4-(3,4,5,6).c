/*3-Write a function that stores the student number, name and age, traverses all the nodes in
	the list, writes all the student information on the screen and counts it. 

  4-Write the function that searches records by student name in the list
	
  5-Write the function that deletes the next node from the node with the searched student
	name in the list.
	
  6-Write the function that prints the record with the longest name in the list. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct for student record
struct Student {
    int studentNumber;
    char name[50];
    int age;
    struct Student* next;
};

// Function to insert node at the end of the list
void insertNode(struct Student** head, int studentNumber, char name[], int age) {
    struct Student* newNode = (struct Student*)malloc(sizeof(struct Student));
    struct Student* last = *head;

    newNode->studentNumber = studentNumber;
    strcpy(newNode->name, name);
    newNode->age = age;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    while (last->next != NULL) {
        last = last->next;
    }

    last->next = newNode;
}

// Function to traverse and print all nodes
void traverseAndPrint(struct Student* head) {
    int count = 1;
    while (head != NULL) {
        printf("%d- %s %d %d\n", count, head->name, head->age, head->studentNumber);
        head = head->next;
        count++;
    }
}

// Function to search for a student by name
void searchByName(struct Student* head, char name[]) {
    while (head != NULL) {
        if (strcmp(head->name, name) == 0) {
            printf("Student found: %s %d %d\n", head->name, head->age, head->studentNumber);
            return;
        }
        head = head->next;
    }
    printf("Student not found.\n");
}

// Function to delete the node after the node containing the specified name
void deleteNextNode(struct Student* head, char name[]) {
    struct Student* current = head;
    struct Student* nextNode;

    while (current != NULL && current->next != NULL) {
        if (strcmp(current->name, name) == 0) {
            nextNode = current->next;
            current->next = nextNode->next;
            free(nextNode);
            printf("Next node after %s has been deleted.\n", name);
            return;
        }
        current = current->next;
    }
    printf("No such name found to delete its next node.\n");
}

// Function to find the node with the longest name
void findLongestName(struct Student* head) {
    int maxLength = 0;
    char* longestName;
    while (head != NULL) {
        if (strlen(head->name) > maxLength) {
            maxLength = strlen(head->name);
            longestName = head->name;
        }
        head = head->next;
    }
    printf("Longest name in the list: %s\nLength: %d\n", longestName, maxLength);
}

int main() {
    struct Student* head = NULL;
    int choice, studentNumber, age;
    char name[50], searchName[50];

    while (1) {
        printf("\n1. Add student record\n");
        printf("2. Print all records\n");
        printf("3. Search for a student by name\n");
        printf("4. Delete the next node after a specified name\n");
        printf("5. Find the student with the longest name\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter student number: ");
                scanf("%d", &studentNumber);
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter age: ");
                scanf("%d", &age);
                insertNode(&head, studentNumber, name, age);
                break;
            case 2:
                traverseAndPrint(head);
                break;
            case 3:
                printf("Enter the name to search: ");
                scanf("%s", searchName);
                searchByName(head, searchName);
                break;
            case 4:
                printf("Enter the name after which you want to delete the next node: ");
                scanf("%s", searchName);
                deleteNextNode(head, searchName);
                break;
            case 5:
                findLongestName(head);
                break;
            case 6:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

