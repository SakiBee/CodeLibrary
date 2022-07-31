#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define     optimize        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
const int M  = 1001;

char grid[M][M];
bool vis[M][M];
int  m,n,cnt;

bool isValid (int x, int y)
{
	if(x < 1 || x > n || y < 1 || y > m) return 0;
	if(vis[x][y] || grid[x][y] == '#') return 0;
	return 1;	
}

int dx[] = {-1, 0, 1, 0};  // when angle will share
int dy[] = {0, 1, 0, -1};

void dfs (int x, int y)
{
	vis[x][y] = 1;
	cnt++;
	//for(int i=0; i<4; i++){if(isValid(x+dx[i],y+dy[i])) dfs(x+dx[i],y+dy[i]);} // when angle share
	//otherwise
	if(isValid(x-1, y)) dfs(x-1,y);
	if(isValid(x, y+1)) dfs(x,y+1);
	if(isValid(x+1, y)) dfs(x+1,y);
	if(isValid(x, y-1)) dfs(x,y-1);
}


int main()
{
	optimize;
	cin >> n >> m;
	cnt=0;
	for(int i=1; i<=n; i++) for(int j=1; j<=m; j++) cin >> grid[i][j];

	int cc = 0;
	for(int i=1; i<=n; i++) for(int j=1; j<=m; j++)
			if(grid[i][j] == '.' && !vis[i][j]) dfs(i,j), cc++;

	cout << cnt << endl;

}