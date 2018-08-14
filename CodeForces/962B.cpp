// Author : Anurag Shah
// @Copyright : 2018
// IIT Jodhpur

#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cmath>
#include<set>
#include<iomanip>

#define forn(i,a,b) for(int i = a; i < b; i++)
#define boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define eb emplace_back
#define pb push_back
#define fr first
#define sc second
#define sins insert

typedef long long ll;

#define M 1000000000
const int mod = 1000000007;

using namespace std;

int main()
{
    ll n, a, b;
    cin >> n >> a >> b;
    string s;
    cin >> s;
    ll ans = 0;
    forn(i,0,s.length())
    {
        if(a > b)
        {
            bool x = 1;
            while(i < s.length() && s[i] != '*')
            {
                if(a == 0 && b == 0)
                    goto hell;
                if(x && a > 0)
                {
                    ans++;
                    a--;
                }
                else if(b > 0)
                {
                    ans++;
                    b--;
                }
                x = !x;
                i++;
            }
        }
        else
        {
            bool x = 1;
            while(i < s.length() && s[i] != '*')
            {
                if(a == 0 && b == 0)
                    goto hell;
                if(x && b > 0)
                {
                    ans++;
                    b--;
                }
                else if(a > 0)
                {
                    ans++;
                    a--;
                }
                x = !x;
                i++;
            }
        }
    }
    hell:;
    cout << ans;
    return 0;
}
