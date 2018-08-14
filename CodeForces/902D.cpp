#include<iostream>
#include<vector>
#include<cstring>

#define forn(a,b) for(int i = a; i < b; i++)

using namespace std;

int main()
{
    int n;
    cin >> n;
    int p[n+1][n+1];
    memset(p, 0, sizeof(p));
    p[0][0] = 1;
    p[1][1] = 1;
    forn(2,n+1)
    {
        p[i][0] = p[i-2][0];
        //bool inc_one = true;
        for(int j = 1; j < i+1; j++)
        {
            if(p[i-1][j-1]*p[i-2][j] == 1)
            {
                //inc_one = false;
                p[i][j] = -p[i-1][j-1]+p[i-2][j];
            }
            else
            {
                p[i][j] = p[i-1][j-1]+p[i-2][j];
            }
        }
        /*
        if(inc_one)
        {
            p[i][0] = p[i-2][0];
            for(int j = 1; j < i+1; j++)
            {
                p[i][j] = p[i-1][j-1]+p[i-2][j];
            }
        }
        else
        {
            p[i][0] = p[i-2][0];
            for(int j = 1; j < i+1; j++)
            {
                p[i][j] = -p[i-]
            }
        }
        */
    }
    cout << n << '\n';
    forn(0,n+1)
    cout << p[n][i] << " ";
    cout << '\n' << n-1 << '\n';
    forn(0,n)
    cout << p[n-1][i] << " ";
    return 0;
}
