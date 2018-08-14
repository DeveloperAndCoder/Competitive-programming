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
    ll n, x, y;
    cin >> n >> x >> y;
    string s;
    cin >> s;
    while(n-1 >= 0 && s[n-1] == '1') n--;
    string temp;
    if(n)
    temp += s[0];
    forn(i,0,n)
    {
        if(s[i] == temp.back()) continue;
        temp += s[i];
    }
    int zero = 0, one = 0;
    while(temp.size() && temp[0] == '1') temp.erase(temp.begin());
    n = temp.size();
    forn(i,0,n)
    {
        if(temp[i] == '0') zero++;
        else one++;
    }
    //cout << temp << " " << one << " " << zero << endl;
    ll ans = one*x+(y*(zero>=1));
    forn(i,0,one+1)
    {
        ans = min(ans, (one-i)*x + (i+(1LL*(zero>=1)))*y);
    }
    cout << ans;
    return 0;
}
