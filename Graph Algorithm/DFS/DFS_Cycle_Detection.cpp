#include <bits/stdc++.h>
using namespace std;
#define pb push_back
bool vis[20012];
std::vector<int> v[20012];

bool dfs (int src,int parent)
{
	vis[src] = 1;

	for(auto child : v[src]){
			if(!vis[child]){
				if(dfs(child, src)) return 1;
			}
			else if(child == parent) return 1;
		}
		return 0;
}


int main()
{
	int n,m,a,b; cin >> n>>m;
	for(int i=1; i<=n; i++) vis[i] = 0, v[i].clear();
	for(int i=1; i<=m; i++) cin >> a >> b, v[a].pb(b), v[b].pb(a);
	
	
}