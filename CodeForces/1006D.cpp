#include <bits/stdc++.h>

using namespace std;

#define forn(i,a,b) for(int i = a; i < b; i++)
#define ll long long
#define N (int)2e5+1

int main()
{
    string a, b;
    int n;
    cin >> n;
    cin >> a >> b;
    int ans = 0;
    forn(i,0,n)
    {
        int cp = n-i-1;
        if(cp <= i) break;
        cout << a[i] << " " << a[cp] << " " << b[i] << " " << b[cp] << " " << ans << endl;
        int a1[4] = {a[i], a[cp], b[i], b[cp]};
        sort(a1, a1+4);
        int diff = 0;
        if(a1[0] == a1[1])
        {
            if(a1[2] == a1[3]) diff = 0;
            else diff = 1;
        }
        else if(a1[1] == a1[2])
        {
            diff = 1;
        }
        else diff = 2;
        ans += diff;
    }
    if(n&1) if(a[n/2] != b[n/2]) ans++;
    cout << ans;
    return 0;
}
