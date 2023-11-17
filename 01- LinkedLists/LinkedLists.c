#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int number;
	struct Node * next;
}node; 
node *head;
node *p;

node* addnode(node* head){
	int nodes,i;
	printf("How many nodes you want to add ?\n");
	scanf("%d" ,&nodes);
	p = head;
	
	for(i=0; i<nodes; i++){
		if(head == NULL){
			head = (node*)malloc(sizeof(node));
			p = head;
		}
		else{
			while(p->next != NULL){
				p=p->next;
			}
			p->next = (node*)malloc(sizeof(node));
			p=p->next;
		}
		p->next = NULL;
		printf("Enter %d. node :" ,i+1);
		scanf("%d" ,&p->number);
	
	}
	
	p->next = NULL;
	return head;
}

void printlist(){
	printf("--------------------------------\n");
	int ct = 0;
	p = head;
	if(p==NULL){
		printf("No Records Found\n");
		printf("--------------------------------\n");
		return;
	}
	while(p!=NULL){
		printf("%d. node : %d\n" ,ct+1,p->number);
		p=p->next;	
		ct++;
	}	
printf("--------------------------------\n");	
}

node* cutlastaddhead(node* head){
	p=head;
	node* prev = NULL;
	node* curr = NULL;
	node* temp = NULL;
	
	if(p->next == NULL || p == NULL){
		printf("Enter nodes first");
		return NULL;
	}
	else{
	while(p->next!=NULL){
		temp = p;
		prev = temp;
		p = p->next;
		curr = p;
		}
	curr->next = head;	
	prev->next = NULL;	
	head = curr;		
	}
	return head;
}

node* deletemiddle(node* head){
	node*temp2 = NULL;
	int counter=0,i;
	p = head;
	while(p->next != NULL){
		counter++;
		p=p->next;
	}
	p = head;
	for(i=0; i<(counter/2); i++){
		temp2 = p;
		p = p->next;
	}
	temp2->next = p->next;
	free(p);
	
	return head;
}

node* changeFirstAndLast(node* head){
	node* prev2 = NULL;
	node* nh = head->next;
	p = head;
	
	while(p->next != NULL){
		prev2 = p;
		p=p->next;
	}
	p->next = (node*)malloc(sizeof(node));
	p->next = nh;
	prev2->next = head;
	head->next = NULL;
	head = p;
	
	return head;
}

int main() {
    int choice;

    while (1) {
        printf("Select an option:\n");
        printf("1 - Add record\n");
        printf("2 - Show all records\n");
        printf("3 - Cut the last node and add it to the head\n");
        printf("4 - Delete the middle node\n");
        printf("5 - Change first and last nodes\n");
        printf("0 - Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                head = addnode(head);
                break;
            case 2:
                printlist();
                break;
            case 3:
                head = cutlastaddhead(head);
                break;
            case 4:
                head = deletemiddle(head);
                break;
            case 5:
                head = changeFirstAndLast(head);
                break;
            case 0:
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    }
    return 0;
}


 
