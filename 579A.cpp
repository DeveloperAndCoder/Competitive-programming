#include<iostream>
#include<algorithm>
#include<cstring>

#define forn(i,a,b) for(int i = a; i < b; i++)
#define ll long long

using namespace std;

int main()
{
    int x;
    cin >> x;
    ll ans = 0;
    int i = 0;
    /*
    while(x)
    {
        if(x-(1<<i) >= 0)
            ++i;
   /*     else if(x == (1<<i))
        {
            ans = 1;
            break;
        }

        else
        {
            i--;
            ans++;
            //cout << "i = " << i << " n = " << x << '\n';
            x -= 1<<i;
            i=0;
        }
    }
    */
    while(x)
    {
        if(x&1) ans++;
        x>>=1;
    }
    cout << ans;
    return 0;
}
