#include<iostream>
#include<vector>
#include<math.h>

#define forn(i,a,b) for(int i = a; i < b; i++)
#define ll long long

using namespace std;

int main()
{
    ll n, k;
    cin >> n >> k;
    if(k == 1)
    {
        cout << n;
    }
    else
    {
        ll ans = n;
        ll bi = 1;
        while(n > 0)
        {
            ans |= bi;
            bi <<= 1;
            n >>= 1;
        }
        cout << ans;
    }
    return 0;
}
