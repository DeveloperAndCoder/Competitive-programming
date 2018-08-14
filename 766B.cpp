#include<iostream>
#include<algorithm>
using namespace std;
int cmp(int i, int j)
{
    return i < j;
}
bool istria(int a, int b, int c)
{
    if(a+b > c && b+c > a && c+a > b)
        return true;
    return false;
}
int main()
{
    int n;
    cin >> n;
    int arr[n],i,j,k;
    for(i=0;i<n;i++)
        cin >> arr[i];
    sort(arr,arr+n, cmp);
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            for(k=j+1;k<n;k++)
            {
                if(istria(arr[i],arr[j],arr[k]))
                {
                    cout << "YES";
                //    cout << arr[i] << " " << arr[j] << " "<<arr[k];
                    return 0;
                }
                if(arr[i] + arr[j] <= arr[k])
                    break;
            }
        }
    }
    cout << "NO";
    return 0;
}
