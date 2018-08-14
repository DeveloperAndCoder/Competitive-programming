#include<iostream>
#include<string>
#include<sstream>
#include<math.h>
#include<stack>
#include<climits>

#define forn(i,a,b) for(int i = a; i < b; i++)
#define ll long long
#define MAX 10001

#define boost ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

int howmany(string s)
{
    stack<char> st;
    int oper = 0;
    forn(i,0,s.size())
    {
        if(s[i] == '{')
        {
            st.push(s[i]);
        }
        else if(s[i] == '}')
        {
            if(st.empty())
            {
                oper++;
                st.push('{');
            }
            else
            {
                st.pop();
            }
        }
    }
    oper += st.size()/2;
    return oper;
}

int main()
{
    boost;
    string s;
    int k = 1;
    while(1)
    {
        cin >> s;
        if(s[0] == '-') break;
        cout << k++ << ". " << howmany(s) << endl;
    }
}
