#include<iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int last = n%10;
    if(last <= 5)
    {
        n = n - last;
    }
    else
    {
        n = n - last + 10;
    }
    cout << n;
    return 0;
}
