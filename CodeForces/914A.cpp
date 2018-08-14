#include<iostream>
#include<math.h>
#define forn(i,a,b) for(int i =a; i < b; i++)
#define ll long long

using namespace std;

bool is_perfect_square(int n) {
    if (n < 0)
        return false;
    int root(round(sqrt(n)));
    return n == root * root;
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    forn(i,0,n) cin >> a[i];
    int m=-1e6;
    forn(i,0,n)
    {
        if(!is_perfect_square(a[i]))
        {
            m = max(m, a[i]);
        }
    }
    cout << m;
    return 0;
}
