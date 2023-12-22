#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	int height;
	struct node *left;
	struct node *right;
}AVLTREE;

int height(AVLTREE *z){
	if(z==NULL)
	return -1;
	else{
		int lheight , rheight;
		lheight = height(z->left);
		rheight = height(z->right);
		if(rheight>lheight)
			return rheight+1;
		else{
			return lheight+1;
		}	
	}
}

void inorder(AVLTREE *z){
	if(z!=NULL){
	
		inorder(z->left);
		printf("%d   ",z->data);
		inorder(z->right);
		
	}
}

AVLTREE *rightRotate(AVLTREE *z){
	AVLTREE* temp = z ->left;
	z->left = temp ->right;
	temp->right=z;
	z->height=maxValue(height(z->left), height(z->right))+1;
	temp -> height = maxValue (height(temp -> left), height(temp -> right))+1;
	return temp;
}

AVLTREE *leftRotate(AVLTREE *z){
	AVLTREE *temp = z->right;
	z -> right = temp -> left;
	temp->left=z;
	z->height = maxValue(height(z->left), height(z->right))+1;
	temp->height=maxValue(height(temp->left),height(temp->right))+1;
	return temp;
}

AVLTREE *leftRightRotate(AVLTREE *z){
	z->left=leftRotate(z->left);
	return rightRotate(z);
}

AVLTREE *rightLeftRotate(AVLTREE *z){
	z->right=rightRotate(z->right);
	return leftRotate(z);
}
int maxValue(int x,int y){
	if(x>y)
		return x;
	else
		return y;
}

AVLTREE *minValue(AVLTREE* root) {
	AVLTREE *current = root;

    while (current->left != NULL)
        current = current->left;

    return current;
}

AVLTREE* new_node(int x){
	AVLTREE *p;
	p = malloc(sizeof(AVLTREE));
	p->data = x;
	p->left = p->right = NULL;
	
	return p;
}

int getBalance(AVLTREE* origin) {
	if (origin == NULL)
	return 0;
	return height(origin ->left) - height(origin ->right);
}

AVLTREE *insertToAVL(int x, AVLTREE *tree){
	if(tree != NULL){
		if(x < tree -> data)
			tree -> left = insertToAVL(x, tree -> left);
		else if(x > tree -> data)
			tree -> right = insertToAVL(x, tree -> right);
		else
return tree;

	tree -> height = maxValue(height(tree->left), height(tree->right)) + 1;

	if((height(tree->left) - height(tree->right)) > 1 && x < tree->left->data)
	return rightRotate(tree);

	if((height(tree->left) - height(tree->right)) > 1 && x > tree->left->data)
	return leftRightRotate(tree);

	if((height(tree->left) - height(tree->right)) < -1 && x > tree->right->data)
	return leftRotate(tree);

	if((height(tree->left) - height(tree->right)) < -1 && x < tree->right->data)
	return rightLeftRotate(tree);
		}
	else
	tree = new_node(x);
return tree;
}

AVLTREE *deleteNode(AVLTREE *root, int key) {
    if (root == NULL)
        return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        if ((root->left == NULL) || (root->right == NULL)) {
            AVLTREE *temp = root->left ? root->left : root->right;

            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else
                *root = *temp;

            free(temp);
        } else {
            AVLTREE *temp = minValue(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }

    if (root == NULL)
        return root;

    root->height = maxValue(height(root->left), height(root->right)) + 1;

    if (getBalance(root) > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    if (getBalance(root) > 1 && getBalance(root->left) < 0) { 
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (getBalance(root) < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    if (getBalance(root) < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

int main() {
    int x, ch,y;
    AVLTREE* root = NULL;

    while (1) {
        printf("[1] - Insert\n");
        printf("[2] - Delete\n");
        printf("[3] - Height\n");
        printf("[4] - Display\n");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter a number: ");
                scanf("%d", &x);
                root = insertToAVL(x, root);
                break;
            case 2:
                printf("Enter a number for delete: ");
                scanf("%d", &y);
                root=deleteNode(root, y);
                break;
            case 3:
                printf("Height: %d\n", height(root));
                break;
            case 4:
                inorder(root);
                printf("\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}





















