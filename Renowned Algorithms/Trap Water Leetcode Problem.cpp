#include <bits/stdc++.h>
using namespace std;
#define ll long long

void SakiBee()
{
  ll n; cin >> n;
  vector<ll> v(n), vleft(n), vright(n),v1(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  if(n<3){cout << 0 << endl; return;}
  v1 = v;
  reverse(v1.begin(), v1.end());
  vleft[0] = v[0];
  vright[0] = v1[0];
  for(int i = 1; i <= n-1; i++) (v1[i] > vright[i-1]) ? vright[i] = v1[i] : vright[i] = vright[i-1];
  for(int i = 1; i <= n-1; i++) (v[i] > vleft[i-1]) ? vleft[i] = v[i] : vleft[i] = vleft[i-1];
  reverse(vright.begin(), vright.end());

  ll ans=0;
  for (int i = 0; i < n; i++)  ans += ( min(vright[i],vleft[i]) - v[i]);

  cout << ans << endl;
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  SakiBee();
}

