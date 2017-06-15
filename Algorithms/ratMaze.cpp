#include <bits/stdc++.h>
using namespace std;
int a[20][20], c = 0, n, v[20][20] = {0, 0};
int solve(int i, int j, int n) {
	//printf("%d %d\n", i, j);
	v[i][j] = 1;
	if(i+1<n) {
		if(!v[i+1][j] && a[i+1][j] == 0) {
			solve(i+1, j, n);
		}
	}
	if(j+1<n) {
		if(!v[i][j+1] && a[i][j+1] == 0) {
			solve(i, j+1, n);
		}
	}
	if(i-1>=0) {
		if(!v[i-1][j] && a[i-1][j] == 0)
			solve(i-1, j, n);
	}
	if(j-1>=0) {
		if(!v[i][j-1] && a[i][j-1] == 0)
			solve(i, j-1, n);
	}
	v[i][j] = 0;
	if(i == n-1 && j == n-1) {
		c++;
	}
	return c;
}
int main() {
	int n, i, j;
	scanf("%d", &n);
	for(i=0;i<n;i++) {
		for(j=0;j<n;j++) {
			scanf("%d", &a[i][j]);
		}
	}
	printf("%d\n", solve(0, 0, n));
}