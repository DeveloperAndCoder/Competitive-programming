#include<iostream>

using namespace std;

#define ll long long
#define forn(i,a,b) for(int i = a; i < b; i++)
#define boost ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main()
{
    boost;
    ll t, n, h, k;
    cin >> t;
    ll a[100001];
    //t = 10;
    while(t--)
    {
        cin >> n >> h;
        //n = (t+1)*1000;
        forn(i,0,n) cin >> a[i];
        ll sum = 0;
        forn(i,0,n)
        {
            sum += a[i];
        }
        k = sum/h;
        if(k==0)k++;
        ll tot = 0;
        while(1)
        {
            tot = 0;
            forn(i,0,n)
            {
                tot += (a[i]/k) + (a[i]%k != 0);
            }
            if(tot <= h) break;
            k++;
            cout << k << endl;
        }
        cout << k << '\n';
    }
    return 0;
}
