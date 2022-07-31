#include<bits/stdc++.h>
using namespace std;
#define   pb        push_back
#define   optimize  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

const int M = 1001;
std::vector<int> adj[M];
int disc[M],low[M];
bool vis[M],inStack[M];
stack<int>st;
int cnt_scc,n,m;

void dfs (int src)
{
	static int timer=0;
	low[src] = disc[src] = timer++;
	st.push(src);
	inStack[src] = true;
	vis[src] = 1;

	for(auto child:adj[src])
	{
		if(!vis[child])
		{
			dfs(child);
			if(inStack[child])
			   low[src] = min(low[child],low[src]);
		}
		else if(inStack[child])
			low[src] = min(low[src], disc[child]);
	}

	if(low[src] == disc[src]) 
	{
		cout << "SCC no: " << ++cnt_scc << endl;
		while(1)
		{
			int p  = st.top();
			cout << p << " ";
			inStack[p] = false;
			st.pop();
			if(p == src) break;
		}
		cout << endl;
	}
}

int main()
{
	int a,b;
	cin >> n >> m;
	
	for(int i=1; i<=m; i++) cin >> a >> b, adj[a].pb(b);
	for(int i=1; i<=n; i++) vis[i]=0, inStack[i] = 0;
	for(int i=1; i<=n; i++) if(!vis[i]) dfs(i);
}
