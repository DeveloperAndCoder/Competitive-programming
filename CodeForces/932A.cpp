#include<iostream>
#include<algorithm>
#include<string>

#define forn(i,a,b) for(int i = a; i < b; i++)

using namespace std;

int main()
{
    string a;
    cin >> a;
    cout << a;
    reverse(&a[0], &a[0]+a.length());
    cout << a;
    return 0;
}
