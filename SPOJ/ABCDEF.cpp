#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstring>
#include <sstream>
#include <vector>

#define ll long long
#define forn(i,a,b) for(ll i = a; i < b; i++)
#define boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

void print(vector<ll> p)
{
    forn(i,0,p.size())
    {
        cout << p[i] << " ";
    }
    cout << endl;
    return;
}

int main()
{
    ll n;
    cin >> n;
    ll s[n];
    forn(i,0,n) cin >> s[i];
    ll a,b,c,d,e,f;
    vector<ll> v1,v2;
    forn(i,0,n)
    {
        forn(j,0,n)
        {
            forn(k,0,n)
            {
                a = s[i];
                b = s[j];
                c = s[k];
                v1.push_back(a*(ll)b+(ll)c);
            }
        }
    }
    forn(i,0,n)
    {
        if(s[i] == 0)
            continue;
        forn(j,0,n)
        {
            forn(k,0,n)
            {
                d = s[i];
                e = s[j];
                f = s[k];
                v2.push_back((e+(ll)f)*(ll)d);
            }
        }
    }

    //sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    ll ans = 0;
   // print(v1);
   // print(v2);
    forn(i,0,v1.size())
    {
        ll x2 = upper_bound(v2.begin(),v2.end(),v1[i])-lower_bound(v2.begin(),v2.end(),v1[i]);
       // cout << v1[i] << " " << x1 << " " << x2 << endl;
        ans += x2;
    }
    cout << ans;
    return 0;
}
