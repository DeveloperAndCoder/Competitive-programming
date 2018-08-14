// Accepted

#include<iostream>
#include<cmath>

using namespace std;

int main()
{
    int n,m,k;
    cin >> n >> m >> k;
    int p[n];
    for(int i = 0;i  < n; i++)
    cin >> p[i];
    int minr = m-1,minl = m-1;
    for(int i = m-1; i < n; i++)
    {
        if(p[i] == 0)
            continue;
        if(p[i] <= k)
        {
            minr = i;
            break;
        }
    }
    for(int i = m-1; i >= 0; i--)
    {
        if(p[i] == 0)
            continue;
        if(p[i] <= k)
        {
            minl = i;
            break;
        }
    }
    if (minl != m-1 && minr != m-1)
    {
        cout << abs(min(m-1-minl,minr+1-m))*10;
    }
    else if(minl == m-1)
        cout << abs(minr+1-m)*10;
    else
        cout << abs(minl+1-m)*10;
    return 0;
}
