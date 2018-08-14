#include<iostream>
#include<algorithm>

#define ll long long
#define forn(i,a,b) for(ll i = a; i < b; i++)
#define mm 1e18

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    ll k;
    cin >> k;
    string s;
    while(k > 1)
    {
        s.push_back('8');
        k -= 2;
    }
    if(k == 1) s.push_back('4');
    if(s.length() <= 18)
        cout << s;
    else
        cout << -1;
    return 0;
}
