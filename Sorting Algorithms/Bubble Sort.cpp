//Bubble Sort
#include<bits/stdc++.h>
using namespace std;

void bubble_sort(vector<int> &v, int n){
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n-i-1; j++) {
			if(v[j] > v[j+1]) swap(v[j+1], v[j]);
		}
	    for (int i = 0; i < n; i++) cout << v[i] << " ";
	    cout << endl;
	}
}
int main(){
	int n; cin >> n;
	vector<int> v(n);
	for(int i = 0; i < n; i++) cin >> v[i];
	bubble_sort(v, n);
	for(int i = 0; i < n; i++) cout << v[i] << " ";
}
