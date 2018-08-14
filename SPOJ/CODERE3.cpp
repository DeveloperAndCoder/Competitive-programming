#include <iostream>
#include <algorithm>
#include <cmath>

#define forn(i,a,b) for(int i = a; i < b; i++)
#define ll long long

using namespace std;

void LIS(int lis[], int a[], int n)
{
    forn(i,1,n)
    {
        forn(j,0,i)
        {
            if(a[j] < a[i]) lis[i] = max(lis[j]+1, lis[i]);
        }
    }
    return;
}
void DIS(int dis[], int a[], int n)
{
    for(int i = n-2; i >= 0; i--)
    {
        forn(j,i+1,n)
        {
            if(a[j] < a[i])
                dis[i] = max(dis[j]+1, dis[i]);
        }
    }
    return;
}

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int n;
        cin >> n;
        int a[n];
        forn(i,0,n) cin >> a[i];
        int lis[n], dis[n];
        forn(i,0,n) lis[i] = dis[i] = 1;
        LIS(lis, a, n);
        DIS(dis, a, n);
        int ans = 1;
        forn(i,0,n)
        {
            ans = max(ans, lis[i]+dis[i]-1);
        }
        cout << ans << endl;
    }
    return 0;
}
