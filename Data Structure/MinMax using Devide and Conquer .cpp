#include <bits/stdc++.h>
using namespace std;

int mx = INT_MIN, mn = INT_MAX;

void findMinMax(vector<int>& v, int l, int r) {
  if (l == r) {
    mx = max(mx, v[l]);
    mn = min(mn, v[r]);
    return;
  }
  if (r - l == 1) {
    if (v[l] < v[r]) {
      mx = max(mx, v[r]);
      mn = min(mn, v[l]);
    }
    else {
      mx = max(mx, v[l]);
      mn = min(mn, v[r]);
    }
    return;
  }

  int mid = (l + r) / 2;
  findMinMax(v, l, mid);
  findMinMax(v, mid + 1, r);
}
 
int main() {
  int n; cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  
  findMinMax(v, 0, n - 1);

  cout  << "Min Value is " << mn << endl;
  cout  << "Max Value is " << mx << endl;
  return 0;
}
