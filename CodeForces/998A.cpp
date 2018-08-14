#include <fstream>
#include <iostream>
#include <string>
#include <complex>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <list>
#include <ctime>
#include <memory.h>
#include <assert.h>

#define forn(i,a,b) for(int i = a; i < b; i++)
#define ll long long

using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    int id = 1, mn = INT_MAX;
    forn(i,0,n) {
        cin >> a[i];
        if(a[i] < mn)
        {
            id = i+1;
            mn = a[i];
        }
    }
    sort(a, a+n);
    int s = 0;
    forn(i,1,n)
    {
        s += a[i];
        if(s > a[0])
        {
            cout << 1 << "\n" << id;
            return 0;
        }
    }
    cout << -1;
    return 0;
}
