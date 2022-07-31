#include <bits/stdc++.h>
using namespace std;
#define     pb              push_back
int merge_sort(vector<int>& v,int l, int r){
    if(l==r) return 0;
    int mid = (l+r)/2;

    int i = l, j = mid+1,k = 0,ret = 0;
    int a = merge_sort(v,l,mid);
    int b = merge_sort(v,mid+1,r);
    vector<int>tm;
    while(i <= mid and j <= r){
        if(v[i] > v[j]) tm.pb(v[j]),j++;
        else tm.pb(v[i]),i++, ret += (j-mid-1);
    }
    while(i<=mid) tm.pb(v[i]),i++, ret += (j-mid-1);
    while(j<=r) tm.pb(v[j]),j++;
    
    for(int x = l; x <= r; x++) v[x] = tm[k++];
    return ret+a+b;
}
int main(){
    int a,n;
    cin >> n;
    vector<int>v(n);
    for(int i=0; i<n; i++) cin >> v[i];
    int ans = merge_sort(v,0,n-1);
    for(int i=0; i<n; i++) cout << v[i] << " ";
    cout << endl << ans << endl;
    return 0;
}
