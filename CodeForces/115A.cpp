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

void dfs(vector<int> g[], bool vis[], int u, int steps)
{
    vis[u] = true;
    ans = max(ans, steps);
    for(auto v : g[u])
    {
        if(!vis[v])
        {
            dfs(g,vis,v,steps+1);
        }
    }
    return;
}

int main()
{
    int n;
    cin >> n;
    vector<int> p[n];
    vector<int> candy;
    forn(i,0,n)
    {
        int pa;
        cin >> pa;
        if(pa != -1)
        {
            p[pa-1].push_back(i);
        }
        else candy.push_back(i);
    }
    bool vis[n];
    forn(i,0,n) vis[i] = false;
    for(auto u : candy)
    {
        dfs(p, vis, u, 1);
    }
    cout << ans;
}
