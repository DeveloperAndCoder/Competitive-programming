#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		double n, s, i;
		cin >> n >> s;
		double m = s;
		double x = s*sqrt(n/2.0);
		if(n == 1 && s != 0)
		{
			cout << -1 << endl;
			goto ed;
		}
		if(s == 0)
		{
			for(i = 0; i < n; i++)
			cout << 1 << " ";
			cout << endl;
			goto ed;
		}
		for(i = 0; i < n-2; i++)
		{
			cout << m << " ";
		}
		cout << m-x << " " << x+m << endl;
		ed:;
	}
}
