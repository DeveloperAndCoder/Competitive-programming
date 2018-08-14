#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstring>
#include <sstream>
#include <vector>
#include <queue>
#include <stack>
#include <climits>
#include <unordered_set>

#define ll long long
#define ull unsigned long long
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
    boost;
    int t;
    cin >> t;
    while(t--)
    {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        string s1(s.begin(), s.begin()+k);
        unordered_set<string> st;
        st.insert(s1);
        forn(i,k,n)
        {
            //cout << string(s.begin()+i, s.begin()+i+k) << endl;
            //st.insert(string(s.begin()+i, s.begin()+i+k));
            s1.erase(s1.begin());
            s1.push_back(s[i]);
            //cout << s1 << endl;
            st.insert(s1);
        }
        cout << st.size() << endl;
    }
}
