#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstring>
#include <sstream>
#include <vector>
#include <stdio.h>

#define ll long long
#define forn(i,a,b) for(ll i = a; i < b; i++)
#define boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define MAX 1000001

using namespace std;

bool isvalid(int pie[], int n, int f, double mid)
{
    int fr = 0;
    forn(i,0,n)
    {
        fr += (acos(-1)*pie[i]*pie[i])/mid;
    }
    ++f;
    return fr>=f;
}

double binsrch(int pie[], int n, int f)
{
    double low = 0.0, high = 0.0;
    forn(i,0,n)
        high += acos(-1)*pie[i]*pie[i];
    while(high-low >= 0.00001)
    {
        double mid = (low+high)/2;
        if(isvalid(pie, n, f, mid))
        {
            low = mid;
        }
        else
        {
            high = mid-0.00001;
        }
    }
    return low;
}

int main()
{
    boost;
    int t;
    cin >> t;
    while(t--)
    {
        int n, f;
        cin >> n >> f;
        int pie[n];
        forn(i,0,n) cin >> pie[i];
        printf("%.4f\n", binsrch(pie, n, f));
    }
}
