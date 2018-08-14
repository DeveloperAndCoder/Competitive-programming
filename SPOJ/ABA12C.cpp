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

int price[101];
int dp[102][102];

int money(int n, int kg)
{
    if(n == 0 && kg > 0)
    {
        dp[n][kg] = 1000000;
        //cout << n << " " << kg << " " << dp[n][kg] << endl;
        return dp[n][kg];
    }
    if(n == 0 || kg == 0)
    {
        dp[n][kg] = 0;
        //cout << n << " " << kg << " " << dp[n][kg] << endl;
        return 0;
    }
    if(n <= 0 || kg < 0) {
        //    cout << n << " " << kg << " " << "MAX" << endl;
            return 1000000;
    }
    int res = 1000000;
    forn(i,0,kg)
    {
        if(price[i] != -1)
        {
            if(dp[n-1][kg-(i+1)] == INT_MAX)
            {
                dp[n-1][kg-(i+1)] = money(n-1,kg-(i+1));
            }
            res = min(res, dp[n-1][kg-(i+1)]/*money(n-1,kg-(i+1))*/ + price[i]);
      //      cout << n << " " << kg << " " << i << " " << res << " " << dp[n-1][kg] << endl;
        }
    }
    //cout << "res = " << res << endl;
    dp[n][kg-1] = res;
    return res;
}

int main()
{
    boost;
    int t;
    cin >> t;
    while(t--)
    {
        int n, k;
        cin >> n >> k;
        forn(i,0,102)
        {
            forn(j,0,102)
            dp[i][j] = INT_MAX;
        }
        forn(i,0,k) cin >> price[i];
        int mm = money(n,k);
        if(mm > 100000) mm = -1;
        cout << mm << endl;
    }
}
