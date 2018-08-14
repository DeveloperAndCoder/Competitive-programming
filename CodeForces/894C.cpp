#include<iostream>
#include<algorithm>

using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++)
        cin >> a[i];
    int minm = a[0];
    int g = a[0];
    for(int i = 0; i < n ; i++)
    {
        if(minm > a[i])
            minm = a[i];
        g = __gcd(g, a[i]);
    }
    if(minm != g)
    {
        cout << -1;
        return 0;
    }
    cout << 2*n-1 << '\n';
    for(int i = 0; i < n-1; i++)
    {
        cout << a[i] << " " << minm << " ";
    }
    cout << a[n-1];
    return 0;
}
