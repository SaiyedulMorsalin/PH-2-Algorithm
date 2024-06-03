#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int parent[N];
int group_size[N];

void dsu_init(int n){
    for(int i = 0;i<n;i++){
        parent[i] = -1;
        group_size[i] = 1;
    }
}

int find_leader(int node){
    if(parent[node] == -1) return node;
    int leader = find_leader(parent[node]);
    parent[node]  = leader;
    return leader;
}
void dsu_union(int node1, int node2){
    int leaderA = find_leader(node1);
    int leaderB = find_leader(node2);
    if(group_size[leaderA]>group_size[leaderB]){
        parent[leaderB] = leaderA;
        group_size[leaderA] +=group_size[leaderB];
    }
    else{
        parent[leaderA] = leaderB;
        group_size[leaderB] += group_size[leaderA];
    }
}
int main(){
    bool ans = false;
    int n,e;
    cin>>n>>e;
    dsu_init(n);
    while(e--){
        int u,v;
        cin>>u>>v;
        int leaderA = find_leader(u);
        int leaderB = find_leader(v);
        if(leaderA == leaderB){
            ans = true;
        }
        else{
            dsu_union(u,v);
        }
    }
    if(ans){
        cout<<"Cycle is found";
    }
    else{
        cout<<"Cycle is not found";
    }
    return 0;
}