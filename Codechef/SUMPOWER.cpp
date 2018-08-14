#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <list>
#include <ctime>
#include <memory.h>
#include <assert.h>
#include <iostream>
#include <unordered_set>

#define forn(i,a,b) for(int i = a; i < b; i++)
#define ll long long
#define boost ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        ll ans = 0;
        int diff[n];
        forn(i,0,n) diff[i] = 0;
        forn(i,1,n)
        {
            diff[i] = diff[i-1];
            if(s[i] != s[i-1]) diff[i]++;
        }
        /*
        forn(i,0,n) cout << diff[i] << " ";
        cout << endl;
        */
        if(k < n)
        for(int i = 0; i < min(k, n); i++)
        {
            //cout << i << " " << n-k+i << " " << diff[i] << " " <<  diff[n-k-i] << endl;
            ans += diff[n-k+i] - diff[i];
        }
        cout << ans << endl;
    }
    return 0;
}
