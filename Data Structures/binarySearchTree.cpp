#include <bits/stdc++.h>
using namespace std;
struct node {
	struct node *left;
	struct node *right;
	int data;
};
struct node *root = NULL;
void insert(int n){
	if(root == NULL){
		root = (node *)malloc(sizeof(node));
		root->data = n;
		root->left = NULL;
		root->right = NULL;
	}
	else{
		struct node *temp = root, *par = NULL;
		while(temp != NULL){
			par = temp;
			if(temp->data > n)
				temp = temp->left;
			else
				temp = temp->right;
		}
		if(par->data > n){
			par->left = (node *)malloc(sizeof(node));
			par->left->data = n;
			par->left->left = NULL;
			par->left->right = NULL;
		}
		else{
			par->right = (node *)malloc(sizeof(node));
			par->right->data = n;
			par->right->left = NULL;
			par->right->right = NULL;

		}
	}
}
bool search(int key){
	struct node *temp = root;
	while(temp != NULL){
		if(temp->data > key)
			temp = temp->left;
		else if(temp->data < key)
			temp = temp->right;
		else
			return true;
	}
	return false;
}
void deleteNode(int n){
	struct node *temp = root, *par = root, *temp1;
	while(temp != NULL){
		temp1 = temp;
		if(temp->data > n)
			temp = temp->left;
		else if(temp->data < n)
			temp = temp->right;
		else
			break;
		par = temp1;
	}
	bool LorR;
	if(par->left->data == temp->data)
		LorR = 0;
	else
		LorR = 1;
	if(temp->left == NULL && temp->right == NULL){  // Deleting a leaf
		if(LorR)
			par->right = NULL;
		else
			par->left = NULL;
	}
	else if(temp->left == NULL && temp->right != NULL){  // Deleting a node with only the right child
		temp->data = temp->right->data;
		temp->right = NULL;	
	}
	else if(temp->left != NULL && temp->right == NULL){  // Deleting a node with only the left child
		temp->data = temp->left->data;
		temp->left = NULL;	
	}
	else{												 // Deleting a node with both childrens
		struct node *inorderSuccessor = temp->right;
		par = temp;
		while(inorderSuccessor->left != NULL){   		 // Finding the inorder succesor
			struct node *temp1 = inorderSuccessor;
			inorderSuccessor = inorderSuccessor->left;
			par = temp1;
		}
		if(par->left->data == inorderSuccessor->data)
			LorR = 0;
		else
			LorR = 1;
		temp->data = inorderSuccessor->data;
		if(LorR)
			par->right = NULL;
		else
			par->left = NULL;	
	}
}
void inorder(struct node *temp){
	if(temp == NULL)
		return;
	inorder(temp->left);
	printf("%d ", temp->data);
	inorder(temp->right);

}
int smallestNode(){
	struct node *temp = root;
	while(temp->left != NULL)
		temp = temp->left;
	return temp->data;
}
int lca(int x, int y){
	struct node *temp = root;
	while(1){
		if(temp->data>x && temp->data <y)
			return temp->data;
		else if(temp->data > max(x, y))
			temp = temp->left;
		else
			temp = temp->right;
	}
}
int printCielValue(int n){
	struct node *temp = root;
	int ans = -1;
	while(temp != NULL){
		if(temp->data == n)
			return temp->data;
		else if(temp->data > n){
			ans = temp->data;
			temp = temp->left;
		}
		else
			temp = temp->right;
	}
	return ans;
}
int printFloorValue(int n){
	int ans = -1;
	struct node *temp = root;
	while(temp != NULL){
		if(temp->data == n)
			return temp->data;
		else if(temp->data < n){
			ans = temp->data;
			temp = temp->right;
		}
		else{
			temp = temp->left;
		}
	}
	return ans;
}
int main()
{
	insert(50);
	insert(70);
	insert(30);
	insert(20);
	insert(40);
	insert(60);
	insert(80);
	//inorder(root);	// Print the inorder traversal
	//cout<<search(500)<<endl; // Hit
	//cout<<search(300)<<endl; // Miss
	/*deleteNode(20);  // Deletion No child
	deleteNode(30);	   // Deletion 1 child
	deleteNode(50);	   // Deletion no childrens
	cout<<endl;
	inorder(root);*/
	//cout<<smallestNode()<<endl;  // Prints the node with the smallest value
	//cout<<lca(40, 60)<<endl;  // Prints the lowest common ancestor
	cout<<printCielValue(33)<<" "<<printFloorValue(33)<<endl; // Prints the cieling value and floor value
}