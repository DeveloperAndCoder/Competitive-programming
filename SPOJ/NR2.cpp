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
#define ul unsigned long long
#define forn(i,a,b) for(ul i = a; i < b; i++)
#define boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define MAX 1000001
#define N 1000001

using namespace std;

void test(ll arr[], int n)
{
    ll ans = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            ans |= (arr[i]^arr[j]);
        }
    }
    cout << ans << endl;
    return;
}


int main()
{
    boost;
    int  n;
    cin >> n;
    ul arr[n];
    forn(i,0,n) cin >> arr[i];
    ul sum = 0;
    forn(id,0,64)
    {
        int one = 0, zero = 0;
        forn(i,0,n)
        {
            if(arr[i] & (1ULL<<id))
                one++;
            else zero++;
        }
        if(one*zero != 0) sum = sum | (1ULL<<id);
    }
    cout << sum;
    return 0;
}
