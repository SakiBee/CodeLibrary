#include<bits/stdc++.h>
#define endl                   "\n"
#define ll                     long long
#define boost                  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);cin.exceptions(ios::badbit | ios::failbit);
#define all(v)                 v.begin(),v.end()
#define revall(v)              v.rbegin(),v.rend()
#define gcd(a,b)                __gcd(a,b)
#define lcm(a,b)               (a*b)/gcd(a,b)
#define pb                     push_back
#define eb                     emplace_back
#define mk                     make_pair
#define F                      first
#define S                      second
#define pi                     acos(-1.0)
#define maxv(v)                *max_element(all(v))
#define minv(v)                *min_element(all(v))
#define countv(v,a)             count(all(v),a)
#define cntone(x)             __builtin_popcountll(x) // number of ones
#define cntzero(x)             __builtin_ctzll(x) // number of zeros
#define rep(i, l, r)           for(long long i = l; i<r; i++)
#define SUM                     accumulate
#define toint(a)                atoi(a.c_str())
#define read                    freopen("input.txt","r",stdin)
#define write                   freopen("output.txt","w",stdout)
#define Unique(c)               (c).resize(unique(all(c))-(c).begin())
#define sp(a)                   fixed<<setprecision(a)
#define printv(container)       for(auto it:container) cout << it << " ";cout << endl
#define vll                     vector <ll>
#define cases(i)                cout << "Case " << i << ":"
#define yes                     cout << "Yes" << endl
#define no                      cout << "No" << endl
#define rand(V)                random_shuffle(all(V))
#define lb(a,X)                lower_bound(all(a),X)-a.begin()
#define ub(a,X)                upper_bound(all(a),X)-a.begin()
#define Tc                     ll tt;cin >> tt;while(tt--)
#define for0(i,l,r)             for(ll i = l;i<r;i++)
#define for1(i,l,r)             for(ll i = l;i<=r;i++)
#define rev0(i,r,l)             for(ll i = r - 1;i>=l;i--)
using namespace std;
const ll inf =1e18;
/*************************************
*          DEBUGGING SECTION         *
**************************************/
template<typename T>void showSTL(T H);template<typename T,typename V>void showSTL(pair<T,V> H);
template<typename T>void showSTL(priority_queue<T> H);template<typename T>void showSTL(stack<T> H);
template<typename T,typename V>void showSTL(map<T,V> H);
template<typename T,typename V>void showSTL(multimap<T,V> H);template<typename T>void showSTL(vector<T> H);
template<typename T>void showSTL(set<T> H);template<typename T>void showSTL(multiset<T> H);
template<typename T>void showSTL(list<T> H);void showSTL(char *H);
template<typename T>void showSTL(deque<T> H);template<typename T>void showSTL(queue<T> H);
template<typename T>void showSTL(T H){stringstream ss;ss<<H;cerr<<ss.str();}
template<typename T,typename V>void showSTL(pair<T,V> H){cerr<<"(";showSTL(H.first);cerr<<"=>";showSTL(H.second);cerr<<")";}
template<typename T>void showSTL(priority_queue<T> H){cerr<<endl;while(!H.empty()){cerr<<H.top()<<endl;H.pop();}cerr<<endl;}
template<typename T>void showSTL(stack<T> H){cerr<<endl;while(!H.empty()){cerr<<H.top()<<endl;H.pop();}}
template<typename T,typename V>void showSTL(map<T,V> H){cerr<<"[ ";for(auto val:H){showSTL(val);cerr<<" ";}cerr<<"]";}
template<typename T,typename V>void showSTL(multimap<T,V> H){cerr<<"[ ";for(auto val:H){showSTL(val);cerr<<" ";}cerr<<"]";}
template<typename T>void showSTL(vector<T> H){cerr<<"[ ";for(auto val : H){showSTL(val);cerr<<' ';}cerr<<"]";}
template<typename T>void showSTL(set<T> H){cerr<<"[ ";for(auto val : H){showSTL(val);cerr<<' ';}cerr<<"]";}
template<typename T>void showSTL(multiset<T> H){cerr<<"[ ";for(auto val : H){showSTL(val);cerr<<' ';}cerr<<"]";}
template<typename T>void showSTL(list<T> H){cerr<<"[ ";for(auto val : H){showSTL(val);cerr<<' ';}cerr<<"]";}
void showSTL(char *H){for(int i=0;i<strlen(H);i++){showSTL(H[i]);};}
template<typename T>void showSTL(deque<T> H){cerr<<"[ ";for(auto val : H){showSTL(val);cerr<<' ';}cerr<<"]";}
template<typename T>void showSTL(queue<T> H){cerr<<"[ ";while(!H.empty()){showSTL(H.front());cerr<<' ';H.pop();}cerr<<"]";}
vector<string>vec_spltr(string s){s+=',';vector<string>res;while(!s.empty())
res.push_back(s.substr(0, s.find(','))),s=s.substr(s.find(',')+1);return res;}
void dbg_out(vector<string>__attribute__((unused))args,__attribute__((unused))int idx,__attribute__((unused))int LINE_NUM)
{cerr<<endl;}template<typename Head,typename... Tail>
void dbg_out ( vector <string> args, int idx, int LINE_NUM, Head H, Tail... T)
{if(idx>0)cerr<<", ";else cerr << "Line(" << LINE_NUM << "):";
cerr<<" "<<args[idx]<<" = ";showSTL(H);dbg_out(args,idx+1,LINE_NUM, T...);}
#define debug(...) dbg_out(vec_spltr(#__VA_ARGS__), 0, __LINE__, __VA_ARGS__)
     /*   CHANGE VALUE OF MOD HERE   */
