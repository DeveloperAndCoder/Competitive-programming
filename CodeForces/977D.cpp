#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

#define forn(i,a,b) for(int i = a; i < b; i++)
#define ll long long
#define mod 1000000007
#define boost ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

void dfs(vector< vector<int> > adj[], int n, bool vis[], int u)
{
    if(vis[u])
        return;
    vis[u] = true;
    forn(i,0,adj[u].size())
    {
        int v = adj[u][v];
        if(!vis[v])
        {
            vis[v] = true;
            dfs(adj, n, vis, v);
        }
    }
    return;
}

bool binsearch(int a[], int val, bool vis[], int i, int j)
{
    int mid = (i+j)/2;
    if(a[mid] > val)
        binsearch(a,val,vis,mid+1,j-1);
    else if(a[mid] < val)
        binsearch(a,val,vis,i,mid-1);
    else
    {
        if(vis[mid])
        {
            int ptr = i;
            while(ptr < n && a[ptr] == a[mid] && vis[ptr]) ptr++;
            if(ptr < n && a[ptr] == a[mid] && !vis[ptr])
            {
                vis[ptr] = true;
                return true;
            }
            ptr = i;
            while(ptr >= 0 && a[ptr] == a[mid] && vis[ptr]) ptr--;
            if(ptr >= 0 && a[ptr] == a[mid] && !vis[ptr])
            {
                vis[ptr] = true;
                return true;
            }
            return false;
        }
        else
        {
            vis[mid] = true;
            return true;
        }
    }
}

int main()
{
    boost;
    int n;
    cin >> n;
    int a[n];
    forn(i,0,n) cin >> a[i];
    sort(a, a+n);

    bool vis[n];
    memset(vis, n, false);

    return 0;
}
