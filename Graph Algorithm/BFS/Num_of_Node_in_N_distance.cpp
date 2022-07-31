#include<bits/stdc++.h>
using namespace std;
#define pb push_back

const int M = 1000001;
std::vector<int> adj[M];
bool vis[M];
int dis[M],level[M];

void bfs (int src)
{
	queue<int>q;
	q.push(src);
	vis[src] = 1;
	dis[src] = 0;

	while(!q.empty())
	{
		int f = q.front();
		q.pop();
		for( auto child : adj[f])
			if(!vis[child])
			{
				vis[child] = 1;
				dis[child] = dis[f]+1;
				level[dis[child]]++;
				q.push(child);
			}
	}
}

int main()
{
	int n,m,a,b,q,x,y;
	cin >> n >> m;

	for(int i=1; i<=m; i++) cin >> a >> b, adj[a].pb(b), adj[b].pb(a);

	cin >> x;
	while(x--)
	{
		cin >> a >> b;
		for(int i=0; i<=n; i++) vis[i] = 0, level[i] = 0;

		bfs(a);
		cout << level[b] << endl;
	}
}

