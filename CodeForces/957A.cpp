#include<iostream>
#include<vector>
#include<cstring>
#include<stack>

#define forn(i,a,n) for(int i = 0; i < n; i++)
#define ll long long
#define eb emplace_back
#define mem(array,value) memset(array, value, sizeof(array))

using namespace std;

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    forn(i,0,n-1)
    {
        if(s[i]==s[i+1] && s[i] != '?')
        {
            cout << "No";
            return 0;
        }
    }
    if(s[0] == '?' || s[n-1]=='?')
    {
        cout << "Yes";
        return 0;
    }
    forn(i,1,n-1)
    {
        if(s[i]=='?')
        {
            int c=0,m=0,y=0;
            if(s[i-1] == 'C') c++;
            if(s[i+1] == 'C') c++;
            if(s[i-1] == 'M') m++;
            if(s[i+1] == 'M') m++;
            if(s[i-1] == 'Y') y++;
            if(s[i+1] == 'Y') y++;
            if(s[i-1]=='?' || s[i+1]=='?')
            {
                cout << "Yes";
                return 0;
            }
            if(c == 2 || m == 2 || y == 2)
            {
                cout << "Yes";
                return 0;
            }
        }
    }
    cout << "No";
    return 0;
}
