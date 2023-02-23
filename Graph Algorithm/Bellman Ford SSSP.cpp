#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll

const int inf = 1e16, N = 1e5+7;

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int n, m; cin >> n >> m;
  int u, v, w;
  vector<vector<int> >g;
  for (int i = 0; i < m; i++) {
    cin >> u >> v >> w;
    g.push_back({u, v, w});
  }
  int src; cin >> src;

  bool neg_cycle = true;
  vector<int> dis(n, inf);
  dis[src] = 0;
  for (int i = 0; i < n - 1; i++) {
  	bool change = false;
  	for (auto e : g) {
  		u = e[0], v = e[1], w = e[2];
  		if(dis[v] > dis[u] + w) {
  			change = true;
  		}
  		dis[v] = min(dis[v], dis[u] + w);
  	}
  	if(!change) {
  		neg_cycle = false;
  	}
  }
  if(neg_cycle) {
  	cout << "Negative cycle found\n";
  	return 0;
  }

  for (auto it : dis) cout << it << " ";
  cout << endl;
}

