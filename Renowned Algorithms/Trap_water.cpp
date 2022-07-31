#include <bits/stdc++.h>
using namespace std;
#define     optimize        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define     ll              long long
#define     vll             vector<ll>
#define     all(x)          x.begin(),x.end()
#define     reall(x)        x.rbegin(),x.rend()
#define     pb              push_back
#define     sz(s)           s.size();
#define     fori(i,b,e)     for(int (i)=(b); (i) <= (e); (i)++)
#define     for0(i,n)       for(int (i)=0; (i) < (n); (i)++)
#define     sp(a)           fixed<<setprecision(a)
#define     endl            '\n'
#define     yes             cout << "YES" << '\n'
#define     no              cout << "NO" << '\n'
#define     coutl(x)        cout << x << '\n'
#define     cout(x)         cout << x
#define     nl              cout << '\n'
#define     printv(v)       for(auto it:v) cout << it << " "
#define     CASE(t)         printf("Case %lld: ",++t)
#define     Fall_in_Code    int main(){optimize; int tt; cin >> tt;while(tt--){SakiBee();}return 0;}
#define     S_Fall_in_Code  int main(){optimize; SakiBee();return 0;}


void SakiBee()
{
  ll n; cin >> n;
  vll v(n), vleft(n), vright(n),v1(n);
  for0(i,n) cin >> v[i];
  if(n<3){cout << 0 << endl; return;}
  v1 = v;
  reverse(all(v1));
  vleft[0] = v[0];
  vright[0] = v1[0];
  fori(i,1,n-1) (v1[i] > vright[i-1]) ? vright[i] = v1[i] : vright[i] = vright[i-1];
  fori(i,1,n-1) (v[i] > vleft[i-1]) ? vleft[i] = v[i] : vleft[i] = vleft[i-1];
  reverse(all(vright));

  ll ans=0;
  for0(i,n)  ans += ( min(vright[i],vleft[i]) - v[i]);

  cout << ans << endl;
}

//Fall_in_Code
S_Fall_in_Code

//Wrong doesn't mean bad
