#include <bits/stdc++.h>
using namespace std;
const int N =1e5+5;
int dis[N];
bool vis[N];
vector<int>v[N];
void bfs(int src){
    queue<int>q;
    q.push(src);
    vis[src] = true;
    dis[src] = 0;
    while(q.empty()){
        int par = q.front();
        q.pop();
        for(int child:v[par]){
            if(!vis[child]){
                q.push(child);
                vis[child] = true;
                dis[child] = dis[par] +1;
            }
        }
    }
}
int main(){
    int n,e;
    memset(vis,false,sizeof(vis));
    memset(dis,-1,sizeof(dis));
    cin>>n>>e;
    while(e--){
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int src,d,k;
    cin>>src>>d>>k;
    bfs(src);
    for(int child:v[2]){
        cout<<child<<endl;
    }
    // cout<<dis[d]<<endl;
    // cout<<vis[d]<<endl;
    for(int i=0;i<n;i++){
        cout<<i<<"-> "<<dis[i]<<" "<<vis[i]<<endl;
    }
    return 0;
}