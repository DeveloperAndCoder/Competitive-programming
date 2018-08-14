#include <bits/stdc++.h>
using namespace std;
map<double,double>a;
int main()
{
	int n;
	cin>>n;

	long double ans=0;
	for (int i=0;i<n;i++)
	{
		double x;
		cin>>x;
		a[x]++;
		cout << ans << "\n";
		ans= ans+ a[x+1]-a[x-1]+x*((i+1)-(n-i));
	}
	cout << fixed << setprecision(0) << ans << endl;
    return 0;
}
