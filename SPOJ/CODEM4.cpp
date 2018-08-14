#include <iostream>
#include <algorithm>

#define forn(i,a,b) for(int i = a; i < b; i++)

int dp[31][31];

using namespace std;

int dumb(int a[], int p1, int p2, bool chance)
{
    if(p1 > p2) return 0;
    if(dp[p1][p2]!=-1) return dp[p1][p2];
    int ans = 0;
    if(chance) ans = max(dumb(a,p1+1,p2,!chance) + a[p1], dumb(a,p1,p2-1,!chance)+a[p2]);
    else
    {
        ans = max(dumb(a,p1,p2-1,!chance), dumb(a,p1+1,p2,!chance));
    }
    //cout << p1 << " " << p2 << " " << ans << endl;
    dp[p1][p2] = ans;
    return ans;
}

int calc(int pre[], int p1, int p2)
{
    if(p1 > p2) return 0;
    if(p1 == 0) return pre[p2];
    return pre[p2]-pre[p1];
}

int clever(int a[], int p1, int p2, bool chance, int pre[])
{
    if(p1 > p2) return 0;
    if(dp[p1][p2]!=-1) return dp[p1][p2];
    int ans = 0;
    if(chance) ans = max(clever(a,p1+1,p2,!chance,pre) + a[p1], clever(a,p1,p2-1,!chance,pre)+a[p2]);
    else
    {
        ans = min(clever(a,p1+1,p2,!chance,pre), clever(a,p1,p2-1,!chance,pre));
    }
    //cout << "dp[" << p1 << "][" << p2 << "] = " << ans << endl;
    dp[p1][p2] = ans;
    return ans;
}

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int n;
        cin >> n;
        forn(i,0,n+1)
        forn(j,0,n+1)
            dp[i][j] = -1;
        int pre[n];
        int a[n];
        forn(i,0,n) {
            cin >> a[i];
        }
        pre[0] = a[0];
        forn(i,1,n)
        {
            pre[i] = pre[i-1] + a[i];
           // cout << i << " " << pre[i] << " " << a[i] << endl;
        }
        cout << dumb(a,0,n-1,1) << " ";
        forn(i,0,n+1)
        forn(j,0,n+1)
            dp[i][j] = -1;
        cout << clever(a,0,n-1,1,pre) << endl;
    }
    return 0;
}
