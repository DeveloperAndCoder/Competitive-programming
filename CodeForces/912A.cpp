#include<iostream>
#include<vector>

#define forn(i,a,b) for(int i = a; i < b; i++)
#define ll long long

using namespace std;

int main()
{
    ll a,b,x,y,z;
    cin >> a >> b >> x >> y >> z;
    ll ans = 0;
    int buf = 0;
    if(a >= 2*x)
    {
        a -= 2*x;
        x = 0;
    }
    else
    {
        if(a%2 != 0)
            buf = 1;
        else
            buf = 0;
        a /= 2;
        x -= (a);
        a=0;
        a += buf;
    }
    if(b >= 3*z)
    {
        b -= 3*z;
        z = 0;
    }
    else
    {
        if(b%3 != 0)
            buf = b%3;
        else
            buf = 0;
        b /= 3;
        z -= (b);
        b=0;
        b += buf;
    }
    if(a >= y && b >= y)
    {
        b -= y;
        a -= y;
        y = 0;
    }
    else
    {
        y -= min(a,b);
        ll d = min(a,b);
        a -= d;
        b -= d;
    }
   // cout << x << " " << y << " " << z << " "  << a << " " << b <<  endl;
    if(x > 0)
    {
        ans += 2*x;
        ans -= a;
        a = 0;
    }
    if(z > 0)
    {
        ans += 3*z;
        ans -= b;
        b = 0;
    }
    if(y > 0)
    {
        ans += 2*y;
        if(a >= y)
            ans -= y;
        else
            ans -= a;
        if(b >= y)
            ans -= y;
        else
            ans -= b;
    }
    cout << ans;
    return 0;
}