#define MOD 1000000007
const int N = 3e5 + 9;
         /*    MODULAR ARITHMETICS   */
ll add(ll a,ll b,ll mod){a += b;return ((a >= mod) ? a - mod : a);}
ll sub(ll a,ll b,ll mod){a -= b;return ((a < 0) ? a + mod : a);}
ll mult(ll a,ll b,ll mod){ll ans = (a%mod)*(b%mod);if(ans >= mod)ans %= mod;return ans;}
ll bigmod(ll x,ll n,ll mod){if(n == 0)return 1;ll ans = bigmod(x,n/2,mod);ans = mult(ans,ans,mod);if(n & 1) ans = mult(x,n,mod);return ans;}
        /*    CUSTOM FUNCTIONS   */
bool isPowerOfTwo (ll x) {return x && (!(x&(x-1)));}
bool ip(long double x){long double sr = sqrt(x);return ((sr - floor(sr)) == 0);}
ll digNO(ll num){  return floor(log10(num)) + 1; }
int findSqrt(int n) { int lo = 0, hi = n; while (lo <= hi) { int mid = (lo + hi) / 2; if (mid * mid <= n) lo = mid + 1; else hi = mid - 1; }return lo - 1;}
ll fib(ll n){double phi = (1+sqrt(5))/2;return round(pow(phi,n)/sqrt(5));}
ll count_N_in_Fact(ll n,ll k){ll res = 0,sum = 0;for(ll i = k;;i*=k){res = n/i;if(res == 0)break;sum += res;}return sum;}
string v2s(vll &A){ll Z=A.size();string S(Z,' ');rep(i,0,Z)S[i]=A[i]+'0';return S;}
bool isPrime(ll n) {if (n <= 1) return false;if (n <= 3) return true;if (n % 2 == 0 || n % 3 == 0) return false; for (ll i = 5; i * i <= n; i = i + 6) if (n % i == 0 || n % (i + 2) == 0) return false; return true; }
bool compare(const pair<string,ll> &a, const pair<string,ll> &b) { return a.F < b.F;}
bool compare1(const pair<ll, ll> &a, const pair<ll, ll> &b){
    if(a.F == b.F)
        return a.S > b.S;
    return a.F < b.F;
}
ll modinverse(ll a,ll M){return bigmod(a,M-2,M);}
ll div_By_X_and_Y(ll n,ll x,ll y){ll m = lcm(x,y);return n / m;}
ll div_By_X_not_Y(ll n,ll x,ll y){ll p = n / x;ll q = n / y;ll m = lcm(x,y);ll both = n / m;ll xory = (p + q) - both;ll xnoty = xory - q;return xnoty;}
ll div_By_Y_not_X(ll n,ll x,ll y){ll p = n / x;ll q = n / y;ll m = lcm(x,y);ll both = n / m;ll xory = (p + q) - both;ll ynotx = xory - p;return ynotx;}


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