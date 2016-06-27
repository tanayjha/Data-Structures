#include <bits/stdc++.h>
using namespace std;
struct node {
	int value;
	node *next;
};
struct node *head = NULL;

bool isPresent(int element){
	struct node *temp = head;
	while(temp != NULL){
		if(temp->value == element)
			return true;
		temp = temp->next;
	}
	return false;
}

bool isListsorted(){
	struct node *temp = head;
	while(temp != NULL){
		if(temp->next != NULL && temp->value > temp->next->value)
			return false;
		temp = temp->next;
	}
	return true;
}

void insertLL(){
	int element;
	cout<<"Enter the element to be inserted ";
	cin>>element;
	if(head == NULL){
		head = new node;
		head->value = element;
		head->next = NULL;
	}
	else{
		struct node *temp = head;
		while(temp->next != NULL)
			temp = temp->next;
		temp->next = new node;
		temp->next->value = element;
		temp->next->next = NULL;
	}
}

void printLL(){
	cout<<"The list at this point is:\n";
	struct node *temp = head;
	while(temp != NULL){
		cout<<temp->value<<"->";
		temp = temp->next;
	}
	cout<<"X"<<endl;
}

void deleteLL(){
	int element;
	cout<<"Enter the element to be deleted ";
	// In case of repetition first occurence will be deleteLLd
	cin>>element;
	if(!isPresent(element)){
		cout<<"The element is not present in the list\n";
		return;
	}
	struct node *temp = head;
	if(temp->value == element){
		head = temp->next;
		free(temp);
	}
	else{
		while(temp->next != NULL){
			if(temp->next->value == element){
				break;
			}
			temp = temp->next;
		}
			struct node *temp1 = temp->next->next;
			free(temp->next);
			temp->next = temp1;
	}
	cout<<"The list after deletion is\n";
	printLL();
}

void iterrativeLength(){
	struct node *temp = head;
	int len = 1;
	while(temp->next != NULL){
		len++;
		temp = temp->next;
	}
	cout<<"The length of the list is: "<<len<<endl;
}

void recursiveLength(int len, struct node *temp){
	if(temp == NULL){
		cout<<"The length of the list is: "<<len<<endl;
		return;
	}
	recursiveLength(len + 1, temp->next);
}

void swapNodes(){
	int element1, element2;
	cout<<"Enter the elements to be swapped ";
	cin>>element1>>element2;
	if(!isPresent(element1) || !isPresent(element2)){
		cout<<"One/Both elements not present\n";
		return;
	}
	struct node *temp1, *temp2, *temp = head;
	if(head->value == element1 || head->value == element2){
		while(temp->next != NULL){
			if(temp->next->value == element1 || temp->next->value == element2)
				break;
			temp = temp->next;
		}
		temp1 = temp;
		temp2 = temp->next;
		temp1->next = head;
		temp1 = head->next;
		head->next = temp2->next;
		temp2->next = temp1;
		head = temp2;
	}
	else{
		while(temp->next != NULL){
			if(temp->next->value == element1)
				temp1 = temp;
			else if(temp->next->value == element2)
				temp2 = temp;
			temp = temp->next;
		}
		if(temp1->next == temp2 || temp2->next == temp1){
			// (FIXME) In case they are adjacent, just swapping the values for now
			swap(temp->value, temp2->value);	
		}
		else{
			struct node *temp3, *temp4, *temp5;
			temp3 = temp1->next;
			temp4 = temp2->next;
			temp5 = temp3->next;
			temp3->next = temp4->next;
			temp2->next = temp3;
			temp1->next = temp4;
			temp4->next = temp5;
		}
	}
	cout<<"The list after swapping is:\n";
	printLL();
}

void findMiddle(){
	struct node *temp1 = head, *temp2 = head;
	while(temp2->next != NULL && temp2->next->next != NULL){
		temp1 = temp1->next;
		temp2 = temp2->next->next;
	} 
	cout<<"The value of the middle element is: "<<temp1->value<<endl;
}

void nthFromEnd(){
	struct node *temp1 = head, *temp2 = head;
	int count = 1, flag = 0, n;
	cout<<"Enter the value of N: ";
	cin>>n;
	while(1){
		if(count == n)
			flag = 1;
		if(temp1->next == NULL)
			break;
		if(flag)
			temp2 = temp2->next;
		temp1 = temp1->next;
		count++;
	}
	cout<<"The nth element from the end is: "<<temp2->value<<endl;
}

void deleteCompleteLL(){
	struct node *temp1 = head, *temp2;
	while(temp1->next != NULL){
		temp2 = temp1->next;
		free(temp1);
		temp1 = temp2;
	}
	free(temp1);
	head = NULL;
	printLL();
}

void noOfOccurence(){
	int n, ans = 0;
	cout<<"Enter the number whose occurence you want to count: ";
	cin>>n;
	struct node *temp = head;
	while(temp != NULL){
		if(temp->value == n)
			ans++;
		temp = temp->next;
	}
	cout<<"The no. of occurences of "<<n<<" is "<<ans<<endl;
}

void reverseLLIterative(){
	struct node *prev = NULL, *cur = head, *future = cur->next;
	while(cur != NULL){
		cur->next = prev;
		prev = cur;
		cur = future;
		if(future)
			future = future->next;
	}
	head = prev;
	printLL();
}

