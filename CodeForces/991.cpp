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

set<string> st;
ll fact[20];
int c[10],c0[10];

void split(string s, int c[10])
{
    forn(i,0,10) c[i] = 0;
    forn(i,0,s.size())
    {
        c[s[i]-'0']++;
    }
    return;
}

ll getcount()
{
    ll ans = fact[accumulate(c, c+10, 0)];
    //cout << "ans = " << ans << " ";
    forn(i,0,10)
    {
        //cout << "c["<<i<<"] = " << c[i] << endl;
        ans /= fact[c[i]];
    }
    //cout << ans << endl;
    return ans;
}

ll getans(string ss)
{
    split(ss,c);
    for (int i = 0; i < 10; i++)
        if (c0[i] && !c[i])
            return 0;
    sort(ss.begin() , ss.end());
    if(st.find(ss) != st.end()) return 0;
    st.insert(ss);
    //cout << ss << endl;
    ll ans = getcount();
    if(c[0] > 0)
    {
        c[0]--;
        ans -= getcount();
    }
    return ans;
}

int main()
{
    fact[0] = 1;
    forn(i,1,20) fact[i] = fact[i-1]*i;
    string s;
    cin >> s;
    split(s,c0);
    ll ans = 0ll;
    //cout << s.length() << endl;
    int len = s.length();
    forn(i,1,(1<<len))
    {
        string c_;
        int k = 0;
        for(ll j = 1; j <= i && k < len; j <<= 1, k++)
        {
            //cout << j << " ";
            if(i & j)
              c_ += s[k];
        }
        //cout << c_ << " \n";
        ans += getans(c_);
        //cout << ans << "\n";
    }
    cout << ans;
    return 0;
}
