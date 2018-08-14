#include<iostream>
#define ll long long
#define forn(i,a,b) for(int i = a; i < b; i++)
using namespace std;

int main()
{
    int n;
    ll k;
    cin >> n >> k;
    int a[n];
    forn(i,0,n) cin >> a[i];
    if(k >= n)
        k = n-1;
    int cur = 0;
    forn(j,0,n)
    {
     //   cout << "j = " << j << endl;
         forn(i,j+1,k+j+1)
        {
            if(cur == k)
            {
                cout << a[j];
                return 0;
            }
            if(a[i%n] < a[j])
                cur++;
            else
            {
                j = i%n-1;
                cur = 1;
                break;
            }
            if(cur == k)
            {
                cout << a[j];
                return 0;
            }
        }
    }
    return 0;
}
