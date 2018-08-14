#include <bits/stdc++.h>
using namespace std;
long long dp[1000000000];
long long coins(long long n)
{
	if (n<=1000000000)
		return dp[n];
	else
		return (coins(n/2)+coins(n/3)+coins(n/4));
}
int main()
{
	long long n;
	for (int i=0; i<=11; i++)
		dp[i]=i;
	for (int i=12; i<=1000000; i++)
		dp[i]=max(dp[i],dp[i/2]+dp[i/3]+dp[i/4]);
	while (scanf("%lld",&n)!=EOF)
		printf("%lld\n",coins(n));
	return 0;
}
