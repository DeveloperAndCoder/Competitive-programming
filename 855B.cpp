#include<iostream>
#include<vector>

#define forn(i,a,b) for(ll i = a; i < b; i++)
#define ll long long

using namespace std;

ll max(ll a, ll b)
{
    if(a>b)
        return a;
    return b;
}

void first_dp(vector<ll> &dp0, ll a[], ll p, ll n)
{
    dp0[0] = a[0]*p;
    forn(i,1,n)
    {
        dp0[i] = max(dp0[i-1],a[i]*p);
    }
    return;
}

void second_dp(vector<ll> &dp1, vector<ll> &dp0, ll a[], ll q, ll n)
{
    dp1[0] = a[0]*q+dp0[0];
    forn(x,1,n)
    {
        dp1[x] = max(dp1[x-1], dp0[x]+a[x]*q);
    }
    return;
}

int main()
{
    ll n, p, q, r;
    cin >> n >> p >> q >> r;
    ll a[n];
    forn(i,0,n) cin >> a[i];
    vector<ll> dp0(n,0);
    vector<ll> dp1(n,0);
    vector<ll> dp2(n,0);

    first_dp(dp0,a,p,n);
    second_dp(dp1,dp0,a,q,n);
    second_dp(dp2,dp1,a,r,n);

    cout << dp2[n-1];

    return 0;
}
