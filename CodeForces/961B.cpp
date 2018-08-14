// Author : Anurag Shah
// @Copyright : 2018
// IIT Jodhpur

#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cmath>
#include<set>
#include<iomanip>

#define forn(i,a,b) for(int i = a; i < b; i++)
#define boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define eb emplace_back
#define pb push_back
#define fr first
#define sc second
#define sins insert

typedef long long ll;

#define M 1000000000
const int mod = 1000000007;

using namespace std;

void print(int a[], int n)
{
    forn(i,0,n) cout << a[i] << " ";
    cout << endl;
    return;
}
int main()
{
    int n, k;
    cin >> n >> k;
    int a[n], t[n];
    forn(i,0,n) cin >> a[i];
    forn(i,0,n) cin >> t[i];
    int cnt[n];
    forn(i,0,n) cnt[i]=0;
    cnt[0] = a[0]*t[0];
    forn(i,1,n)
    {
        cnt[i] = cnt[i-1]+a[i]*t[i];
    }
    ll sum = 0, ans = 0;
    forn(i,0,k)
    {
        sum += a[i];
    }
    //print(cnt, n);
    ans= sum+cnt[n-1]-cnt[k-1];
    forn(i,k,n)
    {
        sum -= a[i-k];
        sum += a[i];
        ans = max(ans, sum+cnt[n-1]-cnt[i]+cnt[i-k]);
        //cout << i << " " << sum << " " << cnt[n-1]-cnt[i]+cnt[i-k] << " " << ans << endl;
    }
    cout << ans;
    return 0;
}
