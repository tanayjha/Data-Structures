#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N =2345678;
ll hash_a[N];
ll hash_b[N];
ll rash_a[N];
ll rash_b[N];

ll pa = 31, pb = 37;
ll ma = 1e9 + 7, mb = 1e9 + 9;
template <typename T>
T modpow(T base, T exp, T modulus) {
  base %= modulus;
  T result = 1;
  while (exp > 0) {
    if (exp & 1) result = (result * base) % modulus;
    base = (base * base) % modulus;
    exp >>= 1;
  }
  return result;
}


void generate_hash(string s){
  for(ll i = 0; i < s.length(); i++){
    if(i == 0)
    	hash_a[i] = s[i] - 'a' + 1;
    else
    	hash_a[i] = ((hash_a[i-1]*pa)%ma + s[i]-'a' + 1)%ma;
  }
  for(ll i = 0; i < s.length(); i++){
    if(i == 0)
    	hash_b[i] = s[i] - 'a' + 1;
    else
    	hash_b[i] = ((hash_b[i-1]*pb)%mb + s[i]-'a' + 1)%mb;
  }
  reverse(s.begin(), s.end());
  for(ll i = 0; i < s.length(); i++){
    if(i == 0)
    	rash_a[i] = s[i] - 'a' + 1;
    else
    	rash_a[i] = ((rash_a[i-1]*pa)%ma + s[i]-'a' + 1)%ma;
  }
  for(ll i = 0; i < s.length(); i++){
    if(i == 0)
    	rash_b[i] = s[i] - 'a' + 1;
    else
    	rash_b[i] = ((rash_b[i-1]*pb)%mb + s[i]-'a' + 1)%mb;
  }
}
int main(){
  string s, t;
  getline(cin, s);
  cin>>t;
  ll n = s.length();
  ll m = t.length();
  ll ha = 0;
  ll hb = 0;

  generate_hash(s);
  for(ll i = 0 ; i < t.length(); i++){
    ha = ((ha*pa)%ma + t[i] - 'a' + 1)%ma;
  }
  for(ll i = 0; i < t.length(); i++){
    hb = ((hb*pb)%mb + t[i] - 'a' + 1)%mb;
  }

  ll ra = 0;
  ll rb = 0;
  for(ll i = 0 ; i < t.length(); i++){
    ra = ((ra*pa)%ma + t[i] - 'a' + 1)%ma;
  }
  for(ll i = 0; i < t.length(); i++){
    rb = ((rb*pb)%mb + t[i] - 'a' + 1)%mb;
  }
 
  for(ll i = 0; i <= n - m; i++){
    ll nx, ny, rx, ry;
    if(i!=0){
      nx = (hash_a[i + m - 1] - (hash_a[i-1]*modpow(pa, m, ma))%ma)%ma;
      ny = (hash_b[i + m - 1] -(hash_b[i-1]*modpow(pb, m, mb))%mb)%mb;
      rx = (rash_a[i + m - 1] - (rash_a[i-1]*modpow(pa, m, ma))%ma)%ma;
      ry = (rash_b[i + m - 1] -(rash_b[i-1]*modpow(pb, m, mb))%mb)%mb;
    }
    else{
      nx = hash_a[i + m - 1];
      ny = hash_b[i + m - 1];
      rx = rash_a[i + m - 1];
      ry = rash_b[i + m - 1];
    }
    if(nx == ha && ny == hb) cout<<i<<" ";
    else if(rx == ra && ry == rb) cout<<i<<" ";
  }
  cout<<endl;
  return 0;
}
  