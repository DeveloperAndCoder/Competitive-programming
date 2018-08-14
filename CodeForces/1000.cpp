#include <iostream>
#include <string>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <unordered_set>

#define forn(i,a,b) for(int i = a; i < b; i++)
#define ll long long
#define boost ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

bool cmp(const pair<ll, char> &p1, const pair<ll, char> &p2)
{
    if(p1.first != p2.first) return p1.first<p2.first;
    return p1.second == 'l' && p2.second == 'r';
}

int main()
{
    boost;
    try
    {
        vector<pair<ll, char> > event;
        int n;
        cin >> n;
        vector<ll> ans(n+1, 0ll);
        forn(i,0,n)
        {
            ll l,r;
            cin >> l >> r;
            event.push_back({l, 'l'});
            event.push_back({r+1, 'r'});
        }
        sort(event.begin(), event.end(), cmp);
        ll cnt = 0ll;
        ll status = -1;
        forn(i,0,event.size())
        {
            if(event[i].second == 'l')
            {
                if(cnt == 0)
                {
                    status = (event[i].first);
                    cnt++;
                    continue;
                }
                ll prev = status;
                if(cnt > n || cnt < 0)
                {
                    cout << "HEHE " << cnt;
                    return 0;
                }
                ans[cnt] += (event[i].first - prev);
                cnt++;
                status = (event[i].first);
            }
            else
            {
                ll prev = status;
                if(cnt > n || cnt < 0)
                {
                    cout << "HOHO " << cnt;
                    return 0;
                }
                ans[cnt] += (event[i].first-prev);
                cnt--;
                status = (event[i].first);
            }
            //cout << event[i].first << " " << event[i].second << " " << ans[2] << endl;
        }
        forn(i,1,n+1) cout << ans[i] << " ";
    }
    catch(...)
    {
        cout << "WHERE";
    }
    return 0;
}
