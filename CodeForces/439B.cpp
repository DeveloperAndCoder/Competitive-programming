#include<iostream>
#include<algorithm>

using namespace std;

bool func(int i, int j)
{
    return i<j;
}

int main()
{
    int n,x;
    cin >> n >> x;
    int t[n];
    for(int i = 0; i < n; i++)
        cin >> t[i];
    sort(t,t+n,func);

    int ans=0;
    for(int i = 0;i < n; i++)
    {
        if(x-i > 1)
        ans+=((x-i)*t[i]);
        else
            ans+=t[i];
    }
    cout << ans;

    return 0;
}
