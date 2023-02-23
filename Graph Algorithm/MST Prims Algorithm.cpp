#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6, inf = 1e9;

int n, m, cost = 0;
vector<int>parent(N), dist(N);
bool vis[N];
vector<vector<int> > g[N];
int u, v, w;

void PrimsMST(int src) {
	for (int i = 0; i < N; i++) dist[i] = inf;

	set<vector<int> >s;
	dist[src] = 0;
	s.insert({0, src});
	
	while(!s.empty()) {
		auto x = *s.begin();
		s.erase(x);
		vis[x[1]] = 1;
		u = x[1];
		v = parent[u];
		w = x[0];
		//cout << u << " " << v << " " << w << endl;
		cost += w;

		for (auto it : g[u]) {
			if(vis[it[0]]) continue;

			if(dist[it[0]] > it[1]) {
				s.erase({dist[it[0]], it[0]});
				dist[it[0]] = it[1];
				s.insert({dist[it[0]], it[0]});
				parent[it[0]] = u;
			}
		}
	}
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
  	cin >> u >> v >> w;
  	g[u].push_back({v, w});
  	g[v].push_back({u, w});
  }
  PrimsMST(0);
  cout << cost << endl;
}

