#include <fstream>
#include <iostream>
#include <string>
#include <complex>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <list>
#include <ctime>
#include <memory.h>
#include <assert.h>
#include <unordered_set>

#define forn(i,a,b) for(int i = a; i < b; i++)
#define ll long long
#define boost ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
const int N = 1000001;

ll test1(ll n, ll m, ll s, ll e, ll f[], vector<int> adj[])
{
    vector<pair<int, int> > S;
    int used[N];
    vector<int> g[N], gr[N];
    vector<int> order;
    int cost[N];
    int C = 0;
    queue<int> qu;

    long long COST[N];
    vector<int> G[N];
    long long dp[N];
    forn(i,0,N) used[i] = cost[i] = COST[i] = dp[i] = 0;
    /*
    for(int i = 0; i < M; i ++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        v[a].push_back(b);
        gv[b].push_back(a);
    }
    */
    //cout << "ONNNNNNNNN\n";
    for (int i = 1; i <= n; i++)
    {
        cost[i] = f[i-1];
    }
    for(int i = 0; i < n; i++)
    {
        forn(j,0,adj[i].size())
        {
            int a = i+1;
            int b = adj[i][j]+1;
            g[a].push_back(b);
            gr[b].push_back(a);
            //cout << a << "->" << b << endl;
        }
    }
    // dfs for traversal order
    //cout << "BRO\n";
    for (int i = 1; i <= n; i++)
    {
        if (used[i])
            continue;
        used[i] = 1;
        S.push_back(make_pair(i, 0));

        while (S.size())
        {
            pair<int, int> P = S.back();
            S.pop_back();
            int qv = P.first;
            int qptr = P.second;
            used[qv] = 1;

            if (qptr == g[qv].size())
            {
                order.push_back(qv);
                continue;
            }

            S.push_back(make_pair(qv, qptr + 1));
            int to = g[qv][qptr];
            if (used[to])
                continue;
            S.push_back(make_pair(to, 0));
        }
    }
    //cout << "YOBRO\n";
    reverse(order.begin(), order.end());

    for (int i = 1; i <= n; i++)
        used[i] = 0;

    for (int i = 0; i < order.size(); i++)
    {
        int id = order[i];
        if (used[id])
            continue;
        ++C;
        qu.push(id);
        while (qu.size())
        {
            int v = qu.front();
            used[v] = C;
            COST[C] += cost[v];
            qu.pop();
            for (int j = 0; j < gr[v].size(); j++)
            {
                int to = gr[v][j];
                if (used[to])
                    continue;
                used[to] = C;
                qu.push(to);
            }
        }
    }
    //cout << "HM\n";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < g[i].size(); j++)
        {
            int to = g[i][j];
            if (used[i] == used[to])
                continue;
            G[used[i]].push_back(used[to]);
            assert(used[i] < used[to]);
        }
    }

    int v1 = used[s];
    int v2 = used[e];

    assert(v1 <= v2);

    for (int i = 1; i <= C; i++)
    {
        dp[i] = -1e18;
    }
    //cout << "HO\n";
    for (int i = C; i; --i)
    {
        if (i == v2)
            dp[i] = COST[i];
        else
        {
            for (int j = 0; j < G[i].size(); j++)
            {
                int to = G[i][j];
                dp[i] = max(dp[i], dp[to] + COST[i]);
            }
        }
    }

    assert(dp[v1] >= 0);
    //cout << v1 << " ";
    cout << "Ans = " << dp[v1] << "\n";
    return dp[v1];
}
//}


ll root(ll A[], ll u)
{
    while(A[u] != u)
    {
        u = A[A[u]];
    }
    return u;
}

void union_(ll A[], ll size[], ll u, ll v)
{
    ll rootu = root(A, u);
    ll rootv = root(A, v);
    if(rootu < rootv)
    {
        A[rootv] = rootu;
        return;
    }
    else
    {
        A[rootu] = rootv;
        return;
    }
    ll sizeu = size[rootu];
    ll sizev = size[rootv];
    if(sizeu >= sizev)
    {
        A[rootv] = rootu;
        size[u] += sizev;
    }
    else
    {
        A[rootu] = rootv;
        size[v] += sizeu;
    }
    return;
}

