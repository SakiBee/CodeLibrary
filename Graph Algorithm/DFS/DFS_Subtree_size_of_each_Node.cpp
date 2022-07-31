#include<bits/stdc++.h>
using namespace std;
#define pb push_back

const int M = 100012;
std::vector<int> adj[M];
std::vector<int> prime;
bool vis[M];
int dis[M];

void bfs (int src)
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
		{
			if(!vis[child]){
				vis[child] = 1;
				dis[child] = dis[tem]+1;
				q.push(child);
			}
		}
	}
}

bool isPrime(int n)
{
	for(int i=2; i*i<=n; i++)
		if(n%i == 0) return false;
	return true;
}

bool isValid(int a, int b)
{
	int cnt = 0;
	while(a>0)
	{
		if(a%10 != b%10) cnt++;
		a/=10, b/=10;
	}
	if(cnt == 1) return true;
	else return false;
}

void buildGraph ()
{
	for(int i=1000; i<9999; i++)
		if(isPrime(i)) prime.pb(i);
	for(int i=0; i<prime.size(); i++)
	{
		for(int j=i+1; j<prime.size(); j++)
		{
			int x = prime[i];
			int y = prime[j];

			if(isValid(x,y)) adj[x].pb(y), adj[y].pb(x);
		}
	}
}


int main()
{
	int tt, a, b; cin >> tt;
	buildGraph();
	while(tt--)
	{
		cin >> a >> b;
		for(int i=1000; i<9999; i++) dis[i] = -1,vis[i]=0;
		
		bfs(a);
		if(dis[b] == -1) cout << "Impossible\n";
		else cout << dis[b] <<'\n';

	}
}