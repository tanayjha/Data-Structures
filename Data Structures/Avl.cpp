#include <bits/stdc++.h>
using namespace std;
struct node{
	int data;
	struct node *left;
	struct node *right;
	int height;
};
struct node* createNode(int n){
	struct node *newNode = (struct node *)(malloc(sizeof(struct node)));
	newNode->data = n;
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->height = 1;
	return newNode;
}
int getHeight(struct node *temp){
	if(temp == NULL)
		return 0;
	else
		return temp->height;
}
int getBalance(struct node *temp){
	if(temp == NULL)
		return 0;
	return getHeight(temp->left) - getHeight(temp->right);

}
struct node* rightRotate(struct node *temp){
	struct node *temp1 = temp->left;
	struct node *temp2 = temp1->right;

	temp1->right = temp;	// Rotations
	temp->left = temp2;

	temp->height = max(getHeight(temp->left), getHeight(temp->right))+1;
	temp1->height = max(getHeight(temp1->left), getHeight(temp1->right))+1;
	return temp1;	// Return new root
}

struct node* leftRotate(struct node *temp){
	struct node *temp1 = temp->right;
	struct node *temp2 = temp1->left;

	temp1->left = temp;	// Rotations
	temp->right = temp2;

	temp->height = max(getHeight(temp->left), getHeight(temp->right))+1;
	temp1->height = max(getHeight(temp1->left), getHeight(temp1->right))+1;
	return temp1;	// Return new root

}

struct node* inorderSuccesor(struct node *temp){
	while(temp->left != NULL){
		temp = temp->left;
	}
	return temp;
}

struct node* insert(struct node *temp, int n){	// Insertion in AVL tree
	if(temp == NULL)
		return createNode(n);

	if(temp->data > n)
		temp->left = insert(temp->left, n);
	else
		temp->right = insert(temp->right, n);

	temp->height = max(getHeight(temp->left), getHeight(temp->right)) + 1;

	int balance = getBalance(temp);

	if(balance > 1 && temp->left->data > n){ // Left Left case
		return rightRotate(temp);
	}
	if(balance > 1 && temp->left->data < n){  // Left Right case
		temp->left = leftRotate(temp->left);
		return rightRotate(temp);
	}
	if(balance < -1 && temp->right->data < n){ // Right Right case
		return leftRotate(temp);
	}
	if(balance < -1 && temp->right->data > n){  // Right Left case
		temp->right = rightRotate(temp->right);
		return leftRotate(temp);
	}
	return temp;
}

struct node* deletion(struct node *temp, int n){	// Deletion in AVL tree
	if(temp == NULL)
		return temp;
	if(n < temp->data)
		temp->left = deletion(temp->left, n);
	else if(n > temp->data)
		temp->right = deletion(temp->right, n);

	else{	// Standard BST delete
		if((temp->left == NULL) || (temp->right == NULL)){
			struct node *temp1 = (temp->left)?(temp->left):(temp->right);
			if(temp1 == NULL){	// No Child
				temp1 = temp;
				temp = NULL; 
			}
			else	// One Child
				*temp = *temp1;
			free(temp1);
		}		
		else{	// Two Children
			struct node *temp1 = inorderSuccesor(temp->right);
			temp->data = temp1->data;
			temp->right = deletion(temp->right, temp1->data);
		}
	}
	if(temp == NULL)
		return temp;
	temp->height = max(getHeight(temp->left), getHeight(temp->right)) + 1;
	int balance = getBalance(temp);
	if(balance > 1 && getBalance(temp->left) >= 0)	// Left Left case
		return rightRotate(temp);
	if(balance > 1 && getBalance(temp->left) < 0){	// Left Right Case
		temp->left = leftRotate(temp->left);
		return rightRotate(temp);
	}
	if(balance < -1 && getBalance(temp->right) <= 0)	// Right Right Case
		return leftRotate(temp);
	if(balance < -1 && getBalance(temp->right) > 0){	// Right Left Case
		temp->right = rightRotate(temp->right);
		return leftRotate(temp);
	}
	return temp;
}

void inorderTraversal(struct node *temp){
	if(temp == NULL)
		return;
	inorderTraversal(temp->left);
	printf("%d ", temp->data);
	inorderTraversal(temp->right);
}
int main()
{
	struct node *root = NULL;
	root = insert(root, 50);
	root = insert(root, 30);
	root = insert(root, 20);
	root = insert(root, 70);
	root = insert(root, 40);
	root = insert(root, 80);
	root = insert(root, 60);
	root = deletion(root, 40);
	root = deletion(root, 50);
	inorderTraversal(root);

}