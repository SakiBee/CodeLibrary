#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll

const int inf = 1e16, N = 1e5+7;

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int n, m; cin >> n >> m;
  vector<vector<int> >g, dist;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < m; j++) {
      cin >> g[i][j];
    }
  }

  dist = g;
  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if(dist[i][j] == inf) {
        cout << "INF ";
      }
      else cout << dist[i][j] << " ";
    }
    cout << endl;
  }


}

