//https://www.spoj.com/problems/LCA/
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+7;

vector<int> g[N];
int par[N], dep[N], BLT[21][N];

void dfs(int u, int lv) {
	dep[u] = lv;
	for (auto v : g[u]) {
		par[v] = u;
		dfs(v, lv + 1);
	}
}

void build_bl(int n) {
	for (int i = 0; i <= n; i++) BLT[0][i] = par[i];
	for (int i = 1; i <= 20; i++) {
		for (int j = 2; j <= n; j++) {
			int p = BLT[i-1][j];
			BLT[i][j] = BLT[i-1][p];
		}
	}
}

int lca(int u, int v) {
	if(dep[u] > dep[v]) swap(u, v);

	int dif = dep[v] - dep[u];
	for (int i = 20; i >= 0; i--) {
		int mask = 1 << i;
		if(dif & mask) {
			v = BLT[i][v];
		}
	}
	if(u == v) return u;

	for (int i = 20; i >= 0; i--) {
		if(BLT[i][u] != BLT[i][v]) {
			u = BLT[i][u];
			v = BLT[i][v];
		}
	}
	u = par[u];
	return u;
}

void solve () {
  int n, u, v; cin >> n;
  for (int i = 1; i <= n; i++) {
  	g[i].clear();
  	cin >> u;
  	while(u--) {
  		cin >> v;
  		g[i].push_back(v);
  	}
  }
  dfs(1, 0);
  build_bl(n);
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

//complexity O(nlogn)