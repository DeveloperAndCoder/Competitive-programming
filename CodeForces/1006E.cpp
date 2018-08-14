#include <bits/stdc++.h>

using namespace std;

#define forn(i,a,b) for(int i = a; i < b; i++)
#define ll long long
#define N 500001

vector<int> trav;
vector<int> idx(N);
vector<int> sz(N);

void dfs(vector<int> g[], bool vis[], int u)
{
    vis[u] = true;
    sz[u] = 1;
    trav.push_back(u);
    idx[u] = trav.size()-1;
    for(auto v : g[u])
    {
        if(!vis[v])
        {
            dfs(g,vis,v);
            sz[u] += sz[v];
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, q;
    cin >> n >> q;
    vector<int> g[n];
    int u = 0;
    forn(i,1,n)
    {
        int a;
        cin >> a;
        a--;
        if(a != i)
        g[a].push_back(i);
    }
    bool vis[n];
    forn(i,0,n) vis[i] = 0;
    dfs(g, vis, u);
/*
    for(auto v : trav) cout << v << " ";
    cout << endl;
    forn(i,0,n) cout << idx[i] << " ";
    cout << endl;

    forn(i,0,n) cout << sz[i] << " ";
    cout << endl;
    */
    while(q--)
    {
        int a, k;
        cin >> a >> k;
        a--;k--;
        if(k >= sz[a])
            cout << -1 << endl;
        else cout << trav[idx[a] + k]+1 << endl;
    }
    return 0;
}
