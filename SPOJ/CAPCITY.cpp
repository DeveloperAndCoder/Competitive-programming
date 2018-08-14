#include <iostream>
#include <stack>
#include <vector>
#include <unordered_set>
#include <utility>
#include <algorithm>

using namespace std;

template<class T>
void initialize(T A[], int n)
{
    for(int i = 0; i < n; i++) A[i] = 0;
    return;
}

int root(int a, int dsu[])
{
    while(a != dsu[a]) {
            dsu[a] = dsu[dsu[a]];
            a = dsu[a];
    }
    return a;
}

void union_(int a, int b, int dsu[], int size[])
{
    int rootA = root(a, dsu);
    int rootB = root(b, dsu);
    int sizeA = size[rootA];
    int sizeB = size[rootB];
    if(sizeA > sizeB)
    {
        sizeA += sizeB;
        dsu[rootB] = rootA;
    }
    else
    {
        sizeB += sizeA;
        dsu[rootA] = rootB;
    }
    return;
}

void dfs(vector<int> adj[], bool vis[], int u)
{
    vis[u] = true;
    //cout << u << "-> ";
    for(int i = 0; i < adj[u].size(); i++)
    {
        int v = adj[u][i];
        if(!vis[v])
        {
            dfs(adj, vis, v);
        }
    }
    return;
}

bool isconnected(vector<int> adj[], int n)
{
    bool vis[n];
    initialize(vis, n);
    dfs(adj, vis, 0);
    for(int i = 0; i < n; i++)
        if(!vis[i]) {
                //cout << i << endl;
                return false;
        }
    return true;
}

void dfs1(vector<int> adj[], stack<int> &time, bool vis[], int u)
{
    vis[u] = true;
    for(int i = 0; i < adj[u].size(); i++)
    {
        int v = adj[u][i];
        if(!vis[v])
        {
            dfs1(adj, time, vis, v);
        }
    }
    time.push(u);
    return;
}

void dfs2(vector<int> adj_t[], bool vis[], int dsu[], int size[], int u)
{
    vis[u] = true;
    for(int i = 0; i < adj_t[u].size(); i++)
    {
        int v = adj_t[u][i];
        if(!vis[v])
        {
            union_(u, v, dsu, size);
            dfs2(adj_t, vis, dsu, size, v);
        }
    }
    return;
}

struct pair_hash {
    inline std::size_t operator()(const std::pair<int,int> & v) const {
        return v.first*31+v.second;
    }
};
unordered_set<pair<int,int>, pair_hash> st;

void condense(vector<int> adj[], vector<int> adj_new[], bool vis[], int dsu[], int u)
{
    vis[u] = true;
    int p_u = root(u, dsu);
    for(int i = 0; i < adj[u].size(); i++)
    {
        int v = adj[u][i];
        int p_v = root(v, dsu);
        if(p_u != p_v)
        {
            if(st.find({p_u, p_v}) == st.end())
            {
                st.insert({p_u, p_v});
                adj_new[p_u].push_back(p_v);
            }
        }
        if(!vis[v])
        {
            condense(adj, adj_new, vis, dsu, v);
        }
    }
    return;
}

void scc(vector<int> adj[], vector<int> adj_t[], vector<int> adj_new[], int dsu[], int size[], int n)
{
    stack<int> time;
    bool vis[n];
    initialize(vis, n);
    for(int i = 0; i < n; i++)
        if(!vis[i]) dfs1(adj, time, vis, i);
    initialize(vis, n);
    while(!time.empty())
    {
        int u = time.top();
        time.pop();
        if(!vis[u])
            dfs2(adj_t, vis, dsu, size, u);
    }
    initialize(vis, n);
    for(int i = 0; i < n; i++)
    if(!vis[i])
        condense(adj, adj_new, vis, dsu, i);
    return;
}

void dfs_out(vector<int> adj[], int out[], int dsu[], bool vis[], int u, int p)
{
    vis[u] = true;
    for(int i = 0; i < adj[u].size(); i++)
    {
        int v = adj[u][i];
        if(v == p) continue;
        out[u]++;
        if(!vis[v])
        {
            dfs_out(adj, out, dsu, vis, v, u);
        }
    }
    return;
}

int main()
{
    int n, m;

    cin >> n >> m;

    vector<int> adj[n], adj_t[n], con[n], adj_new[n];

    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj_t[b].push_back(a);
        con[a].push_back(b);
        con[b].push_back(a);
    }

    if(!isconnected(con, n))
    {
        cout << 0 << endl;
        return 0;
    }

    int dsu[n], size[n];

    for(int i = 0; i < n; i++) dsu[i] = i, size[i] = 1;

    scc(adj, adj_t, adj_new, dsu, size, n);
    /*
    for(int i = 0; i < n; i++)
    {
        if(i != root(i, dsu)) continue;
        for(int j = 0; j < adj_new[i].size(); j++)
            cout << i << "->" << adj_new[i][j] << endl;
    }
    */
    int out_deg[n], rt = -1;
    vector<int> mother;
    bool vis[n];
    initialize(vis, n);
    initialize(out_deg, n);
    for(int i = 0; i < n; i++)
    {
        int u = root(i, dsu);
        if(!vis[u])
        dfs_out(adj_new, out_deg, dsu, vis, u, -1);
    }

    /*
    cout << "--------------------------\n";
    for(int i = 0; i < n; i++)
    {
        if(i != root(i, dsu)) continue;
        cout << i << " " << out_deg[i] << endl;
    }
    cout << "\n--------------------------\n";
    */

    for(int i = 0; i < n; i++)
    {
        int u = root(i, dsu);
        if(i != u) continue;
        if(out_deg[u] == 0)
        {
            if(rt == -1)
            rt = u;
            else
            {
                cout << 0;
                return 0;
            }
        }
    }
    for(int i = 0; i < n; i++)
    {
        if(root(i, dsu) == rt)
            mother.push_back(i+1);
    }
    cout << mother.size() << endl;
    for(int i = 0; i < mother.size(); i++)
    {
        cout << mother[i] << " ";
    }
    return 0;
}
/*
4 5
1 2
2 1
3 2
4 3
1 4
*/
/*
2 1
1 2
*/
