#include <bits/stdc++.h>
using namespace std;

class DSU {
public:
  int components{};
  vector<int> par, sz, rank; //rank is level/height of the sub-tree
                             //sz is the number of node in sub-tree
  DSU(int n) {
    rank.resize(n+1, 0);
    par.resize(n+1);
    sz.resize(n+1, 1);
    iota(par.begin(), par.end(), 0);
    this -> components = n;
  }

  int find(int u) {
    if(par[u] == u) return u;
    return par[u] = find(par[u]);
  }

  void unionRank(int u, int v) {
    u = find(u); v = find(v);
    if(u == v) return;
    components--;
    if(rank[u] < rank[v]) par[u] = v;
    else if(rank[v] < rank[u]) par[v] = u;
    else {
      par[v] = u;
      rank[u]++;
    }
  }

  void unionSize(int u, int v) {
    u = find(u); v = find(v);
    if(u == v) return;
    components--;
    if(sz[u] > sz[v]) swap(u, v);
    sz[v] += sz[u];
    par[u] = v;
  }
};

int32_t main () {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int n; cin >> n;
  DSU dsu(n);
}

