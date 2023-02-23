//https://leetcode.com/problems/kth-ancestor-of-a-tree-node/
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

int Kth_ancestor(int a, int k) {   // a's kth ancestor
	for (int i = 0; i < 21; i++) {
		int mask = (1<<i);
		if(k & mask) {
			a = BLT[i][a];
		}
	}
	return a;
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
  int a, k;
  while(q--) {
  	cin >> a >> k;
  	cout << Kth_ancestor(a, k) << endl;
  }
}

int32_t main () {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  solve();
}

//complexity O(n*q)