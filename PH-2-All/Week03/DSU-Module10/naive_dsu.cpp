#include <bits/stdc++.h>
using namespace std;
int par[105];

void initialize_par(int n){
    for(int i=1;i<=n;i++){
        par[i] = -1;
    }
}
int dsu_find(int node){
    if(par[node] ==-1) return node;
    int leader = dsu_find(par[node]);
    par[node] = leader;
    return leader;
}
void dsu_union(int node1,int node2){
    int leaderA = dsu_find(node1);
    int leaderB = dsu_find(node2);
    if(leaderA != leaderB){
        par[leaderA] = leaderB;
    }
}
int main(){
    int n,e;
    cin>>n>>e;
    initialize_par(n);
    while(e--){
        int u,v;
        cin>>u>>v;
        dsu_union(u,v);
    }
    for(int i=0;i<=n;i++){
        cout<<par[i]<<" ";
    }
    return 0;
}