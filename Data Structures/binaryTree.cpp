#include <bits/stdc++.h>
using namespace std;
int arr[100000];
struct node {
	int data;
	struct node *left, *right;
};
struct node *root = NULL, *temp;
void insert(struct node **temp, int x){
	if(root == NULL){
		root = new node;
		root->data = x;
		root->left = NULL;
		root->right = NULL;
	}
	else{
		(*temp) = new node;
		(*temp)->data = x;
		(*temp)->left = NULL;
		(*temp)->right = NULL;
	}
}
int sizeTree(struct node *temp){
	if(temp == NULL)
		return 0;
	return  sizeTree(temp->left) + 1 + sizeTree(temp->right); 
}
int maxDepth(struct node *temp){
	if(temp == NULL)
		return 0;
	return 1 + max(maxDepth(temp->left), maxDepth(temp->right));
}
void printArray(int path[], int l){
	for(int i = 0; i < l; i++){
		cout<<path[i]<<" ";
	}
	cout<<endl;
}
void rootToLeafPaths(struct node *temp, int path[], int pathLength){
	if(temp == NULL)
		return;
	path[pathLength] = temp->data;
	pathLength++;
	if(temp->left == NULL and temp->right == NULL){
		printArray(path, pathLength);
	}
	rootToLeafPaths(temp->left, path, pathLength);
	rootToLeafPaths(temp->right, path, pathLength);
}
void printPath(struct node *temp){
	int path[10000];
	rootToLeafPaths(temp, path, 0);
}
void printLevelOrder(struct node *temp){
	queue <struct node *> q;
	while(temp != NULL){
		printf("%d ", temp->data);
		if(temp->left)
			q.push(temp->left);
		if(temp->right)
			q.push(temp->right);
		temp = q.front();
		q.pop();
	}
}
void printSpiralLevelOrder(struct node *temp){
	stack <struct node *> s1, s2;
	s1.push(temp);
	while(!s1.empty() || !s2.empty()){
		while(!s1.empty()){
			temp = s1.top();
			s1.pop();
			printf("%d ", temp->data);
			if(temp->right)
				s2.push(temp->right);
			if(temp->left)
				s2.push(temp->left);
		}
		while(!s2.empty()){
			temp = s2.top();
			s2.pop();
			printf("%d ", temp->data);
			if(temp->left)
				s1.push(temp->left);
			if(temp->right)
				s1.push(temp->right);
		}
	}
}
bool isHeightBalanced(struct node *temp){
	if(temp == NULL)
		return true;
	int lDepth = maxDepth(temp->left);
	int rDepth = maxDepth(temp->right);
	if(abs(lDepth - rDepth)<=1 && isHeightBalanced(temp->left) && isHeightBalanced(temp->right))
		return true;
	return false;
}
int diameter(struct node *temp){
	if(temp == NULL)
		return 0;
	int lDepth = maxDepth(temp->left);
	int rDepth = maxDepth(temp->right);
	return max(max(diameter(temp->left), diameter(temp->right)), lDepth+rDepth+1);
}
void inOrderWithoutRecursion(struct node *temp){
	stack <struct node* > s;
	bool done = false;
	while(!done){
		if(temp != NULL){
			s.push(temp);
			temp = temp->left;
		}
		else{
			if(!s.empty()){
				temp = s.top();
				s.pop();
				printf("%d ", temp->data);
				temp = temp->right;
			}
			else
				done = 1;
		}
	}

}
bool rootToLeafSum(struct node *temp, int num){
	if(temp == NULL){
		if(num == 0)
			return true;
		else
			return false;
	}
	if(rootToLeafSum(temp->left, num-temp->data) || rootToLeafSum(temp->right, num-temp->data))
		return true;
	return false;
}
int getMaxWidth(struct node *temp){
	queue <struct node *> q;
	q.push(temp);
	int ans = 0;
	while(!q.empty()){
		int count = q.size();
		ans = max(ans, count);
		while(count--){
			temp = q.front();
			q.pop();
			if(temp->left)
				q.push(temp->left);
			if(temp->right)
				q.push(temp->right);
		}
	}
	return ans;
}
int main()
{
	insert(&root, 1);
	insert(&root->left, 2);
	insert(&root->right, 3);
	insert(&root->left->left, 4);
	insert(&root->left->right, 5);
	insert(&root->right->left, 6);
	//insert(&root->right->right, 7);
	insert(&root->right->left->left, 10);
	//cout<<sizeTree(root)<<endl;  //Number of nodes in the tree
	//cout<<maxDepth(root)<<endl;  //Maximum Depth of the tree
	//cout<<root->data<<" "<<root->left->data<<" "<<root->right->data<<" "<<root->right->left->data<<endl;
	//printPath(root);  //Prints root to leaf Path one per line
	//printLevelOrder(root); //Prints the level order traversal
	//printSpiralLevelOrder(root); //Prints the spiral level order traversal
	//cout<<diameter(root)<<endl; //Prints the length of the diameter of the tree
	//cout<<isHeightBalanced(root)<<endl; //Checks if the binary tree is Height Balanced
	//inOrderWithoutRecursion(root); //Prints inorder traversal using stack
	//cout<<rootToLeafSum(root, 20)<<endl; //Prints if there exists a root to leaf path with the given sum.
	cout<<getMaxWidth(root)<<endl; //Gets the maximum width of the tree over all levels
}