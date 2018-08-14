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
#define forn(i,a,b) for(ll i = a; i < b; i++)
#define boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define MAX 1000001

using namespace std;

int dp[1<<16], arr[16], n;
int max_height = 0, max_count = 0;

int solve(int mask, int peri, int prev_index)
{
    int col = __builtin_popcount(mask);

    if(col == n)
    {
        int curr = 0;
        if(prev_index != -1) curr = peri+arr[prev_index];
        else curr = peri;
        if(curr > max_height)
        {
            max_height = curr;
            max_count = 1;
        }
        else if(curr == max_height)
        {
            max_count++;
        }
        return curr;
    }

    /*
    if(dp[mask] != -1) {
            //cout << "mask = " << mask << endl;
            return dp[mask];
    }
    */

    int ans = peri;

    forn(i,0,n)
    {
        if(!(mask & (1<<i)))
        {
            int curr;
            if(prev_index != -1)
                curr = solve(mask | (1<<i), peri+abs(arr[i]-arr[prev_index])+2, i);
            else
                curr = solve(mask | (1<<i), peri+arr[i]+2, i);
            ans = max(ans, curr);
        }
    }
   // dp[mask] = ans;
    return ans;
}

int main()
{
    boost;
    while(1){
        cin >> n;
        if(n == 0) return 0;
        forn(i,0,n) cin >> arr[i];

        memset(dp, -1, sizeof(dp));

        solve(0, 0, -1);

        cout << max_height << " " << max_count << endl;
    }
    return 0;
}
