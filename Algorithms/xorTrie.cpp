#include <bits/stdc++.h>
using namespace std;
#define null NULL
const int gamm = 2;

struct node{
  struct node* pi[gamm];
  int count;
};
struct node * head;

void insert(int x){
  struct node * temp;
  if(head == null){ 
    head = (struct node *)malloc(sizeof (struct node));
    head->pi[0] = NULL;
    head->pi[1] = NULL;
    head->count = 0;
  }
  temp = head;
  for(int i = 31; i >= 0; i--){
    int val = 0;
    if((1<<i)&x)
      val = 1;
    if(!temp->pi[val]){
      temp->pi[val] = (struct node *)malloc(sizeof (struct node));
      temp->pi[val]->pi[0] = NULL;
      temp->pi[val]->pi[1] = NULL;
      temp->pi[val]->count = 0;
    }  
    temp = temp->pi[val];
    temp->count++;
  }
}

void remove(int x){
  struct node * temp;
  temp = head;
  for(int i = 31; i >= 0; i--){
    int val = 0;
    if((1<<i)&x)
      val = 1;
    temp = temp->pi[val];
    temp->count--;
  }
}

int solve(int x){
  struct node * temp;
  int result = 0;
  temp = head;
  for(int i = 31; i >= 0; i--){
    int val = 0;
    if((1<<i)&x)
      val = 1;
    if(!temp->pi[(val+1)%2] || (temp->pi[(val+1)%2] != NULL && temp->pi[(val+1)%2]->count == 0)){
      temp = temp->pi[val];
    } else {
      temp = temp->pi[(val+1)%2];
      result += pow(2, i);
    }
  }
  return result;
}

int main() {
  int n, x;
  char c;
  cin>>n;
  insert(0);
  while(n--){
    cin>>c>>x;
    if(c == '+')
      insert(x);
    else if(c == '-')
      remove(x);
    else{
      int ans = solve(x);
      cout<<ans<<endl;
    }
  }
}
