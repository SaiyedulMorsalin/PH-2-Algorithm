#include <bits/stdc++.h>
using namespace std;
int n,m;
const int N = 1000+5;
char maze[N][N];
bool vis[N][N];
void bfs(int si,int sj){
    queue<pair<int,int>>q;
    q.push({si,sj});
    // vis[si][sj] = true;
    while(q.empty()){
        pair<int,int>pr = q.front();
        int node = pr.first;
        int childNode = pr.second;

        

    }

}
int main(){
    cin>>n>>m;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>maze[i][j];
        }
    }
    int src[100][100];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){

        }
    }

    return 0;
}