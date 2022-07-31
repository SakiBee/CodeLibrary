#include <bits/stdc++.h>
using namespace std;
#define ll long long

void Kadans_algo(ll n, vector<ll>& v)
{
  ll mx_sum = INT_MIN, csum = 0,left=0,right=0;

  for(int i = 0; i < n; i++) {
    csum += v[i];
    if(v[i] > csum) csum = v[i],left++;
    if(csum > mx_sum) mx_sum = csum,right++;
  }


  ll sub_size = right-left+1;
  cout << "subarray size is : " << sub_size << endl;
  cout << "sunarray is : ";
  for(int i=left; i<=right; i++) cout << v[i] << " "; 
  cout << endl;
  cout << "subarray sum is : ";
  cout << mx_sum <<  endl;
}


int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  ll n; cin >> n;
  vector<ll> v(n);
  for(int i = 0; i < n; i++) cin >> v[i];
  Kadans_algo(n, v);
}
