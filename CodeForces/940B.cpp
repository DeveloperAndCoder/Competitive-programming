#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>

#define forn(i,a,b) for(int i = a; i < b; i++)
typedef long long ll;

using namespace std;

int main()
{
    ll n, k, a, b;
    cin >> n >> k >> a >> b;
    ll x = n;
    ll cost = 0;

    if(k == 1)
    {
        cost += (x-1)*a;
        cout << cost;
        return 0;
    }
    while(x > 1)
    {
        if(x%k == 0)
        {
            if(b < (x-x/k)*a)
            {
                cost += b;
                x = x/k;
            }
            else
            {
                cost += (x-1)*a;
                cout << cost;
                return 0;
            }
        }
        else
        {
            ll cmp;
            if(x < k)
                cmp = x-1;
            else cmp = x%k;
            cost += cmp*a;
            x = x-cmp;
        }
    }
    cout << cost;
    return 0;
}
