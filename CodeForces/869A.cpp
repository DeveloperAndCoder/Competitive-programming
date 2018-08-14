#include<iostream>
using namespace std;

int main()
{
    long long int a, b;
    cin >> a >> b;
    long long int n = b - a;
    if(n == 0)
    {
        cout << 1;
        return 0;
    }
    if(n >= 10)
    {
        cout << 0;
        return 0;
    }
    long long int i = 0;
    a = 0;
    if(n == 1)
    {
        cout << b%10;
        return 0;
    }
    a = (b%10)*((b-1)%10);
    for(i = 2; i < n; i++)
    {
        a *= ((b-i)%10);
        a = a%10;
        if(a == 0)
            break;
    }
    cout << a%10;
    return 0;
}
