#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cstring>

#define forn(i,a,b) for(int i = a; i < b; i++)
#define N 102
#define boost ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long

using namespace std;

int  grid[101][101];
int dp[101][101][505];

void ans(int i, int j, int k, int n, int m)
{
    //cout << i << " " << j << " " << k << endl;
    if(i == n-1 && j == m-1) {
            if(grid[i][j] == k)
                dp[i][j][k] = 1;
            else
                dp[i][j][k] = 0;
            return;
    }
    if(i < 0 || j < 0 || i >= n || j >= m || grid[i][j] > k || k < 0)
    {
        dp[i][j][k] = 0;
        return;
    }
    if(dp[i][j][k] != -1)
    {
        return;
    }
    if(dp[i+1][j][k-grid[i][j]] == -1) ans(i+1,j,k-grid[i][j],n,m);
    if(dp[i][j+1][k-grid[i][j]] == -1) ans(i,j+1,k-grid[i][j],n,m);
    if(dp[i+1][j+1][k-grid[i][j]] == -1) ans(i+1,j+1,k-grid[i][j],n,m);
    /*if(i == 1 && j == 1 && k == 2)
    {
        cout << "------------------------\n";
        cout << dp[i+1][j][k-grid[i][j]] << " " << dp[i][j+1][k-grid[i][j]] << " " << dp[i+1][j+1][k-grid[i][j]] << endl;
    }
    */
    dp[i][j][k] = max(dp[i+1][j][k-grid[i][j]], max(dp[i][j+1][k-grid[i][j]],dp[i+1][j+1][k-grid[i][j]]));
    return;
}

int main()
{
    boost;
    int t;
    cin >> t;
    while(t--)
    {
        memset(dp, -1, sizeof(dp));
        ll n,m,k;
        cin >> n >> m >> k;
        forn(i,0,n)
        forn(j,0,m) cin >> grid[i][j];
        for(int l = k; l >= 0; l--)
        ans(0, 0, l, n, m);
        for(int i = k; i >= 0; i--)
        {
            if(dp[0][0][i] == 1)
            {
                cout << i << endl;
                goto last;
            }
        }
        cout << -1 << endl;
        last:;
    }
}
