#include<iostream>
#include<algorithm>
using namespace std;
bool func(int i, int j)
{
    return i<j;
}
int main()
{
    int n,rep=0,ans=0;
    bool x = false;
    cin >> n;

    int arr[n];

    for (int i = 0; i <n; i++)
    cin >> arr[i];

    if(n > 1)
    {

    sort(arr, arr+n, func);

    int cmp[n-1] = {0};
    int max=0,j=0,k=0;
    cout <<n;
    for (int i = 0; i < n-1; i++)
    {
           if (arr[i] == arr[i+1])
           {
               k++;
           }
           else
           {
               x = 0;
               cmp[j++]=k+1;
               k=0;
           }
           if(i == n-2)
           cmp[j]=k+1;
    }

    for(int i = 0; i < n-1; i++)
    {
        if(cmp[i] > max)
        max = cmp[i];
    }
    cout << n-max;
    }
    else cout<<0;
    return 0;
}
