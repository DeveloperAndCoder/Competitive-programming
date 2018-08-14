#include<iostream>
#include<algorithm>

#define ll long long
#define forn(i,a,b) for(ll i = a; i < b; i++)

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    ll a[n];
    ll b[m];
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];

    long long ans;
    long long ma[n];
    forn(i,0,n) ma[i]=-1000000000000000000;
    forn(i,0,n)
    {
        forn(j,0,n)
        {
            if(j == i)
                continue;
            forn(k,0,m)
            {
                if(ma[i]<a[j]*b[k])
                    {
                        ma[i]=a[j]*b[k];
                    }
            }
        }
    }
    sort(ma,ma+n);
    ans = ma[n-1];
    for(ll i = n-2; i >= 0; i--)
        if(ans != ma[i])
        {
            ans = ma[i];
            break;
        }
    cout << ans;

    return 0;
}
