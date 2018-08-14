#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

#define forn(i,a,b) for(int i = a; i < b; i++)
#define ll long long
#define boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//#define INT_MAX 1000000000

using namespace std;

bool isposs(ll x[], ll c, ll n, ll dis)
{
    ll c_dis = 0, cows = 1;
    forn(i,1,n)
    {
        if(c_dis + x[i] - x[i-1] < dis)
            c_dis += (x[i] - x[i-1]);
        else
        {
            cows++;
            c_dis = 0;
        }
    }
    if(c_dis > dis)
        cows++;
    //cout << "dis = " << dis << " cows = " << cows << endl;
    return cows >= c;
}

ll binsrch(ll x[], ll c, ll n)
{
    ll low = x[1]-x[0], high = x[n-1]-x[0];
    forn(i,1,n)
    {
        low = min(low, x[i]-x[i-1]);
    }
    while(low<high)
    {
       // cout << "low = " << low << " high = " << high << endl;
        ll mid = (high + low) / 2;
        if(low == high-1)
        {
            if(isposs(x,c,n,high)) return high;
            else
                return low;
        }
        if(isposs(x,c,n,mid))
        {
         //   cout << "mid = " << mid << "\n";
            low = mid;
        }
        else
            high = mid-1;
        //cout << "low = " << low << " high = " << high << endl;
        //cout << "--------------------------------" << endl;
    }
    return low;
}

int main()
{
    boost;
    int t;
    cin >> t;
    while(t--)
    {
        ll n, c;
        cin >> n >> c;
        ll x[n];
        forn(i,0,n) cin >> x[i];
        sort(x, x+n);
        cout << binsrch(x,c,n) << '\n';
    }
    return 0;
}
