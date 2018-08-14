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
#define D 400001
#define mod 1000000007

using namespace std;

pair<int,int> knapsack(int W, int wt[], int val[], int n, int &wtt)
{
    pair<int,int> dp[n+1][W+1];
    forn(i,0,n+1)
    {
        forn(w,0,W+1)
        {
            if(i == 0 || w == 0) dp[i][w] = {0,0};
            else if(wt[i-1] <= w)
            {
                dp[i][w].sc = max(dp[i-1][w].sc, dp[i-1][w-wt[i-1]].sc + val[i-1]);
                if(dp[i-1][w].sc == dp[i-1][w-wt[i-1]].sc + val[i-1])
                    dp[i][w].fr = min(dp[i-1][w].fr, dp[i-1][w-wt[i-1]].fr + wt[i-1]);
                else if(dp[i][w].sc == dp[i-1][w].sc)
                dp[i][w].fr = dp[i-1][w].fr;
                else dp[i][w].fr = dp[i-1][w-wt[i-1]].fr + wt[i-1];
            }
            else dp[i][w] = dp[i-1][w];
        }
    }
    /*
    int w = W;
    int res = dp[n][W];
    for(int i = n+1; i > 0 and res > 0; i--)
    {
        if(res == dp[i-1][w])
            continue;
        else
        {
            wtt += wt[i-1];
            w -= wt[i-1];
            res -= val[i-1];
        }
    }
    */
    return dp[n][W];
}

int main()
{
    boost;
    while(1)
    {
        int W, n;
        cin >> W >> n;
        if(W == 0 && n == 0) return 0;
        int wt[n], val[n];
        forn(i,0,n) cin >> wt[i] >> val[i];
        int wtt = 0;
        auto ans = knapsack(W,wt,val,n,wtt);
        cout << ans.fr << " " << ans.sc << endl;
    }
}
