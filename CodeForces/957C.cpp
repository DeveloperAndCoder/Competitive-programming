#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<iomanip>

#define forn(i,a,n) for(int i = 0; i < n; i++)
#define ll long long
#define eb emplace_back
#define mem(array,value) memset(array, value, sizeof(array))

using namespace std;

int main()
{
    int n, u;
    cin >> n >> u;
    vector<ll> e(n);
    forn(i,0,n) cin >> e[i];
    double ans=0;
    bool l = 0;
    forn(i,0,n-2)
    {
        vector<ll>::iterator it = upper_bound(e.begin(), e.end(), e[i]+u);
        if((it-1 == (e.begin()+i)) || (it-1 == e.begin()+i+1));
        else
        {
            it--;
            l=1;
            ans = max(ans, (*it-e[i+1])/(*it-e[i]+0.0));
        }
    }
    if(l)
    {
        cout << setprecision(12) << fixed << ans;
    }
    else
    {
        cout << -1;
    }
    return 0;
}
