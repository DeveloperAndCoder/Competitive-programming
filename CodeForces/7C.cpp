#include<iostream>
using namespace std;

int main()
{
    int A,B,C;
    cin >> A >> B >> C;
    long long x=-B-1,y;
    if(C%B == 0)
    {
        x = B;
        y = -(A+C/B);
    }
    else
    {
        long long k = B - (C%B);
        long long int i;
        if(B < 0)
            i = B;
        else i = -B;
        for(i; i <= B; i++)
        {
            if((i*A+C)%B==0)
            {
                x = i;
                y = -(A*x+C)/B;
                break;
            }
        }
    }
    if(x == -1-B)
        cout << -1;
    else
        cout << x << " " << y;
    return 0;
}
