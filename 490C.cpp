#include<iostream>
#include<string>

#define ll long long
#define forn(i,a,b) for(int i = a; i < b; i++)

using namespace std;

void divby(string s, int l, int r, int a, int suff[])
{
    suff[r] = (s[r]-'0')%a;
    ll pow = 1;
    for(int i = r-1; i >= l; i--)
    {
        pow = (pow*10)%a;
        suff[i] = (suff[i+1] + pow*(s[i]-'0'))%a;
    }
    return;
}

void divbya(string s, int l, int r, int a, int suff[])
{
    suff[l] = (s[l]-'0')%a;
    forn(i,l+1,r)
    {
        suff[i] = (suff[i-1]*10+s[i]-'0')%a;
    }
    return;
}

int main()
{
    string s;
    cin >> s;
    int a, b;
    cin >> a >> b;
    int suffb[s.length()], suffa[s.length()];
    int len = s.length();
    int l1 = 0;
    int r = (s[0]-'0')%a;
    divby(s,0,len-1,b,suffb);
    divbya(s,0,len-1,a,suffa);
    forn(i,0,len-1)
    {
        if(suffa[i] == 0 && suffb[i+1] == 0 && s[i+1] != '0')
        {
            cout << "YES\n";
            forn(j,0,i+1) cout << s[j];
            cout << '\n';
            forn(j,i+1,len) cout << s[j];
            return 0;
        }
    }

    cout << "NO";
    return 0;
}
