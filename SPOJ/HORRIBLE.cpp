#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstring>
#include <sstream>
#include <vector>

#define ll long long
#define forn(i,a,b) for(ll i = a; i < b; i++)
#define boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define MAX 1000001

using namespace std;

///SEGMENT TREES WOTH LAZY PROPAGATION. REFERENCE GEEKSFORGEEKS

ll t[MAX] = {0};
ll lazy[MAX] = {0};

ll getMid(ll s, ll e) {  return s + (e -s)/2;  }

void constructSTUtil(ll arr[], ll ss, ll se, ll si)
{
    if(ss > se)
        return;
    // If there is one element in array, store it in current node of
    // segment tree and return
    if (ss == se)
    {
        t[si] = arr[ss];
        return;
    }

    // If there are more than one elements, then recur for left and
    // right subtrees and store the sum of values in this node
    ll mid = getMid(ss, se);
    constructSTUtil(arr, ss, mid, si*2+1);
    constructSTUtil(arr, mid+1, se, si*2+2);
    t[si] = t[2*si+1]+t[2*si+2];
    return;
}

ll* constructST(ll arr[],ll n)
{
    memset(t,0,sizeof(t));
    memset(lazy,0,sizeof(lazy));
    constructSTUtil(arr, 0, n-1, 0);
}

ll getSumUtil(ll ss, ll se, ll qs, ll qe, ll si, ll n)    // range [l,r)
{
    if(lazy[si] != 0)
    {
        t[si] += (se-ss+1)*lazy[si];
        if(ss != se)
        {
            lazy[2*si+1] += lazy[si];
            lazy[2*si+2] += lazy[si];
        }
        lazy[si] = 0;
    }
    ///Out of range
    if(ss > se || ss > qe || se < qs)
        return 0;

    ///Fully in range
    if(qs <= ss && qe >= se)
    {
        return t[si];
    }
    ///Partially in range
    int mid = (ss + se) / 2;
    return  getSumUtil(ss, mid, qs, qe, 2*si+1, n) +
            getSumUtil(mid+1, se, qs, qe, 2*si+2, n);

}
void UpdateRangeUtil(ll si, ll ss, ll se, ll l, ll r,ll val, ll n)
{
    if(lazy[si] != 0)
    {
        t[si] += (se-ss+1)*lazy[si];
        if(ss != se)
        {
            lazy[si*2+1] += lazy[si];
            lazy[si*2+2] += lazy[si];
        }
        lazy[si] = 0;
    }

    /// Out of range
    if(ss > se || ss > r || se < l)
        return;
    ///Fully in range
    if(ss >= l && se <= r)
    {
        t[si] += (se-ss+1)*val;
        //cout << "Updated si = " << si << " to value = " << t[si] << endl;
        ///If not a leaf node
        if(ss != se)
        {
            lazy[2*si + 1] += val;
            lazy[2*si + 2] += val;
        }
        return;
    }
    ///If partially in range
    ll mid = (ss+se)/2;
    UpdateRangeUtil(2*si+1, ss, mid, l, r, val, n);
    UpdateRangeUtil(2*si+2, mid+1, se, l, r, val, n);

    t[si] = t[2*si+1] + t[2*si+2];
    //cout << "Updated si = " << si << " to value = " << t[si] << endl;
}

ll getSum(ll n, ll qs, ll qe)
{
    if(qs < 0 || qe > n-1 || qs > qe)
    {
        cout << "Invalid Input\n";
        return -1;
    }
    return getSumUtil(0,n-1,qs,qe,0,n);
}

ll UpdateRange(ll n, ll us, ll ue, ll diff)
{
    UpdateRangeUtil(0,0,n-1,us,ue,diff,n);
}

int main()
{
    boost;
    int T;
    cin >> T;
    while(T--){
        ll n;      // Number of nodes
        cin >> n;
        ll arr[n];
        memset(arr, 0, sizeof(arr));
        constructST(arr,n);
        ll c;
        cin >> c;
        while(c--)
        {
            ll instr,us,ue,val;
            cin >> instr;
            if(instr == 0)
            {
                cin >> us >> ue >> val;
                us--,ue--;
                UpdateRange(n, us, ue, val);
            }
            else
            {
                cin >> us >> ue;
                us--,ue--;
                cout << getSum(n, us, ue) << endl;
            }
        }
    }
}
