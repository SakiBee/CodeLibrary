#include <bits/stdc++.h>
using namespace std;
const int N = 1005;

int dp[N][N];

int lps(string s, int i, int j) {
	if (i == j)	return 1;
	if (dp[i][j] != -1) return dp[i][j];
	
	if (s[i] == s[j]) {
		if(i + 1 == j) return 2;
		else return dp[i][j] = 2 + lps(s, i + 1, j - 1);
	}
	return dp[i][j] = max(lps(s, i + 1, j), lps(s, i, j - 1));
}


int main() {
	string s; cin >> s;
	int n = s.size();
	memset(dp, -1, sizeof(dp));
	cout << lps(s, 0, n-1) << endl;
	return 0;
}
