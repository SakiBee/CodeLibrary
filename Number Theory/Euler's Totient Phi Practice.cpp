#include <bits/stdc++.h>
using namespace std;
#define  ll long long
#define  int ll
const int N = 3e5+7;

int euler_totient(int n) {
    int res = n;
    for (int p = 2; p * p <= n; ++p) {
        if (n % p == 0) {
            while (n % p == 0) n /= p;
            res -= res / p;
        }
    }
    if (n > 1) res -= res / n;
    return res;
}

vector<int> divisors(int n) {
    vector<int> divs;
    for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            divs.push_back(i);
            if (i != n / i) divs.push_back(n / i);
        }
    }
    return divs;
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t, tc = 0;
    cin >> t;
    while (t--) {
      cout << "Case " << ++tc << ": ";
        int n, q;
        cin >> n >> q;

        vector<int> qry(q);
        for (int i = 0; i < q; ++i) {
            cin >> qry[i];
        }

        vector<int> div = divisors(n);
        
        map<int, int> mp;
        for (int d : div) {
            mp[d] = euler_totient(n / d);
        }
        
        for (int i = 0; i < q; ++i) {
            int m = qry[i];
            if (n % m != 0) {
                cout << 0 << " ";
            } else {
                cout << mp[m] << " ";
            }
        }
        cout << "\n";
    }

    return 0;
}
