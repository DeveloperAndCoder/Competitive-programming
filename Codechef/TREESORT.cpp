#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#include <ctime>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>

using namespace std;

typedef long long int ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

// utility functions
#define ARGMAX(a, b, c, d) (((a) > (b)) ? (c) : (d))
#define ARGMIN(a, b, c, d) (((a) < (b)) ? (c) : (d))
#define VMAX(a, b) ARGMAX(a, b, a, b)
#define VMIN(a, b) ARGMIN(a, b, a, b)

// Modulo functions
#define MODULO 1000000007
#define ADDM(a, b, mod) (((1LL * (a)) + (b))%(mod))
#define ADD(a, b) ADDM(a, b, MODULO)
#define SUBM(a, b, mod) (((1LL * (a)) - (b) + (mod))%(mod))
#define SUB(a, b) SUBM(a, b, MODULO)
#define MULM(a, b, mod) (((1LL * (a)) * (b))%(mod))
#define MUL(a, b) MULM(a, b, MODULO)

int dfs(vpii& node, int v, int& min, int& max)
{
    if(node[v].first == -1)
    {
        min = max = node[v].second;
        return 0;
    }
    int lmin, lmax, rmin, rmax;
    int lcount = dfs(node, node[v].first, lmin, lmax);
    int rcount = dfs(node, node[v].second, rmin, rmax);

    if(lcount == -1 || rcount == -1)
    {
        return -1;
    }
    // cout<<v<<" "<<lmin<<" "<<lmax<<" "<<rmin<<" "<<rmax<<endl;
    if(lmax <= rmin)
    {
        min = lmin;
        max = rmax;
        return lcount + rcount;
    }
    else if(rmax <= lmin)
    {
        min = rmin;
        max = lmax;
        return lcount + rcount + 1;
    }
    else
    {
        return -1;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        vpii node(N + 1, pii(0, 0));
        for(int i = 1; i <= N; i++)
        {
            cin>>node[i].first>>node[i].second;
        }
        int min, max;
        cout<<dfs(node, 1, min, max)<<endl;
    }

    return 0;
}
