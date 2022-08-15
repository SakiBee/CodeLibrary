#include<bits/stdc++.h>
using namespace std;

const int N = 1e6, mod = 1e9 + 7;

//Big mod for inverse modular arithmetic
int power(long long n, long long k) {
  int ans = 1 % mod; n %= mod; if (n < 0) n += mod;
  while (k) {
    if (k & 1) ans = (long long) ans * n % mod;
    n = (long long) n * n % mod;
    k >>= 1;
  }
  return ans;
}

int Fact[N], invFact[N];

//nCr
int nCr(int n, int r) {
  if (n < r or n < 0) return 0;
  return 1LL * Fact[n] * invFact[r] % mod * invFact[n - r] % mod;
}

//nPr
int nPr(int n, int r) {
  if (n < r or n < 0) return 0;
  return 1LL * Fact[n] * invFact[n - r] % mod;
}


//Factorial and Inverse Factorial
void precal() {
  
  //Factorial precalculation
  
  Fact[0] = 1;
  for (int i = 1; i < N; i++) {
    Fact[i] = 1LL * i * Fact[i - 1] % mod;
  }
  
  //Inverse Factorial Calculation
  
  invFact[N - 1] = power(Fact[N - 1], mod - 2);
  for (int i = N - 2; i >= 0; i--) {
    invFact[i] = 1LL * invFact[i + 1] * (i + 1) % mod;
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  precal(); // declare precal fuction
  
  cout << nCr(6, 2) << '\n';
  cout << nPr(6, 2) << '\n';
  cout << 
  return 0;
}
