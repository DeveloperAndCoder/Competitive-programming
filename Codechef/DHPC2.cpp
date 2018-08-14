#include<iostream>
#include<algorithm>
#include<cstring>

#define forn(i,a,b) for(int i = a; i < b; i++)
#define ll long long

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,x,y;
    cin >> n;
    int a[n];
    forn(i,0,n) cin >> a[i];
    cin >> x >> y;
    sort(a,a+n);
    int i = n-1;
    ll ans = 0;
    for(i; i >= 0 && x > 0; i--)
    {
        if(ans == 0) ans = 1;
        //cout << "i = " << i << " ";
        ans *= a[i];
        if(i != n-1)
        x--;
    }
    for(i; i >= 0; i--)
    {
        ans += a[i];
    }
    cout << ans;
    return 0;
}
