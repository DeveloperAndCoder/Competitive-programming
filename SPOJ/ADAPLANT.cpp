#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstring>
#include <sstream>
#include <vector>
#include <map>
#include <climits>

#define ll long long
#define forn(i,a,b) for(ll i = a; i < b; i++)
#define boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define MAX 1000001

using namespace std;

ll bl_num(ll n, ll p)
{
    return p/(ll)sqrt(n);
}

ll query_max(ll arr[], ll block[], ll p, ll r, ll n, ll M)
{
    ll bs = bl_num(n,p), be = bl_num(n,r);
    //cout << "p = "<< p << " bs = " << bs << " r = " << r <<  " be = " << be << endl;
    ll ans = 0, max_e = LLONG_MIN;
    if(be == bs)
    {
        for(ll i = p; i <= r; i++)
        {
            //min_e = min(arr[i],min_e);
            max_e = max(arr[i], max_e);
        }
        ans = max_e;
        //cout << "be == bs\t" << ans << endl;
        return ans;
    }
    for(ll i = p; i < bs*M+M; i++)
    {
        //min_e = min(arr[i],min_e);
        max_e = max(arr[i], max_e);
    }
    ans = max_e;
    //cout << "p = " << p << "\tbs*M+M = " << bs*M+M << "\tans = " << ans << endl;
    max_e = LLONG_MIN;
    for(ll j = be*M; j <= r; j++)
    {
        //min_e = min(arr[j], min_e);
        max_e = max(arr[j], max_e);
    }
    ans = max(ans, max_e);
    //cout << "be*M = " << be*M << "\tr = " << r << "\tans = " << ans << endl;
    for(ll i = bs+1; i < be; i++)
        ans = max(ans, block[i]);
    //cout << "bs+1 = " << bs+1 << "\tbe = " << be << "\tans = " << ans << endl;
    return ans;
}

ll query_min(ll arr[], ll block[], ll p, ll r, ll n, ll M)
{
    ll bs = bl_num(n,p), be = bl_num(n,r);
    //cout << "p = "<< p << " bs = " << bs << " r = " << r <<  " be = " << be << endl;
    ll ans = 0, min_e = LLONG_MAX;
    if(be == bs)
    {
        for(ll i = p; i <= r; i++)
        {
            min_e = min(arr[i],min_e);
            //max_e = max(arr[i], max_e);
        }
        ans = min_e;
        //cout << "be == bs\t" << ans << endl;
        return ans;
    }
    for(ll i = p; i < bs*M+M; i++)
    {
        min_e = min(arr[i],min_e);
        //max_e = max(arr[i], max_e);
    }
    ans = min_e;
    //cout << "p = " << p << "\tbs*M+M = " << bs*M+M << "\tans = " << ans << endl;
    min_e = LLONG_MAX;//,max_e = LLONG_MIN;
    for(ll j = be*M; j <= r; j++)
    {
        min_e = min(arr[j], min_e);
        //max_e = max(arr[j], max_e);
    }
    ans = min(ans, min_e);
    //cout << "be*M = " << be*M << "\tr = " << r << "\tans = " << ans << endl;
    for(ll i = bs+1; i < be; i++)
        ans = min(ans, block[i]);
    //cout << "bs+1 = " << bs+1 << "\tbe = " << be << "\tans = " << ans << endl;
    return ans;
}

void pr(ll a[],ll n)
{
    forn(i,0,n) cout << a[i] << " ";
    cout << endl;
}

int main()
{
    boost;
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,k;
        cin >> n >> k;
        ll arr[n];
        forn(i,0,n) cin >> arr[i];
        ll M = sqrt(n);
        ll nblock = n/M;
        if(nblock*nblock != n) nblock++;
        ll min_block[nblock];
        ll max_block[nblock];
        min_block[0] = arr[0];
        max_block[0] = arr[0];
        ll j = 0, min_ele = LLONG_MAX, max_ele = LLONG_MIN;
        forn(i,0,n)
        {
            if(i-j*M < M)
            {
                min_ele = min(min_ele,arr[i]);
                max_ele = max(max_ele, arr[i]);
            }
            else
            {
                min_block[j] = min_ele;
                max_block[j] = max_ele;
                j++;
                if(i < n)
                {
                    min_ele = arr[i];
                    max_ele = arr[i];
                }
            }
        }
        if(j < nblock)
        {
            min_block[j] = min_ele;
            max_block[j] = max_ele;
        }
        //pr(min_block, nblock);
        ll ans = 0;
        //cout << "M = "<<M << endl;
        for(ll i = 0; i < n; i++)
        {
            //cout << i << " " << min(i+k+1,n-1) << " "; //<< query(arr,min_block,i,min(i+k+1,n-1),n,M)<<endl;
            ans = max(ans, query_max(arr,max_block,i,min(i+k+1,n-1),n,M)-query_min(arr,min_block,i,min(i+k+1,n-1),n,M));
        }
        cout << ans << endl;
    }
    return 0;
}


/*
1
10 2
2 5 9 6 2 1 0 0 0 2
*/
