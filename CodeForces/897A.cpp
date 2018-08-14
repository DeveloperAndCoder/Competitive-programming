#include<iostream>

#define forn(i,a,b) for(int i = a; i < b; i++)

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    char c[n];
    forn(i,0,n) cin >> c[i];
    while(m--)
    {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        char ch1, ch2;
        cin >> ch1 >> ch2;
        forn(i,l,r+1)
        if(c[i] == ch1)
            c[i] = ch2;
    }
    forn(i,0,n) cout << c[i];
    return 0;
}
