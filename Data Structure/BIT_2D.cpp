//https://cses.fi/problemset/task/1739

#include <bits/stdc++.h>
using namespace std;
const int N = 1e3+7;

int a[N][N], t[N][N];

void upd(int n,int i2,int j2,int v) {
  for (int i = i2; i <= n; i += (i & -i)) {
    for (int j = j2; j <= n; j += (j & -j)) {
      t[i][j] += v;
    }
  }
}

int query(int i2,int j2) {
  int sum = 0;
  for (int i = i2; i; i -= (i & -i)) {
    for (int j = j2; j; j -= (j & -j)) {
      sum += t[i][j];
    }
  }
  return sum;
}

int32_t main () {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  memset(t, 0, sizeof(t));

  int n, q; cin >> n >> q;
  char c;
  for (int i = 1; i <= n; i++) { 
    for (int j = 1; j <= n; j++) {
      cin >> c;
      a[i][j] = (c == '*');
      if(a[i][j]) {
        upd(n, i, j, 1);
      }
    }
  }

  while(q--) {
    int m, x, y, x1, y1;
    cin >> m >> x >> y;;
    if(m == 1) {
      if (a[x][y] == 1) upd(n, x, y, -1);
      else upd(n, x, y, 1);
      a[x][y] ^= 1;
    }
    else {
      cin >> x1 >> y1;
      cout << query(x1, y1) - query(x1, y - 1) - query(x - 1, y1) + query(x - 1, y - 1) << endl;
    }
  }

}

