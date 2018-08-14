#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstring>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <climits>
#include <tuple>

#define ll long long
#define forn(i,a,b) for(ll i = a; i < b; i++)
#define boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define MAX 1000001

using namespace std;

ll m = 0ll;

bool cmp(pair<ll,ll> &p1, pair<ll,ll> &p2)
{
    return p1.first%m < p2.first%m;
}

int main()
{
    ll n;
    cin >> n >> m;
    ll a[n];
    forn(i,0,n) cin >> a[i];
    ll c[m];
    for(int i = 0; i < m; i++) c[i] = 0;
    vector<pair<ll,ll> > free;
    forn(i,0,n)
    {
        if(c[a[i]%m] == n/m)
        {
            free.push_back({a[i],i});
        }
        else
        {
            c[a[i]%m]++;
        }
    }
    sort(free.begin(), free.end(), cmp);
    ll move = 0;
    if(free.size() == 0)
    {
        cout << 0 << endl;
        forn(i,0,n) cout << a[i] << " ";
        return 0;
    }
    /*
    forn(i,0,m)
    cout << c[i] << " ";
    cout << endl;
    for(auto it : free)
    cout << it.first << " " << it.second << endl;
    */
    int p1 = free[0].first%m;
    for(int i = 0; i < free.size(); i++)
    {
        for(; c[p1%m] >= n/m; p1++, p1%=m);
        p1%=m;
        //cout << free[i].first << " " << p1 << endl;
         if(p1 < free[i].first%m)
         {
             //cout << "in\n";
             move += (m-free[i].first%m + p1);
             a[free[i].second] += (m-free[i].first%m + p1);
         }
         else
         {
             move += (p1-free[i].first%m);
             a[free[i].second] += (p1 - free[i].first%m);
         }
         c[p1]++;
    }
    cout << abs(move) << endl;
    forn(i,0,n) cout << a[i] << " ";
    return 0;
}
