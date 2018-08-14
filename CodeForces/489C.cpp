#include<iostream>
#include<cstring>
#define forn(i,a,b) for(int i = a; i < b; i++)
#define forr(i,a,b) for(int i = a; i >= b; i--)
using namespace std;

void calc_min(int m, int s, int ans[])
{
    ans[0] = 1;
    s--;
    forr(i,m-1,0)
    {
        if(s > 9) ans[i] += 9;
        else
        {
            ans[i] += s;
            break;
        }
        s -= 9;
    }
}
void calc_max(int m, int s, int ans[])
{
    forn(i,0,m)
    {
        if(s > 9) ans[i] = 9;
        else
        {
            ans[i] += s;
            break;
        }
        s -= 9;
    }
}

int main()
{
    int m, s;
    cin >> m >> s;
    int ans_m[m], ans_[m];

    memset(ans_m, 0, sizeof(ans_m));
    memset(ans_, 0, sizeof(ans_));
    if(s == 0 && m == 1)
    {
        cout << 0 << " " << 0;
        return 0;
    }
    if(s > 9*m || s < 1)
    {
        cout << -1 << " " << -1 << endl;
        return 0;
    }

    calc_min(m, s, ans_m);calc_max(m, s, ans_);
    if(ans_m[0] == 0) cout << 0;
    else
    forn(i,0,m) cout << ans_m[i];
    cout << " ";
    if(ans_[0] == 0)
        cout << 0;
    else
    forn(i,0,m) cout << ans_[i];
    return 0;
}
