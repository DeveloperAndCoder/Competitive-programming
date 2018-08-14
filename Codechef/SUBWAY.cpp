#include <bits/stdc++.h>

using namespace std;

#define forn(i,a,b) for(int i = a; i < b; i++)
#define ll long long

struct ed
{
    int v{0};
    int w{0};
    ed(){}
    ed(int v, int w) : v(v), w(w){}
};

int ans(int u, int v, int n, vector<ed> g[])
{

}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> g[n];
    for(int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--;v--;
        g[u].push_back(ed(v,w));
        g[v].push_back(ed(u,w));
    }
    int q;
    cin >> q;
    while(q--)
    {
        int u, v;
        cin >> u .> v;
        u--; v--;
        cout << ans(u,v,n,g) << endl;
    }
    return 0;
}
