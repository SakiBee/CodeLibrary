#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define     optimize        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

const int M = 1000001;
std::vector<int> adj[M],res;
bool vis[M];
int inDeg[M];

bool kahns_algo (int n)
{
	//queue<int>q;
	priority_queue<int,vector<int>,greater<int> >q;
	for(int i=1; i<=n; i++) if(inDeg[i] == 0) q.push(i);

	while(!q.empty())
	{
		int temp = q.top();
		q.pop();
		res.pb(temp);

		for(auto child: adj[temp]) 
		{
			inDeg[child]--;
			if(inDeg[child] == 0) q.push(child);
		}
	}
	return res.size() == n;
}


int main()
{
	optimize;
	int n,m,a,b,t;
	cin >> n >> m;
	for(int i=1; i<=m; i++) cin >> a >> b, adj[a].pb(b), inDeg[b]++;

	if(!kahns_algo(n)) cout << "Sandro fails.\n";
	//cout << "After Topological Sort\n";
	else{
		for(auto ans : res) cout << ans << " ";
		cout << '\n';}


}