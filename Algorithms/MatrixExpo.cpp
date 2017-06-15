#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
long long res[2][2] = {1, 1, 1, 0}, y[2][2] = {1, 0, 0, 1};
void mul1(){
	long long temp[4];
	temp[0] = res[0][0]*res[0][0] + res[0][1]*res[1][0];
	temp[1] = res[0][0]*res[0][1] + res[0][1]*res[1][1];
	temp[2] = res[1][0]*res[0][0] + res[1][1]*res[1][0];
	temp[3] = res[1][0]*res[0][1] + res[1][1]*res[1][1];
	res[0][0] = temp[0];
	res[0][1] = temp[1];
	res[1][0] = temp[2];
	res[1][1] = temp[3];
}
void mul2(long long n){
	long long temp[4];
	temp[0] = res[0][0]*y[0][0] + res[0][1]*y[1][0];
	temp[1] = res[0][0]*y[0][1] + res[0][1]*y[1][1];
	temp[2] = res[1][0]*y[0][0] + res[1][1]*y[1][0];
	temp[3] = res[1][0]*y[0][1] + res[1][1]*y[1][1];
	if(!n){
		y[0][0] = temp[0];
		y[0][1] = temp[1];
		y[1][0] = temp[2];
		y[1][1] = temp[3];
	}
	else{
		res[0][0] = temp[0];
		res[0][1] = temp[1];
		res[1][0] = temp[2];
		res[1][1] = temp[3];		
	}	

}
void matrixExpo(long long x){
	if(x == 0)
		return;
	while(x>1){
		if(x%2 == 0){
			mul1();
			x/=2;
		}
		else{
			mul2(0);
			mul1();
			x=(x-1)/2;
		}
	}
	mul2(1);
}
int main()
{
	int q;
	cin>>q;
	while(q--) {
		long long ans = 0;
        int n;
		cin>>n;
		int a[n];
		for(int i = 0; i < n; i++) {
			cin>>a[i];
		}
        long long x;
		for(int i = 0; i < n; i++) {
			for(int j = i; j < n; j++) {
				cout<<"HERE\n";
				x = 0;
				for(int k = i; k <= j; k++) {
					x += a[k];
				}
				cout<<x<<endl;
				n = x;
				if(n == 1 || n == 2)
					ans = (ans%MOD + 1%MOD)%MOD;
				else{
					matrixExpo(n-2);
					ans = (ans%MOD + res[0][0]%MOD + res[0][1]%MOD)%MOD;
				}
			}
		}
		cout<<ans%MOD<<endl;
	}
	
}