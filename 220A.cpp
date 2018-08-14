#include<iostream>
#include<algorithm>

#define forn(i,a,b) for(int i =a;i < b; i++)

using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n], b[n];
    forn(i,0,n) cin >> a[i], b[i]=a[i];
    sort(a, a+n);
    int diff = 0;
    forn(i,0,n)
    {
        if(a[i] != b[i]) diff++;
    }
    if(diff > 2) cout << "NO";
    else cout << "YES";
    return 0;
}
