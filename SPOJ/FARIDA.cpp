#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstring>
#include <sstream>
#include <vector>
#include <queue>
#include <stack>
#include <climits>

#define ll long long
#define ul unsigned long long
#define forn(i,a,b) for(int i = a; i < b; i++)
#define boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define fr first
#define sc second
#define MAX 1000001
#define N 1000001

using namespace std;

long long ans(long long coins[], int n)
{
    if(n == 0) return 0LL;
    if(n == 1) return coins[0];
    long long dp[n+1] = {0LL};
    dp[0] = coins[0];
    dp[1] = max(coins[0], coins[1]);
    for(int i = 2; i < n; i++)
    {
        dp[i] = max(dp[i-1], dp[i-2]+coins[i]);
    }
    return dp[n-1];
}

int main()
{
    int t;
    cin >> t;
    int k = 1;
    while(t--)
    {
        int n;
        cin >> n;
        long long coins[n];
        forn(i,0,n) cin >> coins[i];
        cout << "Case " << k++ << ": " << ans(coins, n) << endl;
    }
    return 0;
}
