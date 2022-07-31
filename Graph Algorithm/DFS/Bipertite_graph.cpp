#include <bits/stdc++.h>
using namespace std;
#define pb push_back
bool vis[20012];
int col[20012];
int dis[20012];
std::vector<int> v[20012];

bool dfs (int src,int c)
{
	vis[src] = 1;
	col[src] = c;

	for(auto child : v[src]){
			if(!vis[child]){
				if(!dfs(child, c^1)) return 0;
			}
			else if(col[src] == col[child]) return false;
		}
		return true;
}


int main()
{
	int t; cin >> t;
	for(int test=1; test<=t; test++){
		
		int n,m,a,b; cin >> n>>m;
		for(int i=1; i<=n; i++) vis[i] = 0, v[i].clear();
		for(int i=1; i<=m; i++) cin >> a >> b, v[a].pb(b), v[b].pb(a);
			
		bool ans = true;
		for(int i=1; i<=n; i++)
			if(!vis[i])
				if(!dfs(i,0)) ans = false;

		cout << "Scenario #" << test << ":" << endl;
		ans ? cout << "No suspicious bugs found!\n" : cout << "Suspicious bugs found!\n";
		
	}return 0;
}