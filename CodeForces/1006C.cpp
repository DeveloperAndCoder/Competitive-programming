#include <bits/stdc++.h>

using namespace std;

#define forn(i,a,b) for(int i = a; i < b; i++)
#define ll long long
#define N (int)2e5+1

int main()
{
    int n;
    cin >> n;
    ll d[n], e[n];
    forn(i,0,n) {
        cin >> d[i];
        e[i] = d[i];
    }
    forn(i,0,n)
    {
        if(i)
        d[i] += d[i-1];
        if(i)
            e[n-1-i] += e[n-i];
    }
    ll mx = 0;
    forn(i,0,n)
    {
        if(binary_search(e+i+1, e+n, d[i], greater<ll>() ))
            mx = max(mx, d[i]);
    }
    cout << mx;
    return 0;
}
