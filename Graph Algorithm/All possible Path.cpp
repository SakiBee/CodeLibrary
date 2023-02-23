//https://leetcode.com/problems/all-paths-from-source-to-target/

#include <bits/stdc++.h>
using namespace std;
const int N = 1e4+7;

vector<int> g[N];
bool vis[N];
void dfs(int s, int t, vector<int>& v) {
	v.push_back(s);
	vis[s] = 1;
	for (auto u : g[s]) {
		if(u == t) {
			for (auto x : v) cout << x << " ";
			cout << t << endl;
		}
		else {
			dfs(u, t, v);
		}
	}
	v.pop_back();
}

int32_t main () {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int n, s, t, x, y;
  cin >> n >> s >> t;
  for (int i = 0; i < n; i++) {
  	cin >> x >> y;
  	g[x].push_back(y);
  }
  vector<int> v;
  dfs(s, t, v);
  
   
}