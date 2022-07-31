#include<bits/stdc++.h>
using namespace std;
#define pb push_back

const int M = 1000001;
std::vector<int> adj[M];
bool vis[M];
int in[M],low[M];
int timer;
set<int>st;

void dfs (int node, int par)
{
	vis[node] = 1;
	in[node] = low[node] = timer++;
	int child_cnt = 0;

	for(auto child : adj[node])
	{
		if(child == par) continue;

		if(vis[child])
		{
			low[node] = min(low[node], in[child]);
		}
		else{
			dfs(child,node);
			low[node] = min(low[node],low[child]);
			if(in[node] <= low[child] && par != -1) st.insert(node);
		}
	}
	if(par == -1 && child_cnt > 1) st.insert(node);

}


int main()
{
	int n,m,a,b,t,x,y;
	while(1)
	{
		cin >> n >> m;
		if(n == 0 && m == 0) break;

		for(int i=1; i<=n; i++) adj[i].clear(), vis[i] = 0;
	    st.clear();
		timer = 1;

		for(int i=1; i<=m; i++) cin >> a >> b, adj[a].pb(b), adj[b].pb(a);

		for(int i=1; i<=n; i++)
			if(!vis[i]) dfs(i,-1);

		cout << st.size() << endl;

	}
}