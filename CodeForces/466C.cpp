#include<iostream>
#include<cstring>
#define forn(i,a,b) for(int i = a; i < b; i++)
#define forr(i,a,b) for(int i = a; i >= b; i--)
#define ll long long
using namespace std;

void print(ll a[], ll n)
{
    //int l = sizeof(a)/sizeof(a[0]);
    //cout << sizeof(a) << " " << sizeof(a[0]) << endl;
    forn(i,0,n) cout << a[i] << " ";
    cout << '\n';
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll n;
    cin >> n;
    ll a[n];
    forn(i,0,n) cin >> a[i];
    ll pre_f[n], pre_s[n];//, pre_t[n];

    memset(pre_f, 0, sizeof(pre_f));
    memset(pre_s, 0, sizeof(pre_s));
  //  memset(pre_t, 0, sizeof(pre_t));

    pre_f[0] = (ll)a[0];
    forn(i,1,n) pre_f[i] = pre_f[i-1]+a[i];
    if(pre_f[n-1]%3)
    {
        cout << 0;
        return 0;
    }

    ll pivot = pre_f[n-1]/3;

    forn(i,0,n) pre_s[i] = pre_f[i] - pivot;

    //forn(i,0,n) pre_t[i] = pre_f[i] - 2*pivot;
/*
    print(pre_f, n);
    print(pre_s, n);
    print(pre_t, n);
*/
    ll /*rec_f[n],*/ rec_s[n];//, rec_t[n];

    //memset(rec_f, 0, sizeof(rec_f));
    memset(rec_s, 0, sizeof(rec_s));
    //memset(rec_t, 0, sizeof(rec_t));

    forn(i,0,n)
    {
       // if(pre_f[i] == pivot) rec_f[i]++;
        if(pre_s[i] == pivot) rec_s[i]++;
       // if(pre_t[i] == pivot) rec_t[i]++;

        if(i)
        {
         //   rec_f[i] += rec_f[i-1];
            rec_s[i] += rec_s[i-1];
          //  rec_t[i] += rec_t[i-1];
        }
    }
    ll ans = 0;
    /*
    cout << pivot << endl;
    cout << '\n';
    print(pre_f, n);
    print(rec_s, n);
    */
    forn(i,0,n-2)
    {
        if(pre_f[i] == pivot)
        {
            ans += (rec_s[n-2]-rec_s[i]);
            //if(pre_s[i] == pivot) ans--;
            //if(pre_s[n-1] == pivot) ans--;
        }
    }
    cout << ans;
    return 0;
}
