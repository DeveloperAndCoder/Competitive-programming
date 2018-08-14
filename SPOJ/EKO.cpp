#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstring>
#include <sstream>
#include <vector>

#define ll long long
#define forn(i,a,b) for(int i = a; i < b; i++)
#define boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define MAX 1000001

using namespace std;

bool isvalid(int tree[], int h, ll desired, int n)
{
    ll wood = 0;
    forn(i,0,n)
        wood += max(0, tree[i]-h);
    return wood>=desired;
}

int binsearch(int tree[], ll m, int n)
{
    int low = 0, high = 0;
    forn(i,0,n) high = max(high, tree[i]);
    while(low < high)
    {
        if(low == high-1)
        {
            if(isvalid(tree,high,m,n))
                return high;
            return low;
        }
        int mid = low + (high-low)/2;
        if(isvalid(tree, mid, m, n))
            low = mid;
        else
            high = mid-1;
    }
    return low;
}

int main()
{
    int n;
    ll m;
    cin >> n >> m;
    int tree[n];
    forn(i,0,n) cin >> tree[i];
    cout << binsearch(tree,m,n);
}
