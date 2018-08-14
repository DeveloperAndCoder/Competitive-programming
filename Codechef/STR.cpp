#include<bits/stdc++.h>
using namespace std;
const int LT=20;

int dp[1<<LT];
int dp2[1<<LT][LT];
int a[100005];

inline bool isset(int mask,int idx)
{
	return (mask>>idx)&1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	int i,j,n;
	cin>>n;
	assert(n>=1 and n<=100000);
	string x;
	for(i=0;i<n;++i)
	{
		cin>>x;
		assert(x.size()>=1 and x.size()<=50);
		for(j=0;j<x.size();++j)
		{
			assert(x[j]>='A' and x[j]<='T');
			a[i]|=(1<<(x[j]-'A'));
		}
		dp[a[i]]++;
	}
/*    for(i = 1<<LT-1; i>=0; i--)
    {
        for(j = LT-1; j >= 0; j--)
            if(dp2[i][j]) cout << i << " " << j << endl;
    }

    cout << "\n-----------------------------------------\n";
*/
	for(i=(1<<LT)-1;i>=0;--i)
	{
		int ct=0;
		for(j=0;j<LT;++j)
		{
			if(!isset(i,j))
			{
				if(ct == 0)
					dp[i]+=dp[i|(1<<j)];
				else
					{
					    dp[i]+=dp2[i|(1<<j)][ct];

					   // if(dp2[i|(1<<j)][ct]) cout << i << " " << j << endl;
					}
				ct++;

			}
		}

		ct=1;
		for(j=0;j<LT;++j)
		{
			if(!isset(i,j))
			{
				if(ct == 1)
					dp2[i][ct]=dp[i]-dp[i|(1<<j)];
				else
					dp2[i][ct]=dp2[i][ct-1]-dp2[i|(1<<j)][ct-1];
				ct++;
			}
		}
	}

	int all=(1<<LT)-1;
	long long int res=0;
	int ct=0;
	for(i=0;i<n;++i)
	{
		if(a[i] == all) ct++;
		res+=dp[all-a[i]];
	}

	cout<<(res-ct)/2+ct<<'\n';

	return 0;
}
