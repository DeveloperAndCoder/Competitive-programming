#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>

#define forn(i,a,b) for(int i = a; i < b; i++)
typedef long long ll;

using namespace std;

int main()
{
    int n, d;
    cin >> n >> d;
    int a[n];
    forn(i,0,n) cin >> a[i];
    int m=0;
    int c=0;
    sort(a,a+n);
    forn(i,0,n)
    {
        c=0;
        forn(j,i,n)
        {
            if(abs(a[i]-a[j]) <= d) c++;
        }
       // cout << i << " " << c << endl;
        m = max(m,c);
    }
    cout << n-m;
    return 0;
}
