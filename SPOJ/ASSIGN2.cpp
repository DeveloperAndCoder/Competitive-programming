/*
NOTE: BOTTOM UP APPROACH

FOR TOP DOWN APPROACH SEE ASSIGN.cpp ==> GIVES BETTER INSIGHT
*/


#include <iostream>
#include <climits>
#include<cstdlib>
#include<cstring>

#define forn(i,a,b) for(int i = a; i < b; i++)
#define boost ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long

using namespace std;

ll dp[1<<20];
bool asgn[21][21];
ll int n,lim;

int main()
{
    boost;
    int c;
    //c = 80;
    cin >> c;
    while(c--)
    {
    	memset(dp, 0, sizeof(dp));
      //  n = 20;
      cin >> n;
        forn(i,0,n)
        forn(j,0,n) //asgn[i][j] = 1;//rand()%2;
        cin >> asgn[i][j];
        dp[(1<<n)-1] = 1;
        for(ll mask = (1<<n)-1; mask >= 0 ; mask--)
        {
            int i = __builtin_popcount(mask);
            for(int j = 0; j < n; j++)
            {
                if(asgn[i][j] && !(mask&(1<<j)))
                    dp[mask] += dp[mask | (1<<j)];
            }
        }
        cout << dp[0] << '\n';
    }
}
