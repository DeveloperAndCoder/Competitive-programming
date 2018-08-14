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

ll f[300001], h[300001];
ll sum0f[300001], sum0b[300001];
ll sum1f[300001], sum1b[300001];

ll F(j, int a[], int b[], int n, int t)
{
    int row = 0;
    ll ans = 0, sap = 0;
    forn(i,j,n)
    {
        if(row == 0)
        {
            ans = max(g(i+1,t+1,row), sap+b[i]*(t+1));
            row=1;
        }
        else
        {
            ans = max(g(i+1,t+1,row), sap+b[i+1]*(t+1));
            row=0;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    int a[n], b[n];
    forn(i,0,n) cin >> a[i];
    forn(i,0,n) cin >> b[i];
    cout << F(0,a,b,n,0);
    return 0;
}
