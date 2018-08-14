#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long
#define mod 1000000007

ll power(ll A, int N)
{
    if(A == 0) return 0;
    if(N == 0) return 1LL;
    ll half = power(A,N/2)%mod;
    if(A&1)
    {
        ll res = (half*half)%mod;
        res = res*A;
        res %= mod;
        return res;
    }
    else
    {
        ll res = (half*half)%mod;
        return res;
    }
}



int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        ll A, B, N;
        cin >> A >> B >> N;
        if(A < B) swap(A,B);
        ll x = (power(A,N) + power(B,N))%mod;
        ll y = (A-B)%mod;
        cout << __gcd(x,y) << '\n';
    }
    return 0;
}
