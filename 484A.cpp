#include<iostream>

#define forn(i,a,b) for(int i = a; i < b; i++)
#define ll long long
using namespace std;

ll f(ll l, ll r)
{
    if(l == r) return l;
    int b = 1;
    while(r>>b) b++;
    b--;
    if((1LL<<b) <= l && (1LL<<b) <= r)
        return f(l-(1LL<<b), r-(1LL<<b))+(1LL<<b);
    else if(r >= ((1LL<<(b+1))-1))
        return (1LL<<(b+1))-1;
    else return (1LL<<b)-1;
}


int main()
{
    int n;
    cin >> n;
    while(n--)
    {
        ll l, r;
        cin >> l >> r;
        cout << f(l,r) << endl;
    }
}
