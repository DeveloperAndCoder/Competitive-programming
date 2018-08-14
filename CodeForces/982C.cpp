#include <iostream>
#include <vector>

#define forn(i,a,b) for(int i = a; i < b; i++)
#define ll long long

using namespace std;

int compo = 0;

int break_dfs(vector<int> v[], bool vis[], int n, int u)
{
    int index = 0;
    vis[u] = true;
    forn(i,0,v[u].size())
    {
        int node = v[u][i];
        if(!vis[node])
        {
            int node_index = break_dfs(v,vis,n,node);
            if(node_index%2 == 1)
            {
                index += node_index;
            }
        }
    }
    if((index+1) % 2 == 0) compo++;
    //cout << u << " " << index+1 << endl;
    return index+1;
}

int main()
{
    int n;
    cin >> n;
    vector<int> v[n];
    bool vis[n];
    forn(i,0,n) vis[i] = false;
    forn(i,0,n-1)
    {
        int a,b;
        cin >> a >> b;
        a--;b--;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int x = break_dfs(v, vis, n, 0);
    if(x%2 != 0) cout << -1;
    else cout << compo-1;
    return 0;
}
