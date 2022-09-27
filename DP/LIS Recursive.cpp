#include <bits/stdc++.h>
using namespace std;

//DP recursive for lis
int dp[1000];
int R_lis(vector<int>& v, int n) {
  if(dp[n] != -1) return dp[n];
  dp[n] = 1;

  for (int i = 0; i < n; i++) {
    if(v[n] > v[i]) 
      dp[n] = max(dp[n], 1 + R_lis(v, i));
  }
  return dp[n];
}

int main() {
  int n; cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  memset(dp, -1, sizeof(dp));
  cout << R_lis(v, n-1) << endl;
}
