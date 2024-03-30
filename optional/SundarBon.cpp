#include <bits/stdc++.h>
using namespace std;
char ch[30][30];
bool vis[1005][1005];
int dis[1005][1005];
int n;
vector<pair<int,int>>d = {{0,1},{0,-1},{1,0},{-1,0}};
pair<int,int>src;
pair<int,int>des;
bool valid(int ci,int cj){
    return ci>=0 && ci<=n && cj>=0 && cj<=n;
}
void bfs(int si,int sj){
    queue<pair<int,int>>q;
    q.push({si,sj});
    vis[si][sj] = true;
    dis[si][si] = 0;
    while(!q.empty()){
        pair<int,int> pr = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int ci = si+d[i].first;
            int cj = sj + d[i].second;
            if(valid(ci,cj) && !vis[ci][cj] && ch[ci][cj] == 'P'){
                q.push({ci,cj});
                cout<<ci<<" "<<cj<<endl;
                vis[ci][cj] = true;
                dis[ci][cj] = dis[pr.first][pr.second]+1;
            }
        }
    }


}
int main(){
    
    cin>>n;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>ch[i][j];
        }
    }
    memset(vis,false,sizeof(vis));
    memset(dis,-1,sizeof(dis));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
           if(ch[i][j] == 'S'){
            src = {i,j};
           }
           if(ch[i][j] == 'E'){
            des = {i,j};
           }
        }
    }
    int si = src.first;
    int sj = src.second;
    bfs(si,sj);
    cout<<dis[des.first][des.second];
    for(int i=0;i<n;i++){
        cout<<vis[i][i];
    }
    return 0;
}