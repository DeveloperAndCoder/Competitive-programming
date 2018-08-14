#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
#include <utility>

#define forn(i,a,b) for(int i = a; i < b; i++)
#define ll long long
#define MX 100001
#define pii pair<int,int>

using namespace std;

int ans;

void dfs(vector<int> g[], bool vis[], int u, bool cat[], int hut, int m)
{
    vis[u] = true;
    if(hut > m) return;
    bool leaf = true;
    for(auto v : g[u])
    {
        if(!vis[v])
        {
            leaf = false;
            if(cat[v])
                dfs(g,vis,v,cat,hut+1,m);
            else
                dfs(g, vis, v, cat ,0, m);
            }
    }
    if(leaf && hut <= m) ans++;
    return;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> g[n];
    bool cat[n];
    forn(i,0,n) cin >> cat[i];
    for(int i = 0; i < n-1; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a-1].push_back(b-1);
        g[b-1].push_back(a-1);
    }
    bool vis[n];
    forn(i,0,n) vis[i] = false;
    dfs(g, vis, 0, cat, cat[0], m);
    cout << ans;
    return 0;
}

