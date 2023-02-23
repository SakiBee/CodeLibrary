#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+7;

int low[N], disc[N], par[N];
bool vis[N], instack[N], AP[N];
vector<int> g[N];
stack<int> st;
int dc = 1; // if vertex start from 0,
						// then dc and and all initials should be -1

void dfs(int n) {
	vis[n] = 1;
	disc[n] = low[n] = dc++;
	int child = 0;
	for (auto u : g[n]) {
		if(!vis[u]) {
			par[u] = n;
			child++;
			dfs(u);
			low[n] = min(low[n], low[u]);
			
			if(par[n] != 0 and low[u] >= disc[n]) AP[n] = 1; // case 1
			if(par[n] == 0 and child > 1) AP[n] = 1;    		 // case 2			
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
  	//g[v].push_back(u);
  }

  for (int i = 1; i <= n; i++) {  //vertex > 0
  	if(!vis[i]) {
  		dfs(i);
  	}
  }

  for (int i = 1; i <= n; i++) {
  	if(AP[i]) cout << i << " ";
  }

  cout << endl;
  
}



// Complexity : O(E+V)