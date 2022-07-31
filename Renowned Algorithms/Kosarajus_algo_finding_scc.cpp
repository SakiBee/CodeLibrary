#include<bits/stdc++.h>
using namespace std;
#define   pb        push_back
#define   optimize  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

const int M = 1001;
std::vector<int> adj[M],rev[M],order,SCC;
bool vis[M];


void dfs1 (int src)
{
	vis[src] = 1;

	for(auto child: adj[src])
		if(!vis[child]) dfs1(child);
	order.pb(src);
}

void dfs2 (int src)
{
	vis[src] = 1;

	for(auto child: rev[src])
		if(!vis[child]) dfs2(child);
	SCC.pb(src);
}

int main()
{
	int n,m,a,b,t;
	cin >> t;
	while(t--)
	{
		cin >> n >> m;
		int cnt_scc = 0;
		for(int i=1; i<=n; i++) // if node given from 0, i have to put i=0.
			vis[i] = 0, adj[i].clear(),rev[i].clear();
	
		for(int i=1; i<=m; i++) 
			cin >> a >> b, adj[a].pb(b), rev[b].pb(a);

		for(int i=1; i<=n; i++)
			if(!vis[i]) dfs1(i);
		for(int i=1; i<=n; i++) vis[i] = 0;

		for(int i=1; i<=n; i++)
			if(!vis[order[n-i]]){
				SCC.clear();
				dfs2(order[n-i]);
				cnt_scc++;
				cout << "SCC no: " << cnt_scc << endl;
				for(auto node:SCC) cout << node << " ";
				cout << '\n';
			}

	}
}