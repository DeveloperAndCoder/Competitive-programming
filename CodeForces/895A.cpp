#include<iostream>
#include<cmath>
#include<algorithm>

#define forn(i,a,b) for(int i = a; i < b; i++)

using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    forn(i,0,n) cin >> a[i];
    int m = 360;
    int sum = 0;
    forn(i,0,n)
    {
        forn(j,i,n)
        {
            sum += a[j];

            m = min(abs(180-sum),m);
        }
        sum = 0;
    }
    cout << 2*m;
    return 0;
}
