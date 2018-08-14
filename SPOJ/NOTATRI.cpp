#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstring>
#include <sstream>
#include <vector>

#define ll long long
#define forn(i,a,b) for(ll i = a; i < b; i++)
#define boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define MAX 1000001

using namespace std;

int main()
{
    boost;
    int n;
    while(1)
    {
        cin >> n;
        if(!n) break;
        int l[n];
        forn(i,0,n) cin >> l[i];
        sort(l ,l+n);
        ll ans = 0;
        forn(i,0,n)
        {
            forn(j,i+1,n)
            {
                ans += (l+n-upper_bound(l ,l+n, l[i]+l[j]));
            }
        }
        cout << ans << endl;
    }
}
