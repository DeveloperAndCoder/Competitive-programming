#include<iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int x = 0, y = 0;
    bool done = false;
    while(4*x <= n)
    {
        if((n-4*x)%7 == 0)
        {
            done = true;
            y = (n-4*x)/7;
            break;
        }
        x++;
    }
    if(done)
    {
        while(x--) cout << '4';
        while(y--) cout << '7';
    }
    else
    {
        cout << -1;
    }
    return 0;
}
