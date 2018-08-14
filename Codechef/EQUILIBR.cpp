#include<bits/stdc++.h>

#define ll long long
#define forn(i,a,b) for(ll i = a; i < b; i++)
#define boost ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'

using namespace std;

ll power(ll x, unsigned ll y, unsigned ll m);

// Function to find modular inverse of a under modulo m
// Assumption: m is prime
ll modInverse(ll a, ll m)
{
    return power(a, m-2, m);
}

// To compute x^y under modulo m
ll power(ll x, unsigned ll y, unsigned ll m)
{
    if (y == 0)
        return 1;
    ll p = power(x, y/2, m) % m;
    p = (p * p) % m;

    return (y%2 == 0)? p : (x * p) % m;
}

int main()
{
    ll mod = (ll)1e9+7;
    //cout << modInverse(0, mod);
    ll n, k;
    cin >> n >> k;
    n--;
    ll den = power(2, n, mod);
    //cout << den << endl;
    den  %= mod;
    ll inv = modInverse(den, mod);
    ll p = (den + mod - (n+1))%mod;
    //cout << p << endl;
    p *= inv;
    p %= mod;
    cout << p << endl;
    return 0;
}
