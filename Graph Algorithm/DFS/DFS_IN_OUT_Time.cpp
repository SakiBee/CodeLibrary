#include <bits/stdc++.h>
using namespace std;
#define pb push_back
bool vis[20012];
int IN[20012], OUT[20012];
std::vector<int> v[20012];
int timer = 1;
bool dfs (int src)
{
	vis[src] = 1;
	IN[src] = timer++;
	for(auto child : v[src]){
			if(!vis[child]) dfs(child);
				
		}
		OUT[src] = timer++;
}


int main()
{
		int n,m,a,b; cin >> n>>m;
		for(int i=1; i<=n; i++) vis[i] = 0, v[i].clear();
		for(int i=1; i<=m; i++) cin >> a >> b, v[a].pb(b), v[b].pb(a);
		
		
		
		
	return 0;
}