#include <bits/stdc++.h>
using namespace std;
int parent[1005];
int level[1005];
void dsu_init(int n){
    for(int i=0;i<n;i++){
        parent[i] = -1;
        level[i] = 0;
    }
}
int find_leader(int node){
    if(parent[node] == -1) return node;
    int leader = find_leader(parent[node]);
    parent[node] = leader;
    return leader;
}

void union_by_level(int node1, int node2){
    int leaderA = find_leader(node1);
    int leaderB = find_leader(node2);
    if(level[leaderA] > level[leaderB]){
        parent[leaderB] = leaderA;
    }
    else if(level[leaderB]>level[leaderA]){
        parent[leaderA] = leaderB;
    }
    else{
        parent[leaderB] = leaderA;
        level[leaderA]++;
    }
}
    

int main(){
    int n,e;
    cin>>n>>e;
    dsu_init(n);
    while(e--){
        int u,v;
        cin>>u>>v;
        union_by_level(u,v);
    }
    for(int i=0;i<n;i++){
        cout<<level[i]<<" ";
    }
    return 0;
}