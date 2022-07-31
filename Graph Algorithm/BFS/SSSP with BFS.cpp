#include <bits/stdc++.h>
using namespace std;

const int mx = 1009;
bool vis[mx];
vector<int>adj[mx];
int dis[mx];

void bfs_sssp(int src)
{
	queue<int>q;
	q.push(src);
	vis[src] = 1;
	dis[src] = 0;
	while(!q.empty())
	{
		int tem = q.front();
		q.pop();
		for(auto child : adj[tem]) 
			if(vis[child] == 0){
				q.push(child);
				vis[child] = 1;
				dis[child] = dis[tem]+1;
			}
	}
}

int main()
{
	int test,r,c,a,b; cin >> test;
	while(test--){
		
		cin >> r >> c;
		for(int i=1; i<=r; i++) vis[i] = 0, adj[i].clear();
		
		while(c--) cin >> a >> b, adj[a].push_back(b), adj[b].push_back(a);
		
		bfs(1);

		cout << dis[r] << endl;

	}
}



