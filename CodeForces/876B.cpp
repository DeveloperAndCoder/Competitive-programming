#include<iostream>
#include<algorithm>
#define forn(i,a,b) for(int i = a; i < b; i++)
using namespace std;

int main()
{
    int n, k, m;
    cin >> n >> k >> m;
    int a[n];
    forn(i,0,n) cin >> a[i];
    int mod[n];
    forn(i,0,n)
    {
        mod[i] = a[i]%m;
    }
    sort(mod,mod+n);
    int c = 1;
    int l = -1;
    forn(i,1,n)
    {
        if(c >= k)
        {
            l = mod[i];
            break;
        }
        if(mod[i] == mod[i-1])
            c++;
        else
            c = 1;
        if(c >= k)
        {
            l = mod[i];
            break;
        }

    }
    if(l == -1)
    {
        cout << "No";
        return 0;
    }
    else
    {
        cout << "Yes\n";
        c = 0;
        forn(i,0,n)
        {
            if(c == k) break;
            if(a[i]%m == l)
                cout << a[i] << " ", c++;
        }
    }
    return 0;
}
