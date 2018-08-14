#include<iostream>
using namespace std;
int ans = 0;
void rem(bool** adj,int vis[],int u,int v);
void remove_edge(bool** adj, int n, int vis[], int u, int r, int b, int g)
{
    for(int i = 0; i < n; i++)
    {
        if(!vis[adj[u][i]])
        {
            vis[adj[u][i]] = true;
            if((u < r && adj[u][i] < r) || ((u >= r && u < r+b) && (adj[u][i] >= r && adj[u][i] < r+b)) || (u >= r+b && u < n) && (adj[u][i] >= r+b && adj[u][i] < n))
            {
                vis[adj[u][i]] = false;
                adj[u][i] = false;
                adj[i][u] = false;
                continue;
            }
            else
            {
                rem(adj, vis, u, adj[u][i], r, b, g);
                remove_edge(adj, n, vis, adj[u][i], r, b, g);
            }
        }
    }
    return;
}

void rem(bool** adj,int vis[],int u,int v)
{
    if (u < r)
    {
        for(int i = 0; i < n; i++)
        {
            int u1 = adj[u][i];
            for(int j = 0; j < n; j++)
            {
                if(u1 < r)
                {
                    ans++;

                }
            }
        }
    }
}

int main()
{
    int r,b,g, i = 0, j = 0;
    cin >> r >> b >> g;
    int n = r + b + g;
    bool** adj = new bool*[n];
    for(i = 0; i < n; i++)
        *(adj + i) = new bool;
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            adj[i][j] = true;
    bool vis[n] = {false};
    remove_edge(adj, n, vis, 0, r, b, g);

}
