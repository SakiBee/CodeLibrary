#include<bits/stdc++.h>
#define endl                   "\n"
#define ll                     long long
#define boost                  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);cin.exceptions(ios::badbit | ios::failbit);
#define all(v)                 v.begin(),v.end()
#define revall(v)              v.rbegin(),v.rend()
#define sp(a)                   fixed<<setprecision(a)
#define vll                     vector <ll>
#define for0(i,l,r)             for(ll i = l;i<r;i++)
#define for1(i,l,r)             for(ll i = l;i<=r;i++)
using namespace std;
const ll inf =1e18;


namespace pcf {
  #define MAXN 20000010
  #define MAX_PRIMES 2000010
  #define PHI_N 100000
  #define PHI_K 100
  int len = 0;
  int primes[MAX_PRIMES];
  int pref[MAXN];
  int dp[PHI_N][PHI_K];
  bitset <MAXN> f;
  void sieve(int n) {
    f[1] = true;
    for (int i = 4; i <= n; i += 2) f[i] = true;
    for (int i = 3; i * i <= n; i += 2) {
      if (!f[i]) {
        for (int j = i * i; j <= n; j += i << 1) f[j] = 1;
      }
    }
    for (int i = 1; i <= n; i++) {
      if (!f[i]) primes[len++] = i;
      pref[i] = len;
    }
  }
  void init() {
    sieve(MAXN - 1);
    for (int n = 0; n < PHI_N; n++) dp[n][0] = n;
    for (int k = 1; k < PHI_K; k++) {
      for (int n = 0; n < PHI_N; n++) {
        dp[n][k] = dp[n][k - 1] - dp[n / primes[k - 1]][k - 1];
      }
    }
  }
  long long yo(long long n, int k) {
    if (n < PHI_N && k < PHI_K) return dp[n][k];
    if (k == 1) return ((++n) >> 1);
    if (primes[k - 1] >= n) return 1;
    return yo(n, k - 1) - yo(n / primes[k - 1], k - 1);
  }
  long long Legendre(long long n) {
    if (n < MAXN) return pref[n];
    int lim = sqrt(n) + 1;
    int k = upper_bound(primes, primes + len, lim) - primes;
    return yo(n, k) + (k - 1);
  }
  long long Lehmer(long long n) {
    if (n < MAXN) return pref[n];
    long long w, res = 0;
    int b = sqrt(n), c = Lehmer(cbrt(n)), a = Lehmer(sqrt(b)); b = Lehmer(b);
    res = yo(n, a) + ((1LL * (b + a - 2) * (b - a + 1)) >> 1);
    for (int i = a; i < b; i++) {
      w = n / primes[i];
      int lim = Lehmer(sqrt(w)); res -= Lehmer(w);
      if (i <= c) {
        for (int j = i; j < lim; j++) {
          res += j;
          res -= Lehmer(w / primes[j]);
        }
      }
    }
    return res;
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0); 
  cin.tie(0);pcf::init();
  int t,test = 1;
  cin >> t;
  while(t--){
    cout << "Case " << test++ << ": ";
    long long l,r; cin >> l >> r;
        if(l == 1 || l == 0)
        cout << pcf::Lehmer(r) << '\n';
        else cout << pcf::Lehmer(r) - pcf::Lehmer(l - 1) << '\n';
  }
  return 0;
}
