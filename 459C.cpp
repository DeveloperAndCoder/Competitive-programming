#include<iostream>

#define forn(i,a,b) for(ll i = a; i < b; i++)
#define ll long long
#define boost ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

int main()
{
    boost;
    ll n, k, d;
    cin >> n >> k >> d;
    ll prod = 1;
    forn(i,0,d) {
        if(prod >= n) break;
        prod*=k;
    }
    if(n > prod)
    {
        cout << -1;
        return 0;
    }
    int ans[d][n];
    forn(i,1,n+1)
    {
        ll a = i;
        forn(j,0,d)
        {
            ans[j][i-1] = a%k+1;
            a/=k;
        }
    }
    forn(i,0,d)
    {
        forn(j,0,n)
        cout << ans[i][j] << " ";
        cout << '\n';
    }
    return 0;
}
