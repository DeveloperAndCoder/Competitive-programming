#include<iostream>
#include<vector>
#include<queue>

#define forn(a,b) for(int i = a; i < b; i++)

using namespace std;

void BFSP(vector<int> adj[], int p[], int n)
{
    bool vis[n];
    forn(0,n) vis[i] = false;
    queue<int> q;
    q.push(0);
    vis[0] = true;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        vis[u] = true;
        for(int i = 0; i < adj[u].size(); i++)
        {
            if(!vis[adj[u][i]])
            {
                vis[adj[u][i]] = true;
                p[adj[u][i]] = u;
                q.push(adj[u][i]);
            }
        }
    }
    return;
}

int BFS(vector<int> adj[], int p[], int c[], int n)
{
    bool vis[n];
    forn(0,n) vis[i] = false;
    queue<int> q;
    q.push(0);
    vis[0] = true;
    int ans = 1;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        vis[u] = true;
        if(u != 0 && c[p[u]] != c[u])
            ans++;
        for(int i = 0; i < adj[u].size(); i++)
        {
            if(!vis[adj[u][i]])
            {
                vis[adj[u][i]] = true;
                q.push(adj[u][i]);
            }
        }
    }
    return ans;
}


int main()
{

    int n;
    cin >> n;
    vector<int> adj[n];
    int p1;
    forn(0,n-1)
    {
        cin >> p1;
        adj[p1-1].push_back(i+1);
        adj[i+1].push_back(p1-1);
    }
    int c[n];
    int p[n];
    forn(0,n) cin >> c[i];
    BFSP(adj, p, n);
    int ans = BFS(adj, p, c, n);

    cout << ans;

    return 0;
}
