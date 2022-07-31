#include<bits/stdc++.h>
using namespace std;
void selection_sort(vector<int> &v, int n) {
	int i=0;
	while(i<n-1) {
		int mn = i;
		for(int j=i+1; j<n; j++) {
			if(v[j] < v[mn]) mn = j;
		}
		swap(v[i], v[mn]);
		i++;
	}
}
int main() {
	int n; cin >> n;
	vector<int> v(n);
	for(int i=0; i<n; i++) cin >> v[i];
	selection_sort(v,n);
	for(int i=0; i<n; i++) cout << v[i] << " ";
}
