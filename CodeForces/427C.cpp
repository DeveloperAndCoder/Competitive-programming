/*
AUTHOR : ANURAG SHAH
INSTITUTE : IIT JODHPUR
*/

#include<iostream>
#include<vector>
#include<cstring>
#include<stack>

#define forn(i,a,n) for(int i = 0; i < n; i++)
#define ll long long
#define eb emplace_back
#define mem(array,value) memset(array, value, sizeof(array))

const int mod = 1000000007;

using namespace std;

int i0;

void dfs(vector< vector<int> > &v, int src, int n, int m, vector<bool> &vis, stack<int> &seq, bool rev, vector< vector<int> > &scc)
{
    if(rev)
    {
        scc[i0].push_back(src);
    }
    vis[src] = true;
    for(unsigned int i = 0; i < v[src].size(); i++)
    {
        int j = v[src][i];
        if(!vis[j])
        {
            dfs(v,j,n,m,vis,seq,rev,scc);
        }
    }
    if(!rev)
    seq.push(src);
    return;
}

void dfs_visit(vector< vector<int> > &v, int n, int m, stack<int> &seq, vector< vector<int> > &scc)
{
    vector<bool> vis(n,0);
    forn(i,0,n)
    {
        if(!vis[i])
        {
            dfs(v,i,n,m,vis,seq,false,scc);
        }
    }
    return;
}

void scc_cmp(vector< vector<int> > &v, int n, int m, stack<int> &seq, vector< vector<int> > &scc)
{
    vector<bool> vis(n,0);
    while(!seq.empty())
    {
        int top = seq.top();
        if(!vis[top])
        {
            scc.push_back( vector<int>() );
            dfs(v,top,n,m,vis,seq,true,scc);
            i0++;
        }
        else
        {
            seq.pop();
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int> cost(n);
    forn(i,0,n) cin >> cost[i];
    int m;
    cin >> m;
    vector< vector<int> > v(n);
    vector< vector<int> > t_v(n);
    vector< vector<int> > scc;
    forn(i,0,m)
    {
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        v[a].push_back(b);
        t_v[b].push_back(a);
    }
    stack<int> seq;
    dfs_visit(v,n,m,seq,scc);
    scc_cmp(t_v,n,m,seq,scc);
    ll per = 1, p0, cst = 0;
    forn(i,0,i0)
    {
        p0=0;
        int mini = cost[scc[i][0]];
        for(unsigned int j = 1; j < scc[i].size(); j++)
        {
            mini = min(mini,cost[scc[i][j]]);
        }
        for(unsigned int j = 0; j < scc[i].size(); j++)
        {
            if(cost[scc[i][j]] == mini) p0++;
        }
        per *= p0;
        per %= mod;
        cst += mini;
    }
    cout << cst << " " << per;
    return 0;
}
