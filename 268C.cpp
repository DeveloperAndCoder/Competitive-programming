#include<iostream>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    if(n == 0 && m == 0)
    {
        cout << 0;
        return 0;
    }
    if(n == 0 || m == 0)
    {
        cout << 1 << endl;
        cout << n << " " << m;
        return 0;
    }
    cout << min(n,m)+1 << '\n';
    for(int i = 0; i <= min(n,m); i++)
    {
        cout << min(n,m)-i << " " << i << '\n';
    }
    return 0;
}
