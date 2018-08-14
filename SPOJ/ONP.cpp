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
#define forn(i,a,b) for(ll i = a; i < b; i++)
#define boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define MAX 1000001

using namespace std;

int main()
{
    boost;
    int t;
    cin >> t;
    while(t--)
    {
        string s;
        cin >> s;
        stack<char> oper;
        for(int i = 0; i < s.size(); i++)
        {
            if(isalpha(s[i])) cout << s[i];
            else
            {
                if(s[i] != ')') oper.push(s[i]);
                else
                {
                    while(oper.top() != '(') {cout << oper.top();oper.pop();}
                    oper.pop();
                }
            }
        }
        cout << endl;
    }
}
