#include<iostream>

using namespace std;

int main()
{
    int q, a, b, c, d;
    cin >> q;
    while(q--)
    {
        cin >> a >> b >> c >> d;
        if(a == b)
        {
            if(c == d)
            {
                cout << "YES\n";
            }
            else
            {
                cout << "NO\n";
            }
        }
        else if(a == c)
        {
            if(b == d)
            {
                cout << "YES\n";
            }
            else
            {
                cout << "NO\n";
            }
        }
        else if(a == d)
        {
            if(b == c)
            {
                cout << "YES\n";
            }
            else
            {
                cout << "NO\n";
            }
        }
        else
            cout << "NO\n";
    }
    return 0;
}
