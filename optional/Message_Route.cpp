#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 2e5+5;
ll par[N];
bool vis[N];
vector<ll>v[N];
void bfs(ll src){
    queue<ll>q;
    q.push(src);
    vis[src] =true;
    while(!q.empty()){
        ll pr = q.front();
        q.pop();
        for(int child:v[pr]){
            if(!vis[child]){
                q.push(child);
                vis[child] = true;
                par[child] = pr;
            }
        }
    }
}
int main(){
    ll n,e;
    cin>>n>>e;
    while(e--){
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    memset(vis,false,sizeof(vis));
    memset(par,-1,sizeof(par));
    bfs(1);
    ll x = n;
    vector<ll>path;
    while(x != -1){
        path.push_back(x);
        x = par[x];
    }
    
    reverse(path.begin(),path.end());
    if(path.size()<=1){
        cout<<"IMPOSSIBLE"<<endl;
    }
    else{
        cout<<path.size()<<endl;
        for(int v:path){
            cout<<v<<" ";
        }
    }
    
    
    return 0;
}