#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
#include <utility>
#include <iomanip>

#define forn(i,a,b) for(int i = a; i < b; i++)
#define ll long long
#define boost ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define INF (int)2e9+10

using namespace std;

bool solve(int n, int m, int x, int b, int freq[])
{
    int y = n+m-b-x;
    int t = n*m;
    if(y >= 1 && y <= m)
    {
        forn(i,1,n+1)
        {
            forn(j,1,m+1)
            freq[abs(i-x)+abs(j-y)]--;
        }
        bool valid = 1;
        forn(j,1,t+1)
        {
            if(freq[j] != 0)
            {
                valid = false;
                break;
            }
        }
        if(!valid)
        {
            forn(i,1,n+1)
            forn(j,1,m+1)
            freq[abs(i-x) + abs(j-y)]++;
            return false;
        }
        cout << n << " " << m << endl;
        cout << x+1 << " " << y+1 << endl;
        return true;
    }
    return false;
}

int main()
{
    int t;
    cin >> t;
    int freq[t+1];
    forn(i,0,t+1) freq[i] = 0;
    forn(i,0,t)
    {
        int a;
        cin >> a;
        freq[a]++;
    }
    int x= -1, y = -1, b = -1;
    for(int i = 1; i <= t; i++)
    {
        if(freq[i]%4)
        {
            x = i;
            break;
        }
        if(freq[i]) b = i;
    }
    for(int n = 1; n*n <= t; n++)
    {
        if(t%n == 0 && solve(n,t/n,x,b,freq))
        {
            return 0;
        }
    }
    cout << -1;
    return 0;
}
