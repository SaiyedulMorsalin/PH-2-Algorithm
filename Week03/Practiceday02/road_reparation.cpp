#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 1e5+5;
ll parent[N];
ll group_size[N];
void dsu_init(ll n){
    for(ll i=1;i<=n;i++){
        parent[i] = -1;
        group_size[i] = 1;
    }
}
ll find_leader(ll node){
    if(parent[node] == -1) return node;
    ll leader = find_leader(parent[node]);
    parent[node] = leader;
    return leader;
}
void dsu_union(ll node1,ll node2){
    ll leaderA = find_leader(node1);
    ll leaderB = find_leader(node2);
    if(group_size[leaderA]>group_size[leaderB]){
        parent[leaderB] = leaderA;
        group_size[leaderA] +=group_size[leaderB];
    }
    else{
        parent[leaderA] = leaderB;
        group_size[leaderB] +=group_size[leaderA];
    }
}
class Edge{
    public:
    ll u,v,w;
    Edge(ll u, ll v, ll w){
        this->u= u;
        this->v= v;
        this->w= w;

    }
};
bool cmp(Edge a, Edge b){
    return a.w < b.w;
}
int main(){
    ll n,e;
    cin>>n>>e;
    dsu_init(n);
    ll totalCost = 0;
    vector<Edge>edgeList;
    while(e--){
        ll u,v,w;
        cin>>u>>v>>w;
        edgeList.push_back(Edge(u,v,w));
    }
    
    sort(edgeList.begin(),edgeList.end(),cmp);
    for(Edge ed : edgeList){
        ll u = ed.u;
        ll v = ed.v;
        ll w = ed.w;
        ll leaderU = find_leader(u);
        ll leaderV = find_leader(v);
        if(leaderU == leaderV){
            continue;
        }
        else{
            dsu_union(u,v);
            totalCost+=w;
        }
    }
    if(totalCost<0){
        cout<<"IMPOSSIBLE"<<endl;
    }
    else{
        cout<<totalCost<<endl;
    }
    

    return 0;
}