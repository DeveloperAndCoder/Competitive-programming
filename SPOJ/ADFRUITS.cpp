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

int dp[101][101];

int lcs(string s1, string s2, int n ,int m)
{
    /*
    if(n < 0 || m < 0) return 0;
    if(dp[n][m] != -1) return dp[n][m];
    if(s1[n] == s2[m])
    {
        dp[n][m] = lcs(s1, s2, n-1, m-1)+1;
    }
    else
    {
        dp[n][m] = max(lcs(s1,s2,n-1,m), lcs(s1,s2,n,m-1));
    }
    return dp[n][m];
    */
    forn(i,0,n+1)
    forn(j,0,m+1)
    {
        if(i == 0 || j == 0) dp[i][j] = 0;
        else if(s1[i-1] == s2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
        else
        {
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[n][m];
}

int main()
{
    string s1,s2;
    while(cin >> s1 && cin >> s2)
    {
        int n = s1.size(), m = s2.size();
        int index = lcs(s1,s2,s1.size(),s2.size());
        char LCS[index];
        //cout << index << endl;
        int i = n, j = m;
        //cout << s1 << " " << s2 << endl;
        int idx = index;
        while(i > 0 && j > 0)
        {
            if(s1[i-1] == s2[j-1])
            {
                LCS[index-1] = s1[i-1];
                //cout << i << " " << s1[i-1] << " " << index << " " << LCS[index-1] << endl;
                index--;
                i--;
                j--;
            }
            else if(dp[i-1][j] > dp[i][j-1]) i--;
            else j--;
        }
        index = 0;
        i = 0, j = 0;
        while(i < n && j < m)
        {
            if(index >= idx) break;
            while(i < n && s1[i] != LCS[index]) {
                    cout << s1[i];
                    i++;
            }
            //cout << endl;
            while(j < m && s2[j] != LCS[index])
            {
                cout << s2[j];
                j++;
            }
            //cout << endl;
            cout << LCS[index];
            i++;j++;
            //cout << endl;
            index++;
        }
        while(i < n){cout << s1[i++];}
        while(j < m){cout << s2[j++];}
        cout << endl;
    }
}
