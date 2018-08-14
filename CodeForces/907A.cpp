#include<iostream>
#define forn(i,a,b) for(int i = a; i <= b; i++)
using namespace std;

int main()
{
    int v1,v2,v3,vm;
    cin >> v1 >> v2 >> v3 >> vm;
    forn(i,v1,2*v1)
    {
        forn(j,v2,2*v2)
        {
            if(j >= i)
                break;
            forn(k,v3,2*v3)
            {
                if(k < j && j < i)
                {
                    if(vm <= k && (2*vm) >= k && (2*vm) < j && (2*vm) < i)
                    {
                        cout << i << "\n" << j << "\n" << k;
                        return 0;
                    }
                }
                else
                    break;
            }
        }
    }
    cout << -1;
    return 0;
}
