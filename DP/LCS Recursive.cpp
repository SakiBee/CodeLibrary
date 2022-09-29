#include <bits/stdc++.h>
using namespace std;
const int N = 10000;
int dp[N][N];

//Recursive
int LCS(string a, string b, int i, int j) {
  if(i < 0 || j < 0) return 0;
  if(dp[i][j] != -1) return dp[i][j];
  if(a[i] == b[j]) dp[i][j] = 1 + LCS(a, b, i - 1, j - 1);
  else dp[i][j] = max(LCS(a, b, i - 1, j), LCS(a, b, i, j - 1));
  
  return dp[i][j];
}



int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  memset(dp, -1, sizeof(dp));
  string a, b; cin >> a >> b;
  int n = a.size(), m = b.size();
  cout << LCS(a, b) << endl;
}
