#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstring>
#include <sstream>
#include <vector>
#include <queue>
#include <stack>
#include <climits>

#define ll long long
#define ull unsigned long long
#define forn(i,a,b) for(int i = a; i < b; i++)
#define boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define fr first
#define sc second
#define MAX 1000001
#define N 1000001

using namespace std;

int dp[N][2];

bool first(int m, int interior, bool g[], bool value[], int si)
{
    //cout << "s = " << si << endl;
    if(si >= interior) return value[si];
    if(g[si]) value[si] = first(m, interior, g, value, 2*si+1) && first(m, interior, g, value, 2*si+2);
    else value[si] = first(m, interior, g, value, 2*si+1) || first(m, interior, g, value, 2*si+2);
    return value[si];
}

bool update(int m, int v, int interiors, bool g[], bool c[], bool value[],int si)
{
    if(si < 0 || si >= m) return false;
    //cout << "si = " << si << " value[" << si << "] = " << value[si] << endl;
    if(g[si]) value[si] = value[2*si+1] && value[2*si+2];
    else value[si] = value[2*si+1] || value[2*si+2];
    if(si == 0)
    {
        return (value[si] == v);
    }
    //if(dp[si][value[si]] != -1) return dp[si][value[si]];
    /*dp[si][value[si]] = */ return update(m, v, interiors, g, c, value, (si&1)?(si/2):((si/2)-1));
    return dp[si][value[si]];
}

int solve(int m, int v, int interiors, bool g[], bool c[], bool value[], int si, int steps)
{
    //cout << "si = " << si << endl;
    for(int i = si; i < interiors; i++)
    {
        if(c[i])
        {
            cout << "i = " << i << endl;
            if(update(m,v,interiors,g,c,value,i)) return steps;
            //cout << "YO";
            if(int y = solve(m,v,interiors,g,c,value,i+1,steps) != -1) return y;
            bool prev = value[i];
            if(g[i])
                value[i] = value[2*i+1] || value[2*i+2];
            else
                value[i] = value[2*i+1] && value[2*i+2];
            cout << "value[" << i << "] = " << value[i] << " " << prev << endl;
            if(value[i] == prev) continue;
            g[i] = !g[i];
            if(update(m,v,interiors,g,c,value,i)) return steps+1;
            if(int y = solve(m, v, interiors, g, c, value, i+1, steps+1) != -1) return y+1;
            g[i] = !g[i];
            value[i] = prev;
            update(m,v,interiors,g,c,value,i);
        }
    }
    return -1;
}

int main()
{
    boost;
    int tests;
    cin >> tests;
    while(tests--)
    {
        forn(i,0,N) forn(j,0,2) dp[i][j] = -1;
        int m;
        bool v;
        cin >> m >> v;
        int interior = (m-1)/2;
        int leaf = (m+1)/2;
        bool value[m];

        bool g[interior], c[interior];
        int i = 0;
        for(i = 0; i < interior; i++)
        {
            cin >> g[i] >> c[i];
        }
        for(i; i < m; i++)
        {
            cin >> value[i];
        }
        /*
        for(i = 0; i < interior; i++)
        {
            cout << g[i] << " " << c[i] << endl;
        }
        for(i; i < m; i++)
        {
            cout << value[i] << endl;
        }
        */
        dp[0][v] = 1;
        dp[0][!v] = 0;
        if(first(m,interior,g,value,0) == v) cout << 0 << endl;
        else if(int y = solve(m, v, interior, g, c, value, 0, 0) != -1) cout <<  y << endl;
        else cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}

/*
1
9 1
1 0
1 1
1 1
0 0
1
0
1
0
1
*/
