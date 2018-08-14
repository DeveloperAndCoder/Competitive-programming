/// Author : Anurag Shah
/// IIT Jodhpur

#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cmath>
#include<set>
#include<iomanip>

#define forn(i,a,b) for(int i = a; i < b; i++)
#define boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define eb emplace_back
#define pb push_back
#define fr first
#define sc second
#define sins insert

typedef long long ll;

#define M 1000000000
const int mod = 1000000007;

using namespace std;

int p[1001], L[10001];

void dfs_p(vector<int> adj[], bool vis[], int n, int u)
{
    L[0] = 0;
    p[0] = 0;
    vis[u] = true;
    forn(i,0,adj[u].size())
    {
        int v = adj[u][i];
        if(vis[v] == false)
        {
            p[v] = u;
            L[v] = L[u]+1;
            dfs_p(adj, vis, n, v);
        }
    }
    return;
}

int LCA(vector<int> adj[], int n, int x, int y)
{
    while(x != y)
    {
      //  cout << x << " "  << L[x] << " " << y << " " << L[y] << endl;
        if(L[x] < L[y]) y = p[y];
        else x = p[x];
    }
    //cout << "LCA is " << x << endl;
    return x;
}

int main()
{
    int t;
    cin >> t;
    int case_no = 1;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> adj[n];
        forn(i,0,n)
        {
            int m;
            cin >> m;
            forn(j,0,m)
            {
                int x;
                cin >> x;
                x--;
                adj[i].push_back(x);
            }
        }
        bool vis[n] = {false};
        dfs_p(adj, vis, n, 0);
        int q;
        cin >> q;
        cout << "Case " << case_no++ << ":" << endl;
        while(q--)
        {
            int x,y;
            cin >> x >> y;
            x--;
            y--;
            cout << LCA(adj, n, x, y)+1 << endl;
        }
    }
}
