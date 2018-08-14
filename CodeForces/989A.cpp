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
#define forn(i,a,b) for(ul i = a; i < b; i++)
#define boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define fr first
#define sc second
#define MAX 1000001
#define N 1000001

using namespace std;

int main()
{
    string s;
    cin >> s;
    forn(i,1,s.size()-1)
    {
        if(s[i] == '.') continue;
        int a = 0, b = 0, c = 0;
        if(s[i] == 'A') a++;
        else if(s[i] == 'B') b++;
        else if(s[i] == 'C') c++;
        if(s[i+1] == 'A') a++;
        else if(s[i+1] == 'B') b++;
        else if(s[i+1] == 'C') c++;
        if(s[i-1] == 'A') a++;
        else if(s[i-1] == 'B') b++;
        else if(s[i-1] == 'C') c++;

        if(a == 1 && b == 1 && c == 1)
        {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
    return 0;
}
