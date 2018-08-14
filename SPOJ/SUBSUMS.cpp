#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstring>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <climits>

#define ll long long
#define forn(i,a,b) for(ll i = a; i < b; i++)
#define boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define MAX 1000001

using namespace std;

void generate_subset(ll x[], ll p, ll r, vector<ll> &v)
{
    ll sum = 0;
    ll n = r-p+1;
    forn(mask,1,(1<<n))
    {
        sum = 0;
        for(ll item=0;item<n;item++)
            if(mask & (1<<item))
                sum+=x[item+p];
        v.push_back(sum);
    }
    return;
}

void print(const vector<ll> &v)
{
    cout << "---------------------\n";
    forn(i,0,v.size())
    cout << v[i] << " ";
    cout << "\n-------------------\n";
}

ll solve(ll x[], ll n, ll a, ll b, ll p, ll r)
{
    vector<ll> left, right;
    ll mid = n/2;
    generate_subset(x,0,mid,left);
    generate_subset(x,mid+1,n-1,right);
    sort(right.begin(), right.end());
    //print(left);
    //print(right);
    ll ans = 0LL;
    forn(i,0,left.size())
    {
        int pos1 = lower_bound(right.begin(), right.end(), a-left[i]) - right.begin();
        int pos2 = upper_bound(right.begin(), right.end(), b-left[i]) - right.begin();
        //if(left[i] == -1) cout << pos1 << " " << pos2 << " " << left[i] << " " << a-x[i] << " " << b-x[i] << endl;
        ans += abs(pos2-pos1);
        if(a <= left[i] && left[i] <= b) ans++;
    }
    forn(i,0,right.size())
    {
        if(a <= right[i] && right[i] <= b) ans++;
    }
    if(a <= 0 && b >= 0) ans++;
    return ans;
}

int main()
{
    ll n,a,b;
    cin >> n >> a >> b;
    ll x[n];
    forn(i,0,n) cin >> x[i];
    //forn(i,0,n) cout << x[i] << " ";
    //cout << endl;
    cout << solve(x,n,a,b,0,n-1) << endl;
}
