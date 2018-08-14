#include <iostream>
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
        int n;
        cin >> n;
        int a[n];
        forn(i,0,n) cin >> a[i];
        unsigned ans = 0;
        forn(i,0,n)
        ans ^= a[i];
        ans <<= 1;
        cout << ans << endl;
    }
    return 0;
}

