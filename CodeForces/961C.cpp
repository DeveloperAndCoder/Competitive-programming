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

int main()
{
    int n;
    cin >> n;
    char ch;
    int a[4], b[4];
    forn(i,0,4)
    {
        a[i]=0;
        b[i]=0;
    }
    forn(i,0,4)
    {
        forn(j,0,n)
        {
            forn(k,0,n)
            {
                cin >> ch;
                if((k+j)%2==0 && ch=='1') a[i]++;
                if((k+j)%2==1 && ch=='0') a[i]++;
                if((k+j)%2==0 && ch=='0') b[i]++;
                if((k+j)%2==1 && ch=='1') b[i]++;
            }
        }
    }
    int ans = INT_MAX;
    forn(i,0,4)
    {
        forn(j,0,4)
        {
            if(j==i) continue;
            int sum = a[i]+a[j];
            bool bb[4];
            forn(i,0,4) bb[i]=0;
            bb[i]=1;bb[j]=1;
            forn(m,0,4)
            if(!bb[m]) sum+=b[m];
            ans = min(ans, sum);
        }
    }
    cout << ans;
    return 0;
}
