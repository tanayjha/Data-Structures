#include <bits/stdc++.h>
using namespace std;
#define N 10000
#define MAX 1000000
int arr[N], tree[MAX], lazy[MAX];
void build_tree(int node, int a, int b){
	if(a > b)
		return;
	if(a == b){
		tree[node] = arr[a];
		return;
	}
	build_tree(node*2, a, (a+b)/2);
	build_tree(node*2+1, (a+b)/2+1, b);
	tree[node] = min(tree[node*2], tree[node*2+1]);
}
void update_tree(int node, int a, int b, int i, int j, int value){
	if(lazy[node]){
		tree[node] = lazy[node];
		if(a != b){
			lazy[node*2] = lazy[node];
			lazy[node*2+1] = lazy[node];
		}
		lazy[node] = 0;
	}
	if(a > b || i > b || j < a)
		return;
	if(a >= i && b <= j){
		tree[node] = value;
		if(a != b){
			lazy[node*2] = value;
			lazy[node*2+1] = value;
		}
		return;
	}
	update_tree(node*2, a, (a+b)/2, i, j, value);
	update_tree(node*2+1, (a+b)/2+1, b, i, j, value);
	tree[node] = min(tree[node*2], tree[node*2+1]);
}
int query_tree(int node, int a, int b, int i, int j){
	if(a > b || i > b || j < a)
		return INT_MAX;
	if(lazy[node]){
		tree[node] = lazy[node];
		if(a != b){
			lazy[node*2] = lazy[node];
			lazy[node*2+1] = lazy[node];
		}
		lazy[node] = 0;
	}
	if(a >= i && b <= j)
		return tree[node];
	int q1 = query_tree(node*2, a, (a+b)/2, i, j);
	int q2 = query_tree(node*2+1, (a+b)/2+1, b, i, j);
	int res = min(q1, q2);
	return res;
}
int main()
{
	int n, l, r, val, q, x;
	cin>>n;
	for(int i = 0; i < n; i++)
		cin>>arr[i];
	build_tree(1, 0, n-1);
	/*for(int i = 1; i <= 25; i++)
		cout<<tree[i]<<" ";
	cout<<endl;*/
	cin>>q;
	while(q--){
		cin>>x;
		if(x == 1){
			cin>>l>>r>>val;
			update_tree(1, 0, n-1, l, r, val);
		}
		else{
			cin>>l>>r;
			cout<<query_tree(1, 0, n-1, l, r)<<endl;
		}
	}
}