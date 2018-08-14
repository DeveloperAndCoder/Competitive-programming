#include<iostream>
#include<vector>

#define forn(i,a,b) for(int i = a; i < b; i++)

using namespace std;

int main()
{
    int n,x;
    cin >> n;
    vector<int> a[n];
    forn(i,0,n)
    forn(j,0,n)
    {
        cin >> x;
        a[i].push_back(x);
    }
    vector<int> b[n];
    forn(i,0,n)
    for(int j = n-1; j >= 0; j--)
    {
        b[i].push_back(a[j][i]);
    }
    forn(i,0,n)
    {
        forn(j,0,n)
        cout << b[i][j] << " ";
        cout << '\n';
    }
    return 0;
}
