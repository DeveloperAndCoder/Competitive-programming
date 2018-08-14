#include <bits/stdc++.h>

using namespace std;

#define forn(i,a,b) for(int i = a; i < b; i++)
#define ll long long
#define N (int)2e5+1

int main()
{
    int n;
    cin >> n;
    int a;
    forn(i,0,n)
    {
        cin >> a;
        if(a&1) cout << a << " ";
        else cout << a-1 << " "[i == n-1];
    }
}
