#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

typedef struct node *BTREE;

BTREE insert(BTREE root, int x) {
    if (root == NULL) {
        BTREE new_node = malloc(sizeof(struct node));
        new_node->left = new_node->right = NULL;
        new_node->data = x;
        return new_node;
    }

    if (root->data < x) {
        root->right = insert(root->right, x);
        return root;
    } else if (root->data > x) {
        root->left = insert(root->left, x);
        return root;
    }
    return root;
}

void traverse(BTREE root) {
    if (root == NULL)
        return;
    printf("%d\t", root->data);
    traverse(root->left);
    traverse(root->right);
}

int size(BTREE root) {
    if (root == NULL)
        return 0;
    return size(root->left) + size(root->right) + 1;
}

int countParents(BTREE root) {
    if (root == NULL)
        return 0;
    int parent_say = 0;
    if (root->left != NULL || root->right != NULL)
        parent_say++;
    parent_say += countParents(root->left);
    parent_say += countParents(root->right);
    return parent_say;
}

int bul(BTREE root, int aranan) {
    if (root == NULL)
        return -1;
    if (root->data == aranan)
        return 1;
    if (bul(root->left, aranan) == 1)
        return 1;
    if (bul(root->right, aranan) == 1)
        return 1;
    return -1;
}

void printTree(BTREE root, int level) {
	int i;
    if (root == NULL) {
        return;
    }
    printTree(root->right, level + 1);
    for (i = 0; i < level; i++) {
        printf("\t");
    }
    printf("%d\n", root->data);
    printTree(root->left, level + 1);
}

	int depth_nodes(BTREE root, int depth){
		if(root == NULL)
			return 0;
		if(depth==0)
			return 1;
		else{
			return depth_nodes(root->left,depth-1) + depth_nodes(root->right,depth-1);
		}		
	}
	
	void mirror(BTREE root){
		if(root == NULL)
			return;
		else{
			BTREE temp;
			temp = root->left;
			root->left = root->right;
			root->right = temp;
			mirror(root->left);
			mirror(root->right);
		}	
	}
	
	BTREE Delete(BTREE root,int x){
	BTREE p,q;
	if(root==NULL)
		return NULL;
	if(root->data ==x ){
		if(root->left==root->right){
			free(root);
			return NULL;
		}
		else{
			if(root->left==NULL){
				p=root->right;
				free(root);
				return p;
			}
			else if(root->right==NULL){
				p=root->left;
				free(root);
				return p;
			}
			else{
				p=root->right;
				while(p->left!=NULL){
					p=p->left;
				}
			p->left = p->right;
			free(root);
			return q;
					
			}
	}
		}
	
	if(root->data<x){
		root->right = Delete(root->right,x);
	}
	else{
		root->left = Delete(root->right,x);
	}

}

int height(BTREE root){
	if(root==NULL)
	return -1;
	else{
		int lheight , rheight;
		lheight = height(root->left);
		rheight = height(root->right);
		if(rheight>lheight)
			return rheight+1;
		else{
			return lheight+1;
		}	
	}
}

void inorder(BTREE root){
	if(root!=NULL){
	
		inorder(root->left);
		printf("%d   ",root->data);
		inorder(root->right);
		
	}
}
int menu() {
    int choice;
    printf("\nBinary Tree Operations:\n");
    printf("1. Add node to the tree\n");
    printf("2. Display tree\n");
    printf("3. Count nodes in the tree\n");
    printf("4. Count parent nodes in the tree\n");
    printf("5. Search for a node in the tree\n");
    printf("6. Find number of nodes in a given depth\n");
    printf("7. Mirror \n");
    printf("8. Delete node  \n");
    printf("9. Height \n");
    printf("10. Inorder sorting \n");
    printf("0. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

int main() {
    BTREE root = NULL;
    int value, result,depth,del;

    while (1) {
        switch (menu()) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;
            case 2:
                printf("Binary Tree Structure:\n");
                printTree(root, 0);
                break;
            case 3:
                printf("Number of nodes in the tree = %d\n", size(root));
                break;
            case 4:
                printf("Number of parent nodes in the tree = %d\n", countParents(root));
                break;
            case 5:
                printf("Enter value to search: ");
                scanf("%d", &value);
                result = bul(root, value);
                if (result == 1) {
                    printf("Node found in the tree.\n");
                } else {
                    printf("Node not found in the tree.\n");
                }
            case 6:
				printf("Enter a depth :");
				scanf("%d" ,&depth);
				printf("Number of nodes in a given depth : %d" ,depth_nodes(root,depth)); 
                break;
            case 7:
				mirror(root);
				break;   
			case 8:
				printf("Enter node to delete : ");
				scanf("%d" ,&del);
				Delete(root,del);
				break;	
			case 9:
				printf("Height is %d\n" ,height(root));	
				break;
			case 10:
				inorder(root);
				break;		 
            case 0:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    }
    return 0;
}
