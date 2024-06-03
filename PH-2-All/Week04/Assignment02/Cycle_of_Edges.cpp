#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int par[N];
int group_size[N];
void dsu_init(int n){
    for(int i=1;i<=n;i++){
        par[i] = -1;
        group_size[i] = 1;
    }
}
int leader_find(int node){
    if(par[node] == -1) return node;
    int leader = leader_find(par[node]);
    par[node] = leader;
    return leader;
}
void dsu_union(int node1, int node2){
    int leaderA = leader_find(node1);
    int leaderB = leader_find(node2);
    if(group_size[leaderA]>group_size[leaderB]){
        par[leaderB] = leaderA;
        group_size[leaderA] +=group_size[leaderB];
    }
    else{
        par[leaderA] = leaderB;
        group_size[leaderB] +=group_size[leaderA];
    }
}
int main(){
    int n,e;
    cin>>n>>e;
    dsu_init(n);
    int ans =0;
    while(e--){
        int u,v;
        cin>>u>>v;
        int leaderU = leader_find(u);
        int leaderV = leader_find(v);
        if(leaderU == leaderV){
            ans++;
        }
        else{
            dsu_union(u,v);
        }

    }
    cout<<ans<<endl;
    return 0;
}