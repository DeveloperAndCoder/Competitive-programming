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
		for(i = 0; i < n-2; i++)
		{
			cout << m << " ";
		}
		cout << x-m << " " << x+m << endl;
	}
}
