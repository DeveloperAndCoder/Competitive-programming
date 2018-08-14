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

int main()
{
    boost;
    int t;
    cin >> t;
    while(t--)
    {
        int n, u;
        cin >> n>> u;
        ll arr[n] = {0LL};
        while(u--)
        {
            int l,r,val;
            cin >> l >> r >> val;
            arr[l]+=val;
            if(r<n-1) arr[r+1]-=val;
        }
        forn(i,1,n) arr[i] += arr[i-1];
        int q;
        cin >> q;
        while(q--)
        {
            int idx;
            cin >> idx;
            cout << arr[idx]<<endl;
        }
    }
    return 0;
}
