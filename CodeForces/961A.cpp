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

bool check(int a[], int n)
{
    forn(i,0,n)
        if(a[i]==0)
            return 0;
    forn(i,0,n)
    a[i]--;
    return 1;
}

int main()
{
    int n, m;
    cin >> n >> m;
    int c[m];
    forn(i,0,m) cin >> c[i];
    int cnt[n];
    int point=0;
    forn(i,0,n)
    cnt[i] = 0;
    forn(i,0,m)
    {
        cnt[c[i]-1]++;
        if(check(cnt, n))
            point++;
    }
    cout << point;
    return 0;
}
