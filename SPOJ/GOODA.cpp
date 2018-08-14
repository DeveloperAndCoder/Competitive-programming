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

#define forn(i,a,b) for(int i = a; i < b; i++)
#define ll long long

using namespace std;

const int me = 1000025;
int comp_count;
int f_[me], used[me], comp_id[me];
long long has[me], result[me];
vector<int> dfs_list;
vector<int> v[me], gv[me];

void dfs1(int node){
    used[node] = 1;
    for(int i : v[node]){
        if(!used[i])
            dfs1(i);
    }
    dfs_list.push_back(node);
}

void dfs2(int node){
    used[node] = 1;
    comp_id[node] = comp_count;
    has[comp_count] += f_[node];
    for(int i : gv[node]){
        if(!used[i])
            dfs2(i);
    }
}

ll test1(ll N, ll M, ll S, ll E, ll f[], vector<int> adj[])
{
    comp_count = 0;
    dfs_list.clear();
    forn(i,0,me)
    {
        v[i].clear();
        gv[i].clear();
    }
    forn(i,0,me) has[i] = used[i] = comp_id[i] = result[i] = f_[i] = 0ll;
    for(int i = 1; i <= N; i ++)
        {
            f_[i] = f[i-1];
            cout << f_[i] << endl;
        }
    /*
    for(int i = 0; i < M; i ++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        v[a].push_back(b);
        gv[b].push_back(a);
    }
    */
    for(int i = 0; i < N; i++)
    {
        forn(j,0,adj[i].size())
        {
            int a = i+1;
            int b = adj[i][j]+1;
            v[a].push_back(b);
            gv[b].push_back(a);
            cout << a << "->" << b << endl;
        }
    }
    for(int i = 1; i <= N; i ++)
    {
        if(!used[i])
            dfs1(i);
    }
    reverse(dfs_list.begin(), dfs_list.end());
    fill(used, used + N + 1, 0);
    for(int i : dfs_list)
    {
        if(!used[i])
        {
            comp_count ++;
            dfs2(i);
        }
    }
    fill(used, used + comp_count + 1, 0);
    for(int i = 1; i <= comp_count; i ++)
        v[i].clear();
    for(int i = 1; i <= N; i ++)
        for(int j : gv[i])
            if(comp_id[i] != comp_id[j])
                v[comp_id[j]].push_back(comp_id[i]);
    //for(int i = 1; i <= N; i ++)
    //  cout << i << " ---> " << comp_id[i] << endl;
    //for(int i = 1; i <= comp_count; i ++)
    //  cout << i << " ---> has = " << has[i] << endl;
    fill(used, used + comp_count + 1, 0);
    queue<int> Q;
    Q.push(comp_id[S]);
    result[comp_id[S]] = has[comp_id[S]];
    while(!Q.empty())
    {
        int node = Q.front();
        Q.pop();
        used[node] = 1;
        for(int i : v[node])
        {
            if(used[i])
                continue;
            if(result[i] < result[node] + has[i])
            {
                result[i] = result[node] + has[i];
                Q.push(i);
            }
        }
    }
    cout << result[comp_id[E]] << " ";
    return result[comp_id[E]];
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
            continue;
        }
        else
        {
            adjList_new[p_start].push_back(p_vertex);
        }
        if(visited[vertex]==false)
            condense_graph_dfs(vertex,adjList,adjList_new,visited,dsu);
    }
}

ll testmy(ll n, ll m, ll s, ll e, ll f[], vector<int> adj[])
{
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
    cout << fun(adj_new, val, vis, dp, e, s) << endl;
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
    ll mx = 10;
    ll n, m, s, e;
    n = rand()%mx;
    if(n <= 1) n = 10;
    n = 3;
    m = rand()%mx;
    s = rand()%n;
    e = rand()%n;
    //cout << n << " " << m << " " << s << " " << e << endl;
    vector<int> adj[n];
    ll f[n];
    forn(i,0,n)
    {
        f[i] = rand()%n+1;
        //cout << "f["<<i<<"] = "<<f[i] << "\n";
    }
    adj[s].push_back(e);
    forn(i,0,m)
    {
        int a = rand()%n;
        int b = rand()%n;
        if(b == a) b++;
        b %= n;
        bool valid = true;
        forn(i,0,adj[a].size())
        {
            if(adj[a][i] == b)
            {
                valid = false;
                break;
            }
        }
        if(valid)
        {
            adj[a].push_back(b);
            //cout << a << "->" << b << endl;
        }
    }
    //if(verify(adj, n, s, e))
    {
        if(test1(n,m,s+1,e+1,f,adj) == testmy(n,m,s,e,f,adj)) return true;

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
