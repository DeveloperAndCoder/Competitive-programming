#include<bits/stdc++.h>

#define forn(i,a,b) for(int i = a;i < b; i++)

using namespace std;

void no()
{
    cout << "-1";
    exit(0);
}

int main()
{
   int n, k;
   cin >> n >> k;
   vector<int> p(n);
   set<int> miss;
    forn(i,0,n) miss.insert(i);
    forn(i,0,k)
    {
        cin >> p[i];
        p[i]--;
        miss.erase(p[i]);
    }
    int out = 0;
    stack<int> s;
    forn(i,0,k)
    {
        while(!s.empty() && s.top() < p[i] && s.top() == out)
            s.pop(),out++;
        if(!s.empty() && s.top() < p[i] && s.top() != out) no();
        s.push(p[i]);
    }
    forn(i,k,n)
    {
        while(!s.empty() && s.top() == out) s.pop(),out++;
        int limit = s.empty()? INT_MAX/2:s.top();
        set<int>::iterator it = prev(miss.lower_bound(limit));
        s.push(*it);
        p[i] = *it;
        miss.erase(it);

    }
    forn(i,0,n) cout << p[i]+1 << " ";

    return 0;
}
