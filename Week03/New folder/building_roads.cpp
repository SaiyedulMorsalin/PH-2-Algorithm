#include <bits/stdc++.h>
using namespace std;
const int N = 2*1e5+5;
vector<int>v[N];
bool vis[N];
void dfs(int s){
    vis[s] = true;
    for(int child:v[s]){
        if(!vis[child]){
            dfs(child);
        }
    }
}
vector<int>c;
int cc = 0;
int main(){
    int n,e;
    cin>>n>>e;
    memset(vis,false,sizeof(vis));
    while(e--){
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            cc++;
            c.push_back(i);
            dfs(i);
        }
    }
    cout<<cc-1<<endl;
    for(int i=0;i<c.size()-1;i++){
        cout<<c[i]<<" "<<c[i+1]<<endl;
    }
    
    return 0;
}