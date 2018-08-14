#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstring>
#include <sstream>
#include <vector>
#include <queue>
#include <set>
#include <climits>

#define ll long long
#define ul unsigned long long
#define forn(i,a,b) for(int i = a; i < b; i++)
#define boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define fr first
#define sc second
#define MAX 1000001
#define D 400001
#define mod 1000000007

using namespace std;

int totalPrimeFactors(int n, int l, int r)
{
    // To keep track of count
    int count = 0;

    // 2s that divide n
    if (!(n%2))
    {
        count++;
        while (!(n%2))
            n /= 2;
    }

    // n must be odd at this point. So we can skip
    // one element (Note i = i +2)
    for (int i = 3; i*i <= n; i = i+2)
    {
        if(i < l) continue;
        if(i > r) break;
        // i divides n
        if (!(n%i))
        {
            if(n/i >= l && n/i <= r)
            count++;
            while (!(n%i))
                n /= i;
        }
    }

    // This condition is to handle the case when n
    // is a prime number greater than 2
    if (n > 2 && n >= l && n <= r)
        count++;

    return count;
}

// C++ function to count number
// of pair with given GCD and LCM
int countPairs(int G, int L, int l, int r)
{
    if (L % G != 0)
       return 0;

    int div = L/G;

    // answer is 2^totalPrimeFactors(L/G)
    return (1 << totalPrimeFactors(div,l,r));
}

int main()
{
    int l,r,x,y;
    cin >> l >> r >> x >> y;
    cout << countPairs(x, y, l, r);
}
