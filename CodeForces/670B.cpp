#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    long long int n,k;
    cin >> n >> k;
    long long int arr[n];
    for(long long int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    long long int m = (-1+sqrt(1+8*k))/2;
    double c = (-1+sqrt(1+8*k))/2;
    c-=m;
    if(c != 0)
    {
        m++;
    }

    k = k - ((m*(m-1))/2);
    cout << arr[k-1];
    return 0;
}
