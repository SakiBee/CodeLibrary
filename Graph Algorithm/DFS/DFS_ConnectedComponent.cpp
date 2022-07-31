#include<bits/stdc++.h>
using namespace std;

bool vis[10000];
std::vector<int> v[10000];

void dfs(int n)
{
	vis[n] = 1;
	for(auto child : v[n])
		if(!vis[child]) dfs(child);
}


int main()
{
	int n,m,a,b;
	cin >> n >> m;
	for(int i=1; i<=m; i++)
		cin >> a >> b, v[a].push_back(b), v[b].push_back(a);

	int cc = 0;
	for(int i=1; i<=n; i++)
		if(!vis[i]) dfs(i), cc++;

	cout << cc << endl;
}