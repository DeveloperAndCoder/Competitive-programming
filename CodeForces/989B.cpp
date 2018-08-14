#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstring>
#include <sstream>
#include <vector>
#include <queue>
#include <stack>
#include <climits>

#define ll long long
#define ul unsigned long long
#define forn(i,a,b) for(int i = a; i < b; i++)
#define boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define fr first
#define sc second
#define MAX 1000001
#define N 1000001

using namespace std;

int main()
{
    int n, p;
    cin >> n >> p;
    string s;
    cin >> s;
    bool solve = false;
    forn(i,0,s.length())
    {
        if(solve)
        {
            if(s[i] == '.') s[i] = '0';
            continue;
        }
        //cout << i << " " << s << endl;
        if(i-p >= 0)
        {
            //cout << "in1\n";
            if(s[i] == '.')
            {
                if(s[i-p] == '0') s[i] = '1';
                else if(s[i-p] == '1') s[i] = '0';
                else
                {
                    s[i-p] = '1';
                    s[i] = '0';
                }
                solve = true;
            }
            else if(s[i] == '0' && s[i-p] == '1')
            {
                solve = true;
            }
            else if(s[i] == '1' && s[i-p] == '0')
            {
                solve = true;
            }
        }
        if(i+p < s.length())
        {
            //cout << "in2\n";
            //cout << i+p << " " << s[i+p] << " " << s[i] << " " << i << endl;
            //if(s[i] == s[i+p]) continue;
            if(s[i] == '.')
            {
          //      cout << "in2.1\n";
                if(s[i+p] == '0') s[i] = '1';
                else if(s[i+p] == '1') s[i] = '0';
                else
                {
                    s[i] = '0';
                    s[i+p] = '1';
                }
                solve = true;
            }
            else if(s[i] == '0' && s[i+p] == '1')
            {
                solve = true;
            }
            else if(s[i] == '1' && s[i+p] == '0')
            {
                solve = true;
            }
        }
        if(s[i] == '.') s[i] = '0';
    }
    if(solve)
        cout << s;
    else cout << "No";
    return 0;
}
