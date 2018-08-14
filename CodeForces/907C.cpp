#include<iostream>
#include<vector>
#include<string>

#define forn(i,a,b) for(int i = a; i < b; i++)

using namespace std;
char ans;
inline bool check(const vector<int>& c)
{
    int d=0;
    forn(i,0,26)
    {
        if(c[i] == 1)
            {
                d++;
                ans = i+97;
            }
    }
    if(d==1) return true;
    d = 0;
    forn(i,0,26)
    {
        if(c[i] == 0)
        {
            d++;
        }
        else ans = i+97;
    }
    if(d == 25)
        return true;
    return false;
}
void rem(vector<int>& c,string s)
{
    vector<bool> sc(26,0);
    int len = s.length();
    forn(i,0,len)
    {
        sc[s[i]-'a'] = 1;
    }
    forn(i,0,26)
    {
        if(c[i] == 1 && sc[i] == 0)
        {
            c[i] = 0;
        }
    }
    return;
}

void print(vector<int> c)
{
    forn(i,0,26)
    {
        if(c[i] == 1)
        {
            cout << (char)(i+97) << " ";
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> c(26,-1);
    char ch;
    string s;
    int q = 0;
    bool once = true;
    bool sett = false;
    int n1=0;
    while(n--)
    {
        cin >> ch;
        cin >> s;
        int len = s.length();
        if(ch == '.')
        {
            forn(i,0,len)
            {
                c[s[i]-'a'] = 0;
            }
        }
        else if(ch == '!')
        {
            if(check(c))
            {
                q++;
                continue;
            }
            rem(c, s);
            if(!sett)
            forn(i,0,len)
            {
                if(c[s[i]-'a'] != 0)
                    c[s[i]-'a'] = 1;
            }
            sett = true;
        }
        else if(ch == '?')
        {
            if(check(c) && s[0] != ans)
            {
                q++;
                continue;
            }
            if(n > 0)
                {
                    c[s[0]-'a'] = 0;
                }
        }
    n1++;
/*
        if(once && check(c))
        {
            once = false;
        }

        print(c);
        cout << endl;
*/
    }
    cout << q;
    return 0;
}