void dfs(vector<ll> g[], stack<ll> &time, bool vis[], ll u)
{
    vis[u] = true;
    forn(i,0,g[u].size())
    {
        ll v = g[u][i];
        if(vis[v] == false)
        {
            dfs(g,time,vis,v);
        }
    }
    time.push(u);
    return;
}

void dfs_t(vector<ll> gt[], ll dsu[], ll size[], bool vis[], ll u)
{
    vis[u] = true;
    forn(i,0,gt[u].size())
    {
        ll v = gt[u][i];
        if(vis[v] == false)
        {
            union_(dsu, size, u, v);
            dfs_t(gt, dsu, size, vis, v);
        }
    }
    return;
}

void scc(vector<ll> g[], vector<ll> gt[], ll dsu[], ll size[], ll n)
{
    stack<ll> time;
    bool vis[n];
    forn(i,0,n) vis[i] = false;
    forn(i,0,n)
    {
        if(vis[i]) continue;
        dfs(g, time, vis, i);
    }
    forn(i,0,n) vis[i] = false;
    while(!time.empty())
    {
        ll u = time.top();
        time.pop();
        if(vis[u] == false)
        {
            dfs_t(gt, dsu, size, vis, u);
        }
    }
}

//ll ans = 0ll;

long long fun(vector<ll> cdn_g[], ll val[], bool vis[], ll dp[], ll e, ll u)
{
    if(u == e)
    {
        //ans = max(ans, val[e] + fn);
        return val[e];
    }
    if(dp[u] != -1e18) return dp[u];
    queue<ll> q;
    q.push(u);
    while(!q.empty())
    {
        ll v = q.front();
        vis[v] = true;
        q.pop();
        forn(i,0,cdn_g[v].size())
        {
            ll cv = cdn_g[v][i];
            //if(vis[cv] == false)
            {
                q.push(cv);
                dp[v] = max(dp[v], fun(cdn_g, val, vis, dp, e, cv) + val[v]);
            }
        }
    }
    vis[u] = false;
    return dp[u];
}

struct pair_hash {
    inline std::size_t operator()(const std::pair<ll,ll> & v) const {
        return v.first*31+v.second;
    }
};
unordered_set<pair<ll,ll>, pair_hash> st;

void condense_graph_dfs(ll start,vector<ll> adjList[],vector<ll> adjList_new[],bool visited[], ll dsu[])
{
    visited[start]=true;
    for(int i=0; i<adjList[start].size(); i++)
    {
        ll vertex=adjList[start][i];
        ll p_start=root(dsu, start);
        ll p_vertex=root(dsu, vertex);
        if(p_start==p_vertex)
        {
            //continue;
        }
        else
        {
            if(st.find({p_start, p_vertex}) == st.end())
            {
                adjList_new[p_start].push_back(p_vertex);
                st.insert({p_start, p_vertex});
            }
        }
        if(visited[vertex]==false)
            condense_graph_dfs(vertex,adjList,adjList_new,visited,dsu);
    }
}

ll testmy(ll n, ll m, ll s, ll e, ll f[], vector<int> adj[])
{
    st.clear();
    //ll n, m, s, e;
    //cin >> n >> m >> s >> e;
    //ll f[n];
    //forn(i,0,n) cin >> f[i];
    vector<ll> g[n], gt[n];

    /*
    forn(i,0,m)
    {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        gt[b].push_back(a);
    }
    */
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < adj[i].size(); j++)
        {
            int a = i;
            int b = adj[i][j];
            g[a].push_back(b);
            gt[b].push_back(a);
        }
    }
    ll dsu[n], size[n];
    forn(i,0,n) dsu[i] = i, size[i] = 1;
    //cout << "SCC\n";
    scc(g, gt, dsu, size, n);
    /// TESTING
    //forn(i,0,n) cout << i+1 << " " << dsu[i] << "\n";
    ///SUCCESS
    ll val[n];
    forn(i,0,n) val[i] = 0ll;
    forn(i,0,n)
    {
        ll rt = root(dsu, i);
        if(rt != i)
        {
            val[rt] += f[i];
        }
        val[i] += f[i];
    }
    //forn(i,0,n) cout << i << " " << val[i] << " \n";
    //cout << endl;
    bool vis[n];
    forn(i,0,n) vis[i] = false;
    vector<ll> adj_new[n];
    //cout << "CONDENSEIT!\n";
    condense_graph_dfs(s, g, adj_new, vis, dsu);
    /*
    forn(i,0,n)
    {
        cout << "i = " << i << " " << root(dsu, i) <<  endl;
        forn(j,0,adj_new[i].size()) cout << adj_new[i][j] << " ";
        cout << endl;
    }
    */
    //bool inc = false;
    ll dp[n];
    forn(i,0,n) dp[i] = -1e18;
    s = root(dsu, s);
    e = root(dsu, e);
    forn(i,0,n) vis[i] = false;
    //cout << "FINALE\n";
    cout << "Your O/P = " << fun(adj_new, val, vis, dp, e, s) << endl;
    return fun(adj_new, val, vis, dp, e, s);
}

