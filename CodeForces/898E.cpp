#include<iostream>
#include<math.h>
#include<algorithm>

#define forn(a,b) for(int i = a; i < b; i++)
#define ll long long

using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    int diff[n];
    int zero = 0;
    forn(0,n)
    {
        cin >> a[i];
        if(a[i] == 0)
            zero++;
    }
    forn(0,n)
    {
        int root = sqrt(a[i]);
        diff[i] = min(abs(a[i]-root*root), abs((root+1)*(root+1)-a[i]));
    }
    sort(diff, diff+n);
    ll sum = 0;/*
    forn(0,n)
    cout << diff[i] << " ";
    cout << '\n';*/
    forn(0,n/2)
    {
        sum += diff[i];
    }
    if(sum == 0)
    {
        forn(n/2, n)
        {
            if(diff[i] == 0)
                sum++;
            else
                break;
        }
        zero -= n/2;
        if(zero >= sum)
        {
            cout << 2*zero;
        }
        else
        {
            //cout << one << " " << sum << endl;
            if(zero < 0)
                zero = 0;
            sum -= zero;
            cout << (zero*2+sum);
        }
    }
    else
        cout << sum;
    return 0;
}
