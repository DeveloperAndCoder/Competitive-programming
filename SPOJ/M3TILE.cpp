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

int fa[31], ga[31];

using namespace std;

void g(int n);

void f(int n)
{
    if(fa[n] != -1)
        return;
    for(int i = 2; i <= n; i++)
    {
        if(fa[i] != -1)
            continue;
        if(fa[i-2] == -1) f(i-2);
        fa[i] = fa[i-2];
        if(ga[i-1] == -1) g(i-1);
        fa[i] += 2*ga[i-1];
    }
    return;
}

void g(int n)
{
    if(ga[n] != -1) return;
    for(int i = 2; i <= n; i++)
    {
        if(ga[i] != -1) continue;
        if(ga[i-2] == -1) g(i-2);
        ga[i] = ga[i-2];
        if(fa[i-1] == -1) f(i-1);
        ga[i] += fa[i-1];
    }
    return;
}

int main()
{
    boost;
    while(1)
    {
        int n;
        cin >> n;
        if(n == -1) return 0;
        memset(fa, -1, sizeof(fa));
        memset(ga, -1, sizeof(ga));
        fa[0] = 1;
        fa[1] = 0;
        ga[0] = 0;
        ga[1] = 1;
        f(n);
        cout << fa[n] << endl;
    }
    return 0;
}
