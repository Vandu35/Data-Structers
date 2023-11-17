#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define QUEUE_SIZE 5

void initalize();
int isEmpty();
int isFull();
void enqueue();
int dequeue();
int menu();
void displayQueue();

typedef struct node {
    int data;
    struct node* next;
} node;

typedef struct {
    node *front;
    node *rear;
    int cnt;
} queue;


int main(){
	queue q;
	int x;
	initalize(&q);
	while(1){
		switch(menu()){
			case 1:
				printf("Enter a number that you want to add in queue");
				scanf("%d" ,&x);
				enqueue(&q,x);
				printf("Number added in queue");
				break;
			case 2:
				 dequeue(&q);
				printf("Number deleted from queue");
				break;
			case 3:
				displayQueue(&q);
				break;
			case 4:
				exit(0);
			default:
				printf("Please enter a valid option");		
				break;
		}
	}
	return 0;
}
int menu() {
    int choice;
    printf("\nQueue Operations:\n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Display Queue\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}
void initalize(queue *q){
	q->rear = q->front = NULL;
	q->cnt;	
}

int isEmpty(queue *q) {
    return q->cnt == 0;
}

int isFull(queue *q) {
    return q->cnt == QUEUE_SIZE;
}

void enqueue(queue *q,int x){
	if(isFull(q)){
		printf("Queue is Full");
	}
	struct node *temp = malloc(sizeof(struct node));
	temp->data = x;
    temp->next = NULL;
    if(isEmpty(q)) {
        q->front = q->rear = temp;
    } else {
        q->rear->next = temp;
        q->rear = temp;
    }
    q->cnt++;
}

int dequeue(queue *q) {
    if(isEmpty(q)) {
        printf("Queue is Empty");
        return 0;
    } else {
        node* temp = q->front;
        int x = temp->data;
        q->front = q->front->next;
        free(temp);
        q->cnt--;
        return x;
    }
}

void displayQueue(queue *q) {
    if (q->front == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    struct node *traverse = q->front;
    while (traverse != NULL) {
        printf("%d ", traverse->data);
        traverse = traverse->next;
    }
    printf("\n");
}

	
	
	
	
	
	
	

	
	
	
	
	
	










