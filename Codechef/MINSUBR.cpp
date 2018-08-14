#include<iostream>
#include<map>

#define ll long long
#define forn(i,a,b) for(int i = a; i < b; i++)

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, d;
        cin >> n >> d;
        int a[n];
        map<int, int> mp;
        forn(i,0,n) cin >> a[i];
        forn(i,1,n) a[i] += a[i-1];
        forn(i,0,n)
        {
            mp[a[i]] = i;
        }
    }
}




