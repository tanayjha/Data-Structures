#include <bits/stdc++.h>
using namespace std;
int vis[100000], noOfCycles;
vector <int> graph[100000];
void detectCycle(int node){
	if(vis[node]){
		noOfCycles++;
		return;
	}
	vis[node] = 1;
	for(vector <int>::iterator it = graph[node].begin(); it != graph[node].end(); it++){
		detectCycle(*it);
	}
}
int main()
{
	int n, a, b, e;
	cin>>n>>e;
	for(int i = 0; i < e; i++){
		cin>>a>>b;
		graph[a].push_back(b);
	}
	for(int i = 1; i <= n; i++){
		if(!vis[i])
			detectCycle(i);
	}
	cout<<noOfCycles<<" cycles found!\n"
}