#include<iostream>
#include<algorithm>

#define uni unsigned int
#define lli long long int
#define li long int
#define N 100000

#define For(a,b) for(int i = a; i < b; i++)
#define fori(a) for(int i = 0; i < a; i++)
#define Forn(a,b) for(int i = b; i >= a; i--)
#define forn(a) for(int i = a; i >= 0; i--)

using namespace std;

int main()
{
    int m[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int n;
    cin >> n;
    int a[n];
    fori(n)
    {
        cin >> a[i];
    }
    bool leap = false;
    int ans = 0;
    int i = 0, j = 0;
    for(j = 0; j < 12; j++)
    {
        for(i = 0; i < n; i++)
        {
            if(a[i] == 29)
            {
                leap = true;
                break;
            }
            if(a[i] != m[(i+j)%12])
               {
                   ans++;
                   break;
               }
        }
        if(leap)
            break;
    }
    if(leap)
    {
        i++;
        j = 2;
        for(i; i < n; i++)
        {
            if(m[j%12] != a[i])
            {
                ans = 12;
                break;
            }
            j++;
        }
    }
    if(ans < 12)
        cout << "YES";
    else
        cout << "NO";
}
