#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6;

vector<int> parent(N), sz(N);

void make_set(int v) {
	parent[v] = v;
	sz[v] = 1;
}
int find_set(int v) {
	if(v == parent[v]) return v;
	return parent[v] = find_set(parent[v]);
}
void union_set(int a, int b) {
	a = find_set(a);
	b = find_set(b);
	if(a != b) {
		if(sz[a] < sz[b]) swap(a, b);
		parent[b] = a;
		sz[a] += sz[b];
	}
}

int32_t main() {
  for (int i = 0; i < N; i++) make_set(i);

  int n, m; cin >> n >> m;	
  vector<vector<int> >g;
  int u, v, w;

  for (int i = 0; i < m; i++) {
 		cin >> u >> v >> w;
  	g.push_back({w, u, v});
  }
  sort(g.begin(), g.end());

  int cost = 0;
  for (auto e : g) {
  	w = e[0], u = e[1], v = e[2];
  	int p = find_set(u);
  	int q = find_set(v);
  	if(p == q) continue;
  	else {
  		cost += w;
  		union_set(u, v);
  	}
  }
  cout << "cost = " << cost << endl;
}

