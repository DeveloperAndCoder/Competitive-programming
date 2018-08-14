#include<iostream>
#include<cstdlib>
#include<vector>
#include<cstring>
#include<stack>

#define forn(i,a,n) for(int i = 0; i < n; i++)
#define ll long long
#define eb emplace_back
#define mem(array,value) memset(array, value, sizeof(array))

using namespace std;

const int N = 10001;
int f[N], g[N], diameter;

void dfs(vector<vector<int> > &adj, int v, int par)
{
    vector<int> fval;
    forn(i,0,adj[v].size())
    {
        if(adj[v][i] == par) continue;
        dfs(adj, adj[v][i], v);
        fval.eb(f[adj[v][i]]);
    }
    int max1 = -1, max2 = -1;
    int idx = -1;
    forn(i,0,fval.size()) if(max1 < fval[i]) max1 = fval[i], idx = i;
    forn(i,0,fval.size()) if(i != idx && max2 < fval[i]) max2 = fval[i];

    if(!fval.empty())
    f[v] = max1+1;

    if(fval.size() >= 2)
    g[v] = 2+max1+max2;

    diameter = max(diameter, max(f[v], g[v]));

    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    vector< vector<int> > adj(n, vector<int>());
    forn(i,0,n-1)
    {
        int a,b;
        cin >> a >> b;
        a--;b--;
        adj[a].eb(b);
        adj[b].eb(a);
    }
    dfs(adj, 0, -1);
    cout << diameter;
    return 0;
}
