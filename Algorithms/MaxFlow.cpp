#include <bits/stdc++.h>
using namespace std;
#define WHITE -1
#define BLACK -2
const int N = 1234;
int n;
int parent[N];
int color[N];
int rg[N][N];
bool is_augmented_path_present(int s, int t){
  for(int i = 1; i <= n; i++)
    color[i] = WHITE;
  queue<int> q;
  q.push(s);
  color[s] = BLACK;
  while(!q.empty()){
    int u = q.front();
    q.pop();
    for(int i = 1; i <= n; i++){
      if(rg[u][i]>0 && color[i] == WHITE){
        parent[i] = u;
        color[i] = BLACK;
        q.push(i);
      }
    }
  }
  return color[t] == BLACK;
}
int max_flow(int s, int t){
  int maxFlow = 0;
  while(is_augmented_path_present(s, t)){
    int pathFlow = INT_MAX;
    for(int i = t; i != s; i = parent[i]){
      pathFlow = min(pathFlow, rg[parent[i]][i]);
    }
    for(int i = t; i != s; i = parent[i]){
      rg[parent[i]][i] -= pathFlow;
      rg[i][parent[i]] += pathFlow;
    }
    maxFlow += pathFlow;
  }
  return maxFlow;
}
int main(){
  cin>>n;
  int m;
  cin>>m;
  for(int i = 0; i < m; i++){
    int x, y, z;
    cin>>x>>y>>z;
    rg[x][y] = z;
  }
  cout<<max_flow(1, 4)<<endl;
}
 