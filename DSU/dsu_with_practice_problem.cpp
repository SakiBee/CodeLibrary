//https://www.hackerrank.com/contests/srbd-code-contest-2022-round-1/challenges/building-a-research-and-development-center/submissions/code/1383269777
#include <bits/stdc++.h>
using namespace std;
#define endl '\n';

class DSU {
public:
  int components{};
  vector<int> par, sz, rank; //rank is level/height of the sub-tree
                             //sz is the number of node in sub-tree
  vector<pair<int, int> >lead;
  DSU(vector<int>& a, int n) {
    rank.resize(n+1, 0);
    par.resize(n+1);
    sz.resize(n+1, 1);
    lead.resize(n, {0, 0});
    for (int i = 0; i < n; i++) {
      lead[i] = {a[i], i};
    }
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
    sz[u] += sz[v];
    par[v] = u;

    if(lead[v].first > lead[u].first) {
      lead[u] = lead[v];
    }
    else if(lead[u].first == lead[v].first) {
      lead[u] = {lead[u].first, max(lead[u].second, lead[v].second)};
    }
  }

  void upd(int id, int val) {
    int pre_id = find(id);
    if(lead[pre_id].first < val) 
      lead[pre_id] = {val, id};
    else if(lead[pre_id].first == val) 
      lead[pre_id] = {lead[id].first, max(lead[pre_id].second, id)};
  }
};

int32_t main () {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int n, q, x; cin >> n >> q;
  vector<int> v(n);
  for (int i = n-1; i >= 0; i--) {
    cin >> x;
    v[x] = i;
  }
  DSU dsu(v, n);
  
  int t, a, b;
  while(q--) {
    cin >> t;
    if(t == 1) {
      cin >> a >> b;
      dsu.unionSize(a, b);
    }
    else if(t == 2) {
      cin >> a;
      v[a]++;
      dsu.upd(a, v[a]);
    }
    else {
      cin >> a;
      a = dsu.find(a);
      cout << dsu.lead[a].second << endl;
    }
  }
}

