#include<iostream>
#include<algorithm>

#define uni unsigned int
#define lli long long int
#define li long int
#define N 100000

#define For(a,b) for(int i = a; i < b; i++)
#define fori(a) for(int i = 0; i < a; i++)
#define Forn(a,b) for(int i = b; i >= a; i--)
#define forn(a) for(int i = a; i >= 0; i--)

using namespace std;

int main()
{
    int n;
    cin >> n;
    int t=0,o=0;
    int x;
    fori(n)
    {
        cin >> x;
        if(x == 1)
            o++;
        else
            t++;
    }
    int ans = 0;
    if(o > t)
    {
        ans += t;
        o -= t;
        ans += o/3;
    }
    else
    {
        ans += o;
    }
    cout << ans;
}
