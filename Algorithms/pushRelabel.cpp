#include <bits/stdc++.h>
using namespace std;
int res[1005][1005], h[1005], excess[1005];
set <pair<int, int> > maxExcess;
set <pair<int, int> >:: iterator it, it1, it2;
void init(int source, int target) {
	h[source] = target;
	for(int i = 0; i < 1005; i++) {
		if(res[source][i] != 0) {
			res[i][source] += res[source][i];
			excess[i] = res[source][i];
			res[source][i] = 0;
		}
	}
	for(int i = 1; i < 1005; i++) {
		if(i != source && i != target)
			maxExcess.insert(make_pair(excess[i], i));
	}
}
bool push(int x, int n) {
	for(int i = 0; i <= n; i++) {
		if(res[x][i] != 0 && h[x] > h[i]) {
			int y = min(res[x][i], excess[x]);
			res[i][x] += y;
			res[x][i] -= y;
			it1 = maxExcess.end();
			it1--;
			it2 = maxExcess.find(make_pair(excess[i], i));
			excess[i] += y;
			excess[x] -= y;
			maxExcess.erase(it1);
			if(it2 != maxExcess.end())
				maxExcess.erase(it2);
			maxExcess.insert(make_pair(excess[x], x));
			if(i != 1 && i != n)
				maxExcess.insert(make_pair(excess[i], i));
			return true;
		}
	}
	return false;
}
void relabel(int x) {
	h[x] += 1;
}
int main() {
	int n, e, a, b, c;
	cin>>n>>e;
	for(int i = 0; i < e; i++) {
		cin>>a>>b>>c;
		res[a][b] = c;
	}
	init(1, n);
	int k = 20;
	while(1) {
		k--;
		if(k == 0)
			break;
		it = maxExcess.end();
		it--;
		if((*it).first == 0)
			break;
		if(push((*it).second, n)) {
		} else
			relabel((*it).second);
	}
	cout<<excess[n]<<endl;
}