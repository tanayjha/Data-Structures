#include <bits/stdc++.h>
using namespace std;
#define null NULL
const int gamm = 26;

struct node{
  struct node* pi[gamm];
};
struct node * head;

void insert(string s){
  struct node * temp;
  if(head == null) head = (struct node *)malloc(sizeof (struct node));
  temp = head;
  for(int i = 0; i < s.length(); i++){
    if(!temp->pi[s[i]-'a']){
      temp->pi[s[i]-'a'] = (struct node *)malloc(sizeof (struct node));
    }
    temp = temp->pi[s[i]-'a'];
  }
}

int search(string s){
  struct node * temp;
  temp = head;
  for(int i = 0; i < s.length(); i++){
    if(!temp->pi[s[i]-'a']) return 0;
    else{
      temp = temp->pi[s[i]-'a'];
    }
  }
  return 1;
}

int main(int argc, char const *argv[]) {
  string s;
  getline(cin, s);
  string t;
  cin>>t;
  stringstream ss(s);
  while(ss>>s){
    cout<<s;
    insert(s);
  }
  cout<<endl;

  if(search(t) == 1) cout<<"Found"<<endl;
  else cout<<"Not Found"<<endl;

  return 0;
}
