#include <bits/stdc++.h>
using namespace std;
char ch[1005][1005];
bool vis[1005][1005];
vector<pair<int,int>>d = {{0,1},{0,-1},{1,0},{-1,0}};
int n,m;
pair<int,int>src;
bool valid(int ci,int cj){
    return ci>=0 && ci<=n && cj>=0 && cj<=n && !vis[ci][cj];
}
int ans = 1;
void dfs(int si,int sj){
    vis[si][sj] =true;
    for(int i=0;i<4;i++){
        int ci = si+d[i].first;
        int cj = sj + d[i].second;
        if(valid(ci,cj) && ch[ci][cj] == '.'){
            ans++;
            dfs(ci,cj);
        }
    }
}
int main(){
    cin>>m>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>ch[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(ch[i][j] == '@'){
                src={i,j};
            }
        }
        
    }
    memset(vis,false,sizeof(vis));
    int si = src.first;
    int sj = src.second;
    dfs( si,sj);
    cout<<ans<<endl;
    return 0;
}