#include<iostream>
#include<cstring>

#define forn(i,a,b) for(int i = a; i < b; i++)
#define ll long long

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    int x;
    cin >> n >> x;
    int a[n];
    forn(i,0,n) cin >> a[i];
    int ans = 0;
    forn(i,0,n)
    {
        if(a[i] >= x)
            ans++;
    }
    cout << ans;
    return 0;
}
