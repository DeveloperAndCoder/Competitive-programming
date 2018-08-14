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
    while(1)
    {
        int n;
        cin >> n;
        if(n == 0) return 0;
        stack<int> st;
        queue<int> q;
        forn(i,0,n)
        {
            int x;
            cin >> x;
            q.push(x);
        }
        int num = 1;
        while(!q.empty())
        {
            if(q.front() == num)
            {
                num++;
                q.pop();
            }
            else
            {
                if(st.empty())
                {
                    st.push(q.front());
                    q.pop();
                }
                else
                {
                    if(st.top() == num)
                    {
                        st.pop();
                        num++;
                    }
                    else
                    {
                        st.push(q.front());
                        q.pop();
                    }
                }
            }
        }
        while(!st.empty())
        {
            if(st.top() == num)
            {
                st.pop();
                num++;
            }
            else
            {
                break;
            }
        }
        if(st.empty()) cout << "yes\n";
        else cout << "no\n";
    }
    return 0;
}
