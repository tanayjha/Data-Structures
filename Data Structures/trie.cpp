#include <bits/stdc++.h>
using namespace std;
struct trie_node{
	int value; 
	trie_node *child[30];
};
struct trie_node *root;
void initialize(){
	root = (trie_node *)malloc(sizeof(trie_node));
	root->value = 0;
	for(int i = 0; i < 30; i++)
		root->child[i] = NULL;
}
void insert(string s){
	struct trie_node *t = root;
	int l = s.length();
	for(int i = 0; i < l; i++){
		if(t->child[s[i]-'a'] != NULL)
			t = t->child[s[i]-'a'];
		else{
			t->child[s[i]-'a'] = (trie_node *)malloc(sizeof(trie_node));
			t->child[s[i]-'a']->value = 0;
			for(int j = 0; j < 30; j++)
				t->child[s[i]-'a']->child[i] = NULL;
			t = t->child[s[i]-'a'];			
		}
	}
	t->value = 1; 
}
bool search(string s){
	struct trie_node *t = root;
	int l = s.length();
	for(int i = 0; i < l; i++){
		if(t->child[s[i]-'a'] != NULL)
			t = t->child[s[i]-'a'];
		else{
			return 0;			
		}
	}
	if(t->value == 1)
		return 1;
	return 0; 	
}
int main()
{
	initialize();
	insert("hey");
	insert("jude");
	insert("dont");
	insert("make");
	insert("it");
	insert("bad");
	insert("take");
	insert("a");
	cout<<search("bad")<<endl;
	cout<<search("remember")<<endl;
	cout<<search("it")<<endl;
	cout<<search("dont")<<endl;
	cout<<search("take")<<endl;

}