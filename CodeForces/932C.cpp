#include<iostream>
#include<algorithm>
#include<string>

#define forn(i,a,b) for(int i = a; i < b; i++)

using namespace std;

int main()
{
    int n,a,b;
    cin >> n >> a >> b;
    bool abc = false;
    int k = 0;
    for(int i = 0; i <= n; i+=a)
    {
        if((n-i)%b == 0)
            {
                abc = 1;
                k = i;
                break;
            }
    }
    if(!abc)
    {
        cout << -1;
        return 0;
    }
    int i;
    //cout << "k = " << k << endl;
    for(i = 0; i < k; i++)
    {
        if(i%a == 0)
        {
            //cout << "i = " << i << endl;
            cout << i+a << " ";
        }
        else cout << i << " ";
    }
    //cout << "\n---------------------\n";
    int j = i;
    for(i; i<n; i++)
    {
        if((i-j)%b == 0) cout << (i+b) << " ";
        else cout << i << " ";
    }
    return 0;
}
