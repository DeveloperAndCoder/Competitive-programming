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
        int n;
        cin >> n;
        int mid = n/2;
        if(n&1) mid++;
        cout << 1 << " " << 1;
        forn(i,mid+1,n+1) cout << 0;
        cout << endl;
    }
}
