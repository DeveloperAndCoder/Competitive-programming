#include <bits/stdc++.h>

using namespace std;

#define forn(i,a,b) for(int i = a; i < b; i++)
#define ll long long

int main()
{
    int n, m;
    cin >> n >> m;
    if(m < n-1)
    {
        cout << "Impossible";
    }
    else
    {
        int m1 = m;
        vector<pair<int,int> > ed;
        for(int i = 1; i <= n && m; i++)
        {
            for(int j = i+1; j <= n && m; j++)
            {
                if(__gcd(i, j) == 1)
                {
                    ed.push_back({i,j});
         //           cout << i << " " << j << endl;
                    m--;
                }
            }
        }
        if(ed.size() == m1)
        {
            cout << "Possible\n";
            for(auto it : ed)
            {
                cout << it.first << " " << it.second << endl;
            }
        }
        else
            cout << "Impossible\n";
    }
    return 0;
}
