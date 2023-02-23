//https://leetcode.com/problems/rotting-oranges/

#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+7;


vector<int> dx = {1, -1, 0, 0};
vector<int> dy = {0, 0, 1, -1};
map<pair<int, int>, int >vis, dis;
bool isVal(int i, int j, int m, int n) {
    return (i >= 0 and j >= 0 and i < m and j < n);
}
int orangesRotting(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    queue<pair<int, int> >q;
    
    int good = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            vis[{i, j}] = 0;
            if(grid[i][j] == 2) {
                q.push({i, j});
                dis[{i, j}] = 0;
                vis[{i, j}] = 1;
            }
            else if(grid[i][j] == 1) {
                good++;
            }
        }
    }
    int ans = 0;
    while(!q.empty()) {
        auto [i, j] = q.front();
        q.pop();
        for (int k = 0; k < 4; k++) {
            int X = dx[k] + i;
            int Y = dy[k] + j;
            if(isVal(X, Y, m, n) and !vis[{X, Y}] and grid[X][Y] != 0) {
                q.push({X, Y});
                dis[{X, Y}] = dis[{i, j}] + 1;
                ans = max(ans, dis[{X, Y}]);
                good--;
                vis[{X, Y}] = 5;
            }
        }
    }
    if(good == 0) return ans;
    else return -1;
}

int32_t main () {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  
  int n, m; cin >> m >> n;
  vector<vector<int> >g(m, vector<int>(n, 0));
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cin >> g[i][j];
    }
  }

  cout << orangesRotting(g) << endl;
}