#include <bits/stdc++.h>
using namespace std;
#define MAX 10000
#define edge pair< int,int >
vector< pair<int,edge> >G,MST;
int parent[MAX];
void reset(int n)
{
	G.clear();
	MST.clear();
	for(int i=0;i<=n;i++)
		parent[i]=i;
}
int find(int x)
{
	if(x!=parent[x])
		parent[x]=find(parent[x]);
	return parent[x];
}
int main()
{
	int n, e, u, v, w, pu, pv, total = 0;
	printf("Enter the number of vertices in the graph ");
	scanf("%d", &n);
	printf("Enter the number of edges in the graph ");
	scanf("%d", &e);
	reset(n);
	printf("Enter the edges with the weights\n");
	for(int i=0;i<e;i++)
	{
		printf("%d%d%d", &u, &v, &w);
		G.push_back(pair<int,edge >(w,make_pair(u,v)));// w(u,v) format
	}
 	sort(G.begin(), G.end());    //sort will be done in increasing order of weight
	for(int i=0;i<e;i++)
	{
		pu = find(G[i].second.first); 
		pv = find(G[i].second.second);
		if((pu) != (pv))
		{
			MST.push_back(G[i]);
			total += G[i].first;
			parent[pu] = parent[pv];
		}
	}
	for(int i=0;i<MST.size();i++)
	{
		printf("%d -> %d  %d\n", MST[i].second.first, MST[i].second.second, MST[i].first);
	}
	printf("Mimimum cost for spanning tree is: %d\n", total);
}