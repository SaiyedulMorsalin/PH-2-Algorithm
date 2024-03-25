#include <bits/stdc++.h>
using namespace std;
const int N =1e5+5;
int dis[N];
bool vis[N];
vector<int>v[N];
int main(){
    int n,e;
    cin>>n>>e;
    while(e--){
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i=0;i<n;i++){
        cout<<i<<" ";
        for(int child:v[i]){
            cout<<child<<" ";
        }
        cout<<endl;

    }
    return 0;
}
