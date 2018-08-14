#include<iostream>
#include<algorithm>
#include<vector>

#define forn(i,a,b) for(int i = a; i < b; i++)
#define ll long long

using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    forn(i,0,n) cin >> a[i];
    sort(a, a+n);
    int piles = 0;
    forn(i,0,n)
    {
        if(piles*(a[i]+1) <= i)
            piles++;
    }
    cout << piles;
    return 0;
}
