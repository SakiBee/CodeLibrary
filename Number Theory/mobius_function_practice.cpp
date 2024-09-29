//https://www.hackerrank.com/contests/srbd-code-contest-2022-round-1/challenges/coprime-query/submissions/code/1383085090

#include <bits/stdc++.h>
using namespace std;

#define  ll long long
#define  int ll
const int N = 2e5+7;

int mob[N];
void mobius() {
  mob[1] = 1;
  for (int i = 2; i < N; i++) {
    mob[i]--;
    for (int j = i + i; j < N; j += i) {
      mob[j] -= mob[i];
    }
  }
}

int32_t main () {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  mobius();
  int n, q, x; 
  cin >> n >> q;
  vector<int> v(n), cnt(N, 0);
  for (int i = 0; i < n; i++) {
    cin >> x;
    for (int j = 1; j * j <= x; j++) {
      if(x % j == 0) {
        cnt[j]++;
        if(x/j != j) cnt[x/j]++;
      }
    }
  }
  
  
  while(q--) {
    int tot = 0;
    cin >> x;
    for (int j = 1; j * j <= x; j++) {
      if(x % j == 0) {
        tot += (cnt[j] * mob[j]);
        if(x/j != j) {
          tot += (cnt[x/j] * mob[x/j]);
        }
      }
    }
    cout << tot << endl;
  }
  
}
