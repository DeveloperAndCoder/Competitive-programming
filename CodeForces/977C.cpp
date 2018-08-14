#include<iostream>
#include<algorithm>

#define forn(i,a,b) for(int i = a; i < b; i++)
#define ll long long
#define mod 1000000007

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int a[n];
    forn(i,0,n) cin >> a[i];
    sort(a,a+n);
    if(k == 0)
        {
            if(a[0] == 1)
                cout << -1;
            else
                cout << a[0]-1;
        }
    else if(k > n)
        cout << -1;
    else if(k == n)
        {
            cout << a[n-1];
        }
    else if(a[k] == a[k-1])
        cout << -1;
    else
        {
            cout << a[k-1];
        }
    return 0;
}
