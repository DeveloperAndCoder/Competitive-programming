#include <cstdio>
#include <iostream>
#include <vector>

#define forn(i,a,b) for(int i = a; i < b; i++)
#define N 100001
#define boost ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

int pa[N];

void dfs(vector<int> adj[], bool vis[], int u)
{
    vis[u] = true;
    forn(i,0,adj[u].size())
    {
        int v = adj[u][i];
        if(vis[v] == false)
        {
            pa[v] = u;
            dfs(adj, vis, v);
        }
    }
    return;
}

int crawlup(vector<int> adj[], bool color[], int n, int v)
{
    int ans = -1;
    while(v != -1)
    {
        if(color[v]) ans = v+1;
        v = pa[v];
    }
    return ans;
}

int main()
{
    boost;
    int n, q;
    cin >> n >> q;
    bool vis[n];
    forn(i,0,n)
    {
        vis[i] = false;
    }
    vector<int> adj[n];
    bool color[n] = {0};
    forn(i,0,n-1)
    {
        int a, b;
        cin >> a >> b;
        a--;b--;
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }
    pa[0] = -1;
    dfs(adj, vis, 0);
    while(q--)
    {
        int k;
        cin >> k;
        if(k == 0)
        {
            int i;
            cin >> i;
            i--;
            color[i] = !color[i];
        }
        else
        {
            int v;
            cin >> v;
            v--;
            cout << crawlup(adj, color, n, v) << endl;
        }
    }
}
