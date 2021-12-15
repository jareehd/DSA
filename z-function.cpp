#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
// Z-function / algorithm 
 
void z_function(string &s, vector<ll>&z){
	
	ll l=0, r=0;
	for(ll i=1; i<s.size(); i++){
		if(i>r){
			l = r = i;  // [0....]  == [i...]
			while(r < s.size() && s[r] == s[r-l]) ++r;
			z[i] = r-l; --r;	
		} else {
			ll k = i-l;
			if(z[k] < r-i+1) z[i] = z[k];   // [0...k] = [i...i+k]
			else {
				l = i;	                    
				while(r < s.size() && s[r] == s[r-l]) ++r;
				z[i] = r-l; --r;
			}
		}
	}
}
 
int main(){
   ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   string s; cin >> s;
   vector<ll> z(1000005,0);   
   
   z_function(s,z);
   
}
