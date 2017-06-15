#include <bits/stdc++.h>
using namespace std;
vector <int> ans;
#define d 256
#define mod 101
void rabinKarp(string txt, string pat){
	int ltxt = txt.length();
	int lpat = pat.length();
	if(lpat > ltxt)
		return;
	int h = 1;
	for(int i = 0; i < lpat-1; i++)
		h = (h*d)%mod;
	int hashtxt = 0, hashpat = 0;
	for(int i = 0; i < lpat; i++){
		hashtxt = (d*hashtxt + txt[i])%mod;
		hashpat = (d*hashpat + pat[i])%mod;
	}
	cout<<hashpat<<endl;
	for(int i = 0; i <= ltxt - lpat; i++){
		if(hashtxt == hashpat){
			int f = 0;
			for(int j = 0; j < lpat; j++){
				if(txt[i+j] != pat[j]){
					f = 1;
					break;
				}
			}
			if(!f)
				ans.push_back(i);
		}
		hashtxt = (d*(hashtxt - txt[i]*h) + txt[i+lpat])%mod;
		if(hashtxt < 0)
			hashtxt += mod;
		cout<<hashtxt<<endl;
	}

}
int main()
{
	string pattern, text;
	getline(cin, text);
	getline(cin, pattern);
	cout<<text<<" "<<pattern<<endl;
	rabinKarp(text, pattern);
	cout<<ans.size()<<endl;
	for(int i = 0; i < ans.size(); i++)
		cout<<ans[i]<<" ";
	cout<<endl;
}