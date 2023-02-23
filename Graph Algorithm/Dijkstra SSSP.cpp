#include <bits/stdc++.h>
using namespace std;
#define     ll      long long
#define     pb      push_back
#define     F       first
#define     S       second

const ll M = 1e5+4;
const ll MX = 1e15;
ll dis[M],f,s,parent[M];
vector<pair<ll,ll>>v[M];

void dijkstra(ll src){
    dis[src] = 0;
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>, greater<pair<ll,ll>> >pq;
    pq.push({0,src});
    while(!pq.empty()) {
        ll par = pq.top().S;
        pq.pop();
        for(auto &[f, s] : v[par]) {
            if(dis[f] > dis[par] + s) {
                dis[f] = dis[par]+s;
                pq.push({dis[f],f});
                parent[f] = par;
            }
        }
    }
}

int main(){
    ll n,m,a,b,w; 
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        cin >> a >> b >> w;
        v[b].pb({a,w});
        v[a].pb({b,w});
    }
    for(int i = 1; i <= n; i++) {
        dis[i] = MX;
    }

    dijkstra(n);

    if(dis[1] == MX){
        cout << -1 << endl;
        return 0;
    }
    ll x = 1;
    while(x != n)
    {
        cout << x << " ";
        x = parent[x];
    }
    cout << x << endl;
    return 0;
}


