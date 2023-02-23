#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+7;

int low[N], disc[N];
bool vis[N], instack[N];
vector<int> g[N];
stack<int> st;
int dc = 1; // if vertex start from 0,
						// then dc and disc should be -1

void dfs(int n) {
	vis[n] = 1;
	disc[n] = low[n] = dc++;
	st.push(n);
	instack[n] = 1;

	for (auto u : g[n]) {
		if(!vis[u]) {
			dfs(u);
			low[n] = min(low[n], low[u]);
		}
		else if(instack[u]) {
			low[n] = min(low[n], disc[u]);
		}
	}

	if(low[n] == disc[n]) {
		while(1) {
			int x = st.top();
			instack[x] = 0;
			st.pop();
			cout << x << " ";
			if(x == n) break;
		}
		cout << endl;
	}
}

int32_t main () {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int n, m; cin >> n >> m;
  int u, v;
  for (int i = 0; i < m; i++) {
  	cin >> u >> v;
  	g[u].push_back(v);
  }

  for (int i = 1; i <= n; i++) {  //vertex > 0
  	if(!vis[i]) {
  		dfs(i);
  	}
  }
  
}



// Complexity : O(E+V)