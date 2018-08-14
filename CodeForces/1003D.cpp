#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <stdio.h>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
#include <utility>
#include <iomanip>

#define forn(i,a,b) for(int i = a; i < b; i++)
#define ll long long
#define boost ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;
    int cnt[31];
    forn(i,0,31) cnt[i] = 0;
    forn(i,0,n)
    {
        int x;
        cin >> x;
        //cout << __builtin_ctz(x) << endl;
        cnt[__builtin_ctz(x)]++;
    }
    while(q--)
    {
        int x;
        cin >> x;
        int ans = 0;
        for(int i = 30; i >= 0 && x > 0; i--)
        {
            int need = min(cnt[i], x>>i);
            //cout << x << " " << i << " " << need << " " << cnt[i] << " " << x << endl;
            ans += need;
            x -= need*(1<<i);
        }
        if(x > 0) cout << -1 << endl;
        else cout << ans << endl;
    }
    return 0;
}
