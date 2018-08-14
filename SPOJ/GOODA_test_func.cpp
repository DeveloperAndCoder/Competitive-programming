#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include<unordered_set>
#include<utility>

#define forn(i,a,b) for(int i = a; i < b; i++)
#define ll long long

using namespace std;

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

ll ans = 0ll;

long long fun(vector<ll> cdn_g[], ll val[], bool vis[], ll dp[], ll e, ll u)
{
    if(u == e) {
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
bool cmp(const pair<ll,ll> &p1, const pair<ll,ll> &p2)
{
    return (p1.first == p2.first && p1.second == p2.second);
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
    for(int i=0;i<adjList[start].size();i++)
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
            /*
        	bool inc = true;
        	for(int i = 0; i < adjList_new[p_start].size(); i++)
        	if(adjList_new[p_start][i] == p_vertex)
        	{
        		inc = false;
        		break;
        	}

            if(inc)*/
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

int main()
{
    ll n, m, s, e;
    cin >> n >> m >> s >> e;
    s--;e--;
    ll f[n];
    forn(i,0,n) cin >> f[i];
    vector<ll> g[n], gt[n];
    forn(i,0,m)
    {
        ll a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        gt[b].push_back(a);
    }
    ll dsu[n], size[n];
    forn(i,0,n) dsu[i] = i, size[i] = 1;
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
   // forn(i,0,n) cout << i+1 << " " << val[i] << " \n";
  //  cout << endl;
    bool v_root[n], vis[n];
    forn(i,0,n) vis[i] = v_root[i] = false;
    vector<ll> adj_new[n];
    condense_graph_dfs(s, g, adj_new, vis, dsu);
/*
    forn(i,0,n)
    {
        //cout << "i = " << i << " " << root(dsu, i) <<  endl;
        forn(j,0,adj_new[i].size()) cout << i+1 << "->" << adj_new[i][j]+1 << "\n";
        cout << endl;
    }

*/
    //bool inc = false;
    ll dp[n];
    forn(i,0,n) dp[i] = -1e18;
    s = root(dsu, s);
    e = root(dsu, e);
    cout << fun(adj_new, val, vis, dp, e, s);
    return 0;
}
/*
5 7 4 0
5
5
4
4
3
0 1
1 0
1 2
2 3
2 1
4 0
4 2
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
