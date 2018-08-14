#include<iostream>
#include<vector>
#include<queue>

#define forn(a,b) for(int i = a; i < b; i++)

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    /*
    bool v[n];
    forn(0,n) v[i] = false;
    */
    int i_, j_;
    bool ini = true;
    int m_ = 0;
    forn(0,n)
    {
        cin >> i_ >> j_;
        if(i == 0 && i_ != 0)
            ini = false;
        if(i_ <= m_ && j_ > m_)
            m_ = j_;
    }
    if(m_ >= m && ini)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}
