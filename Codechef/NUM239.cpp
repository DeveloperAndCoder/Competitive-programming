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
#include <unordered_set>

#define forn(i,a,b) for(int i = a; i < b; i++)
#define ll long long
#define boost ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int l, r;
        //cin >> l >> r;
         l =1;
         r = 100000;
        int ans = 0;
        while(l <= r)
        {
            if(l%10 == 2 || l%10 == 3 || l%10 == 9) ans++;
            l++;
        }
        cout << ans << endl;
    }
    return 0;
}
