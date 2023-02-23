#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+7;

int low[N], disc[N], par[N];
bool vis[N];
vector<int> g[N];
vector<pair<int, int> >bridge;

void dfs(int n) {
	static int dc = 1;
	vis[n] = 1;
	disc[n] = low[n] = dc++;
	for (auto u : g[n]) {
		if(!vis[u]) {
			par[u] = n;
			dfs(u);
			low[n] = min(low[n], low[u]);
			
			if(low[u] > disc[n]) {
				bridge.push_back({n, u});
			}			
		}
		else if(u != par[n]) {
			low[n] = min(low[n], disc[u]);
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

  for (int i = 1; i <= n; i++) {  //vertex > 0
  	if(!vis[i]) {
  		dfs(i);
  	}
  }

  for (auto [x, y] : bridge) {
  	cout << x << " " << y << endl;
  }
  
}



// Complexity : O(E+V)