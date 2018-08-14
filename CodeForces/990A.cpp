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

int main()
{
    ll n,m,a,b;
    cin >> n >> m >> a >> b;
    ll left = (n/m)*m;
    ll right = ((n/m)+1)*m;
   // cout << left << " " << right << endl;
    ll rup = min(b*(n-left), a*(right-n));
    cout << rup;
    return 0;
}
