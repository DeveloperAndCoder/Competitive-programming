#include<iostream>
#include<algorithm>

#define forn(i,a,b) for(int i = a; i < b; i++)
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    int a[n];
    forn(i,0,n) cin >> a[i];
    sort(a,a+n);
    int m = a[0];
    for(int i = n-1; i>=0; i--)
    {
        if(k%a[i] == 0)
        {
            m = a[i];
            break;
        }
    }
    cout << k/m;
    return 0;
}
