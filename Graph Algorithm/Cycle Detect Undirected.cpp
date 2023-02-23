//https://cses.fi/problemset/task/1669/
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+7;

vector<int> g[N], parent(N);
bool vis[N];
int l, r;

bool dfs(int n, int par) {
	vis[n] = 1;
	parent[n] = par;
	for (auto u : g[n]) {
		if(u == par) continue;
		if(vis[u]) {
			r = n;
			l = u;
			return true;
		}
		else {
			if(dfs(u, n)) return true;
		}
	}
	return false;
}

int32_t main () {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int n, m; cin >> n >> m;
  memset(vis, 0, sizeof(vis));
  int x, y;
  for (int i = 0; i < m; i++) {
  	cin >> x >> y;
  	g[x].push_back(y);
  	g[y].push_back(x);
  }

  bool ok = 0;
  for (int i = 1; i <= n; i++) {
  	if(!vis[i]) ok |= dfs(i, -1);
  	if(ok) break;
  }
  
  if(!ok) {
  	cout << "IMPOSSIBLE\n";
  	return 0;
  }

  int tm = r;
  vector<int> v;
  
  v.push_back(r);
  while(tm != l) {
  	v.push_back(parent[tm]);
  	tm = parent[tm];
  }
  v.push_back(r);
  cout << v.size() << endl;
  for (auto u : v) cout << u << " ";
  cout << endl;
  
}