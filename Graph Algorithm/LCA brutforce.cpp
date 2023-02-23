//https://www.spoj.com/problems/LCA/
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+7;

vector<int> g[N];
int par[N], dep[N];

void dfs(int u, int lv) {
	dep[u] = lv;
	for (auto v : g[u]) {
		par[v] = u;
		dfs(v, lv + 1);
	}
}

int lca(int u, int v) {
	if(dep[u] > dep[v]) swap(u, v);
	while(dep[u] != dep[v]) {
		v = par[v];
	}
	while(u != v) {
		u = par[u];
		v = par[v];
	}
	return u;
}

void solve () {
  int n; cin >> n;
  int u, v;
  for (int i = 1; i <= n; i++) {
  	g[i].clear();
  	cin >> u;
  	while(u--) {
  		cin >> v;
  		g[i].push_back(v);
  	}
  }
  dfs(1, 0);
  int q; cin >> q;
  while(q--) {
  	cin >> u >> v;
  	cout << lca(u, v) << endl;
  }
}

int32_t main () {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int tc = 1, t = 0; 
  cin >> tc; 
  while(tc --) {
  	cout << "Case " << ++t << ":\n";
  	solve();
  }
}

//complexity O(n*q)