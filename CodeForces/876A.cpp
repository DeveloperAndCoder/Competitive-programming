#include<iostream>
using namespace std;
int main()
{
    int n,ans=0,j=0;
    int x[3];
    cin >> n >> x[0] >> x[1] >> x[2];
    n--;
    if(n == 0)
    {
        cout << ans;
        return 0;
    }
    if(x[0] < x[1])
    {
        ans += x[0];
        j = 2;
    }
    else
    {
        ans += x[1];
        j = 1;
    }
    for(int i = 1; i < n; i++)
    {
        if(j == 0)
        {
            if(x[0] < x[1])
            {
                ans += x[0];
                j = 2;
            }
            else
            {
                ans += x[1];
                j = 1;
            }
        }
        else if(j == 1)
        {
            if(x[1] < x[2])
            {
                ans += x[1];
                j = 0;
            }
            else
            {
                ans += x[2];
                j = 2;
            }
        }
        else if(j == 2)
        {
            if(x[0] < x[2])
            {
                ans += x[0];
                j = 0;
            }
            else
            {
                ans += x[2];
                j = 1;
            }
        }
    }
    cout << ans;
}
