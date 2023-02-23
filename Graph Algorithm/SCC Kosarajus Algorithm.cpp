#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+7;
vector<int> g[N], rev_g[N];
bool vis[N];
stack<int> st;

void dfs1(int n) {
	vis[n] = 1;
	for (auto u : g[n]) {
		if(!vis[u]) dfs1(u);
	}
	st.push(n);
}

void dfs2(int n) {
	vis[n] = 1;
	cout << n << " "; //print or store ssc
	for (auto u : rev_g[n]) {
		if(!vis[u]) dfs2(u);
	}
}

int32_t main () {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int n, m; cin >> n >> m;
  int u, v;
  for (int i = 0; i < m; i++) {
  	cin >> u >> v;
  	g[u].push_back(v);
  	rev_g[v].push_back(u);
  }

  for (int i = 1; i <= n; i++) {
  	if(!vis[i]) {
  	  dfs1(i);
  	}
  }
  memset(vis, 0, sizeof(vis));
  int cnt_scc = 0;
  while(!st.empty()) {
  	int p = st.top();
  	st.pop();
  	if(!vis[p]) {
  		cnt_scc++;
  		cout << "SSC No." << cnt_scc << " = ";
  		dfs2(p);
  		cout << endl;
  	}
  }

  cout << "Total Number of SCC = " << cnt_scc << endl;
  
   
}

//Complexity: O(3*(E+V))