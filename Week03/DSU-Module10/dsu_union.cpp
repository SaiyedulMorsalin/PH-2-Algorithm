#include <bits/stdc++.h>
using namespace std;
int par[105];

void dsu_initialize(int n){
    for(int i =0;i<n;i++){
        par[i] = -1;
    }
    par[3] = 2;
    par[2] = 1;
    par[1] = 0;
    par[4] = 5;
    par[5] = 6;

}
int dsu_find(int node){
    if(par[node] == -1) return node;
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
    dsu_initialize(7);
    cout<<dsu_find(3)<<endl;
    cout<<dsu_find(4)<<endl;
    dsu_union(3,4);
    cout<<dsu_find(3)<<endl;
    cout<<dsu_find(4)<<endl;
    return 0;
}