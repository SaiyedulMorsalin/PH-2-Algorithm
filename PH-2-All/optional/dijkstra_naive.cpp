#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 2e5+5;
ll dis[N];
ll parent[N];
vector<pair<ll,ll>>v[N];
void dijkstra_init(ll n){
    for(ll i=1;i<=n;i++){
        dis[i] = 1e18;
        parent[i] = -1;
    }
}
void dijkstra(ll src){
    queue<pair<ll,ll>>q;
    q.push({src,0});
    dis[src] = 0;
    while (!q.empty())
    {
        pair<ll,ll>pr = q.front();
        q.pop();
        ll node = pr.first;
        ll cost = pr.second;
        for(pair<ll,ll>child: v[node]){
            ll childNode = child.first;
            ll childCost = child.second;
            if(childCost + cost<dis[childNode]){
                dis[childNode] = childCost + cost;
                q.push({childNode,dis[childNode]});
                parent[childNode] = node;

            }
        }
    }
    
}
int main(){
    ll n,e;
    cin>>n>>e;
    while(e--){
        ll a,b,c;
        cin>>a>>b>>c;
        v[a].push_back({b,c});
        v[b].push_back({a,c});
    }
    dijkstra_init(n);
    dijkstra(1);
 
    ll x = n;
    vector<ll>path;
    while(x!= -1){
        path.push_back(x);
        x = parent[x];
    }
    if(path.size() <=1){
        cout<<"-1"<<endl;
    }
    else{
        reverse(path.begin(),path.end());
        for(ll v:path){
        cout<<v<<" ";
        }

    }
    
    
    return 0;
}