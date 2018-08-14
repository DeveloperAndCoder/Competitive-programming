#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

bool ispalin(string s)
{
    int j = s.size()-1;
    for(int i = 0; i < j; i++, j--)
        if(s[i] != s[j]) return false;
    return true;
}

int main()
{
    int t;
    cin >> t;
    int k = 1;
    while(t--)
    {
        cout << "Case " << k++ << ":\n";
        int n;
        cin >> n;
        string s;
        cin >> s;
        int m;
        cin >> m;
        int diff = 0;
        for(int i = 0; i < static_cast<int>(n/2); i++)
            if(s[i] != s[n-1-i]) diff++;
        while(m--)
        {
            int p;
            cin >> p;
            p--;
            char c;
            cin >> c;
            if(s[p] != s[n-1-p])
            {
                s[p] = c;
                if(s[p] == s[n-1-p]) diff--;
            }
            else
            {
                s[p] = c;
                if(s[p] != s[n-1-p]) diff++;
            }
            //cout << "dif = " << diff << endl;
            //cout << s << endl;
            if(diff == 0)
            {

            /*
                if(!ispalin(s))
                {
                    cout << "Error\n";
                    cout << n << " " << m << " " << s;
                    //return 0;
                }
                */

                cout << "YES\n";
            }
            else
            {
                /*
                if(ispalin(s))
                {
                    cout << "Error\n";
                    cout << n << " " << m << " "  << s << endl;
                }
                */
                cout << "NO\n";
            }
        }
    }
    return 0;
}
