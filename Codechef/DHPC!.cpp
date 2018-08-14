#include<iostream>
#include<algorithm>
#include<cstring>

#define forn(i,a,b) for(int i = a; i < b; i++)
#define ll long long

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    int n;

    while(t--)
    {
        cin >> n;
        ll ans = 0;
        ans += n/2;
        ans += n/3;
        ans += n/5;
        ans -= n/6;
        ans -= n/10;
        ans -= n/15;
        ans += n/30;
        cout << ans << endl;
    }
    return 0;
}
