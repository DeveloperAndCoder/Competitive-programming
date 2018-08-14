#include <iostream>
#include <algorithm>
#include <math.h>

#define forn(i,a,b) for(int i = a; i < b; i++)
#define ll long long
#define boost ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

int dp[105][10001];

int f(int a[], int n, int k)
{
    if(k < 0) return INT_MAX;
    if(k == 0) return 0;
    if(n == 0)
    {
        if(a[0] == k) return 1;
        return INT_MAX;
    }
    if(n < 0) return INT_MAX;
    if(dp[n][k] != -1) return dp[n][k];
    int jk = f(a,n-1,k-a[n]);
    if(jk != INT_MAX) jk = jk+1;
    return dp[n][k] = min(f(a,n-1,k), jk);
}

int main()
{
    boost;
    int T;
    cin >> T;
    while(T--)
    {
        int n, k;
        cin >> n >> k;
        forn(i,0,n+1)
        forn(j,0,k+1) dp[i][j] = -1;
        int a[n];
        forn(i,0,n) cin >> a[i];
        int an = f(a, n-1, k);
        if(an == INT_MAX) cout << "impossible\n";
        else cout << an << '\n';
    }
    return 0;
}