struct node *reverseLLRecursive(struct node *cur, struct node *prev){
	if(cur == NULL)
		return prev;
	struct node *temp = cur->next;
	cur->next = prev;
	temp = reverseLLRecursive(temp, cur);
}

void checkPalindrome(){
	struct node *temp1 = head, *temp2 = head, *temp3 = head, *prev, *temp4;
	int f = 0;
	if(head == NULL){
		cout<<"The list is empty\n";
		return;
	}
	while(temp2 != NULL && temp2->next != NULL){
		prev = temp1;
		temp1 = temp1->next;
		temp2 = temp2->next->next;
	}
	temp2 = reverseLLRecursive(temp1->next, temp1);
	temp4 = temp2;
	temp1->next = NULL;
	while(temp2 != NULL){
		if(temp3->value != temp2->value){
			f = 1;
			break;
		}
		temp2 = temp2->next;
		temp3 = temp3->next;
	}
	if(f)
		cout<<"Not a palindrome\n";
	else
		cout<<"It is a palindrome\n";
	temp1 = reverseLLRecursive(temp4, NULL);
}

void printReverseRecurse(struct node *temp){
	if(temp == NULL){
		cout<<"X\n";
		return;
	}
	printReverseRecurse(temp->next);
	cout<<temp->value<<"->";
}

void removeDuplicates(){
	if(!isListsorted()){
		cout<<"The list is not sorted\n";
		return;
	}
	else{
		struct node *temp = head, *temp1;
		while(temp != NULL){
			if(temp->next != NULL && temp->value == temp->next->value){
				 temp1 = temp->next;
				free(temp->next);
				temp->next = temp1->next;
			}
			temp = temp->next;
		}
		printLL();
	}
}

void pairwiseSwap(struct node *temp1){
	if(temp1 == NULL){
		return;
	}
	if(temp1->next != NULL){
		swap(temp1->value, temp1->next->value);
		pairwiseSwap(temp1->next->next);
	}
}

void deleteAlternate(){
	struct node *temp = head;
	while(temp != NULL){
		if(temp->next != NULL){
			struct node *temp1;
			temp1 = temp->next;
			free(temp->next);
			temp->next = temp1->next;
		}
		temp = temp->next;
	}
	printLL();
}


// FIXME
struct node *reverseInGroups(struct node *temp, int k){
	int count = 0;
	struct node *cur = temp, *prev = NULL, *future = NULL;
	while(cur != NULL){
		future = cur->next;
		cur->next = prev;
		prev = cur;
		cur = future;
		count++;
		if(count == k)
			break;
	}
	if(future != NULL)
		cur->next = reverseInGroups(future, k);
	return prev;
}

void deleteGreaterRight(){
	struct node *temp = head, *temp1;
	while(temp != NULL){
		if(temp->next != NULL && temp->value < temp->next->value){
			swap(temp->value, temp->next->value);
			temp1 = temp->next;
			free(temp->next);
			temp->next = temp1->next;
		}
		temp = temp->next;
	}
	printLL();
}

int main()
{
	int choice;
	while(1){
		cout<<"Enter your choice\n";
		cout<<"1. Enter an element in the linked list\n";
		cout<<"2. Print the linked list\n";
		cout<<"3. Delete an element from the linked list\n";
		cout<<"4. Find the length of the linked list(Iterative)\n";
		cout<<"5. Find the length of the linked list(Recusive)\n";
		cout<<"6. Swap nodes without swapping data\n";
		cout<<"7. Print the value of the middle element of the list\n";
		cout<<"8. Find Nth element from the end\n";
		cout<<"9. Delete the linked list\n";
		cout<<"10. No. of occurence of an integer in the list\n";
		cout<<"11. Reverse a linked list(Iterative)\n";
		cout<<"12. Reverse a linked list(Recursive)\n";
		cout<<"13. Check if list is a palindrome\n";
		cout<<"14. Print reverse of a list recursively\n";
		cout<<"15. Remove duplicates from a sorted list\n";
		cout<<"16. Pairwise swap the elements of the list\n";
		cout<<"17. Delete alternate nodes of the list\n";
		cout<<"18. Reverse the list in groups\n";
		cout<<"19. Delete nodes with greater value on right\n";
		cout<<"20. Segregate even and odd in the list\n";
		cin>>choice;
		switch(choice){
			case 1:
				insertLL();
				break;
			case 2:
				printLL();
				break;
			case 3:
				deleteLL();
				break;
			case 4:
				iterrativeLength();
				break;
			case 5:
				recursiveLength(0, head);
				break;
			case 6:
				swapNodes();
				break;
			case 7:
				findMiddle();
				break;
			case 8:
				nthFromEnd();
				break;
			case 9:
				deleteCompleteLL();
				break;
			case 10:
				noOfOccurence();
				break;
			case 11:
				reverseLLIterative();
				break;
			case 12:
				head = reverseLLRecursive(head, NULL);
				printLL();
				break;
			case 13:
				checkPalindrome();
				break;
			case 14:
				printReverseRecurse(head);
				break;
			case 15:
				removeDuplicates();
				break;
			case 16:
				pairwiseSwap(head);
				printLL();
				break;
			case 17:
				deleteAlternate();
				break;
			case 18:
				int k;
				cout<<"Enter the size of the goups: ";
				cin>>k;
				// head = reverseInGroups(head, k);
				printLL();
				break;
			case 19:
				deleteGreaterRight();
				break;
			default:
				return 0;
		}
	}
}