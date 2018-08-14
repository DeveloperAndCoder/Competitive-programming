#include<iostream>
#include<cstring>

#define forn(i,a,b) for(int i = a; i < b; i++)
#define ll long long
#define mod 1000000007

using namespace std;

int main()
{
    int n, i, maxx = -1, ans = -1;
    cin >> n;
    char s[n];
    forn(i,0,n) cin >> s[i];
    forn(i,0,n-1)
    {
        int count = 0;
        forn(j,0,n-1)
        {
            if(s[j] == s[i] && s[j+1] == s[i+1])
                count++;
        }
        if(count > maxx)
        {
            maxx = count;
            ans = i;
        }
    }
    cout << s[ans] << s[ans+1];
    return 0;
}
