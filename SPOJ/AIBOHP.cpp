#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int LCS(string s, string rev_s, int i, int j, int n, int** dp)
{
	for(int i = 0; i <= n; i++)
	dp[i][0] = 0;
	for(int i = 0; i <= n; i++)
	dp[0][i] = 0;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			if(s[i-1] == rev_s[j-1])
			{
				dp[i][j] = dp[i-1][j-1]+1;
			}
			else
			{
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}
	return dp[n][n];
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int test;
	cin >> test;
	while(test--)
	{
	//cout << "F";
	string s;
	cin >> s;
	int n = s.length();
	string rev_s = s;
	//cout << "T";
	std::reverse(rev_s.begin(), rev_s.end());
	//cout << "G";
	int** dp = new  int*[n+1];
	for(int i = 0; i <= n; i++)
	*(dp+i) = new int[n+1];
	for(int i = 0; i <= n; i++)
	for(int j = 0; j <= n; j++)
	dp[i][j] = -1;
	dp[0][0] = 0;
	//cout << "K";
	int l = LCS(s, rev_s, n, n, n, dp);
	cout << n-l << endl;
	for(int i = 0; i <= n; i++)
	delete[] dp[i];
	delete[] dp;
	}
	return 0;
}
