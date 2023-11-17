#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define STACK_SIZE 5

typedef struct {
    int top;
    int data[STACK_SIZE];
} stack;

int pop(stack *stk);
void push(stack *stk, int x);
void reset(stack *stk);
int menu();
void displayStack(stack *stk);

int main() {
    stack s;
    reset(&s);
	
    while (1) {
        switch (menu()) {
            case 1:
                printf("Enter the number you want to push: ");
                int x;
                scanf("%d", &x);
                push(&s, x);
                break;

            case 2:
                printf("Popped element: %d\n", pop(&s));
                break;

            case 3:
                displayStack(&s);
                break;

            case 4:
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}

void reset(stack *stk) {
    stk->top = -1;
}

int pop(stack *stk) {
    if (stk->top == -1) {
        printf("Stack is Empty\n");
        return -1;
    } else {
        int x = stk->data[stk->top];
        stk->top--;
        return x;
    }
}

void push(stack *stk, int x) {
    if (stk->top == STACK_SIZE - 1) {
        printf("Stack is FULL\n");
    } else {
        stk->data[++stk->top] = x;
        printf("Element %d pushed to the stack.\n", x);
    }
}

int menu() {
    int choice;
    printf("\nStack Operations:\n");
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Display Stack\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

void displayStack(stack *stk) {
	int i;
    if (stk->top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements: ");
        for (i = stk->top; i >= 0; i--) {
            printf("%d ", stk->data[i]);
        }
        printf("\n");
    }
}

