#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cmath>
#include<set>
#include<iomanip>

#define forn(i,a,b) for(int i = a; i < b; i++)
#define boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define eb emplace_back
#define pb push_back
#define fr first
#define sc second
#define sins insert

typedef long long ll;

#define M 1000000000
const int mod = 1000000007;

using namespace std;

int main()
{
    int r,c;
    cin >> r >> c;
    char a[r][c];
    forn(i,0,r)
    forn(j,0,c) cin >> a[i][j];
    forn(i,0,r)
    {
        forn(j,0,c)
        {
            if(a[i][j] == 'W')
            {
                if((i > 0 && a[i-1][j] == 'S') || (i < r-1 && a[i+1][j] == 'S') || (j > 0 && a[i][j-1] == 'S') || (j < c-1 && a[i][j+1] == 'S'))
                {
                    cout << "No";
                    return 0;
                }
                if(i > 0 && a[i-1][j] == '.')   a[i-1][j] = 'D';
                if(i < r-1 && a[i+1][j] == '.') a[i+1][j] = 'D';
                if(j > 0 && a[i][j-1] == '.')   a[i][j-1] = 'D';
                if(j < c-1 && a[i][j+1] == '.') a[i][j+1] = 'D';
            }
        }
    }
    cout << "Yes\n";
    forn(i,0,r)
    {
        forn(j,0,c) cout << a[i][j];
        cout<<'\n';
    }
    return 0;
}
