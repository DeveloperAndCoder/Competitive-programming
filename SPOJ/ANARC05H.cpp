#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cstring>

#define forn(i,a,b) for(int i = a; i < b; i++)
#define N 102
#define boost ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long

using namespace std;

int solve(string s, int p, int j, int sum)
{
    if(p < 0 || j < 0) return 0;
    if(p == 0)
    {
        int sum_c = 0;
        for(int i = j; i >= 0; i--) sum_c += s[i]-'0';
        if(sum_c <= sum) return 1;
        return 0;
    }
    int ans = 0, sum_c = 0;
    for(int i = j; i >= 0; i--)
    {
        sum_c += s[i]-'0';
        if(sum_c <= sum)
            ans += solve(s, p-1, i-1, sum_c);
       // if(j == s.size()-1) cout << "i = " << i << " " << j << " " << p << " " << sum << " " << sum_c << " " << solve(s, p-1, i-1, sum_c) << endl;
    }
    return ans;
}

int main()
{
    boost;
    string s;
    int h = 1;
    while(1)
    {
        cin >> s;
        if(s == "bye") break;
        int ans = 0;
        forn(i,0,s.size())
        {
            //cout << i << " " << solve(s,i,(int)s.size()-1,INT_MAX) << endl;
            ans += solve(s,i,(int)s.size()-1,INT_MAX);
        }
        cout << h++ << ". " << ans << endl;
    }
}
