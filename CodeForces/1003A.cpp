#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <unordered_set>
#include <cmath>
#include <utility>
#include <iomanip>

#define forn(i,a,b) for(int i = a; i < b; i++)
#define ll long long
#define boost ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

int p[101];

int main()
{
    int a,b,x;
    cin >> a >> b >> x;
    string s;
    while(1)
    {
        if(x == 1)
        {
            //cout << s << endl;
            if(s.empty())
            {
                while(a--) s += "0";
                while(b--) s += "1";
            }
            else
            {
                if(s.back() == '1')
                {
                    while(b--) s += "1";
                    while(a--) s += "0";
                }
                else
                {
                    while(a--) s += "0";
                    while(b--) s += "1";
                }
            }
            break;
        }
        else
        {
            if(s.empty())
            {
                if(a > b)
                    {
                        s += "0";
                        a--;
                    }
                else
                    {
                        b--;
                        s += "1";
                    }
            }
            else
            {
                if(s.back() == '0')
                {
                    s += "1";
                    b--;
                }
                else
                {
                    s += "0";
                    a--;
                }
                x--;
            }
        }
    }
    cout << s;
    return 0;
}
