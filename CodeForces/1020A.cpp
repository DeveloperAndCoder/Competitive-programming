#include<iostream>
#include<cmath>
using namespace std;
#define forn(i,a,b) for(int i = a; i < b; i++)

int main()
{
    int n, h, a, b;
    cin >> n >> h >> a >> b;
    int k;
    cin >> k;
    while(k--)
    {
        int ta, fa, tb, fb;
        cin >> ta >> fa >> tb >> fb;
        int ans = 0;
        int pf = fa;
        if(ta != tb && fa < a) { ans = a-fa; pf = a; }
        else if(ta != tb && fa > b) { ans = fa-b; pf = b; }
        ans += abs(tb-ta);
        ans += abs(pf-fb);
        cout << ans << '\n';
    }
    return 0;
}
