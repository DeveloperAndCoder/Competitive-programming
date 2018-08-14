#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstring>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <climits>
#include <tuple>

#define ll long long
#define forn(i,a,b) for(ll i = a; i < b; i++)
#define boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define MAX 1000001

using namespace std;

void pr(vector<int> &a,ll n)
{
    forn(i,0,n) cout << a[i] << " ";
    cout << endl;
}

int binary_search(vector<int> &A, int B, int p, int r)
{
    int low = p, high = r;
    while(low <= high)
    {
        int mid = (low+high)/2;
        if(A[mid] == B) return mid;
        if(A[mid] > B) high = mid-1;
        else if(A[mid] < B) low = mid+1;
    }
    return -1;
}

bool cmp(const tuple<ll,ll,ll> &t1, const tuple<ll,ll,ll> &t2)
{
    if(get<0>(t1) < get<0>(t2)) return true;
    if(get<0>(t1) > get<0>(t2)) return false;
    if(get<1>(t1) < get<1>(t2)) return true;
    if(get<1>(t1) > get<1>(t2)) return false;
    if(get<2>(t1) < get<2>(t2)) return true;
    if(get<2>(t1) > get<2>(t2)) return false;
    return false;
}

int main()
{
    boost;
    ll t;
    cin >> t;
    while(t--)
    {
        ll n;
        cin >> n;
        vector<ll> arr(n);
        forn(i,0,n) cin>>arr[i];
        sort(arr.begin(),arr.end());
        set< tuple<ll,ll,ll> > ans;
        forn(i,0,n)
        {
            if(i && arr[i-1] == arr[i]) continue;
            ll l = i+1;
            ll r = n-1;
            while(l < r)
            {
                ll sum = arr[i]+arr[l]+arr[r];
                if(sum == 0LL)
                {
                    tuple<ll,ll,ll> tp(arr[i], arr[l], arr[r]);
                    ans.insert(tp);
                    l++;
                    r--;
                }
                else if(sum > 0LL) r--;
                else l++;
            }
        }
        cout << ans.size() << endl;
        vector <tuple<int,int,int> > aa(ans.size());
        int j = 0;
        for(const auto &i : ans) aa[j++] = i;
        sort(aa.begin(), aa.end());
        for(const auto &i : aa) cout << get<0>(i) << " " << get<1>(i) << " " << get<2>(i) << endl;
    }
    return 0;
}
