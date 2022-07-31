#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define     optimize        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

const int M = 10;

char grid[M][M];
bool vis[M][M];
int dis[M][M];

int ex,ey;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
//knight move
int kx[] = {-2,-1,1,2,2,1,-1,-2};
int ky[] = {1,2,2,1,-1,-2,-2,-1};



bool isValid (int x, int y)
{
	if(x > 8 || x < 1 || y > 8 || y < 1) return false;
	if(vis[x][y]) return false;
	return true;
}

int bfs (int x, int y)
{
	queue<pair<int,int> > qp;
	qp.push({x,y});
	vis[x][y] = 1;
	dis[x][y] = 0;

	if(x == ex && y == ey) return dis[x][y];

	while(!qp.empty()){

		int cx = qp.front().first;
		int cy = qp.front().second;
		qp.pop();
		for(int i=0; i<8; i++)
		{
			if(isValid(cx+kx[i],cy+ky[i]))
			{
				x = cx+kx[i];
				y = cy+ky[i];
				vis[x][y] = 1;
				dis[x][y] = dis[cx][cy] + 1;
				qp.push({x,y});

				if(x == ex && y == ey) return dis[x][y];

			}
		}
	}
}

int main()
{
	optimize;
	int sx,sy,t;
	cin >> t;
	while(t--){
		string s1,s2;
		cin >> s1 >> s2;
		
		for(int i=1; i<=8; i++){
			for(int j=1; j<=8; j++) vis[i][j] = 0;}

		sx = s1[0]-'a'+1;
		sy = s1[1]-'0';
		ex = s2[0]-'a'+1;
		ey = s2[1]-'0';
		
		cout << bfs(sx,sy) << endl;
	}
}