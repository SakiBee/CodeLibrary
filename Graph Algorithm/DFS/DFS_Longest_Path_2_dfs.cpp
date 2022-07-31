//https://www.spoj.com/problems/PT07Z/
#include <bits/stdc++.h>
using namespace std;


#define pb  push_back
const int mod = 1000000007;
const int M = 100012;
vector<int> adj[M],hight;
bool vis[M];
int mxDis, mxNode,mx;
void dfs (int src,int dis)
{
	vis[src] = 1;
	if(dis > mxDis) mxDis = dis, mxNode = src;
	for(auto child : adj[src])
		if(!vis[child]) dfs(child, dis+1);
}

void dfs1 (int src,int dis)
{
	vis[src] = 1;
	if(dis == (mxDis+1)/2 || dis == (mxDis/2)){
		hight.pb(src);
	}
	if(dis > mx) mx = dis, mxNode = src;
	for(auto child : adj[src])
		if(!vis[child]) dfs1(child, dis+1);
}


void SakiBee ()
{
	int n,m,a,b; cin >> n;

	for(int i=1; i<n; i++) 
		cin >> a >> b,adj[a].pb(b), adj[b].pb(a);
	mxDis = -5;
	dfs(1,0);

	for(int i=1; i<=n; i++) vis[i] =0;
	mxDis = -5;
	dfs(mxNode,0);
	for(int i=1; i<=n; i++) vis[i] =0;
	dfs1(mxNode,0);

	cout << mxDis << endl;
}


int main()
{
	SakiBee();
}
