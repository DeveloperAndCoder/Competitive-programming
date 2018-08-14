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

ul fac[D+2];

void calc()
{
    fac[0] = 1;
    forn(i,1,D+1)
    {
        fac[i] = fac[i-1]*i%mod;
        //cout << i << " "  << fac[i] << endl;
        fac[i]%=mod;
    }
}

ul power(ul x, ul y, ul p)
{
    ul res = 1;      // Initialize result

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

ul modInverse(ul n, ul p)
{
    return power(n, p-2, p);
}

ul nCr(ul n, ul r, ul p)
{
    if(n < 0) return 1;
    if(r < 0) return 1;
    if(n < r) return 0;
    if (r==0)
        return 1;
    return (fac[n]* modInverse(fac[r], p) % p *
            modInverse(fac[n-r], p) % p) % p;
}

bool cmp(ul x, const pair<ul,ul> &p2)
{
    return x<p2.fr;
}

bool cmp1(const pair<ul,ul> &p1, const pair<ul,ul> &p2)
{
    if(p1.fr == p2.fr)
        return p1.sc<p2.sc;
    return p1.fr<p2.fr;
}

int main()
{
    boost;
    int test;
    cin >> test;
    calc();
    while(test--)
    {
        ul n, k;
        cin >> n >> k;
        vector<pair<ul,ul> > seg(n);
        forn(i,0,n) cin >> seg[i].fr >> seg[i].sc;
        if(k == 1)
        {
            cout << n << endl;
            continue;
        }
        sort(seg.begin(), seg.end(), cmp1);
        ul ans = 0;
        forn(i,0,n)
        {
            ul x = upper_bound(seg.begin()+i+1, seg.end(), seg[i].sc, cmp) - seg.begin() - i - 1;
            //cout << i << " " << x << "\n";
            ans += nCr(n-i-1,k-1,mod) - nCr(x,k-1,mod);
            //cout << ans << endl;
            ans %= mod;
        }
        cout << ans%mod << endl;
        }
    return 0;
}
