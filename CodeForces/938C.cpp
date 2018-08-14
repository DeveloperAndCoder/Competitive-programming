#include<iostream>
#include<algorithm>
#include<cstring>
#include<math.h>
#include<vector>

#define forn(i,a,b) for(int i = a; i < b; i++)
#define ll long long
#define eb emplace_back
#define boost ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

int main()
{
   // boost;
    int t;
    cin >> t;
    //t = 100;
    while(t--)
    {
        ll xi;
        cin >> xi;
      //  xi = 1000000000-t;
        ll n,m,q,t;
        bool mn = 1;
        forn(i,sqrt(xi),100000)
        {
            t = i*i-xi;
            if(t<=0) continue;
            q = sqrt(t);
            if(q*q == t)
            {
                n = i;
                m = n/q;
                cout << n << " " << m << " " << q << endl;
                if(n%q == 0)
                {
                    cout << n << " " << m << endl;
                    mn = 0;
                    break;
                }
            }
        }
        if(mn) cout << -1 << endl;
    }
    return 0;
}
