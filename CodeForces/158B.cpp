#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int arr[4] = {0};
    for(int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        arr[a-1]++;
    }
    int ans = arr[3];
    if(arr[0] >= arr[2])
    {
        ans += arr[2];
        arr[0] -= arr[2];
        ans += arr[1]/2;
        arr[1] = arr[1] - 2*(arr[1]/2);
        if(arr[0] >= 2*arr[1])
        {
            ans += arr[1];
            arr[0] = arr[0] - 2*(arr[1]);
            ans += arr[0]/4;
            if(arr[0]%4 != 0)
                ans++;
        }
        else
        {
            ans += arr[0]/2;
            if(arr[0]%2 != 0)
            {
                ans++;
                arr[1]-- ;
            }
            arr[1] -= arr[0]/2;
            ans += arr[1]/2;
            if(arr[1]%2 != 0)
                ans++;
        }

    }
    else
    {
        ans += arr[0];
        arr[2] -= arr[0];
        ans += arr[1]/2;
        arr[1] = arr[1] - 2*(arr[1]/2);
        ans += arr[1] + arr[2];
    }
    cout << ans;
}
