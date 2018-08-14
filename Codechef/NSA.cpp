#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
#include <utility>
#include <iomanip>

#define ll long long
#define forn(i,a,b) for(ll i = a; i < b; i++)
#define boost ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'

using namespace std;

ll query(ll BIT[27], ll x)
{
    ll sum = 0;
    for(x; x>0; x-=x&-x)
    {
        sum += BIT[x];
    }
    return sum;
}

void update(ll BIT[26], ll x)
{
    for(x; x<=26; x+=x&-x)
    {
        BIT[x]++;
    }
    return;
}

ll inverse_count(string &s)
{
    ll BIT[27];
    forn(i,0,27) BIT[i] = 0;
    ll n = s.size();
    ll ans = 0;
    forn(i,0,n)
    {
        ans += query(BIT, s[i]-'a');
        update(BIT, s[i]-'a'+1);
    }
    return ans;
}

ll test2(string &s)
{
    ll ans = inverse_count(s);
    ll n = s.size();
    forn(i,0,n)
    {
        ll mx = 100000;
        char ori = s[i];
        forn(ch,0,26)
        {
            s[i] = ch+'a';
            ans = min(ans, inverse_count(s)+abs(ori-ch-'a'));
        }
        s[i] = ori;
    }
    cout << ans << " ";
    return ans;
}

ll test1(string &s)                     ///CHANGE RETURN TYPE
{
    ll n = s.size();
    vector<vector<ll> > pre(n, vector<ll>(26, 0)), suf(n, vector<ll>(26, 0));
    forn(i,0,n)
    {
        if(i)
        {
            forn(j,0,26)
            pre[i][j] = pre[i-1][j];
        }
        pre[i][s[i]-'a']++;
    }
    for(ll i = n-1; i >= 0; i--)
    {
        if(i != n-1)
        {
            forn(j,0,26)
            suf[i][j] = suf[i+1][j];
        }
        suf[i][s[i]-'a']++;
    }
    ll ans = inverse_count(s);
    ll ORIG = ans;
    forn(i,0,n)
    {
        forn(j,1,26)
        {
            pre[i][j] += pre[i][j-1];
            suf[i][j] += suf[i][j-1];
        }
    }
    /*
    forn(i,0,n)
    {
        forn(j,0,3)
        {
            cout << pre[i][j] << " ";
        }
        cout << endl;
    }
    cout << "-------------------\n";
    forn(i,0,n)
    {
        forn(j,0,3)
        {
            cout << suf[i][j] << " ";
        }
        cout << endl;
    }
    cout << "-------------------\n";
    */
    forn(i,0,n)
    {
        for(ll present = 'a'; present <= 'z'; present++)
        {
            if(present == s[i]) continue;
            ll min_ = 0;
            if(present > s[i])
            {
                min_ += pre[i][present-'a'-1];
                //cout << min_ << endl;
                if(s[i] != 'a')
                min_ -= pre[i][s[i]-'a'-1];
                //cout << min_ << endl;
                ll i1 = 0LL;
                //if(present != 'z')
                i1 = suf[i]['z'-'a'] - suf[i][present-'a'];
                ll i2 = suf[i]['z'-'a'] - suf[i][s[i]-'a'];
                min_ += i1-i2;
                //cout << i1 << " " << i2 << endl;
                min_--;
                //cout << min_ << endl;
            }
            else if(present < s[i])
            {
                if(present != 'a')
                min_ += pre[i][present-'a'-1];
                min_ -= pre[i][s[i]-'a'-1];
                //cout << min_ << endl;
                ll i1 = 0LL, i2 = 0LL;
                i1 = suf[i]['z'-'a'] - suf[i][present-'a'];
                //if(s[i] != 'z')
                i2 = suf[i]['z'-'a'] - suf[i][s[i]-'a'];
                min_ += i1-i2;
                //cout << i1 << " " << i2 << " " << min_ << endl;
                min_--;
                //cout << min_ << endl;
            }
            ans = min(ans, ORIG + min_ + abs(present-s[i]));
            //cout << "Changed " << s[i] << " to " << (char)present << " " << min_ << " " << ans << endl;
        }
    }
    return ans;
}


void verify()
{
    bool match = 1;
    while(match)
    {
        int N = 100;
        srand(rand());
        int n = rand()%N+1;
        string s(n, 'a');
        forn(i,0,n)
        {
            s[i] = rand()%26 + 'a';
        }
        cout << s << endl;
        match = (test2(s)==test1(s));
    }
}

string input()
{
    int N = 1e5;
    srand(rand());
    int n = N;
    string s(n, 'a');
    forn(i,0,n)
    {
        s[i] = rand()%26 + 'a';
    }
    return s;
}


int main()
{
    boost;
    //verify();
    //return 0;
    int t;
    cin >> t;
    string s;
    while(t--)
    {
        //cin >> s;
        s = input();
        cout << s;
        cout << test1(s) << endl;
    }

    return 0;
}
