#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstring>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <climits>

#define ll long long
#define forn(i,a,b) for(ll i = a; i < b; i++)
#define boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define MAX 1000001

int f[2001], g[2001], h[2001];

using namespace std;

void solve_g(int w);
void solve_h(int w);

void solve_f(int w)
{
    if(f[w] != -1) return;
    forn(i,2,w+1)
    {
        if(f[i] != -1) continue;
        if(g[i-1] == -1) solve_g(i-1);
        if(h[i-1] == -1) solve_h(i-1);
        f[i] = 2*g[i-1] + f[i-1] + h[i-1] + f[i-2];
    }
    return;
}

void solve_g(int w)
{
    if(g[w] != -1) return;
    forn(i,2,w+1)
    {
        if(g[i] != -1) continue;
        if(f[i-1] == -1) solve_f(i-1);
        g[i] = g[i-1] + f[i-1];
    }
    return;
}

void solve_h(int w)
{
    if(h[w] != -1) return;
    forn(i,2,w+1)
    {
        if(h[i] != -1) continue;
        if(f[i-1] == -1) solve_f(i-1);
        h[i] = h[i-2] + f[i-1];
    }
    return;
}

int main()
{
    boost;
    int n, k = 1;
    cin >> n;
    int w;
    memset(f, -1, sizeof(f));
    memset(g, -1, sizeof(g));
    memset(h, -1, sizeof(h));
    f[0] = 1;
    f[1] = 1;
    g[0] = 0;
    g[1] = 1;
    h[0] = 0;
    h[1] = 1;
    while(n--)
    {
        cin >> w;
        solve_f(w);
        cout << k++ << " " << f[w] << endl;
    }
    return 0;
}
