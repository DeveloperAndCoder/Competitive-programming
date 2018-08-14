#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<math.h>
#include<stack>
#include<climits>

#define forn(i,a,b) for(int i = a; i < b; i++)
#define ll long long
#define MAX 100001
#define boost ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

ll dp[MAX] = {0};

bool cmp(const pair<int,int> &p1, const pair<int,int> &p2)
{
    return p1.second<p2.second;
}
bool compareit(int n, pair<int,int> &p)
{
    return p.second > n;
}

ll subsets(pair<int,int> time[], int p)
{
    if(p < 0) return 0;
    if(p == 0)  return 1;
    ll ans = 0;
    int j = upper_bound(time, time+p+1, time[p].first, compareit) - time;
    j--;
    if(j >= 0 && dp[j] == -1) dp[j] = subsets(time, j)%1000000000;
    if(j >= 0) ans += dp[j];
    ans++;
    if(p >= 1 && dp[p-1] == -1) dp[p-1] = subsets(time,p-1)%1000000000;
    if(p >= 1) ans += dp[p-1];
    dp[p] = ans%1000000000;
    return dp[p];
}

int main()
{
    boost;
    while(1)
    {
        memset(dp,-1,sizeof(dp));
        int n;
        cin >> n;
        if(n == -1) break;
        pair<int,int> time[n];
        forn(i,0,n)
        {
            int s,e;
            cin >> s >> e;
            time[i].first = s;
            time[i].second = e;
        }
        sort(time, time+n, cmp);
        /*
        cout << "---------------------------------\n";
        forn(i,0,n)
         {
             cout << time[i].first << " " << time[i].second << endl;
         }
         cout << "----------------------------------\n";
         */
         ll ans =  subsets(time, n-1);
         ans %= (1000000000);
         string s = to_string(ans);
         for(int i = 0; i < 8 - s.size(); i++)
         {
             cout << 0;
         }
         cout << s << endl;
    }
}
