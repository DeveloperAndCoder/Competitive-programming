#include<iostream>
#include<set>

#define forn(i,a,b) for(int i = a; i < b; i++)

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n,x;
        set<int> s;
        cin >> n;
        forn(i,0,n)
        {
            cin >> x;
            s.insert(x);
        }
        cout << n-s.size() << '\n';
    }
    return 0;
}

