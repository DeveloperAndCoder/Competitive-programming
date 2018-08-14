#include<iostream>
#include<unordered_map>
#include<cmath>
#include<map>
#include<cstdlib>
#include<time.h>

#define forn(i,a,b) for(int i = a; i < b; i++)
#define forr(i,a,b) for(int i = a; i >= b; i--)
#define mod 100000
#define ll long long

using namespace std;

int main()
{
    //int q = 100;
    //while(q--)
    {
    ll n;
    cin >> n;
    //srand(time(NULL)+q);
    //n = rand()%mod;
    //n = 1e5;
    //cout << n << " ";
    map<ll, ll> freq;
    int mx = 0;
    forn(i,0,n)
    {
        int x;
        cin >> x;
        //x = rand()%mod;
      //  x = 1e5;
        freq[x]++;
        mx = max(mx, x);
    }
    /*
    for(auto i: freq)
    {
        cout << i.first << " frequency = " <<  i.second << endl;
    }
    */
    ll dp[mx+1];
    dp[0] = 0;
    dp[1] = freq[1];
    //cout << dp[1];
    //int j = 0;
    //if(freq[1]) j++;
    forn(i,2,mx+1)
    {

        //if(freq[i] != 0) j++;// cout << i << endl;
        dp[i] = max((dp[i-2]+(freq[i]*i)), dp[i-1]);
    }
    cout << dp[mx] << '\n';
    }
    return 0;
}
