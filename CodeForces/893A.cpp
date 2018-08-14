#include<iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int win;
    int pl1 = 1, pl2 = 2;
    while(n--)
    {
        cin >> win;
        if(win == pl1 || win == pl2)
        {
            if(win == pl1)
            {
                pl2%=3;
                pl2++;
                if(pl2 == pl1)
                {
                    pl2%=3;
                    pl2++;
                }
            }
            else
            {
                pl1%=3;
                pl1++;
                if(pl1 == pl2)
                {
                    pl1%=3;
                    pl1++;
                }
            }
        }
        else
        {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}
