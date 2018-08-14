#include<iostream>

#define ll long long
#define forn(i,a,b) for(int i = a; i < b; i++)

using namespace std;

int main()
{
    int n;
    cin >> n;
    int even = n/2;
    int odd = n-even;
    cout << 2*even+odd << endl;
    forn(i,2,n+1)
    {
        cout << i << " ";
        i++;
    }
    forn(i,1,n+1)
    {
        cout << i << " ";
        i++;
    }
    forn(i,2,n+1)
    {
        cout << i << " ";
        i++;
    }
    return 0;
}
