#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstring>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <climits>

#define ll long long
#define forn(i,a,b) for(ll i = a; i < b; i++)
#define boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define fr first
#define sc second
#define MAX 1000001

int dp[1<<17];
int dis[17][17];

using namespace std;

/*
bool cmp(pair<pair<ll,ll>,ll > &p1, pair<pair<ll,ll>,ll > &p2)
{
    return p1.fr.fr < p2.fr.fr;
}
*/

int main()
{
    int t;
    //cin >> t;
    t = 1;
    while(t--)
    {
        ll n,k;
        cin >> n >> k;
        vector<pair<pair<ll,ll>,ll > > pp(n);
        forn(i,0,n) cin >> pp[i].first.first;
        forn(i,0,n) cin >> pp[i].first.second;
        forn(i,0,n) pp[i].sc = i;
        sort(pp.begin(), pp.end());
        vector<ll> cnt(n);
        cnt[0] = pp[0].fr.sc;
        /*
        forn(i,1,n)
        {
            cnt[i] = cnt[i-1] + pp[i].fr.sc;
        }
        */
        vector<pair<ll,ll > > ans(n);
        multiset<int> st;
        ll sum = 0;
        forn(i,0,n)
        {
            //cout << i << " " << sum << " " << st.size() << endl;
            ans[i].sc = sum + pp[i].fr.sc;
            if(st.size() < k)
            {
                //cout << "in here\n";
                st.insert(pp[i].fr.sc);
                sum += pp[i].fr.sc;
            }
            else if(k)
            {
                if(*st.begin() < pp[i].fr.sc)
                {
                    //cout << pp[i].fr.sc << " added and del " << *st.begin() << endl;
                    sum += pp[i].fr.sc - *st.begin();
                    st.erase(st.begin());
                    st.insert(pp[i].fr.sc);
                }
            }
            ans[i].fr = pp[i].sc;
        }
        sort(ans.begin(), ans.end());
        forn(i,0,n) cout << ans[i].sc << " ";
    }
    return 0;
}
