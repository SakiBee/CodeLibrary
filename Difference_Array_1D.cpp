#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+7;

int32_t main () {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int n, q; cin >> n >> q;
  vector<int> v(n+1), d(n+2, 0), pred(n+2, 0);
  for (int i = 1; i <= n; i++) {
    cin >> v[i];
  }

  int x, y, m;
  while(q--) {
    cin >> x >> y >> m;
    d[x] += m;
    d[y+1] -= m;
  }

  for (int i = 1; i <= n; i++) {
    pred[i] = pred[i-1] + d[i];
    v[i] += pred[i];
  }

  for (int i = 1; i <= n; i++) {
    cout << v[i] << " ";
  }
  cout << endl;   
}