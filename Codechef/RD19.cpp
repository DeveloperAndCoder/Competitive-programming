#include <iostream>
#define forn(i,a,b) for(int i = a; i < b; i++)
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
        int gcd1 = a[0];
        forn(i,1,n) gcd1 = gcd(gcd1, a[i]);
        if(gcd1 == 1) cout << 0;
        else cout << -1;
        cout << endl;
    }
    return 0;
}
