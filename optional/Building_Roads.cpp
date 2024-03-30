#include <bits/stdc++.h>
using namespace std;
const int N= 1e5+5;
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
        group_size[leaderA] += group_size[leaderB];
    }
    else{
        par[leaderA] = leaderB;
        group_size[leaderB] += group_size[leaderA];
    }

}

int main(){
    int n,e;
    cin>>n>>e;
    dsu_init(n);
    while(e--){
        int a,b;
        cin>>a>>b;
        int leaderA = leader_find(a);
        int leaderB = leader_find(b);
        if(leaderA!=leaderB){
            dsu_union(a,b);
        }

        
    }
    vector<int>path;
    for(int i=1;i<=n;i++){
        path.push_back(leader_find(i));
    }
    
    sort(path.begin(),path.end());
    path.erase(unique(path.begin(),path.end()),path.end());
    cout<< path.size()-1<<endl;
    for(int i=0;i<path.size()-1;i++){
        cout<<path[i]<<" "<<path[i+1]<<endl;
    }
    return 0;
}