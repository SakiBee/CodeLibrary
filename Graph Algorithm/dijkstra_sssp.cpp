#include <bits/stdc++.h>
using namespace std;
#define     ll      long long
#define     pb      push_back
#define     F       first
#define     S       second
#define     fori(i,b,e)     for(ll (i)=(b); (i) <= (e); (i)++)
#define     for0(i,n)       for(ll (i)=0; (i) < (n); (i)++)

const ll M = 1e5+4;
const ll MX = 1e15;
ll dis[M],f,s,parent[M];
vector<pair<ll,ll>>v[M];

void dijkstra(ll src){
    dis[src] = 0;
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>, greater<pair<ll,ll>> >pq;
    pq.push({0,src});
    while(!pq.empty()){
        ll par = pq.top().S;
        pq.pop();
        for(auto& child: v[par]){
            f = child.F, s = child.S;
            if(dis[f] > dis[par] + s){
                dis[f] = dis[par]+s;
                pq.push({dis[f],f});
                parent[f] = par;
            }
        }
    }
}

int main(){
    ll n,m,a,b,w; cin >> n >> m;
    fori(i,1,m){
        cin >> a >> b >> w;
        v[b].pb({a,w}), v[a].pb({b,w});
    }
    fori(i,1,n) dis[i] = MX;
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


