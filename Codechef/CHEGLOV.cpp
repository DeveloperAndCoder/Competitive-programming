#include<iostream>

#define forn(i,a,b) for(int i = a; i < b; i++)

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int l[n],g[n];
        forn(i,0,n) cin >> l[i];
        forn(i,0,n) cin >> g[i];
        bool f=1,b=1;
        forn(i,0,n)
        {
            if(l[i] > g[i])
            {
                f=0;
                break;
            }
        }
        for(int i = n-1; i>= 0; i--)
        {
            if(l[n-i-1] > g[i])
            {
                b=0;
                break;
            }
        }
        if(b && f) cout << "both\n";
        else if(b) cout << "back\n";
        else if(f) cout << "front\n";
        else cout << "none\n";
    }
    return 0;
}
