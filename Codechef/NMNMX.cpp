// A modular inverse based solution to
// compute nCr % p
#include<bits/stdc++.h>

#define ll unsigned long long
#define forn(i,a,b) for(ll i = a; i < b; i++)
#define boost ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'

using namespace std;

ll fac[5000];
ll modinv[5000];

void cacl(ll p)
{
    fac[0] = 1;
    for (ll i=1 ; i<=5000; i++)
        fac[i] = fac[i-1]*i%p;
}

/* Iterative Function to calculate (x^y)%p
  in O(log y) */
ll power(ll x, ll y, ll p)
{
    ll res = 1;      // Initialize result

    x = x % p;  // Update x if it is more than or
                // equal to p

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;

        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}

// Returns n^(-1) mod p
ll modInverse(ll n, ll p)
{
    return power(n, p-2, p);
}

// Returns nCr % p using Fermat's little
// theorem.
ll nCrModPFermat(ll n, ll r, ll p)
{
   // Base case
   if (r==0)
      return 1LL;
    if(n < r) return 0LL;

    // Fill factorial array so that we
    // can find all factorial of r, n
    // and n-r
    if(modinv[r] == -1) modinv[r] = modInverse(fac[r], p)%p;
    if(modinv[n-r] == -1) modinv[n-r] = modInverse(fac[n-r], p)%p;
    /**return (fac[n]* modInverse(fac[r], p) % p *
            modInverse(fac[n-r], p) % p) % p;
    */
    return ((fac[n]* modinv[r])%p * modinv[n-r]) % p;
}
int main()
{
    //boost;
    int N = 5000;
    vector<vector<ll> > C(N, vector<ll>(N, 0ULL));
    int mod = (int)1e9+7;
    cacl(mod);
    //cout << fac[2] << " " << fac[3] << endl;
    forn(i,0,N) modinv[i] = -1;
    /*
    forn(i,1,N)
    {
        forn(j,0,N)
        {
            C[i][j] = nCrModPFermat(i, j, mod);
        }
    }
    */
    for(int n = 0; n < N; n++)
    {
        for(int r = 0; r < N; r++)
        {
            if(n == 0 || n < r) {
                break;
            }
            if(r == 0)
            {
                C[n][r] = 1;
                continue;
            }
            if(n == 1 && r == 1)
            {
                C[1][1] = 1;
                continue;
            }
            C[n][r] = (C[n-1][r-1] + C[n-1][r])%(mod-1);
            //cout << n << "C" << r << " = " << C[n][r] << endl;
        }
    }
    //cout << modInverse(3, mod) << " " << modinv[3] << endl;
    //cout << "YO " << C[3][2] << " " << C[4][2] << " " << C[N-1][N/2] << endl;

    int t;
    cin >> t;
    while(t--)
    {
        ll n, k;
        cin >> n >> k;
        ll a[n];
        forn(i,0,n) cin >> a[i];
        sort(a, a+n);
        ll x = C[n-1][k-1];
        //cout << "x = " << x << endl;
        ll mul[n];
        forn(i,0,n) mul[i] = 0;
        forn(i,0,n)
        {
            mul[i] = (C[i][k-1] + C[n-i-1][k-1])%(mod-1);
            //cout << mul[i] << " ";
            mul[i] = (x - mul[i] + mod-1)%(mod-1);
            //cout << mul[i] << endl;
        }
        ll pow[n];
        forn(i,0,n)
        {
            pow[i] = power(a[i], mul[i], mod);
        }
        ll ans = 1;
        forn(i,0,n)
        {
            ans *= pow[i]%mod;
            ans %= mod;
        }
        cout << ans << endl;
    }
}
