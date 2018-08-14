#include<iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    long long sum[n];
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        if(i)
        sum[i] = sum[i-1]+a[i];
        else sum[i] = a[i];
    }
    long long mid;
    if(sum[n-1]%2==0) mid = sum[n-1]/2;
    else
    {
        mid = sum[n-1]/2;
        mid++;
    }
    for(int i = 0; i < n; i++)
    {
        if(sum[i] >= mid)
        {
            cout << i+1;
            return 0;
        }
    }
}
