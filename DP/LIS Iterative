#include <bits/stdc++.h>
using namespace std;


//DP iterative for lis
void lis(vector<int>& v) {
  int n = v.size();
  vector<int> lis(n, 1), lis_ar;

  for (int i = 1; i < n; i++) {
    for (int j = 0; j < i; j++)
      if (v[i] > v[j] && lis[i] < lis[j] + 1)
        lis[i] = lis[j] + 1;
  }
  int mx = *max_element(lis.begin(), lis.end());
  cout << mx << endl;
  int tm = mx;
  for (int i = n - 1; i >= 0; i--) {
    if(lis[i] == tm) {
      tm--;
      lis_ar.push_back(v[i]);
    }
  }
  reverse(lis_ar.begin(), lis_ar.end());
  for (auto u : lis_ar) cout << u << " "; cout << endl;
}

int main() {
  int n; cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  lis(v);
}
