#include<iostream>
using namespace std;

int BS(int A[], int p, int r, int k)
{
	if(p > r)
	return -1;
	int q = p+r;
	q /= 2;
	if(A[q] == k)
	return q;
	else if(A[q] > k)
	return BS(A, p, q-1, k);
	else
	return BS(A, q+1, r, k);
}

long long int Ans(int A[], int B[], int n1, int n2)
{
	long long int s[n2];
	s[0] = (long long)B[0];
	for(int i = 1; i < n2; i++)
	s[i] = s[i-1]+B[i];
	/*
	cout << "s[n2-1] = " << s[n2-1] << endl;
	cout << "s[0] = " << s[0] << endl;
	*/
	int c2 = -1;
	int last = -1;
	long long int sum1 = 0L;
	long long int ans = 0L;
	for(int i = 0; i < n1; i++)
	{
		c2 = BS(B, 0, n2-1, A[i]);
		if(c2 == -1)
		sum1+=A[i];
		else
		{
			if(last == -1 && c2 > 0)
			ans += max(s[c2-1], sum1);
			else if(c2 > 0)
			ans += max(s[c2-1]-s[last], sum1);
			ans += A[i];
			sum1 = 0;
			last = c2;
		}
	}
	/*
	cout << "c2 = " << c2 << endl; 
	cout << "last = " << last << endl;
	cout << "sum1 = " << sum1 << endl;
	cout << "ans = " << ans << endl;
	cout << "s[n2-1] = " << s[n2-1] << " s[last] = " << s[last] << endl;
	*/
	if(last < n2 && last >= 0)
	ans += max(s[n2-1]-s[last], sum1);
	else if(last == -1)
	{
		ans = max(sum1, s[n2-1]);
	}
	return ans;
}

int main()
{
	while(1)
	{
		int n1,n2;
		cin >> n1;
		if(n1 == 0)
		return 0;
		int A[n1];
		for(int i = 0; i < n1; i++)
		cin >> A[i];
		cin >> n2;
		int B[n2];
		for(int i = 0; i < n2; i++)
		cin >> B[i];
		cout << Ans(A, B, n1, n2) << "\n";
	}
}
