//Quick Sort
#include<bits/stdc++.h>
using namespace std;
int partition(vector<int> &v, int l, int h) {
	int i = l, j = h, pivot = v[l];
	while(i<j) {
		while(v[i] <= pivot) i++;
		while(v[j] > pivot) j--;
		if(i<j) swap(v[i], v[j]);
	}
	swap(v[l],v[i-1]);
	return j;
}
void Q_sort(vector<int> &v, int l, int h) {
	if(l < h) {
		int mid = partition(v, l, h);
		Q_sort(v, l, mid-1);
		Q_sort(v, mid+1, h);
	}
}
int main() {
	int n; cin >> n;
	vector<int> v(n);
	for(int i = 0; i < n; i++) cin >> v[i];
	Q_sort(v, 0, n-1);
	for(int i = 0; i < n; i++) cout << v[i] << " ";

}
