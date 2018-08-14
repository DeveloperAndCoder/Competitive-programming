#include<iostream>
#include<string>
using namespace std;

bool dp[105][9] = {0};
string store[105][9];
string s;
#define d(x) (s[x]-'0')

int main()
{
    cin >> s;
    dp[0][d(0)%8]=1;
    store[0][d(0)%8]=s[0];
    for(int i = 1; i < s.length(); i++)
    {
        dp[i][d(i)%8] = 1;
        store[i][d(i)%8] = s[i];
        for(int j = 0; j < 8; j++)
        {
            if(dp[i-1][j])
            {
                store[i][j] = store[i-1][j];
                store[i][(j*10+d(i))%8] = store[i-1][j] + s[i];
            }
            dp[i][(j*10+d(i))%8] |= dp[i-1][j];
            dp[i][j] |= dp[i-1][j];
        }
    }
    for(int i = 0; i < s.length(); i++)
        if(dp[i][0] && store[i][0].length())
    {
        cout << "YES\n" << store[i][0];
        return 0;
    }
    cout << "NO";
    return 0;
}
