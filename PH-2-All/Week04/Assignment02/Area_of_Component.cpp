#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int n,m;
char a[N][N];
bool vis[N][N];
vector<pair<int,int>>d ={{0,1},{0,-1},{-1,0},{1,0}};
bool valid(int ci,int cj){
    return ci>=0 && ci<=n && cj >=0 && cj <=m;
}
int ans;
int dfs(int si,int sj){
    vis[si][sj] = true;
    
    for(int i=0;i<4;i++){
        int ci = si + d[i].first;
        int cj = sj + d[i].second;
        if(valid(ci,cj) && !vis[ci][cj] && a[ci][cj] == '.'){
            ans++;
            dfs(ci,cj);
        }
    }
    return ans;
}
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    int minCnt = INT_MAX;
    ans =0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!vis[i][j] && a[i][j] == '.'){
                int cnt = dfs(i,j);
                minCnt = min(minCnt,cnt);
            }
        }
        
    }
    if(minCnt == INT_MAX){
        cout<<"-1"<<endl;
    }
    else{
        cout<<minCnt<<endl;
    }
    
    return 0;
}