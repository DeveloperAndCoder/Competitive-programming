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
    int n, b;
    cin >> n >> b;
    int a[n];
    forn(i,0,n) cin >> a[i];
    vector<int> v;
    int e = 0, o = 0;
    forn(i,0,n)
    {
        if(i && e == o)
        {
            v.push_back(abs(a[i]-a[i-1]));
        }
        if(a[i]%2 == 0) e++;
        else o++;
    }
    sort(v.begin(), v.end());
    int cut = 0;
    int sum = 0;
    forn(i,0,v.size())
    {
        sum += v[i];
        if(sum <= b)
        {
            cut++;
        }
    }
    cout << cut;
    return 0;
}
