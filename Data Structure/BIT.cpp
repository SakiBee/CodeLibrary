#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+7;

int a[N], t[N];

void upd(int n, int id, int v) {  //logn
  while(id <= n) {
    t[id] += v;
    id += (id & -id);  // adding MSB
  }
}

int query(int id) {
  int sum = 0;
  while(id > 0) {
    sum += t[id];
    id -= (id & -id);  // fliping MSB
  }
  return sum;
}

int32_t main () {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  memset(t, 0, sizeof(t));
  int n, q, x; cin >> n >> q;
  for (int i = 1; i <= n; i++) { //nlogn
    cin >> a[i];
    upd(n, i, a[i]);
  }

  while(q--) {
    int m, x, y;
    cin >> m >> x >> y;
    if(m == 1) upd(n, x, y);  //logn
    else cout << query(y) - query(x - 1) << endl;  //logn
  }

}

