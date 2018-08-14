#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<algorithm>
#include<utility>

#define forn(i,a,b) for(int i = a; i < b; i++)
#define ll long long
#define fr first
#define sc second
#define MOD 1000000007

using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[2*n];
    forn(i,0,2*n) cin >> a[i];
    sort(a, a+2*n);
    ll ans = 1e18;
    for(int i = 0; i <= n; i++)
    {
        int h_m = i==0?a[n]:a[0];
        int h_ = i==n?a[n-1]:a[2*n-1];
        //cout << a[i] << " " << a[i+n-1] << " " << h_m << " " << h_ << endl;
        ll temp = (a[i+n-1]-a[i])*1LL*(h_-h_m);
        ans = min(ans, temp);
    }
    cout << ans;
    return 0;
}
