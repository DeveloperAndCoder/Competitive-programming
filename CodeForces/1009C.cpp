#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_set>

#define forn(i,a,b) for(int i = a; i < b; i++)
#define ll long long

using namespace std;

ll C(int n)
{
    if(n < 0) return 0LL;
    return n*1LL*(n+1)/2;
}

int main()
{
    int n, m;
    cin >> n >> m;
    ll ans = 0;
    while(m--)
    {
        int x, d;
        cin >> x >> d;
        int j = (n-1)/2;
        ll a = (C(j) + C(n-j-1))*d;
        j++;
        ll b = (C(j) + C(n-j-1))*d;
        ll c = (C(0) + C(n-1))*d;

        ans += max(a, max(c, b)) + n*x;
    }
    double mean = ans/(n+0.0);
    cout << mean;
    return 0;
}
