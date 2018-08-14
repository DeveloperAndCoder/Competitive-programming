#include<bits/stdc++.h>
using namespace std;
#define forn(i,a,b) for(int i = a; i < b; i++)
#define ll long long
#define boost ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int d[32];
int table[V+1];

// m is size of coins array (number of different coins)
int minCoins(int coins[], int m, int V)
{
    // table[i] will be storing the minimum number of coins
    // required for i value.  So table[V] will have result

    // Base case (If given value V is 0)
    table[0] = 0;
    if(table[V] != INT_MAX) return table[V];

    // Initialize all table values as Infinite

    // Compute minimum coins required for all
    // values from 1 to V
    for (int i=1; i<=V; i++)
    {
        // Go through all coins smaller than i
        for (int j=0; j<m; j++)
          if (coins[j] <= i)
          {
              int sub_res = table[i-coins[j]];
              if (sub_res != INT_MAX && sub_res + 1 < table[i])
                  table[i] = sub_res + 1;
          }
    }
    return table[V];
}

int main()
{
    int n, q;
    cin >> n >> q;
    int a[n];
    forn(i,0,n)
    cin >> a[i];
    for (int i=1; i<=V; i++)
        table[i] = INT_MAX;
    /*
    forn(i,0,n)
    {
        d[count(a[i])]++;
    }
    */
    sort(a, a + n);
    forn(i,0,q)
    {
        int b;
        cin >> b;
        int ans = minCoins(a, n, b);
        if(ans == INT_MAX) ans = -1;
        cout << ans << endl;
    }
    return 0;
}
