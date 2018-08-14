#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
#include <utility>
#include <iomanip>
#include <sstream>

#define ll long long
#define forn(i,a,b) for(ll i = a; i < b; i++)
#define boost ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, m;
        cin >> n >> m;
        int a;
        int ans = 0;
        forn(i,0,n)
        {
            cin >> a;
            if(a%m == 0) ans++;
        }
        cout << (1<<ans)-1 << endl;
    }
    return 0;
}
