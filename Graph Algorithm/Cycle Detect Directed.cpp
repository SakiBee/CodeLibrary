//https://cses.fi/problemset/task/1678

#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+7;

vector<int> g[N], col(N), par(N);
int l = -1, r = -1;
bool cycle;
void dfs(int n) {
	col[n] = 1;
	for (auto u : g[n]) {
		if(col[u] == 0) {
			par[u] = n;
			dfs(u);
		}
		else if(col[u] == 1) {
			l = u;
			r = n;
			cycle = true;
		}
	}
	col[n] = 2;
}

int32_t main () {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  int n, m, x, y; cin >> n >> m;
  for (int i = 1; i <= m; i++) {
  	cin >> x >> y;
  	g[x].push_back(y);
  }
  cycle = false;
  for (int i = 1; i <= n; i++) {  //vertex from 1 to n
  	dfs(i);
  }
  
  if(!cycle) {
  	cout << "IMPOSSIBLE\n";
  	return 0;
  }
  
  vector<int> path;  //printing cycle
  path.push_back(r);
  int tm = r;
  while(tm != l) {
  	path.push_back(par[tm]);
  	tm = par[tm];
  }
  path.push_back(r);
  int sz = path.size();
  cout << sz << endl;
  for (int i = sz-1; i >= 0; i--) cout << path[i] << " ";
  cout << endl;
   
}