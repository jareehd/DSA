#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 100005;
ll mod=1e9+7, pow1[N] , pow2[N] ,inv1[N] ,inv2[N] ,hash1[N], hash2[N] ;
 
ll power(ll x,ll y){
   ll res=1;
   while(y){
       if(y&1) res = (x*res)%mod;
       y>>=1; x = (x*x)%mod;
   }
   return res;
}
 
void calc(){
    ll p1=101,p2=103;
    pow1[0] = pow2[0] = 1;
    for(ll i=1;i<N;i++){
       pow1[i] = (pow1[i-1]*p1)%mod;
       pow2[i] = (pow2[i-1]*p2)%mod;
    }
    inv1[0] = inv2[0] = 1;
    // inverse modulo of x with respect to m is pow( x , m-2 )
    inv1[1] = power(pow1[1],mod-2);
    inv2[1] = power(pow2[1],mod-2);
    for(ll i=2;i<N;i++){
        inv1[i] = (inv1[i-1]*inv1[1])%mod;
        inv2[i] = (inv2[i-1]*inv2[1])%mod;
    }        
}

pair<ll,ll> hashed(string s){
    ll h1=0,h2=0,k;
    for(ll i=0;i<s.size();i++){
      if(s[i]<='Z') k = s[i]-'A'+1; else k = s[i]-'a'+1;
      h1 = (h1+pow1[i+1]*k)%mod;  h2 = (h2+pow2[i+1]*k)%mod;
    }
    return make_pair(h1,h2);
}
 
int main(){
    
    calc();
    
    string s;   cin >> s;
    
    hash1[0] = hash2[0] = 0;
  
    for(i=1;i<=n;i++){
        hash1[i] = (hash1[i-1] + pow1[i]*(s[i-1]-'a'+1) )%mod;
        hash2[i] = (hash2[i-1] + pow2[i]*(s[i-1]-'a'+1) )%mod;
    }
    
    // hash value of a substring j to i
    
    ll h1 = ( (hash1[i]-hash1[j-1] + mod )*inv1[j-1] )%mod;
    ll h2 = ( (hash2[i]-hash2[j-1] + mod )*inv2[j-1] )%mod;
    
  
}
