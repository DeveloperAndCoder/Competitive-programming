#include <cstdio>
#include <vector>
#include <iostream>
#include <stack>
#include <unordered_set>
#include <utility>
#include <algorithm>

#define MAXN 200000

using namespace std;

vector< int > graph[ MAXN + 1 ], graphT[ MAXN + 1 ], sol;
bool visited[ MAXN + 1 ];
int comp[ MAXN + 1 ], in[ MAXN + 1 ];

void dfs1_( int S )
{
    visited[ S ] = true;
    int i;
    for ( i = 0; i < graph[ S ].size(); ++i )
    {
        if ( !visited[ graph[ S ][ i ] ] )
        {
            dfs1_( graph[ S ][ i ] );
        }
    }
    sol.push_back( S );
}

void dfs2_( int S, int c )
{
    visited[ S ] = false;
    comp[ S ] = c;
    int i;
    for ( i = 0; i < graphT[ S ].size(); ++i )
    {
        if ( visited[ graphT[ S ][ i ] ] )
        {
            dfs2_( graphT[ S ][ i ], c );
        }
    }
}

vector<int> test1(int n, int m, vector<int> g[])
{
    cout << "Answer ";
    int t, i, N, v, j, compon, M, u, count, lim;
    //scanf( "%d%d", &N, &M );
    sol.clear();
    N = n;
    M = m;
    for ( i = 1; i <= N; ++i )
    {
        visited[ i ] = false;
        graph[ i ].clear();
        graphT[ i ].clear();
        in[ i ] = 0;
    }
    for(int i = 0; i < N; i++)
        for (int j = 0; j < g[i].size(); ++j )
        {
            int u = i+1;
            int v = g[i][j]+1;
            graph[ v ].push_back( u );
            graphT[ u ].push_back( v );
        }
    for ( i = 1; i <= N; ++i )
    {
        if ( !visited[ i ] )
        {
            dfs1_( i );
        }
    }
    compon = 0;
    for ( i = sol.size() - 1; i >= 0; --i )
    {
        if ( visited[ sol[ i ] ] )
        {
            dfs2_( sol[ i ], compon++ );
        }
    }
    lim = compon;
    for ( i = 1; i <= N; ++i )
    {
        for ( j = 0; j < graph[ i ].size(); ++j )
        {
            if ( comp[ i ] != comp[ graph[ i ][ j ] ] )
            {
                in[ comp[ graph[ i ][ j ] ] ] += 1;
            }
        }
    }
    count = 0;
    for ( i = 0; i < lim; ++i )
    {
        if ( in[ i ] == 0 )
        {
            ++count;
        }
    }
    vector<int> vv;
    if ( count > 1 )
    {
        printf( "0\n" );
    }
    else
    {
        count = 0;
        for ( i = 1; i <= N; ++i )
        {
            if ( in[ comp[ i ] ] == 0 )
            {
                ++count;
            }
        }
        cout << count << endl;
        for ( i = 1; i <= N; ++i )
        {
            if ( in[ comp[ i ] ] == 0 )
            {
                //printf( "%d\n", i );
                vv.push_back(i);
            }
        }
    }
    return vv;
}

// *********************************************************************************************************************** //


template<class T>
void initialize(T A[], int n)
{
    for(int i = 0; i < n; i++) A[i] = 0;
    return;
}

int root(int a, int dsu[])
{
    while(a != dsu[a])
    {
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
    initialize(vis, false);
    dfs(adj, vis, 0);
    for(int i = 0; i < n; i++)
        if(!vis[i])
        {
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

struct pair_hash
{
    inline std::size_t operator()(const std::pair<int,int> & v) const
    {
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

vector<int> test2(int n, int m, vector<int> g[])
{
    cout << "My answer: ";
//    int n, m;

    //  cin >> n >> m;
    vector<int> adj[n], adj_t[n], con[n], adj_new[n];
    st.clear();
    for(int i = 0; i < n; i++)
        for (int j = 0; j < g[i].size(); ++j )
        {
            int a = i;
            int b = g[i][j];
            adj[a].push_back(b);
            adj_t[b].push_back(a);
            con[a].push_back(b);
            con[b].push_back(a);
        }
    /*
    for(int i = 0; i < m; i++)
    {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    adj[a].push_back(b);
    adj_t[b].push_back(a);
    con[a].push_back(b);
    con[b].push_back(a);
    }
    */
    if(!isconnected(con, n))
    {
        cout << 0 << "here" << endl;
        //return 0;
        return vector<int>();
    }

    int dsu[n], size[n];

    for(int i = 0; i < n; i++) dsu[i] = i, size[i] = 1;

    scc(adj, adj_t, adj_new, dsu, size, n);
    cout << "scc done\n";
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
    cout << "outedges done\n";
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
                return vector<int>();
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
        //cout << mother[i] << " ";
    }
    return mother;
}
/*
4 5
1 2
2 1
3 2
4 3
1 4
*/

bool cmp()
{
    int MX = 1000000;
    int n, m;
    srand(rand());
    n = rand()%MX+1;
    m = rand()%MX+1;
    m = n*(n-1)/16;
    vector<int> g[n];
    for(int i = 0; i < m; i++)
    {
        int a = rand()%n;
        int b = rand()%n;
        if(a == b) continue;
        bool valid = true;
        /*
        for(int i = 0; i < g[a].size(); i++)
        {
            if(g[a][i] == b)
            {
                valid = false;
                break;
            }
        }
        */
        if(valid)
        {
            //cout << a << "->" << b << endl;
            g[a].push_back(b);
        }
    }
    cout << "***********************\n" << endl;
    auto v1 = test1(n,m,g);
    auto v2 = test2(n,m,g);
    if(v1 == v2)
        return true;
    cout << n << " " << m << endl;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < g[i].size(); j++)
        {
            cout << i+1 << "->" << g[i][j]+1 << endl;
        }
    }
    return false;
}

int main()
{
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    //cout.tie(0);
    while(cmp()) cout << "\n-----------------------\n";
    cout << "ERROR";
    return 0;
}
