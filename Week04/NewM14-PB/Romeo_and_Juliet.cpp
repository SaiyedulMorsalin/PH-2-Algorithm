#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
vector<int> v[N];
int dis[N];
bool vis[N];
void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;
    dis[src] = 0;
    while (!q.empty())
    {
        int par = q.front();
        q.pop();
        // cout << par << endl;
        for (int child : v[par])
        {
            if (vis[child] == false)
            {
                q.push(child);
                vis[child] = true;
                dis[child] = dis[par]+1;
            }
        }
    }
}
int main()
{
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    memset(vis, false, sizeof(vis));
    memset(dis,-1,sizeof(dis));
    int src,d,k;
    cin>>src>>d>>k;
    bfs(src);
    if(dis[d] != -1 && dis[d]<=k*2) cout<<"YES"<<endl;
    else cout<<"NO"<<endl; 
    return 0;
}