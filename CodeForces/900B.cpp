#include<iostream>
#include<cstring>

#define forn(i,a,b) for(int i = a; i < b; i++)

using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    bool dig[b];
    memset(dig, false, sizeof(dig));
    int rem=0;
    int pos = 0;
    while(b > a)
    {
        if(c == 0 && pos == 1)
        {
            cout << 1;
            return 0;
        }
        a*=10;
        pos++;
    }

    rem = a%b;
    while(1)
    {
        rem = a%b;
        if( (int)(a/b) == c)
        {
            cout << pos;
            break;
        }
        if(!dig[rem])
        dig[rem] = true;
        else
        {
            cout << -1;
            break;
        }
        a = rem*10;
        pos++;
    }
    return 0;
}
