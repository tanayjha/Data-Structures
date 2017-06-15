// Valid only for directed acyclic graphs (DAG)
#include <bits/stdc++.h>
using namespace std;
vector <int> graph[100000];
void topoSort(int node, bool vis[], stack<int> &s){
	vis[node] = true;
	for(vector<int>::iterator it = graph[node].begin(); it != graph[node].end(); it++){
		if(!vis[*it])
			topoSort(*it, vis, s);
	}
	s.push(node);
}
int main()
{
	int n, e, a, b;
	cin>>n>>e;
	bool vis[n+1];
	for(int i = 1; i <= n; i++)
		vis[i] = false;
	for(int i = 0; i < e; i++){
		cin>>a>>b;
		graph[a].push_back(b);
	}
	stack <int> s;
	for(int i = 1; i <= n; i++){
		if(!vis[i])
			topoSort(i, vis, s);
	}
	while(!s.empty()){
		cout<<s.top()<<" ";
		s.pop();
	}
	cout<<"\n";
}