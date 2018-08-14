#include<iostream>
#include<unordered_map>

#define forn(i,a,b) for(int i = a; i < b; i++)
#define ll long long

using namespace std;

const int mod = 1000000007;

ll sum(int n)
{
    if(n < 2) return 1;

    //ll x = sum(n/2);
    return (sum((n+1) / 2)*sum(n/2) + sum((n-1) / 2)*sum((n-2) / 2)) % mod;
}

int main()
{
    int t;
    //cin >> t;
    t = 1e5;
    int n, k, rem;
    ll ans = 0;
    forn(i,0,t)
    {
        //cin >> n >> k;
        n=k=1e9;
         if(k < n)
        {
            rem = n%k;
            ans = sum(k)-1;
            ans *= n/k;
            if(rem >= 1)
            ans += sum(rem)-1;
            ans %= mod;
            cout << ans << '\n';
        }
        else
        {
            ans = sum(n)-1;
            cout << ans << '\n';
            continue;
        }
    }
}
