#include <bits/stdc++.h>
using namespace std;
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
  mobius();
  
}

