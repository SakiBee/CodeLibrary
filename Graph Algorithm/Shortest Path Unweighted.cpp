#include<bits/stdc++.h>
using namespace std;

#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;
vector<int> g[N];
bool vis[N]; 
int col[N], par[N], lvl[N];


int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m; cin >> n >> m;
  while (m--) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  int s, t; cin >> s >> t;
  queue<int> q;
  q.push(s);
  vis[s] = 1;
  par[s] = -1;
  lvl[s] = 0;
  while(!q.empty()) {
    int p = q.front();
    q.pop();
    for (auto u : g[p]) {
      if(!vis[u]) {
        q.push(u);
        par[u] = p;
        vis[u] = 1;
        lvl[u] = lvl[p] + 1;
      }
    }
  }
  cout << lvl[t] << endl;
}