#include<iostream>
#include<string>
#include<sstream>
#include<math.h>

#define forn(i,a,b) for(int i = a; i < b; i++)
#define ll long long
#define MAX 10001

#define boost ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

int n;
int dig;
int dp[MAX][101][2];

int num_of_dig(int n)
{
    int ans = 0;
    while(n)
    {
        n /= 10;
        ans++;
    }
    return ans;
}

string To_string(int n)
{
    ostringstream ss;
    ss << n;
    return ss.str();
}
int To_int(const string &s)
{
    int n = 0;
    forn(i,0,s.size())
    {
        n *= 10;
        n += s[i]-'0';
    }
    return n;
}

bool solution(string snum, int step, bool player)
{
    //cout << snum << " " << step << " " << player << endl;
    if(dp[To_int(snum)][step][player] != -1) return dp[To_int(snum)][step][player];
    /// Base Case 1
    if(step == 0)
    {
        int n1 = To_int(snum);
        return (n1>n == player);
    }
    /// Base Case 2
    if(step == 1)
    {
        forn(i,0,dig)
        {
            if(snum[i] == '9')
            {
                snum[i] = '0';
            }
            else
            {
                snum[i]++;
            }
            int num = To_int(snum);

            if(snum[i] == '0') snum[i] = '9';
            else snum[i]--;

            bool pr;
            if(num > n) pr = 1;
            else pr = 0;
            //cout << num << " " << n << endl;
            if(pr == player)
            {
                dp[To_int(snum)][step][player] = player;
                return player;
            }
        }
        dp[To_int(snum)][step][player] = !player;
        return !player;
    }
    for(int i = 0; i < dig; i++)
    {
        if(snum[i] == '9')
        {
            snum[i] = '0';
            //cout << 9*pow(10,i) << " " << snum << endl;
        }
        else
        {
            snum[i]++;
            //cout << pow(10,i) << " " << snum << endl;
        }
        if(dp[To_int(snum)][step-1][!player] == -1)
        {
            dp[To_int(snum)][step-1][!player] = solution(snum,step-1,!player);
        }
        if(dp[To_int(snum)][step-1][!player] == player) {
            if(snum[i] == '0')
                snum[i] = '9';
            else
                snum[i]--;
            dp[To_int(snum)][step][player] = player;
            return player;
        }
        if(snum[i] == '0') snum[i] = '9';
        else snum[i]--;
    }
    dp[To_int(snum)][step][player] = !player;
    return !player;
}

int main()
{
    boost;
    int t;
    cin >> t;
    while(t--)
    {
        forn(i,0,MAX)
        {
            forn(j,0,101)
            {
                forn(k,0,2) dp[i][j][k] = -1;
            }
        }
        int m;
        string s;
        cin >> s >> m;
        n = To_int(s);
        dig = s.size();
        if(solution(s,m,true)) cout << "Ada\n";
        else cout << "Vinit\n";
    }
    return 0;
}
