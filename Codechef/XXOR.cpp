
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

#define M 1000000
const int mod = 1000001;

using namespace std;

int main()
{
    int n;
    cin >> n;
    int q;
    cin >> q;

    int m[n][33];
    int b[n];
    forn(i,0,n) cin >> b[i];
    forn(i,0,n)
    {
        for(int j = 32; j >= 0; j--)
        {
            m[i][j] = b[i]&1;
        }
    }
    int sum[33];
    memset(sum,0,sizeof(sum));
    forn(i,0,32)
    forn(j,0,n)
    {
        sum[i]+=m[j][i];
    }
    while(q--)
    {
        int l,r;
        cin >> l >> r;
        int ans[n];
        forn(i,0,33)
        {
            if(n-sum[i] > sum[i]) ans[i] = 1;
            else ans[i] = 0;
        }
        ll an = 1<<32-1;
        forn(i,0,n)
        {
            an&=ans[i];
        }
        cout << an;
        cout << '\n';
    }
    return 0;
}
