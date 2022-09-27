#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll mulMod (ll a, ll b, ll M) { 
  a %= M, b %= M; 
  if(M <= 1000000009) return a * b % M; 
  ll res = 0;
  while(a > 0) {
    a %= M, b %= M; 
    if (a & 1) { 
      res += b; 
      if (res >= M) res -= M;
    } 
    a >>= 1; b <<= 1; b %= M;
    if (b >= M) b -= M;
  } 
  return res;
}


ll bigMod(ll p, ll q, ll M) { 
  ll ans = 1;
  while(q) { 
    if(q & 1) ans = mulMod(ans, p, M); 
    p = mulMod(p, p, M); 
    q>>=1;
  } 
  return ans % M;
}


ll inverseMod(ll p, ll M) { 
  return bigMod(p, M - 2, M);
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  
}





