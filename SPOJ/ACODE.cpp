#include<iostream>
#include<string>
using namespace std;

long long int dp(string s)
{
	int len = s.length();
	if(len == 1)
	return 1;
	long long ans[len+1];
	ans[0] = 0;
	ans[1] = 1;
	for(int i = 2; i <= len; i++)
	{
		if(s[i-1] == '0' && s[i-2] != '1' && s[i-2] != '2')
		ans[i] = 0;
		else if(s[i-1] == '0')
		{
			ans[i] = ans[i-2];
			if(ans[i-2] == 0)
			ans[i]++;
		}
		else if(s[i-2] == '1' || (s[i-2] == '2' && (s[i-1] != '7' && s[i-1] != '8' && s[i-1] != '9')))
		{
			ans[i] = ans[i-1]+ans[i-2];
			if(ans[i-2] == 0)
			ans[i]++;
		}
		else
		ans[i] = ans[i-1];
	}
	return ans[len];
}


int main()
{
	string s;
	while(1)
	{
		cin >> s;
		if(s == "0")
		return 0;
		cout << dp(s);
		cout << endl;
	}
	return 0;
}
