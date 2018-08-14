#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstring>
#include <sstream>
#include <vector>
#include <queue>
#include <stack>
#include <climits>

#define ll long long
#define ul unsigned long long
#define forn(i,a,b) for(ul i = a; i < b; i++)
#define boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define MAX 1000001
#define N 1000001

using namespace std;

void print(vector<int> &a)
{
    forn(i,0,a.size())
    cout << a[i] << " ";
    cout << endl;
    return;
}

int main()
{
    boost;
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    forn(i,0,n) cin >> a[i];
    sort(a.begin(), a.end());
    //print(a);
    bool vis[n];
    memset(vis, true, sizeof(vis));
    forn(i,0,a.size()-1)
    {
        //auto p1 = upper_bound(a.begin()+i+1, a.end(), a[i]);
        auto p2 = lower_bound(a.begin()+i+1, a.end(), a[i]+k);
        if(p2 == a.end()) {
                p2--;
                if((*p2) <= a[i]+k && (*p2) > a[i]) vis[i] = false;
                else
                vis[i] = true;
        }
        else
        {
            if(*p2 != a[i]+k) p2--;
            if(*p2 == a[i]);
            else if(*p2 <= a[i]+k) vis[i] = false;
        }
        //a.erase(p1, p2);
        //cout << a[i] << " "  << *p2 << " " << vis[i] << "\n";
        //print(a);
    }
    int ans = 0;
    forn(i,0,n)
    if(vis[i]) ans++;
    cout << ans;
    return 0;
}
