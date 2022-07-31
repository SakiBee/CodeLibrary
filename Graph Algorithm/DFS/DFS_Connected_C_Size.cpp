//https://www.codechef.com/problems/FIRESC
#include <bits/stdc++.h>
using namespace std;
#define pb  push_back
const int mod = 1000000007;
const int M = 100012;
std::vector<int> adj[M];
bool vis[M];

int cc_size = 0;

void dfs (int src)
{
	vis[src] = 1;
	cc_size++;

	for(auto child : adj[src])
		if(!vis[child]) dfs(child);
}


void SakiBee ()
{
	int n,m,a,b; cin >> n >> m;

	for(int i=1; i<=n; i++) adj[i].clear(), vis[i] =0;

	for(int i=1; i<=m; i++) cin >> a >> b, adj[a].pb(b), adj[b].pb(a);

	long long cc = 0, tot_cc = 1;
	for(int i=1; i<=n; i++) if(!vis[i]){
		cc_size = 0;
		cc++;
		dfs(i);
		tot_cc = (tot_cc*cc_size)%mod; 
	}
	cout << cc << " " << tot_cc << endl;
}


int main()
{
	int tt; cin >> tt;
	while(tt--)
	{
		SakiBee();
	}
}