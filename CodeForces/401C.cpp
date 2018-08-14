#include<iostream>
//#include<cstring>

#define forn(i,a,b) for(int i = a; i < b; i++)
#define ll long long

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> m >> n;
    if(m - n == 1)
    {
        cout << 0;
        m--;
    }
    //int ans[n+m];
    //memset(ans, 0, sizeof(ans));
    if(n >= m)
    {
        if(n > 2*(m+1))
        {
            cout << -1;
            return 0;
        }
        int diff = n-m-1;
        //cout << diff << endl;
        bool add_zero = false;
        forn(i,0,n+m)
        {
            if(add_zero)
            {
                //ans[i] = 0;
                cout << 0;
            }
            else
            {
                //ans[i] = 1;
                cout << 1;
                if(diff > 0)
                {
                    //ans[++i] = 1;
                    i++;
                    cout << 1;
                    diff--;
                }
            }
            add_zero = !add_zero;
        }
    }
    else
    {
        cout << -1;
        return 0;
    }
    //forn(i,0,n+m) cout << ans[i];
    return 0;
}
