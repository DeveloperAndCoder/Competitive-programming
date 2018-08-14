#include<iostream>
#include<algorithm>

#define forn(i,a,b) for(int i = a; i < b; i++)
using namespace std;

int main()
{
    int n, pos, l, r;
    cin >> n >> pos >> l >> r;
    int ans = 0;
    if(pos >= l && pos <= r)
    {
        if(l != 1 && r != n)
        {
            if(pos-l < r-pos)
            {
                ans += pos-l;
                ans += r-l;
                ans+=2;
            }
            else
            {
                ans += r-pos;
                ans++;
                ans += r-l;
                ans++;
            }
        }
        else
        {
            if(l == 1 && r == n)
            {
                ans = 0;
            }
            else if(l == 1)
            {
                ans += r-pos;
                ans++;
            }
            else if(r == n)
            {
                ans += pos-l;
                ans++;
            }
        }
    }
    else if(pos <= l)
    {
        ans += l-pos;
        ans++;
        if(r != n)
        ans += r-l+1;
    }
    else
    {
        ans += pos-r+1;
        if(l != 1)
            ans += r-l+1;
    }
    cout << ans;
    return 0;
}
