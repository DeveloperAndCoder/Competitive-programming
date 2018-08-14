#include<iostream>
#include<cstring>

#define forn(i,a,b) for(int i = a; i < b; i++)
#define ll long long
#define mod 1000000007

using namespace std;

int main()
{
    int n,m;
    cin >> n >> m;
    char a[n][m];

    forn(i,0,n)
    forn(j,0,m)
    {
        cin >> a[i][j];
        //cout << a[i][j] << " " << i << " " << j << endl;
    }

    ll ans = 1LL;
    int diff = 0;
    bool done[26];
    memset(done, 0, sizeof(done));

    forn(i,0,m)
    {
        memset(done, 0, sizeof(done));
        diff = 0;
        forn(j,0,n)
        {
            if(done[a[j][i]-'A'] == false)
            {
                //cout << a[j][i] << " ";
                done[a[j][i]-'A'] = true;
                diff++;
            }
        }
       // if(diff == 0) cout << "i = " << i << endl;
       //cout << diff << "\n";
        ans = (ans*diff)%mod;
    }
    cout << ans%mod;
    return 0;
}
