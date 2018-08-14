#include<iostream>
#include<utility>
#include<vector>

#define forn(i,a,b) for(int i = a; i < b; i++)
#define fr first
#define sc second

using namespace std;

void dfs(const vector<pair<int, int> > &c, int k, int n, vector<bool> &vis)
{
    vis[k] = true;
    forn(j,0,n)
    {
        if((c[k].sc == c[j].sc || c[k].fr == c[j].fr) && !vis[j])
        {
            vis[j] = true;
            dfs(c, j, n, vis);
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int> > c(n);
    forn(i,0,n) cin >> c[i].fr >> c[i].sc;
    int ans = 0;
    vector<bool> vis(1001,0);
    forn(i,0,n)
    {
        if(vis[i]) continue;
        ans++;
        dfs(c, i, n, vis);
    }

    cout << ans-1;
    return 0;
}
