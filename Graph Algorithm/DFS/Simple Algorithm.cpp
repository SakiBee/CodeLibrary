#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;
vector <int> g[N];
bool vis[N];
void dfs (int n) {
  vis[n] = 1;
  for (auto u : g[n]) {
    if(!vis[u]) dfs(u);
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  
}
