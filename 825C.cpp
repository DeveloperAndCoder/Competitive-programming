#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n,k;
    cin >> n >> k;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];

        sort(arr, arr+n);
         int ans = 0;
        if(n == 1)
        {
            if(arr[0] > 2*k)
                {
                    while(2*k < arr[0])
                    {
                        ans++;
                        k= k*2;
                    }
                    cout << ans;
                }
            else
                cout << 0;
            return 0;
        }
    int maxi = 0, max_d = 2*k, mini = INT_MAX;
/*
    int k1 = k;
    while(mini > 2*k1)
    {
        ans++;
        k1*=2;
    }
    curr = k1;
    */

        for(int i = 0; i < n; i++)
        {
            while(max_d < arr[i])
            {
                ans++;
                max_d = max_d*2;
            }
        }
        cout << ans;
        /*
        if(max_d >= maxi)
            cout << ans;
        else
            {
                while(max_d < maxi)
                {
                    ans++;
                    max_d*=2;
                }
                cout << ans;
            }
            */
        return 0;
}
