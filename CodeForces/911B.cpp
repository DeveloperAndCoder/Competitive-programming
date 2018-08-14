#include<iostream>
#include<vector>

#define forn(i,a,b) for(int i = a;i < b; i++)

using namespace std;


int main()
{
    int n, a, b;
    cin >> n >> a >> b;
    int x = -1;
    if(a > b)
        swap(a,b);
    for(int i = 1; i <= n-1; i++)
    {
        int a1 = a/i;
        int b1 = b/(n-i);
        if(a1 <= 0 || b1 <= 0)
            continue;
        x = max(x,min(a1,b1));
    }
    cout << x;
    return 0;
}
