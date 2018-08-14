#include<iostream>
#include<vector>

#define forn(i,a,b) for(int i = a; i < b; i++)
#define forn_r(i,a,b) for(int i = a; i >= b; i--)
#define ll long long

using namespace std;

ll abc(vector< vector<int> > &dp, int c[], int n, int l)
{
    forn(i,0,n+1) dp[i][0] = 0;
    forn(j,0,l+1) dp[0][j] = INT_MAX;
    dp[0][0] = 0;

    forn(i,1,n+1)
    {
        forn(j,1,l+1)
        {
            dp[i][j] = INT_MAX;
            forn(k,0,j+1)
            {
                int po = 1<<(k-1);
                if(k-po >= 0)
                {
                    dp[i][j] = min(dp[i][j], min(dp[i-1][k], dp[i-1][k-po] + c[k-1]));
                }
                else
                {
                    dp[i][j] = min(dp[i][j], min(dp[i-1][k], c[k-1]));
                }
            }
            cout << "dp[" << i << "][" << j << "] = " << dp[i][j] << endl;
        }
    }

    return dp[n][l];
}


int main()
{
    int n, l;
    cin >> n >> l;
    int c[n];
    forn(i,0,n) cin >> c[i];
    vector< vector<int> > dp(n+1, vector<int>(l+1));
    ll ans = abc(dp,c,n,l);
    cout << ans;
    return 0;
}
