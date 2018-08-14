#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

#define forn(i,a,b) for(int i = a; i < b; i++)
#define ll long long
#define mod 1000000007
#define pb push_back
#define em emplace_back
#define mk make_pair
#define fr first
#define sc second

using namespace std;

ll dp[101][2];

ll dfs(int n, int k, int d, ll sum, bool inc)
{
    ll ans = 0;
    if(sum > n) return 0;
    if(sum == n)
    {
        dp[sum][inc] = inc;
        return dp[sum][inc];
    }
    forn(i,1,k+1)
    {
        if(sum+i > n) break;

        if(dp[sum+i][inc|(i>=d)] == -1)
            ans += dfs(n,k,d,sum+i,inc|(i>=d))%mod;
        else
            ans += dp[sum+i][inc|(i>=d)]%mod;
    }
    dp[sum][inc] = ans;
    return ans;
}


int main()
{
    memset(dp, -1, sizeof(dp));
    int n,d,k;
    cin >> n >> k >> d;
    bool inc = false;
    ll ans = 0;
    ans = dfs(n,k,d,0,inc);
    cout << ans%mod;
    return 0;
}
