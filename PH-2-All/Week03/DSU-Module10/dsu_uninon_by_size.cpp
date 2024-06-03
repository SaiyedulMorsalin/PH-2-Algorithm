#include <bits/stdc++.h>
using namespace std;
int parent[1005];
int group_size[1005];
void dsu_init(int n){
    for(int i=0;i<n;i++){
        parent[i] = -1;
        group_size[i] = 1;
    }
}
int leader_find(int node){
    if(parent[node] == -1) return node;
    int leader = leader_find(parent[node]);
    parent[node] = leader;
    return leader;
}
void union_by_size(int node1,int node2){
    int leaderA = leader_find(node1);
    int leaderB = leader_find(node2);
    if(group_size[leaderA]>group_size[leaderB]){
        parent[leaderB] = leaderA;
        group_size[leaderA] +=group_size[leaderB];
    }
    else{
        parent[leaderA] = leaderB;
        group_size[leaderB] +=group_size[leaderA];

    }
}
int main(){
    int n,e;
    cin>>n>>e;
    dsu_init(n);
    while(e--){
        int u,v;
        cin>>u>>v;
        union_by_size(u,v);
    }
    for(int i=0;i<n;i++){
        cout<<parent[i]<<" ";
    }
    return 0;
}