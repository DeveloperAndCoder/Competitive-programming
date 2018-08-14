#include<iostream>
#include<algorithm>

#define ll long long
#define forn(i,a,b) for(ll i = a; i < b; i++)
#define print(a,n) forn(i,0,n) cout << a[i] << " ";

using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n], pref[n], inc[n];
    forn(i,0,n) cin >> a[i];
    pref[0] = 1;
    int len = 1;
    forn(i,1,n)
    {
        if(a[i] <= a[i-1])
            len++;
        else len = 1;
        pref[i] = len;
    }
    //print(pref, n);
    //cout << endl;
    len = 1;
    inc[0] = len;
    forn(i,1,n)
    {
        if(a[i] >= a[i-1])
            len++;
        else len = 1;
        inc[i] = len;
    }
    //print(inc, n);
    //cout << endl;
    int inc_rev[n];
    len = 1;
    inc_rev[n-1] = 1;
    for(int i= n-2; i >= 0; i--)
    {
        if(a[i] <= a[i+1]) len++;
        else len = 1;
        inc_rev[i] = len;
    }
    int ans = pref[0];
    int cmp = 0;
    forn(i,0,n)
    {
        forn(j,i+1,n)
        {
            if(i == 0)
            {
                cmp = pref[j];
            }
            else if(a[j] >= a[i-1])
            {
                if(pref[j] >= j-i+1)
                cmp = inc[i-1]+j-i+1;
                else cmp = inc[i-1] + pref[j];
            }
            else
                cmp = max(inc[i-1],pref[j]);
            if(pref[j] >= j-i+1 && j != n-1)
                cmp += inc_rev[j+1];
            if(cmp > ans)
            {
                ans = cmp;
      //          cout << ans << " " << i << " " << j << " " << cmp;
        //        cout << endl;
            }
            //if(i == 2 && j == 6) cout << ans << endl;
        }
    }
    cout << ans;
    return 0;
}
