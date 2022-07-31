//Insertion Sort
#include<bits/stdc++.h>
using namespace std;

void insertion_sort(vector<int> &v, int h){
	int temp, i = 1, j;
	while(i < h){
		temp = v[i];
		j = i - 1;
		while(v[j] > temp and j >= 0) v[j + 1] = v[j], j--;
		v[j + 1] = temp;
		i++;
		for(int p = 0; p < h; p++) cout << v[p] << " ";
		cout << endl;
	}
}
int main(){
	int n; cin >> n;
	vector<int> v(n);
	for(int i = 0; i < n; i++) cin >> v[i];
	insertion_sort(v, n);
	for(int i = 0; i < n; i++) cout << v[i] << " ";
}
