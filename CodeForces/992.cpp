#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstring>
#include <sstream>
#include <vector>
#include <queue>
#include <stack>
#include <climits>

#define ll long long
#define ul unsigned long long
#define forn(i,a,b) for(int i = a; i < b; i++)
#define boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define fr first
#define sc second
#define MAX 1000001
#define D 400001
#define mod 1000000007

using namespace std;

ll power(ll a, ll b) {
	a %= mod;

	ll rv = 1LL;
	while (b) {
		if (b % 2) rv = rv*a%mod;
		a = a*a%mod;
		b /= 2;
	}
	return rv%mod;
}

ll modInverse(ll a, ll m)
{
        return power(a, m-2LL);
}

ll fix(ll n)
{
    if(n < 0LL) n += mod;
    return n;
}

int main()
{
    boost;
    ul x, k;
    cin >> x >> k;
    if(x == 0)
    {
        cout << 0;
        return 0;
    }
    x %= mod;
    ul pk = power(2LL, k);
    ul pk1 = power(2LL,k+1LL);
    ll ans = ((pk1%mod)*(x%mod))%mod;
    ans -= pk - 1LL;
    ans = (ans%mod + mod) % mod;
    ans *= pk;
    //cout << ans << endl;
    ans %= mod;
    //cout << ans;
    ans*=modInverse(pk, mod);
    ans %= mod;
    */
    cout << fix(ans);
}
