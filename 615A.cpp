#include<iostream>

#define forn(a,b) for(int i = a; i < b; i++)

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    bool vis[m];
    int x;
    forn(0,m) vis[i] = false;
    forn(0,n)
    {
        cin >> x;
        int y;
        forn(0,x)
        {
            cin >> y;
            vis[y-1] = true;
        }
    }
    forn(0,m)
    {
        if(!vis[i])
        {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}
