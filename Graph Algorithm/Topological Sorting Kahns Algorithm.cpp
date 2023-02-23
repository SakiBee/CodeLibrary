//https://cses.fi/problemset/task/1679
//https://leetcode.com/problems/course-schedule-ii/

#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+7;

vector<int> g[N], indeg(N);
bool vis[N];

int32_t main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n, m; cin >> n >> m;
  int x, y;
  for (int i = 0; i < m; i++) {
  	cin >> x >> y;
  	g[x].push_back(y);
    indeg[y]++;
  }
  //ready can be a queue
  vector<int> ready, ans;
  for (int i = 1; i <= n; i++) {
    if(indeg[i] == 0) {
      ready.push_back(i);
      vis[i] = 1;
    }
  }
  while(ans.size() < n) {
    if(ready.empty()) {
      cout << "IMPOSSIBLE\n";
      return 0;
    }
    int cur = ready.back();
    ready.pop_back();
    ans.push_back(cur);
    for (auto u : g[cur]) {
      indeg[u]--;
      if(!vis[u] and indeg[u] == 0) {
        ready.push_back(u);
        vis[u] = 1;
      }
    }
  }
  
  for (auto u : ans) cout << u << " ";
  cout << endl;
  
}