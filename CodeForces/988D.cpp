#include<iostream>
#include<string>
#include<vector>
#include<math.h>
#include<algorithm>
#include<climits>
#include<set>

#define forn(i,a,b) for(unsigned int i = a; i < b; i++)
#define ll long long
#define MAX 3000000007
#define boost ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

bool ispower(ll d)
{
    if( __builtin_popcount(d) == 1) return true;
    return false;
}

int main()
{
    boost;
    unsigned ll n;
    cin >> n;
    ll x[n];
    forn(i,0,n) cin >> x[i];
    sort(x,x+n);
    vector<ll> ans;
    for(ll i = 0; i < n; i++)
    {
        vector<ll> v;
        for(ll d = 1; d <= (1<<30); d <<= 1)
        {
            if(binary_search(x+i+1,x+n,x[i]+d))
            {
                v.push_back(x[i]+d);
            }
        }
        ll n1 = v.size();
        for(ll j = 0; j < n1-1; j++)
        {
            if(ispower(v[j+1]-v[j]))
            {
                cout << "3\n";
                cout << x[i] << " " << v[j] << " " << v[j+1];
                return 0;
            }
        }
        if(ans.size() == 2)
        {
            continue;
        }
        ans.clear();
        ans.emplace_back(x[i]);
        if(n1)
            ans.emplace_back(v[0]);
    }
    cout << ans.size() << endl;
    forn(i,0,ans.size())
    cout << ans[i] << " ";
    return 0;
}
