#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>

#define forn(i,a,n) for(int i = 0; i < n; i++)
#define ll long long
#define eb emplace_back
#define mem(array,value) memset(array, value, sizeof(array))

using namespace std;

int main()
{
    string s;
    cin >> s;
    int c[26];
    forn(i,0,26) c[i]=0;
    forn(i,0,s.length())
    {
        c[s[i]-'a']++;
    }
    int x[4],j=0;
    mem(x,0);
    forn(i,0,26)
    {
        if(c[i] >= 1 && j > 3)
        {
            cout << "No";
            return 0;
        }
        if(c[i]>=1 && j <= 3) x[j++] = c[i];
    }
    sort(x,x+4);
    if((x[0]==0&&x[1]==0&&x[2]==1&&x[3]>1) || (x[3]==1&&x[2]==1&&x[1]==1&&x[0]==0) || (x[0]==0&&x[1]==0&&x[2]==0))
    {
        cout << "No";
    }
    else
    {
        cout << "Yes";
    }
    return 0;
}
