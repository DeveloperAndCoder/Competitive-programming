/*
NOTE:
TOP DOWN APPROACH
TLE ON SPOJ

FOR BOTTOM UP SEE ASSIGN2.cpp
*/
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

ll dp[1<<20][21];
bool asgn[20][20];
int n;

ll count_assign(ll mask, int i)
{
    if(i == n && mask == (1<<n)-1)
    {
        dp[mask][i] = 1;
        return 1;
    }
    if(i >= n)
    {
        return 0;
    }
    if(i < n && mask == (1<<n)-1)
    {
        dp[mask][i] = 0;
        return 0;
    }
    if(dp[mask][i] != -1) {
            return dp[mask][i];
    }
    ll cnt = 0;
    forn(j,0,n)
    {
        if(asgn[i][j] && !(mask&(1<<j)))
        {
            if(dp[mask | (1<<j)][i+1] == -1) dp[mask | (1<<j)][i+1] = count_assign(mask | (1<<j), i+1);
            cnt += dp[mask | (1<<j)][i+1];
        }
    }
    dp[mask][i] = cnt;
    return cnt;
}

int main()
{
    boost;
    int c;
    cin >> c;
    while(c--)
    {
        forn(i,0,1<<20)
        forn(j,0,21) dp[i][j] = -1;
        cin >> n;
        forn(i,0,n)
        forn(j,0,n) cin >> asgn[i][j];
        ll mask = 0;
        cout << count_assign(mask, 0) << '\n';
    }
}
