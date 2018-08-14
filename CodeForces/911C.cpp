#include<iostream>
#include<vector>

#define forn(i,a,b) for(int i = a;i < b; i++)

using namespace std;

int main()
{
    int x1,x2,x3;
    cin >> x1 >> x2 >> x3;
    int c = 0;
    if(x1 == 1 || x2 == 1 || x3 == 1)
    {
        cout << "YES";
        return 0;
    }
    if(x1 == 3 && x2 == 3 && x3 == 3)
    {
        cout << "YES";
        return 0;
    }
    if(x1 == 2)
        c++;
    if(x2 == 2)
        c++;
    if(x3 == 2)
        c++;
    if(c>=2)
    {
        cout << "YES";
    }
    else if(c == 1 && ((x1 == 4 && x2 == 4) || (x2 == 4 && x3 == 4) || (x1 == 4 && x3 == 4)))
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
    return 0;
}
