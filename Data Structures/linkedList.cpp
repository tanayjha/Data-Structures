#include <bits/stdc++.h>
using namespace std;
struct node{
    int data;
    struct node *next;
};
struct node *head = NULL, *temp = NULL, *prev = NULL, *temp1, *temp2 = NULL, *temp3, *temp4, *jugaad;
void insert(int n){
    if(head == NULL){
        head = (node *)(malloc(sizeof(node)));
        head->data = n;
        head->next = NULL;
    }
    else{
        temp = head;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        //cout<<temp->data<<endl;
        temp->next = (node *)(malloc(sizeof(node)));
        temp->next->data = n;
        temp->next->next = NULL;
    }
}
void swapAdj(struct node *temp){
    if(temp->next == NULL || temp == NULL || temp->next->next == NULL)
        return;
    temp->next = temp->next->next;
    swapAdj(temp->next);
}
void reverseList(struct node *temp, struct node *prev){
	if(temp == NULL){
		head = prev;
		return;
	}
	node *t = temp->next;
	temp->next = prev;
	prev = temp;
	reverseList(t, prev);
}
void printList(){
    temp = head;
    while(temp->next != NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<temp->data<<endl;
}
int main(){
    int ch, n, x, y;
    while(1){
        cout<<"Do you want to add a element(1/0) ";
        cin>>ch;
        if(ch == 0){
            break;
        }
        else{
            cout<<"Enter the element ";
            cin>>n;
            insert(n);
        }
    }
    printList();
    reverseList(head, NULL);
    //swapAdj(head);
    printList();
}