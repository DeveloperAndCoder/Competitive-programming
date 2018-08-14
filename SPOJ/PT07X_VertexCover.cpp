#include<iostream>
#include<cstdlib>
#include<vector>
#include<cstring>
#include<stack>

#define forn(i,a,n) for(int i = 0; i < n; i++)
#define ll long long
#define eb emplace_back
#define mem(array,value) memset(array, value, sizeof(array))

using namespace std;

const int N = 100001;
vector<int> v[N];
int dp[N][2];

void dfs(int u, int par)
{
    forn(i,0,v[u].size())
    {
        int x = v[u][i];
        if(x == par) continue;
        dfs(x, u);
    }
    forn(i,0,v[u].size())
    {
        int x = v[u][i];
        if(x == par) continue;
        dp[u][0] += dp[x][1];
    }
    forn(i,0,v[u].size())
    {
        int x = v[u][i];
        if(x == par) continue;
        dp[u][1] += min(dp[x][0], dp[x][1]);
    }
    dp[u][1]++;
    return;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    forn(i,0,n-1)
    {
        int a,b;
        cin >> a >> b;
        a--;b--;
        v[a].eb(b);
        v[b].eb(a);
    }
    dfs(0, -1);
   // cout << dp[0][0] << " " << dp[0][1] << endl;
    cout << min(dp[0][0], dp[0][1]);
    return 0;
}
