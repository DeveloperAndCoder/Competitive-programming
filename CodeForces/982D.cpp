#include <iostream>

#define forn(i,a,b) for(int i = a; i < b; i++)

using namespace std;


int findk(int a[], int n)
{
    int low = 0,
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    forn(i,0,n) cin >> a[i];
    cout << findk(a,n);
    return 0;
}
