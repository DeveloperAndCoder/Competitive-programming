#include<iostream>
#include<string>

using namespace std;

#define endl '\n'

void solve(string s)
{
    int n = s.length();
    int center = n/2;
    for(int i = 0; i <= center; i++)
    {
        int i1 = n - i - 1;
        cout << i << " " << i1 << endl;
        if(i1 <= i) break;
        if(s[i] == s[i1]) continue;
        if(s[i] > s[i1])
        {
            s[i1] = s[i];
        }
        else
        {
            s[i1] = s[i]+1;
            s[i]++;
        }
    }
    cout << s << endl;
    return;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        string s;
        cin >> s;
        solve(s);
    }
}
