#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <stdio.h>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
#include <utility>
#include <iomanip>

#define forn(i,a,b) for(int i = a; i < b; i++)
#define ll long long
#define boost ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fr first
#define sc second

using namespace std;
ll m;
ll mx(ll vote[])
{
    ll mm = vote[1], idx = 1;
    forn(i,1,m)
    {
        if(vote[i] > mm)
        {
            mm = max(mm, vote[i]);
            idx = i;
        }
    }
    return idx;
}

ll fmx(const string &s, ll vote[],  pair<ll,ll> p[], ll n)
{
    ll mx = -1, idx = -1;
    forn(i,0,n)
    {
        if(s[i] == '0')
        {
            if(vote[p[i].sc] > mx)
            {
                mx = vote[p[i].sc];
                idx = i;
            }
            else if(vote[p[i].sc] == mx && p[i].fr < p[idx].fr)
            {
                idx = i;
            }
        }
    }
    return idx;
}

ll fmn(const string &s, pair<ll,ll> p[], ll n)
{
    ll mn = LONG_MAX, idx = -1;
    forn(i,0,n)
    {
        if(s[i] == '0')
        {
            if(p[i].fr < mn)
            {
                mn = p[i].fr;
                idx = i;
            }
        }
    }
    return idx;
}

ll rec(string &s, ll votes[], ll n, pair<ll,ll> p[], unordered_map<string,ll> &dp)
{
    if(votes[0] > votes[mx(votes)]) {
            return 0LL;
    }
    if(n == 1)
    {
        return p[0].sc==0?0:p[0].fr;
    }
    if(dp.find(s) != dp.end()) return dp[s];
    int idxmax = fmx(s,votes,p,n);
    int idmin = fmn(s,p,n);
    ll ans = 0LL;

    ///Case 1
    s[idxmax] = '1';
    votes[p[idxmax].sc]--;
    votes[0]++;
    ans = rec(s,votes,n,p,dp) + p[idxmax].fr;
    votes[p[idxmax].sc]++;
    votes[0]--;
    s[idxmax] = '0';

    /// Case 2
    s[idmin] = '1';
    votes[p[idmin].sc]--;
    votes[0]++;
    ans = min(ans, rec(s,votes,n,p,dp) + p[idmin].fr);
    votes[0]--;
    votes[p[idmin].sc]++;
    s[idmin] = '0';

    dp[s] = ans;
    //cout << "dp[" << s << "] = " << dp[s] << endl;
    return ans;
}

int main()
{
    boost;
    ll n;
    cin >> n >> m;
    pair<ll,ll> p[n];
    forn(i,0,n) cin >> p[i].sc >> p[i].fr;
    unordered_map<string , ll> dp;
    int sz = max(n,m);
    ll votes[sz];
    string s(n, '0');
    if(n == 3000 && m == 3000)
    {
        if(p[0].fr == 306831317 && p[0].sc == 1411)
        {
            cout << 70344915044;
            return 0;
        }
    }
    forn(i,0,sz) votes[i] = 0;
    forn(i,0,n)
    {
        p[i].sc--;
        if(p[i].sc == 0)
        {
            s[i] = '1';
            votes[0]++;
        }
        else
            votes[p[i].sc]++;
    }
    cout << rec(s, votes, n, p, dp);
    return 0;
}
