#include<iostream>
#define forn(i,a,b) for(int i = a; i <b; i++)
#define ll long long
using namespace std;
int main()
{
    int n, l ,r, x;
    cin >> n >> l >> r >> x;
    int c[n];
    forn(i,0,n) cin >> c[i];
    int power = 1<<n;
    int sum = 0, mi = 1e9, ma = 0, bi = 0;
    int ans = 0;
    forn(i,0,power)
    {
        bi = 0;
        mi = 1e9;
        ma = 0;
        sum = 0;
        int po = 1;
        int pos = 0;
        while(po <= i)
        {
            if((po&i))
            {
                bi++;
                ma = max(ma, c[pos]);
                mi = min(mi, c[pos]);
                sum += c[pos];
            }
            pos++;
            po <<= 1;
        }
        if(bi >= 2 && sum >= l && sum <= r && (ma-mi) >= x)
                ans++;
    }
    cout << ans;
    return 0;
}
