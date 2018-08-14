// Author : Anurag Shah
// @Copyright : 2018
// IIT Jodhpur

#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cmath>
#include<string>
#include<algorithm>

#define forn(i,a,b) for(int i = a; i < b; i++)
#define boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define eb emplace_back
#define pb push_back
#define fr first
#define sc second
#define sins insert

typedef long long ll;

using namespace std;

int main()
{
    ll n, k1, k2;
    cin >> n >> k1 >> k2;
    ll a[n], b[n];
    forn(i,0,n) cin >> a[i];
    forn(i,0,n) cin >> b[i];
    ll k = k1+k2;
    ll dif[n];
    forn(i,0,n) dif[i] = abs(a[i]-b[i]);
    int j = n-1;
    sort(dif, dif+n);
    ll cnt = 1;
    while(k)
    {
        if(dif[n-1] == 0)
            break;
        dif[n-1]--;
        sort(dif, dif+n);
        k--;
    }
    ll error = 0;
    forn(i,0,n)
    {
        error += (dif[i]*dif[i]);
    }
    if(dif[n-1] == 0)
        error += (k&1);
    cout << error;
    return 0;
}
