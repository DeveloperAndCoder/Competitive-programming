/*
#include<iostream>
#include<unordered_map>

#define forn(i,a,b) for(int i = a; i < b; i++)
#define ll long long

using namespace std;

const int mod = 1000000007;
const int N = 1e8;
//ll pre[N];

unordered_map<ll,ll> Fib;
int rem;

ll fib(ll n)
{
    if(n<2)
    {
        //pre[n] = 1;
        return 1;
    }
    if(Fib.find(n) != Fib.end())
    {

        //if(n < 1e8)
          //  pre[n] = Fib[n];

        return Fib[n];
    }
    //if(n < 1e8 && pre[n] == 0)
        {
            ll s,f;
            if(n&1)
            {
               // f = fib(((n+1)/2));
                s = fib((n/2));
                Fib[n] = (fib(((n+1)/2))*s + s*fib((n-2) / 2)) % mod; //(sum((n+1) / 2)*sum(n/2) + sum((n-1) / 2)*sum((n-2) / 2)) % mod;
                //pre[n] = Fib[n];
            }
            else
            {
                f = fib((n)/2);
                s = fib((n-1)/2);
                Fib[n] = f*f + s*fib(((n-2) / 2)) % mod;
            }
        }
   // if(n == rem) rem = Fib[n];
    return Fib[n];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    register int t;
    //cin >> t;
    t=1e5;
    register int n, k, rem;

    while(t--)
    {

        //cin >> n >> k;
        n = k = 1e9;
        ll ans = 0;
        if(k < n)
        {
            rem = n%k;
            ans = fib(k)-1;
            ans *= n/k;
            if(rem >= 1)
            ans += fib(rem)-1;
            ans %= mod;
            cout << ans << '\n';
        }
        else
        {
            ans = fib(n)-1;
            cout << ans%mod << '\n';
            continue;
        }
        //cout << ans << endl;

        //ans *= n/k;
        //rem = n%k;
        //ans += fib(rem)-1;
      //  cout << ans << '\n';

    }
    return 0;
}
*/
#include<iostream>
#include<stdio.h>
#include<unordered_map>

#define forn(i,a,b) for(int i = a; i < b; i++)
#define ll long long

using namespace std;

const int mod = 1000000007;
unordered_map<ll,ll> Fib;

ll fib(ll n)
{
    ll i,h,j,k,t;
    i=h=1;
    j=k=0;
    while(n>0) {
        if(n%2==1){
            t=j*h % mod;
            j=(i*h + j*k +t) % mod;
            i=(i*k%mod + t);
        }
        t=h*h%mod;
        h=(2*k*h + t)%mod;
        k=(k*k%mod + t%mod)%mod;
        n=(ll) n/2;
    }
    return j%mod;
}
void fastscan(int &number)
{
    //variable to indicate sign of input number
    bool negative = false;
    register int c;

    number = 0;

    // extract current character from buffer
    c = getchar();
    if (c=='-')
    {
        // number is negative
        negative = true;

        // extract the next character from the buffer
        c = getchar();
    }

    // Keep on extracting characters if they are integers
    // i.e ASCII Value lies from '0'(48) to '9' (57)
    for (; (c>47 && c<58); c=getchar())
        number = number *10 + c - 48;

    // if scanned input has a negative sign, negate the
    // value of the input number
    if (negative)
        number *= -1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    register int t;
    //cin >> t;
    fastscan(t);
    //t = 1e5;
    register int n, k, rem;

    while(t--)
    {
        fastscan(n);
        fastscan(k);
    //    n=k=1e9;
        ll ans = 0;
        if(k < n)
        {
            rem = n%k;
            ans = fib(k+1)-1;
            ans *= n/k;
            if(rem >= 1)
            ans += fib(rem+1)-1;
            ans %= mod;
            cout << ans%mod << '\n';
        }
        else
        {
            ans = fib(n+1)-1;
            cout << ans%mod << '\n';
            continue;
        }
    }
    return 0;
}
