Problem Link: https://codeforces.com/contest/1722/problem/E


#include <bits/stdc++.h>
//#include<dbg.h>
using namespace std;
#define int long long
const int N = 1010;
int pre[N][N], v[N][N];

int cal(int A, int B, int a, int b) {
	return (1LL * pre[A][B] - pre[A][b-1] - pre[a-1][B] + pre[a-1][b-1]);
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int tc; cin >> tc;
  while(tc--) {
  	memset(pre, 0, sizeof(pre));
  	memset(v, 0, sizeof(v));
	  int n, m, a, b; cin >> n >> m;

	  for (int i  = 1; i <= n; i++) {
	  	cin >> a >> b;
	  	v[a][b] += 1LL * a * b;
	  }

	  for (int i  = 1; i < N; i++) {
	  	for (int j = 1; j < N; j++) {
	  		pre[i][j] = 1LL * pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1] + v[i][j];
	  	}
	  }
	  int A, B;
	  while(m--) {
	  	cin >> a >> b >> A >> B;
	  	cout << cal(A - 1, B - 1, a + 1, b + 1) << endl;
	  }
  }
  
}
