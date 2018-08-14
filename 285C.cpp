#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;

bool cmp(long long int i, long long int j)
{

    return i<j;
}

int main()
{
    long long int n;
    cin >> n;
    long long int arr[n];
    long long int i=0,ans=0;
    for(i;i<n;i++)
        cin >> arr[i];
    sort(arr,arr+n,cmp);
    for(i = 0;i < n; i++)
    {
        ans+=abs(arr[i] - (i+1));
    }
    cout << ans;
}
