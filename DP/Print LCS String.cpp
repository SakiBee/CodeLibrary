#include <bits/stdc++.h>
using namespace std;
const int N = 1e3;

int dp[N][N], cnt = 0;

string LCS(string a, string b, int n, int m) {
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      if(i == 0 || j == 0) dp[i][j] = 0;
      else if(a[i-1] == b[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
      else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    }
  }
  
  string lcs = "";
  int i = n-1, j = m-1;
  while(i >= 0 and j >= 0) {
    if(a[i] == b[j]) lcs += a[i], i--, j--;
    else if(dp[i][j+1] > dp[i+1][j]) i--;
    else j--;
  }
  reverse(lcs.begin(), lcs.end());
  return lcs;
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  string a, b;
  cin >> a >> b;
  int na = a.size(), nb = b.size();
  memset(dp, 0, sizeof dp);
  cout << LCS(a, b, na, nb) << endl;
}

