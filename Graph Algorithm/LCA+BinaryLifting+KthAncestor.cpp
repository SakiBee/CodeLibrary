//Problem Link: https://www.hackerrank.com/contests/srbd-code-contest-2024-round-1/challenges/terror-in-terminus/problem

#include <bits/stdc++.h>
using namespace std;
// #ifndef ONLINE_JUDGE
//   #include "dbg.h"    
// #endif
const int N = 3e5+7, LOG = 17;

vector<int> g[N];
int up[N][LOG], dep[N];

void reset(int n) {
  for (int i = 1; i <= n; i++) {
    g[i].clear();
    dep[i] = 0;
    for (int j = 0; j < LOG; j++) up[i][j] = -1;
  }
}

void dfs(int n, int par) {
  up[n][0] = par;
  for(int i = 1; i < LOG; i++) {
    if(up[n][i-1] != -1) {
      up[n][i] = up[up[n][i-1]][i-1];
    }
  }
  for (auto u : g[n]) {
    if(par != u) {
      dep[u] = dep[n] + 1;
      dfs(u, n);
    }
  }
}

int lca(int u, int v) {
  if(dep[u] < dep[v]) swap(u, v);

  int dif = dep[u] - dep[v];

  for (int i = LOG-1; i >= 0; i--) {
    if(dif & (1<<i)) u = up[u][i];
  }
  if(u == v) return u;

  for (int i = LOG-1; i >= 0; i--) {
    if(up[u][i] != up[v][i]) {
      u = up[u][i];
      v = up[v][i];
    }
  }
  return up[u][0];
}

int kthAncestor(int u, int k) {
  for (int i = LOG-1; i >= 0; i--) {
    if(k & (1 << i)) u = up[u][i];
  }
  return u;
}

void solve () {
  int n, u, v, q; cin >> n;
  reset(n);
  for (int i = 1; i < n; i++) {
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(1, -1);

  cin >> q;
  while(q--) {
    cin >> u >> v;
    int _lca = lca(u, v);
    int dlca = dep[_lca];
    int du = dep[u];
    int dv = dep[v];
    
    du -= dlca;
    dv -= dlca;
    // debug(du, dv, dlca,  _lca);

    int ans = 0;
    if(du == dv) ans = _lca; 
    else if(du == 0 || dv > du) ans = kthAncestor(v, (dv + du + 1) / 2);
    else ans = kthAncestor(u, (du + dv) / 2); //(dv == 0 || du > dv)

    cout << ans << '\n';
  }
}

int32_t main () {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int __ = 1; 
  cin >> __; 
  while(__--) {
    solve();
  }
}
