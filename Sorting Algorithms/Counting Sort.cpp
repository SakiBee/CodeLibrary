#include <bits/stdc++.h>
using namespace std;


vector<int> Count_sort(vector<int>& v, int n) {
  int mx = v[0];
  for (int i = 1; i < n; i++) mx = max(mx, v[i]);
  vector<int> count(mx+1, 0), pre(mx+1, 0), ans(n);

  for (int i = 0; i < n; i++) count[v[i]]++;
  pre[0] = count[0];
  for (int i = 1; i <= mx; i++) pre[i] = pre[i-1] + count[i];
  for (int i = n-1; i >= 0; i--) ans[--pre[v[i]]] = v[i];

  return ans;
}

int main() {
  int n; cin >> n;
  vector<int> v(n), ans;
  for (int i = 0; i < n; i++) cin >> v[i];
  ans = Count_sort(v, n);

  for (int i = 0; i < n; i++) cout << ans[i] << " ";
  cout << endl;
  
}
