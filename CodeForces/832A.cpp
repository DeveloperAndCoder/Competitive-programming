#include<iostream>
using namespace std;
int main()
{
    unsigned long long int n, k;
    cin >> n >> k;
    n = n/k;
    if (n%2 == 0)
    {
        cout << "NO";
    }
    else
    {
        cout << "YES";
    }
    return 0;
}
