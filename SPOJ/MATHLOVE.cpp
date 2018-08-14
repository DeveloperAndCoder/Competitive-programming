#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>

#define forn(i,a,b) for(int i = a; i < b; i++)
#define ll long long
#define boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main()
{
    boost;
    int t;
    cin >> t;
    while(t--)
    {
        ll y;
        cin >> y;
        ll n;
        y = 1 + 8*y;
        ll sq = sqrt(y);
        if(sq*sq == y)
        {
            sq--;
            if(sq >= 0 && sq%2 == 0)
            {
                cout << sq/2;
            }
            else
            {
                cout << "NAI";
            }
        }
        else
        {
            cout << "NAI";
        }
        cout << "\n";
    }
}
