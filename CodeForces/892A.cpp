#include<iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int b[n];
	int a;
	long long sum = 0L;
	for(int i = 0; i < n; i++)
	{
		cin >> a;
		sum += a;
	}
	int maxi = 0;
	int max = 0L;
	for(int i = 0; i < n; i++)
	{
		cin >> b[i];
		if(max < b[i])
		{
			max = b[i];
			maxi = i;
		}
	}
	long long cap = max;
	max = 0L;
	for(int i = 0; i < n; i++)
	{
		if(max < b[i] && i != maxi)
		{
			max = b[i];
		}
	}
	cap += max;
	if(cap >= sum)
	cout << "YES";
	else
	cout << "NO";
}
