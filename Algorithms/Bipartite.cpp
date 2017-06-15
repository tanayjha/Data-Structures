#include <bits/stdc++.h>
using namespace std;
#define WHITE -1
#define BLACK -2
#define EPS 1e-7
const int N = 123;
typedef int LL;
int n;
int parent[N];
int ind[N], even[N], odd[N];
int color[N];
int rg[N][N];

bool IsPrimeSlow (LL x){
  if(x<=1) return false;
  if(x<=3) return true;
  if (!(x%2) || !(x%3)) return false;
  LL s=(LL)(sqrt((double)(x))+EPS);
  for(LL i=5;i<=s;i+=6)
  {
    if (!(x%i) || !(x%(i+2))) return false;
  }
  return true;
}
bool is_augmented_path_present(int s, int t, int g[N][N]){
  for(int i = 0; i < n+20; i++)
  color[i] = WHITE;
  queue<int> q;
  q.push(s);
  color[s] = BLACK;
  while(!q.empty()){
    int u = q.front();
    q.pop();
    for(int i = 0; i < n+20; i++){
      if(g[u][i]>0 && color[i] == WHITE){
        parent[i] = u;
        color[i] = BLACK;
        q.push(i);
      }
    }
  }
  return color[t] == BLACK;
}
int max_flow(int s, int t){
  int g[N][N];
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      g[i][j] = rg[i][j];
    }
  }
  int maxFlow = 0;
  while(is_augmented_path_present(s, t, g)){
    int pathFlow = INT_MAX;
    for(int i = t; i != s; i = parent[i]){
      pathFlow = min(pathFlow, g[parent[i]][i]);
    }
    for(int i = t; i != s; i = parent[i]){
      g[parent[i]][i] -= pathFlow;
      g[i][parent[i]] += pathFlow;
    }
    maxFlow += pathFlow;
  }
  return maxFlow;
}
int main(){
  vector <int> v;
  cin>>n;
  int a[n+1], k1 = 0, k2 = 0;
  for(int i = 1;i <= n; i++){
    cin>>a[i];
    ind[a[i]] = i;
    if(a[i]%2)
      odd[k1++] = a[i];
    else
      even[k2++] = a[i];
  }
  for(int i = 0; i < k1; i++){
    if(odd[i] != a[1])
      rg[0][ind[odd[i]]] = 1;
  }
  for(int i = 0; i < k2; i++){
    if(even[i] != a[1])
      rg[ind[even[i]]][n+1] = 1;
  }
  for(int i = 0; i < k1; i++){
    for(int j = 0; j < k2; j++){
      if(IsPrimeSlow(odd[i]+even[j])){
        rg[ind[odd[i]]][ind[even[j]]] = 1;
      }
    }
  }
  for(int i = 2; i <= n; i++){
    if(a[i]%2)
      rg[0][ind[a[i]]] = 0;
    else
      rg[ind[a[i]]][n+1] = 0;
    if(max_flow(0, n+1) == n/2-1 && IsPrimeSlow(a[i]+a[1]))
      v.push_back(a[i]);
    if(a[i]%2)
      rg[0][ind[a[i]]] = 1;
    else
      rg[ind[a[i]]][n+1] = 1;
  }
  if(v.size() == 0){
    cout<<" sdfs"<<endl;
  }
  for(int i=0;i<v.size();i++){
    cout<<v[i]<<" ";
  cout<<endl;
  }
}
 