#include<iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int ans = 0;
	int i = 0, j = 0;
	char c;
	int count = 0;
	while(n--)
	{
		cin >> c;
		count++;
		if(c == 'L')
		i--;
		else if(c == 'R')
		i++;
		else if(c == 'U')
		j++;
		else
		j--;
		if(i == 0 && j == 0)
		{
	 	 	 ans += count;
	 	 	 count = 0;
		}
	}
	cout << ans;
	return 0;
}
