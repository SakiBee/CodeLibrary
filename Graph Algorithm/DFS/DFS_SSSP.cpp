#include <bits/stdc++.h>
using namespace std;
#define pb push_back
bool vis[1012];
int dis[1012];
std::vector<int> v[1012];

void dfs (int src, int d)
{
	vis[src] = 1;
	dis[src] = 0;

	for(auto child : v[src])
		if(!vis[child]) dfs(child,d+1),dis[child] = dis[src]+1;
}


int main()
{
	int n,a,b; cin >> n;
	n--;
	while(n--) cin >> a >> b, v[a].pb(b), v[b].pb(a);

	dfs(1,0);

	int girls,gd,mn = INT_MAX, ans = -1;
	cin >> girls;
	while(girls--){
		cin >> gd;
		if(dis[gd] < mn) mn = dis[gd], ans = gd;
		else if(dis[gd] == mn && gd < ans) ans = gd;
	} cout << ans << endl;

}