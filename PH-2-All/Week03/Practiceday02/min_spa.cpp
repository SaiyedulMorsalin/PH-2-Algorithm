#include <bits/stdc++.h>
using namespace std;
const int N =1e5+5;
int parent[N];
int group_size[N];
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
void dsu_union(int node1,int node2){
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
    return a.w <b.w;
}
int main(){
    int n,e;
    cin>>n>>e;
    int totalCost = 0;
    dsu_init(n);
    vector<Edge>edgeList;
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
        int leaderA = leader_find(u);
        int leaderB = leader_find(v);
        if(leaderA == leaderB){
            continue;
        }
        else{
            dsu_union(u,v);
            totalCost +=w;
        }
    }
    cout<<totalCost<<endl;
    return 0;
}