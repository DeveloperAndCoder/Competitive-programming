#include <iostream>
#include <map>

using namespace std;

int ans(int a[], int n)
{
    int x = 0;
    for(int i = 4; i >= 0; i--)
    {
        x += n/a[i];
        n = n%a[i];
    }
    return x;
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    int t[n];
    for(int i = 0; i < n; i++)
    {
        t[i] = max(a[i]-i, 0) / n;
        int vali = a[i] - (t[i]*n + i);
        if(vali > 0) t[i]++;
    }
    int mn = t[0];
    int time = 1;
    for(int i = 0; i < n; i++)
    {
        //cout << t[i] << " ";
        if(mn > t[i])
        {
            mn = t[i];
            time = i+1;
        }
    }
    cout << time;
    return 0;
}
