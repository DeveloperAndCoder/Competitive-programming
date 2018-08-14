#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstring>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <climits>
#include <tuple>

#define ll long long
#define forn(i,a,b) for(ll i = a; i < b; i++)
#define boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define MAX 1000001

using namespace std;

int BIT[11];

void update(int x, int val = 1)
{
    for(;x <= 10;x+=x&-x)
    {
        BIT[x] += val;
    }
}
int getsum(int x)
{
    if(x < 0) return 0;
    int sum = 0;
    for(x; x >= 1; x -= x&-x)
    {
        sum += BIT[x];
    }
    return sum;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        forn(i,0,11) BIT[i] = 0;
        int n;
        cin >> n;
        int ans = 0;
        bool makeit[10];
        forn(i,0,10) makeit[i] = 0;
        int k = 0;
        while(n)
        {
            ans += (1<<(k - getsum((n%10))))-1;
            update(n%10+1);
            makeit[n%10] = 1;
            n /= 10;
            k++;
        }
        forn(i,0,10) if(makeit[i]) ans++;
        cout << ans << endl;
    }
    return 0;
}
