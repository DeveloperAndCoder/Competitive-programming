#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstring>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <climits>

#define ll long long
#define forn(i,a,b) for(ll i = a; i < b; i++)
#define boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define MAX 1000001

int dp[1<<17];
int dis[17][17];

using namespace std;

int solve(int mask, int n)
{
    int queen = __builtin_popcount(mask);
    if(queen == n)
    {
        return 0;
    }
    if(dp[mask] != -1)
        return dp[mask];
    int ans = INT_MAX;
    forn(i,0,n)
    {
        if(!(mask & (1<<i)))
        {
            ans = min(ans, solve(mask|(1<<i), n) + dis[queen][i]);
        }
    }
    dp[mask] = ans;
    return ans;
}

int main()
{
    boost;
    while(1){
    int n;
    cin >> n;
    if(n == 0)
        return 0;
    memset(dp, -1, sizeof(dp));
    int q[n], f[n];
    forn(i,0,n) cin >> q[i];
    forn(i,0,n) cin >> f[i];
    forn(i,0,n)
    {
        forn(j,0,n)
        {
            dis[i][j] = abs(q[i]-f[j]) + abs(j-i);
        }
    }
    cout << solve(0, n) << endl;
    }
}
