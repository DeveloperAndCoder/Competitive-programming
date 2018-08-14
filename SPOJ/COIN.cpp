#include <bits/stdc++.h>
using namespace std;
long long int dp[1000001];
long long int find_max_money(long long int n,long long int dp[])
{
	if(n <= 0)
		return 0;
	long long int n1 = n/2;
	long long int n2 = n/3;
	long long int n3 = n/4;
	if(n > 1000000)
	return max(find_max_money(n1, dp) + find_max_money(n2, dp) + find_max_money(n3, dp), n);
	else
	{
		if(dp[n1] == -1)
			dp[n1] = find_max_money(n1, dp);
		if(dp[n2] == -1)
			dp[n2] = find_max_money(n2, dp);
		if(dp[n3] == -1)
			dp[n3] = find_max_money(n3, dp);
		dp[n] = max(dp[n1] + dp[n2] + dp[n3], (long long)n);
		return dp[n];
	}
}

int main()
{
	long long int n;
	while(scanf("%lld", &n) == 1)
	{
	//	printf("%d\n", n);
	//	printf("Hello");
		for(int i = 0; i <= 1000000; i++)
			dp[i] = -1;
		cout << find_max_money(n, dp) << endl;
		//delete dp;
	}
	return 0;
}
