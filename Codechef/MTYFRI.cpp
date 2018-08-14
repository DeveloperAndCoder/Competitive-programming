#include <iostream>
#include <algorithm>
#define forn(i,a,b) for(int i = a; i < b; i++)
#define ll long long

using namespace std;

int gcd(int a, int b)
{
    if(a == 0) return b;
    if(b == 0) return a;
    if(a < b) swap(a,b);
    return gcd(a%b, b);
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, k;
        cin >> n >> k;
        int a[n];
        forn(i,0,n) cin >> a[i];
        int motu = 0, tomu = 0;
        int card = n/2;
        int to[card], mo[n-card];
        int j = 0, j1 = 0;
        forn(i,0,n)
        {
            if(i&1)
            {
                to[j++] = a[i];
                tomu += a[i];
            }
            else
            {
                mo[j1++] = a[i];
                motu += a[i];
            }
        }
        sort(mo, mo+n-card);
        sort(to, to+card);
        int n1 = n-card-1;
        forn(i,0,min(k, card))
        {
            if(mo[n1-i] > to[i])
            {
                motu -= mo[n1-i];
                tomu += mo[n1-i];
                motu += to[i];
                tomu -= to[i];
            }
            else break;
        }
        if(tomu > motu)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    return 0;
}