bool verify(vector<int> adj[], ll n, ll s, ll e)
{
    queue<ll> q;
    q.push(s);
    bool vis[n];
    forn(i,0,n) vis[i] = 0;
    while(!q.empty())
    {
        ll u = q.front();
        vis[u] = true;
        q.pop();
        if(u == e) return true;
        forn(i,0,adj[u].size())
        {
            int v = adj[u][i];
            if(vis[v] == false)
            {
                q.push(v);
            }
        }
    }
    return false;
}

int compare()
{
    ll mx = 10000;
    ll n, m, s, e;
    n = rand()%mx;
    if(n <= 1) n = 10;
    m = rand()%mx;
    s = rand()%n;
    e = rand()%n;
    cout << n << " " << m << " " << s << " " << e << endl;
    vector<int> adj[n];
    ll f[n];
    forn(i,0,n)
    {
        f[i] = rand()%n+1;
        //cout << "f["<<i<<"] = "<<f[i] << "\n";
    }
    if(s == e) e = (e+1)%n;
    adj[s].push_back(e);
    forn(i,0,m-1)
    {
        int a = rand()%n;
        int b = rand()%n;
        if(b == a || a >= n || b >= n || a < 0 || b < 0) continue;
        b %= n;
        bool valid = true;
        //cout << i << " ";
        if(i == 8462)
        {
            cout << a << "->" << b << endl;
        }
        forn(j,0,adj[a].size())
        {
            if(i == 8462)
            {
                cout << adj[a][j] << endl;
            }
            if(i==8462 || adj[a][j] == b)
            {
                if(i==8462)
                cout << "WTM\n";
                valid = false;
                if(i==8462)
                cout << "in here\n";
                break;
            }
            if(i == 8462)
            cout << "cnt\n";
            if(cout.fail())
            {
                cout.clear();
                cout << flush;
            }
        }
        if(i == 8462) cout << "OUT " << valid << "\n";
        if(valid)
        {
            if(i == 8462) cout << "IN\n";
            //cout << a << "->" << b << endl;
            adj[a].push_back(b);
        }
    }
    cout << "OVER\n";
    //return false;
    //if(verify(adj, n, s, e))
    {
        ll u1 = test1(n,m,s+1,e+1,f,adj);
        cout << "u1 = "  << u1 << " ";
        ll u2 = testmy(n,m,s,e,f,adj);
        cout << "u2 = " << u2 << endl;
        if(u1 == u2) return true;

        cout << "ERROR" << endl;
        cout << n << " " << m << " " << s+1 << " " << e+1 << endl;
        forn(i,0,n) cout << f[i] << "\n";
        //cout << "///////////////////////////////////////\n";
        forn(i,0,n)
        {
            //cout << "vertex = " << i << endl;
            forn(j,0,adj[i].size()) cout << i+1 << " " << adj[i][j]+1 << endl;
            //cout << endl;
        }
        return false;
    }
    return 2;
}

int main()
{
    boost;
    while(int  u = compare())
    {
        if(u == 2) cout << "Wrong data\n";
        else cout << "CORRECT DATA\n";
    }
    return 0;
}
/*
6 6 5 6
1
2
3
4
5
6
1 2
2 3
3 4
4 3
5 6
6 5
*/

/*
6 8 1 4
5
4
5
10
2
1
1 2
1 3
2 4
3 4
4 5
5 4
3 6
6 1
*/

/*
5 8 5 3
2
4
2
4
4
1 2
1 4
2 3
2 1
4 2
5 3
5 4
Ans = 16
*/
