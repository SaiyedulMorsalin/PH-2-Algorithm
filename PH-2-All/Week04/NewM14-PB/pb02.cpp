#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int par[N];
int group_size[N];
void init(int n){
    for(int i=0;i<n;i++){
        par[i] = -1;
        group_size[i] = 1;
    }
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
    if(group_size[leaderA]>group_size[leaderB]){
        par[leaderB] = leaderA;
        group_size[leaderA] += group_size[leaderB];

    }
    else{
        par[leaderA] = leaderB;
        group_size[leaderB] += group_size[leaderA];
    }
}
class Edge{
    public:
    int u,v,w;
    Edge(int u,int v,int w){
        this->u = u;
        this->v = v;
        this->w = w;
    }
};
bool cmp(Edge a,Edge b){
    return a.w<b.w;
}
int main(){
    int n,e;
    cin>>n>>e;
    init(n);
    vector<Edge>edgeList;
    int minTotalCost = 0;
    while(e--){
        int u,v,w;
        cin>>u>>v>>w;
        edgeList.push_back(Edge(u,v,w));
    }
    sort(edgeList.begin(),edgeList.end(),cmp);
    for(Edge ed: edgeList){
        int u = ed.u;
        int v = ed.v;
        int w = ed.w;
        int leaderU = dsu_find(u);
        int leaderV = dsu_find(v);
        if(leaderU != leaderV){
            dsu_union(u,v);
            minTotalCost +=w;
        }
    }
    cout<<minTotalCost<<endl;
    
    return 0;
}