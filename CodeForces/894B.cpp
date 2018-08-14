#include<bits/stdc++.h>
#define ull unsigned long long
#define mod 1000000007
using namespace std;

int power(int x, int y)
{
    if(y == 0)
        return 1;
    if(y == 1)
        return x;
    int temp = power(x, y/2);
    if(y % 2 == 0)
        return temp*temp;
    else
    {
        if(y > 0)
            return x*temp*temp;
        else
            return temp*temp/x;
    }
}

ull qpower(ull a, ull b)
{
    ull res = 1;
    while(b)
    {
        if(b&1)
        {
            res = (res * a)%mod;
        }
        a = a*a;
        a = a%mod;
        b >>= 1;
    }
    return res;
}

int main()
{
    ull n,m;
    int k;
    cin >> n >> m >> k;
    if(((n+m)&1) && (k==-1)) puts("0");
    else
    {
        cout << qpower(qpower(2, n-1), m-1);
    }
    return 0;
}
