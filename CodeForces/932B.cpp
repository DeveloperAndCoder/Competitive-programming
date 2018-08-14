#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>

#define forn(i,a,b) for(ll i = a; i < b; i++)
#define ll long long

using namespace std;

const int M = 1000002;
const int N = 4782970;
vector<ll> g(M,0);
vector<ll> dp(N,0);

ll f(ll n)
{
    ll ans = 1;
    while(n != 0LL)
    {
        if(n%10)
        ans = ans*(n%10);
        n /= 10;
    }
    return ans;
}

ll calc(ll a)
{
    while(a >= 10LL)
    {
        a = f(a);
    }
    return a;
}

void G()
{
    ll f_;
    forn(i,0,M)
    {
        f_ = f(i);
        if(dp[f_] == 0LL)
        {
            //cout << f_ << " dp = ";
            dp[f_] = calc(f_);
            //cout << dp[f_];
        }
        //cout << "RE " << i << '\n';
        g[i] = dp[f_];
    }
    return;
}

int main()
{
/*
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
*/
    int q;
    cin >> q;

    //memset(dp, 0, sizeof(dp));
    G();
   // forn(i,0,M) cout << g[i];
    vector< vector<ll> > l(M, vector<ll>(10,0));
    forn(i,0,10) l[0][i] = 0;
    forn(i,1,M)
    {
        //cout << g[i] << endl;
        l[i][g[i]]++;
        forn(j,0,10)
        {
            l[i][j] += l[i-1][j];
        }
    }
    ll x,y,t;
    while(q--)
    {
        cin >> x >> y >> t;
        cout << l[y][t] - l[x-1][t] << '\n';
    }
    return 0;
}
