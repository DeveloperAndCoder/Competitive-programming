#include<iostream>
#include<vector>
using namespace std;
int index = 0;
void dfs(int n, vector<int> adj[], bool vis[], int u, int d, int &m)
{

    for(int i = 0; i < adj[u].size(); i++)
    {
        if(!vis[adj[u][i]])
        {
            vis[adj[u][i]] = true;
            d++;
            if(d > m)
               {
               	m = d;
               	index  = adj[u][i];
              // 	cout << d << " = d\n";
               }
              // cout << adj[u][i]+1 << " = a\n";
            dfs(n, adj, vis, adj[u][i], d, m);
            d--;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> G[n];
    for(int i = 0; i < n-1; i++)
    {
        int a,b;
        cin >> a >> b;
        G[a-1].push_back(b-1);
        G[b-1].push_back(a-1);
    }
    bool vis[n];
for(int i = 0; i < n; i++)
vis[i] = false;
    int m = 0;
    vis[0] = true;
    dfs(n, G, vis, 0, 0, m);
    m = 0;
    for(int i = 0; i < n; i++)
        vis[i] = false;
    //cout << index+1<<" = i"<<endl;
    vis[index] = true;
    dfs(n, G, vis, index, 0, m);
    cout << m;
    return 0;
}
