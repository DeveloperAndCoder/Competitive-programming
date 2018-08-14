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
#define MAXN 100010

typedef long long ll;

#define M 1000000000
const int mod = 1000000007;
ll n,x[MAXN],y[MAXN];

using namespace std;

bool slopecmp(int a, int b, int c)
{
    return (((y[b]-y[a])*(x[c]-x[b]))-((y[c]-y[b])*(x[b]-x[a])))==0;
}

bool judge(int a, int b)
{
    bool init[n];
    forn(i,0,n)
    {
        init[i] = slopecmp(a,b,i);
    }
    int t1,t2;
    t1=-1;t2=-1;
    forn(i,0,n)
    {
        if(!init[i])
        {
            if(t1==-1)t1=i;
            else if(t2==-1)t2=i;
            else if(!slopecmp(t1,t2,i)) return 0;
        }
    }
    return 1;
}

int main()
{
    cin >> n;
    forn(i,0,n) cin >> x[i] >> y[i];
    if(n <= 4) cout << "YES";
    else if(judge(0,1)||judge(1,2)||judge(0,2))
        cout<<"YES";
    else
        cout<<"NO";
    //cout << judge(0,1) << judge(1,2) << judge(0,2) << endl;
    return 0;
}
