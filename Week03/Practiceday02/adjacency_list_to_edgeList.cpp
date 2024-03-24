#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;

vector<pair<int,int>> edge_list(int n,vector<int>adj[]){
    vector<pair<int,int>>ed;
    for(int i=0;i<n;i++){
        int u = i;
        for(int v:adj[i]){
            if(i-1 == v){
                continue;
            }
            else{
                ed.push_back({i,v});
            }
            
        }
    }
    return ed;
}
int main(){
    // cout<<adj[i][j]<<endl;
    // int n =5;
    vector<int>adj[100000+5];
    int n,e;
    cin>>n>>e;
    // cout<<n<<e<<endl;
    while(e--){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    // vector<int>adj[5]={{1},{0,2,4},{1,3},{2,4},{1,3}};

    vector<pair<int,int>>edgeList = edge_list(n,adj);

    for(pair<int,int> ed:edgeList){
        cout<<ed.first<<" "<<ed.second<<endl;
    }

    return 0;
}