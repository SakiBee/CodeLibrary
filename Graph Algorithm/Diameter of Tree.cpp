//https://www.quora.com/How-do-I-find-the-diameter-of-a-tree

#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+7;

bool vis[N];
vector<int> g[N];
int node, mx, ans, dep[N];

void dfs1(int u, int p) {
	dep[u] = dep[p] + 1;
	if(dep[u] > mx) {
		mx = dep[u];
		node = u;
	}
	for (auto v : g[u]) {
		if(v != p) {  // not visited
			dfs1(v, u); 
		}
	}
}

void dfs2(int u, int p) {
	dep[u] = dep[p] + 1;
	ans = max(ans, dep[u] - 1);
	for (auto v : g[u]) {
		if(v != p) {
			dfs2(v, u);
		}
	}
}

int32_t main () {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int n, m; cin >> n >> m;
  int u, v;
  for (int i = 0; i < m; i++) {
  	cin >> u >> v;
  	g[u].push_back(v);
  	g[v].push_back(u);
  }

  node = -1, mx = 0, ans = 0;

  dfs1(1, 0);
  dfs2(node, 0);

  cout << ans << endl;

}