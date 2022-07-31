#include <bits/stdc++.h>
using namespace std;
#define pb push_back
bool vis[20012];
int dis[20012];
std::vector<int> v[20012];

void dfs (int src)
{
	vis[src] = 1;

	for(auto child : v[src])
		if(!vis[child]) dfs(child);
}


int main()
{
	int n,m,a,b; cin >> n>>m;
	
	for(int i=1; i<=m; i++) cin >> a >> b, v[a].pb(b), v[b].pb(a);
	int cc=0;
	for(int i=1; i<=n; i++){
		if(!vis[i]) dfs(i),cc++;
	}
	cc == 1 && m == n-cc ? cout << "YES\n" : cout << "NO\n";
	

}