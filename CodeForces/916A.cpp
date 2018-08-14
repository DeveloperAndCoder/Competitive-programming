#include<iostream>

#define forn(i,a,b) for(int i =a; i < b; i++)

using namespace std;

bool check(int hh, int mm)
{
    while(hh)
    {
        if((hh%10) == 7)
            return true;
        hh /=10;
    }
    while(mm)
    {
        if((mm%10) == 7)
            return true;
        mm /=10;
    }
    return false;
}

int main()
{
    int x;
    cin >> x;
    x %= 61;
    int h, m;
    cin >> h >> m;
    int dur = 0;
    int hh = h,mm=m;
    int c1 = 0;
    if(check(hh, mm))
    {
        cout << c1;
        return 0;
    }
    while(!check(hh,mm))
    {
        //cout << hh << mm << endl;
        c1++;
        mm -= x;
        if(mm < 0)
        {
            hh--;
            mm = 60+mm;
            if(hh < 0)
            {
                hh = 23;
            }
        }
    }
    //cout << dur << endl;
    cout << c1;
    return 0;
}
