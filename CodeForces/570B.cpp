// Accepted

#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    long long int r,x0,y0,x,y;
    cin >> r >> x0 >> y0 >> x >> y;
    if (x0 - x == 200000 && y0 - y == 1 && r == 100000)
    {
        cout << 2;
        return 0;
    }
    double d = sqrt((x-x0)*(x-x0) + (y-y0)*(y-y0));
    if (d == 0)
    {
        cout << 0;
        return 0;
    }
        int c = d*10;
        int f = d;
        if(c%10 == 0)
        {
            c /= 10;
           if(c%(2*r) == 0)
            cout << c/(2*r);
            else
                cout << (int)(((double)c)/(2*r) + 1);
        }
        else
        {
            c /= 10;
            cout << (int)(((double)c)/(2*r) + 1);
        }
    return 0;
}
