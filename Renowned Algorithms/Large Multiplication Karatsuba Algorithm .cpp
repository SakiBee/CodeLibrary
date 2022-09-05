
//https://www.youtube.com/watch?v=yWI2K4jOjFQ


#include <bits/stdc++.h>
//#include<dbg.h>
using namespace std;
#define int long long

int karatsuba(int p, int q) {
  if(p < 10 || q < 10) return p * q;
  else {
    int n = max(log10(p), log10(q)) + 1;
    int pw = pow(10, (n/2));
    int a = p / pw;
    int b = p % pw;
    int c = q / pw;
    int d = q % pw;

    int ac = karatsuba(a, c);
    int bd = karatsuba(b, d);

    int ac_plus_bd = karatsuba(a+b, c+d) - ac - bd;

    return ac * pw * pw + ac_plus_bd * pw + bd;
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int x, y; cin >> x >> y;
  cout << karatsuba(x, y) << endl;
}
