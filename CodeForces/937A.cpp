#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cmath>
#include<set>

#define forn(i,a,b) for(int i = a; i < b; i++)
#define boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define eb emplace_back
#define pb push_back
#define fr first
#define sc second
#define sins insert

typedef long long ll;

#define M 1000000000
const int mod = 1000000007;

using namespace std;

int main()
{
    boost;
    int n;
    cin >> n;
    set<int> s;
    int a;
    forn(i,0,n)
    {
        cin >> a;
        s.sins(a);
    }
    int ans = s.size();
    set<int> :: iterator it = s.begin();
    if(*it == 0) ans--;
    cout << ans;
    return 0;
}
