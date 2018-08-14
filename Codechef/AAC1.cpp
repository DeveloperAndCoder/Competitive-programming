#include <iostream>
#include <vector>
#include <queue>

#define forn(i,a,b) for(int i  = a; i < b; i++)

using namespace std;

int bfs(int n, vector<int> g[])
{
    bool vis[n];
    for(int i  = 0; i < n; i++) vis[i] = false;
    queue<pair<int,int> > q;
    q.push({0,0});
    vis[0] = true;
    while(!q.empty())
    {
        auto u = q.front();
        q.pop();
        for(auto v : g[u.first])
        {
            if(v == n-1) return u.second+1;
            if(!vis[v])
            {
                vis[v] = true;
                q.push({v,u.second+1});
            }
        }
    }
    return 0;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> g[n];
        forn(i,0,m)
        {
            int a, b;
            cin >> a >> b;
            a--; b--;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        cout << bfs(n, g) << endl;
    }
    return 0;
}
